package Runners;

import domain.MessageTask;

import java.time.LocalDateTime;

public class MessageTaskTest {
    public static MessageTask[] generateTasks() {
        MessageTask t1 = new MessageTask("1", "Da", "Salut", "Ion", "Mircea", LocalDateTime.of(2019,10,11,23,44));
        MessageTask t2 = new MessageTask("2", "Yes", "Ce tare", "Mihai", "Ion", LocalDateTime.of(2019,10,11,23,44));
        MessageTask t3 = new MessageTask("3", "No", "Ce faci?", "Ema", "Miruna", LocalDateTime.of(2019,10,11,23,44));
        MessageTask t4 = new MessageTask("4", "Ok", "Ce mai faci?", "Ion", "Mircea", LocalDateTime.of(2019,10,11,23,44));
        MessageTask t5 = new MessageTask("5", "Da", "Salut", "Giovanni", "Mirel", LocalDateTime.of(2019,10,11,23,44));

        return new MessageTask[]{t1, t2, t3, t4, t5};
    }

    public static void messageTaskTest() {
        MessageTask[] tasks = generateTasks();
        for (MessageTask task : tasks) {
            System.out.println(task);
        }
    }
}
