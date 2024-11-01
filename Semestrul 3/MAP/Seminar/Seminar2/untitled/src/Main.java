import java.util.*;

public class Main {

    public static List<Student> getList() {
        List<Student> students = new ArrayList<>();
        students.add(new Student("1", 9.7f));
        students.add(new Student("2", 3.7f));
        students.add(new Student("3", 5.7f));
        students.add(new Student("4", 2.3f));
        students.add(new Student("5", 7.5f));
        students.add(new Student("6", 3.5f));

        return students;
    }


    public static void main(String[] args) {
        Student s1 = new Student("Dan", 4.5f);
        Student s2 = new Student("Ana", 8.5f);
        Student s3 = new Student("Dan", 4.5f);

        Set<Student> students = new HashSet<>();
        students.add(s1);
        students.add(s2);
        students.add(s3);
        System.out.println("---------------1.----------------");

        for(Student s : students) {
            System.out.println(s);
        }

        System.out.println("---------------2.----------------");

        Set<Student> students1 = new TreeSet<>();
        students1.add(s1);
        students1.add(s2);
        students1.add(s3);

        for(Student s : students1) {
            System.out.println(s);
        }

        System.out.println("---------------3.----------------");

        Set<Student> students2 = new TreeSet<>(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o2.getNume().compareTo(o1.getNume());
            }
        });
        students2.add(s1);
        students2.add(s2);
        students2.add(s3);

        for(Student s : students2) {
            System.out.println(s);
        }

        System.out.println("---------------4.----------------");

        Map<String, Student> studentMap = new TreeMap<>();  // HashMap<>();
        studentMap.put(s1.getNume(), s1);
        studentMap.put(s2.getNume(), s2);
        studentMap.put(s3.getNume(), s3);

        for(Map.Entry<String, Student> s : studentMap.entrySet()) {
            System.out.println(s.getKey() + " " + s.getValue().getMedie());
        }

        System.out.println("---------------5.----------------");

        MyMap myMap = new MyMap();
        List<Student> studentsList = getList();
        for (Student s : studentsList) {
            myMap.addStudent(s);
        }
        for (Map.Entry<Integer, List<Student>> entry : myMap.getEntries()) {
            System.out.println("Medie=" + entry.getKey());
            List<Student> lista = entry.getValue();
            Collections.sort(lista);
            System.out.println("Studenti:");
            for (Student s : entry.getValue()) {
                System.out.println(s.getNume());
            }
        }

        System.out.println("---------------6.----------------");

        MyMapCompostion map = new MyMapCompostion();
        List<Student> studentsList1 = getList();
        for (Student s : studentsList1) {
             map.addStudent(s);
        }
        for (Map.Entry<Integer, List<Student>> entry : map.getEntries()) {
            System.out.println("Medie=" + entry.getKey());
            List<Student> lista = entry.getValue();
            Collections.sort(lista);
            System.out.println("Studenti:");
            for (Student s : entry.getValue()) {
                System.out.println(s.getNume());
            }
        }
    }
}