package lab4.service.exceptions;

import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

public class ExistingUsernameException extends RESTServiceException {

    private final int ERROR_CODE = 401;

    public ExistingUsernameException(HttpExchange httpExchange) {
        super(httpExchange);
    }

    @Override
    public void sendError() {
        Headers responseHeaders = httpExchange.getResponseHeaders();
        List<String> headerValue = new LinkedList<>();
        headerValue.add("Token realm='Username is already in use'");
        responseHeaders.put("WWW-Authenticate", headerValue);

        try {
            httpExchange.sendResponseHeaders(ERROR_CODE, -1);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
