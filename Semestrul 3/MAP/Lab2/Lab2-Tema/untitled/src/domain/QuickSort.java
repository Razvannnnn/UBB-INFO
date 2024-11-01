package domain;

public class QuickSort extends AbstractSorter{
    @Override
    public void sort(int[] numbers) {
        quickSort(numbers, 0, numbers.length - 1);
    }

    private void quickSort(int[] numbers, int i, int i1) {
        if (i < i1) {
            int pi = partition(numbers, i, i1);
            quickSort(numbers, i, pi - 1);
            quickSort(numbers, pi + 1, i1);
        }
    }

    private int partition(int[] numbers, int i, int i1) {
        int pivot = numbers[i1];
        int i2 = i - 1;
        for (int j = i; j < i1; j++) {
            if (numbers[j] < pivot) {
                i2++;
                int temp = numbers[i2];
                numbers[i2] = numbers[j];
                numbers[j] = temp;
            }
        }
        int temp = numbers[i2 + 1];
        numbers[i2 + 1] = numbers[i1];
        numbers[i1] = temp;
        return i2 + 1;
    }
}
