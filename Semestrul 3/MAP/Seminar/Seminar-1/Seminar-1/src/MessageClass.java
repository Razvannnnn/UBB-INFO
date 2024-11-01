import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MessageClass extends Task {
    private String message;
    private String from;
    private String to;
    private LocalDateTime data;

    private static DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");

    public MessageClass(String id, String description, String message, String from, String to, LocalDateTime data) {
        super(id, description);
        this.message = message;
        this.from = from;
        this.to = to;
        this.data = data;
    }

    @Override
    public void execute() {
        System.out.println(data.format(formatter) + ": " + message);
    }

    @Override
    public String toString() {
        return  "id=" + getId() +"|descrption=" + getDescription() + "  lab1|" +
                "message='" + message + "|from=" + from + "|to" + to +
                "|data=" + data.format(formatter);
    }
}
