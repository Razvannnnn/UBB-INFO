package Tests;
import Enum.ContainerStrategy;

public class DelayTaskRunnerTest {
    public static void delayTaskRunnerTest(ContainerStrategy strategy, domain.MessageTask[] tasks) {
        Runners.StrategyTaskRunner taskRunner = new Runners.StrategyTaskRunner(strategy);
        Runners.DelayTaskRunner delayTaskRunner = new Runners.DelayTaskRunner(taskRunner);
        delayTaskRunner.addTask(tasks[0]);
        delayTaskRunner.addTask(tasks[1]);
        delayTaskRunner.addTask(tasks[2]);
        while (delayTaskRunner.hasTask()) {
            delayTaskRunner.executeOneTask();
        }
    }
}
