package Runners;

import Container.Container;
import Factory.TaskContainerFactory;
import domain.Task;
import Enum.ContainerStrategy;

public class StrategyTaskRunner implements TaskRunner{

    private Container container;
    private ContainerStrategy strategy;

    public StrategyTaskRunner(ContainerStrategy strategy) {
        this.strategy = strategy;
        this.container = TaskContainerFactory.getInstance().createContainer(strategy);
    }

    @Override
    public void executeOneTask() {
        container.remove().execute();
    }

    @Override
    public void executeAll() {
        while (hasTask()) {
            executeOneTask();
        }
    }

    @Override
    public void addTask(Task t) {
        container.add(t);
    }

    @Override
    public boolean hasTask() {
        return !container.isEmpty();
    }
}
