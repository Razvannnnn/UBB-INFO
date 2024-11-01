package domain;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MessageTask extends Task{
    private String mesaj;
    private String from;
    private String to;
    private LocalDateTime date;
    public static final DateTimeFormatter format = DateTimeFormatter.ofPattern("dd-MM-yy hh:mm");



    public MessageTask(String taskID, String descriere, String mesaj, String from, String to, LocalDateTime date) {
        super(taskID, descriere);
        this.mesaj = mesaj;
        this.from = from;
        this.to = to;
        this.date = date;
    }

    @Override
    public String toString() {
        return "MessageTask{" +
                "mesaj='" + mesaj + '\'' +
                ", from='" + from + '\'' +
                ", to='" + to + '\'' +
                ", date=" + date +
                '}';
    }

    @Override
    public void execute() {
        System.out.println("id=" + this.getTaskID() + "|description=" + this.getDescriere() +
                "|message='" + mesaj + '\'' +
                "|from='" + from + '\'' +
                "|to='" + to + '\'' +
                "|date=" + date.format(format));
    }
}
