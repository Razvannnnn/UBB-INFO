import java.util.*;
import java.util.function.Supplier;
import java.util.stream.Collectors;

public class MyMap extends TreeMap<Integer, List<Student>> {

    public MyMap() {

    }

    public void addStudent(Student student) {
        int grade = Math.round(student.getMedie());
        List<Student> list = super.get(grade);
        if(list == null) {
            list = new ArrayList<>();
            super.put(grade, list);
        }
        list.add(student);
    }

    /*
    public Set<Map.Entry<Integer, List<Student>>> getEntries() {
        Comparator<Map.Entry<Integer, List<Student>>> byKeyDesc = (e1, e2) -> e2.getKey().compareTo(e1.getKey());
        Supplier<TreeSet<Map.Entry<Integer, List<Student>>>> sortedSet = () -> new TreeSet<>(byKeyDesc);
        return super.entrySet().stream().collect(Collectors.toCollection(sortedSet));
    }
     */

    public Set<Map.Entry<Integer, List<Student>>> getEntries() {
        return super.entrySet();
    }


}
