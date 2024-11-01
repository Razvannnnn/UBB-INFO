import java.util.Comparator;
import java.util.Objects;

public class Student implements Comparable<Student> {

    String nume;
    float medie;

    public Student(String nume, float medie) {
        this.nume = nume;
        this.medie = medie;
    }

    public float getMedie() {
        return medie;
    }

    public String getNume() {
        return nume;
    }

    @Override
    public String toString() {
        return "Student{" +
                "nume='" + nume + '\'' +
                ", medie=" + medie +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return Float.compare(medie, student.medie) == 0 && Objects.equals(nume, student.nume);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nume, medie);
    }

    @Override
    public int compareTo(Student o) {
        return nume.compareTo(o.nume);
    }
}
