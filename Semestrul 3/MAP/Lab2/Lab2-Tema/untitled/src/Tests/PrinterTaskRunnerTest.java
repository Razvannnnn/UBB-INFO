package Tests;
import Enum.ContainerStrategy;
import Runners.PrinterTaskRunner;
import Runners.StrategyTaskRunner;
import domain.MessageTask;

public class PrinterTaskRunnerTest {

    public static void printerTaskRunnerTest(ContainerStrategy strategy, MessageTask[] tasks) {
        StrategyTaskRunner taskRunner = new StrategyTaskRunner(strategy);
        PrinterTaskRunner printerTaskRunner = new PrinterTaskRunner(taskRunner);
        printerTaskRunner.addTask(tasks[0]);
        printerTaskRunner.addTask(tasks[1]);
        printerTaskRunner.addTask(tasks[2]);
        while (printerTaskRunner.hasTask()) {
            printerTaskRunner.executeOneTask();
        }
    }

}
