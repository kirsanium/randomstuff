package lab4.service.exceptions;

import com.sun.net.httpserver.HttpExchange;

public abstract class RESTServiceException extends Exception {

    protected HttpExchange httpExchange;

    public RESTServiceException(HttpExchange httpExchange) {
        this.httpExchange = httpExchange;
    }

    public HttpExchange getHttpExchange() {
        return httpExchange;
    }

    abstract public void sendError();
}
