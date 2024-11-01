import java.util.List;

public class TestFunctionalInterface {

    static <E> void printArie(List<E> lista, Arie<E> f) {
        lista.forEach(x -> System.out.println(f.compute(x)));
    }
}
