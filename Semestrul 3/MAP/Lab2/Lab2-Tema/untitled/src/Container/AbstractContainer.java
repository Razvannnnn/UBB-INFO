package Container;

import domain.Task;

public abstract class AbstractContainer implements Container{
    protected Task[] tasks;
    protected int size;

    public void add(Task task) {
        if(tasks.length == size) {
            Task[] t = new Task[size*2];
            System.arraycopy(tasks,0,t, 0, size);
            tasks = t;
        }
        tasks[size] = task;
        size++;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
