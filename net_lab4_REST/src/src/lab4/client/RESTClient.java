package lab4.client;

import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonWriter;
import lab4.client.exceptions.LoginErrorException;
import lab4.client.exceptions.RESTClientException;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;

import static java.lang.Thread.sleep;

public class RESTClient {

    private int port;

    public RESTClient(int port) {
        this.port = port;
    }

    public void start() {
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter your username:");
            String username = scanner.next();
            String token = login(username);
            System.out.println("Welcome to the chat!");
            while (true) {
                String userInput = scanner.next();
                switch (userInput) {
                    case "/logout":
                        logout(token);
                        break;

                    case "/list":
                        list(token);
                        break;

                    default:
                        sendMessage(userInput, token);
                        break;
                }
                if (userInput.equals("/logout"))
                    break;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (LoginErrorException e) {
            e.printStackTrace();
        } catch (RESTClientException e) {
            e.printStackTrace();
        }
    }

    private String login(String username) throws IOException, LoginErrorException {
        URL url = new URL("http://localhost:" + port + "/login");
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        con.setRequestMethod("POST");
        con.setRequestProperty("Content-Type", "application/json");
        con.setDoOutput(true);
        JsonWriter writer = new JsonWriter(new OutputStreamWriter(con.getOutputStream()));
        writer.beginObject();
        writer.name("username").value(username);
        writer.endObject();
        writer.close();

        if (con.getResponseCode() != 200)
            throw new LoginErrorException();

        JsonReader reader = new JsonReader(new InputStreamReader(con.getInputStream()));
        reader.beginObject();
        String token = null;
        while (reader.hasNext()) {
            String name = reader.nextName();
            if (name.equals("token")) {
                token = reader.nextString();
            }
            else {
                reader.skipValue();
            }
        }
        if (token == null)
            throw new LoginErrorException();
        return token;
    }

    private void logout(String token) throws IOException, LoginErrorException {
        URL url = new URL("http://localhost:" + port + "/logout");
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        con.setRequestMethod("POST");
        con.setRequestProperty("Authorization", "Token " + token);
        con.setDoOutput(true);

        if (con.getResponseCode() != 200)
            throw new LoginErrorException();
    }

    private void list(String token) throws IOException, RESTClientException {
        URL url = new URL("http://localhost:" + port + "/list");
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        con.setRequestMethod("GET");
        con.setRequestProperty("Authorization", "Token " + token);

        if (con.getResponseCode() != 200)
            throw new LoginErrorException();

        System.out.println("~~List of people online~~");
        JsonReader reader = new JsonReader(new InputStreamReader(con.getInputStream()));
        reader.beginObject();
        if(!reader.nextName().equals("users"))
            throw new RESTClientException();
        reader.beginArray();
        while (reader.hasNext()) {
            reader.beginObject();
            Integer id = null;
            String username = null;
            Boolean isOnline = null;
            while (reader.hasNext()) {
                switch (reader.nextName()) {
                    case "id":
                        id = reader.nextInt();
                        break;

                    case "username":
                        username = reader.nextString();
                        break;

                    case "online":
                        isOnline = reader.nextBoolean();
                        break;
                }
            }
            reader.endObject();
            if (isOnline != null && isOnline) {
                if (username != null) {
                    System.out.println(username);
                }
                else
                    System.out.println(id);
            }
        }
        reader.endArray();
        reader.endObject();
        reader.close();
    }

    private void sendMessage(String message, String token) throws IOException, RESTClientException {
        URL url = new URL("http://localhost:" + port + "/messages");
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        con.setRequestMethod("POST");
        con.setRequestProperty("Authorization", "Token " + token);
        con.setRequestProperty("Content-Type", "application/json");
        con.setDoOutput(true);

        JsonWriter writer = new JsonWriter(new OutputStreamWriter(con.getOutputStream()));
        writer.beginObject();
        writer.name("message").value(message);
        writer.endObject();
        writer.close();

        if (con.getResponseCode() != 200)
            throw new RESTClientException();
    }

    private class Updater implements Runnable {

        @Override
        public void run() {
            try {
                sleep(1);
                update();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void update() {

        }
    }
}
