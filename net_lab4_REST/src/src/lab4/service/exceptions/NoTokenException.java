package lab4.service.exceptions;

import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;

public class NoTokenException extends RESTServiceException {

    private final int ERROR_CODE = 401;

    public NoTokenException(HttpExchange httpExchange) {
        super(httpExchange);
    }

    @Override
    public void sendError() {
        try {
            httpExchange.sendResponseHeaders(ERROR_CODE, -1);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
