import Runners.MessageTaskTest;
import Runners.StrategyTaskRunner;
import Tests.DelayTaskRunnerTest;
import Tests.PrinterTaskRunnerTest;
import Tests.StrategyTaskRunnerTest;
import Tests.SortingTaskTest;
import Enum.ContainerStrategy;
import domain.MessageTask;
import Enum.SortStrategy;


public class Main {
    public static void main(String[] args) {
        String cmd = "";
        if(args.length > 0) {
            cmd = args[0];
        }

        System.out.println("\nSortingTaskTest - TEST - BubbleSort");
        SortingTaskTest.SortingTaskTest(new int[]{1, 5, 3, 2, 4}, SortStrategy.BUBBLESORT);

        System.out.println("\nSortingTaskTest - TEST - QuickSort");
        SortingTaskTest.SortingTaskTest(new int[]{1, 5, 3, 2, 4}, SortStrategy.QUICKSORT);

        System.out.println("\nMessageTaskTest - TEST");
        MessageTaskTest.messageTaskTest();

        if(cmd.equalsIgnoreCase("LIFO")) {
            System.out.println("\nStrategyTaskRunner - TEST - LIFO");
            StrategyTaskRunnerTest.strategyTaskRunnerTest(ContainerStrategy.LIFO, MessageTaskTest.generateTasks());

            System.out.println("\nPrinterTaskRunner - TEST - LIFO");
            PrinterTaskRunnerTest.printerTaskRunnerTest(ContainerStrategy.LIFO, MessageTaskTest.generateTasks());

            System.out.println("\nDelayTaskRunner - TEST - LIFO");
            DelayTaskRunnerTest.delayTaskRunnerTest(ContainerStrategy.LIFO, MessageTaskTest.generateTasks());

        } else if(cmd.equalsIgnoreCase("FIFO")) {
            System.out.println("\nStrategyTaskRunner - TEST - FIFO");
            StrategyTaskRunnerTest.strategyTaskRunnerTest(ContainerStrategy.FIFO, MessageTaskTest.generateTasks());

            System.out.println("\nPrinterTaskRunner - TEST - FIFO");
            PrinterTaskRunnerTest.printerTaskRunnerTest(ContainerStrategy.FIFO, MessageTaskTest.generateTasks());

            System.out.println("\nDelayTaskRunner - TEST - FIFO");
            DelayTaskRunnerTest.delayTaskRunnerTest(ContainerStrategy.FIFO, MessageTaskTest.generateTasks());
        }
    }
}