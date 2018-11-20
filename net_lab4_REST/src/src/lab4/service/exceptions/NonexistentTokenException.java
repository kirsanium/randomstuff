package lab4.service.exceptions;

import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;

public class NonexistentTokenException extends RESTServiceException {

    private final int ERROR_CODE = 403;

    public NonexistentTokenException(HttpExchange httpExchange) {
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
