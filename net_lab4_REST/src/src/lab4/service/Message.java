package lab4.service;

public class Message {

    private int messageID;
    private String message;
    private int authorID;

    public Message(int messageID, String message, int authorID) {
        this.messageID = messageID;
        this.message = message;
        this.authorID = authorID;
    }

    public int getMessageID() {
        return messageID;
    }

    public String getMessage() {
        return message;
    }

    public int getAuthorID() {
        return authorID;
    }
}
