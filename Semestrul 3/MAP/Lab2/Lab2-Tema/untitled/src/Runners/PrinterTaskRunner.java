package Runners;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class PrinterTaskRunner extends AbstractTaskRunner {

    public PrinterTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }

    @Override
    public void executeOneTask() {
        super.executeOneTask();
        System.out.println("Task executat la ora: " + LocalDateTime.now().format(DateTimeFormatter.ofPattern("HH:mm")));
    }
}
