package lab4.service.exceptions;

import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;

public class IllegalRequestFormatException extends RESTServiceException {

    private final int ERROR_CODE = 400;

    public IllegalRequestFormatException(HttpExchange httpExchange) {
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
