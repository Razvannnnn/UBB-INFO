package Tests;

import domain.SortingTask;
import Enum.SortStrategy;

public class SortingTaskTest {
    public static void SortingTaskTest(int[] numbers, SortStrategy sortStrategy) {
        SortingTask sortingTask = new SortingTask("1","Sort", numbers, sortStrategy);
        sortingTask.execute();
    }
}
