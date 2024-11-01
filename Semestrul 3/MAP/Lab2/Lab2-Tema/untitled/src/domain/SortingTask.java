package domain;
import Enum.SortStrategy;

import java.util.Arrays;

public class SortingTask extends Task{

    private int[] numbers;
    private final SortStrategy sortStrategy;
    private AbstractSorter abstractSorter;


    public SortingTask(String taskID, String descriere, int[] numbers, SortStrategy sortStrategy) {
        super(taskID, descriere);
        this.numbers = numbers;
        this.sortStrategy = sortStrategy;

        switch (sortStrategy) {
            case BUBBLESORT -> abstractSorter = new BubbleSort();
            case QUICKSORT -> abstractSorter = new QuickSort();
            default -> {

            }
        }
    }

    @Override
    public void execute() {
        abstractSorter.sort(numbers);
        System.out.println(Arrays.toString(numbers) + "\n");
    }
}
