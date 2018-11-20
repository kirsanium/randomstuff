package lab4.service;

import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonWriter;
import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;
import lab4.service.exceptions.*;

import java.io.*;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

public class RESTService {

    private final int TOKEN_START = "Token ".length();

    private File messagesFile = null;
    private int port;

    private Map<String, Integer> tokensMap = new ConcurrentHashMap<>();
    private Map<Integer, User> usersMap = new ConcurrentHashMap<>();
    private AtomicInteger currentUserId = new AtomicInteger(0);
    private AtomicInteger currentMessageId = new AtomicInteger(0);

    public RESTService(int port) {
        this.port = port;
    }

    public void start() {
        try {
            File messagesDir = new File("messages".trim());
            if (!messagesDir.exists()) {
                messagesDir.mkdir();
            }
            File newMessagesFile = new File(("messages" + File.separator + "messages.json").trim());
            newMessagesFile.delete();
            if (!newMessagesFile.exists()) {
                messagesDir.createNewFile();
            }
            messagesFile = newMessagesFile;
            HttpServer server = HttpServer.create();
            server.bind(new InetSocketAddress(InetAddress.getByName("localhost"), port), 0);
            server.createContext("/login", new LoginHandler());
            server.createContext("/logout", new LogoutHandler());
            server.createContext("/users", new UsersHandler());
            server.createContext("/messages", new MessagesHandler());
            server.setExecutor(java.util.concurrent.Executors.newCachedThreadPool());
            server.start();
        } catch (IOException e) {
            System.out.println("There was an error starting up the server");
        }
    }

    private class LoginHandler implements HttpHandler {

        @Override
        public void handle(HttpExchange httpExchange) {
            try (JsonReader reader = new JsonReader(new InputStreamReader(httpExchange.getRequestBody()))) {
                if (!httpExchange.getRequestMethod().equals("POST"))
                    throw new IllegalMethodException(httpExchange);
                if (!httpExchange.getRequestHeaders().getFirst("Content-Type").equals("application/json"))
                    throw new IllegalRequestFormatException(httpExchange);

                String username = readUsername(reader, httpExchange);
                for (User user: usersMap.values()) {
                    if (user.getUsername().equals(username)) {
                        throw new ExistingUsernameException(httpExchange);
                    }
                }

                String token = UUID.randomUUID().toString();
                int id = currentUserId.getAndIncrement();
                tokensMap.put(token, id);
                usersMap.put(id, new User(username));

                Headers responseHeaders = httpExchange.getResponseHeaders();
                List<String> contentTypeList = new LinkedList<>();
                contentTypeList.add("application/json");
                responseHeaders.put("Content-Type", contentTypeList);

                httpExchange.sendResponseHeaders(200, 0);

                JsonWriter writer = new JsonWriter(new OutputStreamWriter(httpExchange.getResponseBody()));
                writer.beginObject();
                writer.name("id").value(id);
                writer.name("username").value(username);
                writer.name("online").value(true);
                writer.name("token").value(token);
                writer.endObject();
                writer.close();

            } catch (RESTServiceException e) {
                e.sendError();
            } catch (Exception e) {
                sendUnknownError(httpExchange);
            }
        }

        private String readUsername(JsonReader reader, HttpExchange httpExchange) throws IOException, IllegalRequestFormatException {
            reader.beginObject();
            String username;
            String name = reader.nextName();
            if (name.equals("username")) {
                username = reader.nextString();
            }
            else
                throw new IllegalRequestFormatException(httpExchange);
            reader.endObject();
            return username;
        }
    }

    private class LogoutHandler implements HttpHandler {

        @Override
        public void handle(HttpExchange httpExchange) {
            try {
                if (!httpExchange.getRequestMethod().equals("POST"))
                    throw new IllegalMethodException(httpExchange);

                String token = checkAndGetToken(httpExchange);
                Headers responseHeaders = httpExchange.getResponseHeaders();
                List<String> contentTypeList = new LinkedList<>();
                contentTypeList.add("application/json");
                responseHeaders.put("Content-Type", contentTypeList);
                httpExchange.sendResponseHeaders(200, 0);

                int id = tokensMap.get(token);
                usersMap.remove(id);
                tokensMap.remove(token);

                JsonWriter writer = new JsonWriter(new OutputStreamWriter(httpExchange.getResponseBody()));
                writer.beginObject();
                writer.name("message").value("bye!");
                writer.endObject();
                writer.close();

            } catch (RESTServiceException e) {
                e.sendError();
            } catch (Exception e) {
                sendUnknownError(httpExchange);
            }
        }
    }

    private class UsersHandler implements HttpHandler {

        @Override
        public void handle(HttpExchange httpExchange) {
            try {
                if (!httpExchange.getRequestMethod().equals("GET"))
                    throw new IllegalMethodException(httpExchange);

                checkAndGetToken(httpExchange);

                Headers responseHeaders = httpExchange.getResponseHeaders();
                List<String> contentTypeList = new LinkedList<>();
                contentTypeList.add("application/json");
                responseHeaders.put("Content-Type", contentTypeList);

                String requestPath = httpExchange.getRequestURI().getPath();
                if (!requestPath.equals("/users")) {
                    int userID = Integer.parseInt(requestPath.substring("/users/".length(), requestPath.length()));
                    User user = usersMap.get(userID);
                    if (user == null)
                        throw new UnknownIdException(httpExchange);
                    httpExchange.sendResponseHeaders(200, 0);
                    JsonWriter writer = new JsonWriter(new OutputStreamWriter(httpExchange.getResponseBody()));
                    writer.beginObject();
                    writeUser(writer, userID, user);
                    writer.close();
                }
                else {
                    httpExchange.sendResponseHeaders(200, 0);
                    JsonWriter writer = new JsonWriter(new OutputStreamWriter(httpExchange.getResponseBody()));
                    writer.beginObject();
                    writer.name("users").beginArray();
                    for (int id: usersMap.keySet()) {
                        writeUser(writer, id, usersMap.get(id));
                    }
                    writer.endArray();
                    writer.endObject();
                    writer.close();
                    return;
                }


                System.out.println("check"); //TODO: remove me

            } catch (RESTServiceException e) {
                e.sendError();
            } catch (Exception e) {
                sendUnknownError(httpExchange);
            }
        }
    }

    private class MessagesHandler implements HttpHandler {

        @Override
        public void handle(HttpExchange httpExchange) {
            switch (httpExchange.getRequestMethod()) {
                case "POST":
                    try (JsonReader reader = new JsonReader(new InputStreamReader(httpExchange.getRequestBody()))) {
                        if (!httpExchange.getRequestHeaders().getFirst("Content-Type").equals("application/json"))
                            throw new IllegalRequestFormatException(httpExchange);

                        String token = checkAndGetToken(httpExchange);
                        String message = readMessage(reader, httpExchange);

                        int messageID = currentMessageId.getAndIncrement();
                        JsonWriter fileWriter = new JsonWriter(new FileWriter(messagesFile));
                        fileWriter.beginObject();
                        fileWriter.name("id").value(messageID);
                        fileWriter.name("message").value(message);
                        fileWriter.name("author").value(tokensMap.get(token));
                        fileWriter.endObject();
                        //messagesMap.put(messageID, new Message(message, tokensMap.get(token)));
                        fileWriter.close();

                        Headers responseHeaders = httpExchange.getResponseHeaders();
                        List<String> contentTypeList = new LinkedList<>();
                        contentTypeList.add("application/json");
                        responseHeaders.put("Content-Type", contentTypeList);
                        httpExchange.sendResponseHeaders(200, 0);

                        JsonWriter writer = new JsonWriter(new OutputStreamWriter(httpExchange.getResponseBody()));
                        writer.beginObject();
                        writer.name("id").value(messageID);
                        writer.name("message").value(message);
                        writer.endObject();
                        writer.close();

                    } catch (RESTServiceException e) {
                        e.sendError();
                    } catch (Exception e) {
                        sendUnknownError(httpExchange);
                    }
                    break;
                case "GET":
                    try {
                        String query = httpExchange.getRequestURI().getQuery();
                        String[] offsetAndCount = query.split("&");
                        for (String str: offsetAndCount) {
                            System.out.println(str);//TODO: remove me
                        }
                        if (offsetAndCount.length > 2)
                            throw new IllegalRequestFormatException(httpExchange);

                        int offset = 0;
                        int count = 10;

                        for (String anOffsetAndCount : offsetAndCount) {
                            String[] queryArray = anOffsetAndCount.split("=");
                            switch (queryArray[0]) {
                                case "offset":
                                    offset = Integer.parseInt(queryArray[1]);
                                    break;
                                case "count":
                                    count = Integer.parseInt(queryArray[1]);
                                    if (count > 100)
                                        throw new IllegalRequestFormatException(httpExchange);
                                    break;
                                default:
                                    throw new IllegalRequestFormatException(httpExchange);
                            }
                        }

                        checkAndGetToken(httpExchange);

                        List<Message> messageList = new LinkedList<>();
                        JsonReader fileReader = new JsonReader(new FileReader(messagesFile));
                        for (int i = 0; i < offset; ++i) {
                            fileReader.skipValue();
                        }
                        for (int i = 0; i < count; ++i) {
                            fileReader.beginObject();
                            Integer id = null;
                            String message = null;
                            Integer author = null;
                            while (fileReader.hasNext()) {
                                switch (fileReader.nextName()) {
                                    case "id":
                                        id = fileReader.nextInt();
                                        break;

                                    case "message":
                                        message = fileReader.nextString();
                                        break;

                                    case "author":
                                        author = fileReader.nextInt();
                                        break;
                                }
                            }
                            messageList.add(new Message(id, message, author));
                        }
                        fileReader.close();

                        Headers responseHeaders = httpExchange.getResponseHeaders();
                        List<String> contentTypeList = new LinkedList<>();
                        contentTypeList.add("application/json");
                        responseHeaders.put("Content-Type", contentTypeList);
                        httpExchange.sendResponseHeaders(200, 0);

                        JsonWriter writer = new JsonWriter(new OutputStreamWriter(httpExchange.getResponseBody()));
                        writer.beginObject();
                        writer.name("messages").beginArray();
                        for (Message message: messageList) {
                            writeMessage(writer, message);
                        }
                        writer.endArray();
                        writer.endObject();
                        writer.close();

                    } catch (RESTServiceException e) {
                        e.sendError();
                    } catch (Exception e) {
                        e.printStackTrace();
                        sendUnknownError(httpExchange);
                    }
                    break;
                default:
                    try {
                        throw new IllegalMethodException(httpExchange);
                    } catch (RESTServiceException e) {
                        e.sendError();
                    }
                    break;
            }
        }

        private void writeMessage(JsonWriter writer, Message message) throws IOException {
            writer.beginObject();
            writer.name("id").value(message.getMessageID());
            writer.name("message").value(message.getMessage());
            writer.name("author").value(message.getAuthorID());
            writer.endObject();
        }

        private String readMessage(JsonReader reader, HttpExchange httpExchange) throws IOException, IllegalRequestFormatException {
            reader.beginObject();
            String message;
            String name = reader.nextName();
            if (name.equals("message")) {
                message = reader.nextString();
            }
            else
                throw new IllegalRequestFormatException(httpExchange);
            reader.endObject();
            return message;
        }
    }

    private String checkAndGetToken(HttpExchange httpExchange) throws IllegalRequestFormatException, NoTokenException, NonexistentTokenException {
        String token = httpExchange.getRequestHeaders().getFirst("Authorization");
        if (!token.startsWith("Token "))
            throw new IllegalRequestFormatException(httpExchange);
        token = token.substring(TOKEN_START, token.length());
        System.out.println(token); //TODO: remove me
        System.out.println(tokensMap.keySet().toString());
        if (token.trim().equals(""))
            throw new NoTokenException(httpExchange);
        if (!tokensMap.containsKey(token))
            throw new NonexistentTokenException(httpExchange);
        return token;
    }

    private void writeUser(JsonWriter writer, int id, User user) throws IOException {
        writer.beginObject();
        writer.name("id").value(id);
        writer.name("username").value(user.getUsername());
        writer.name("online").value(user.isOnline());
        writer.endObject();
    }

    private void sendUnknownError(HttpExchange httpExchange) {
        try {
            httpExchange.sendResponseHeaders(500, -1);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
