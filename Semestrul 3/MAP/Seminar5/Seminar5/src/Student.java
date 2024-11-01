public class Student extends Entity<Long>{
    private String name;
    private int group;

    Student(String name, int group) {
        this.name = name;
        this.group = group;
    }

    public String getName() {
        return name;
    }

    public int getGroup() {
        return group;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setGroup(int group) {
        this.group = group;
    }

    public Student setId(Long id) {
        super.setId(id);
        return this;
    }
}
