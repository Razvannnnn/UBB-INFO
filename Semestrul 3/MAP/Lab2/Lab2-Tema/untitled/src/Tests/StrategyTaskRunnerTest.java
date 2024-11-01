package Tests;

import Enum.ContainerStrategy;
import Runners.StrategyTaskRunner;
import Runners.TaskRunner;
import domain.MessageTask;

public class StrategyTaskRunnerTest {

    public static void strategyTaskRunnerTest(ContainerStrategy strategy, MessageTask[] messageTasks) {
        TaskRunner taskRunner = new StrategyTaskRunner(strategy);
        taskRunner.addTask(messageTasks[0]);
        taskRunner.addTask(messageTasks[1]);
        taskRunner.addTask(messageTasks[2]);
        taskRunner.executeAll();
    }

}
