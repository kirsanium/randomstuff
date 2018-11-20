package lab4.service.exceptions;

import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;

public class UnknownIdException extends RESTServiceException {

    private final int ERROR_CODE = 404;

    public UnknownIdException(HttpExchange httpExchange) {
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
