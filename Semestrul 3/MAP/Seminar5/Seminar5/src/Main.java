import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        List<Student> students = new ArrayList<>();
        students.add(new Student("Ana", 225).setId(1L));
        students.add(new Student("Maria", 221).setId(2L));
        students.add(new Student("Ion", 224).setId(3L));


        List<Tema> teme = new ArrayList<>();

        teme.add(new Tema("Tema1", 5, 3).setId(1L));
        teme.add(new Tema("Tema2", 6, 4).setId(2L));
        teme.add(new Tema("Tema3", 7, 5).setId(3L));

        List<Nota> note = new ArrayList<>();



    }
}