import java.time.LocalDateTime;

public class Main {
    public static void main(String[] args) {
        MessageClass[] tasks = new MessageClass[5];
        tasks[0] = new MessageClass("12", "yeye", "sda", "aici", "acolo", LocalDateTime.now());
        tasks[1] = new MessageClass("122", "YAYA", "mda", "aici", "acolo", LocalDateTime.now());
        tasks[2] = new MessageClass("412", "yeyeye", "lda", "aici", "acolo", LocalDateTime.now());
        tasks[3] = new MessageClass("43", "yeye", "cda", "aici", "acolo", LocalDateTime.now());
        tasks[4] = new MessageClass("543", "yers", "sda", "aici", "acolo", LocalDateTime.now());

        for(MessageClass task: tasks) {
            System.out.println(task);
        }

        StrategyTaskRunner strategyTaskRunner = new StrategyTaskRunner(Strategy.valueOf(args[0]));

        for (MessageClass task: tasks) {
            strategyTaskRunner.addTask(task);
        }

        //strategyTaskRunner.executeAll();

        PrinterTaskRunner printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
        //printerTaskRunner.executeAll();

        DelayTaskRunner delayTaskRunner = new DelayTaskRunner(new DelayTaskRunner(printerTaskRunner));
        delayTaskRunner.executeAll();
    }
}