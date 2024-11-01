import java.time.format.DateTimeFormatter;

public class DelayTaskRunner extends AbstractTaskRunner {

    public DelayTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }

    private static final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm");

    @Override
    public void executeOneTask() {
        super.executeOneTask();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        super.executeOneTask();
    }
}
