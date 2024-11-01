import java.time.Instant;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;
import java.util.stream.Collectors;

public class Main {

    static <E> void printWithCondition(Predicate<E> pred, List<E> list) {
        for(E el: list) {
            if(pred.test(el)) {
                System.out.println(el);
            }
        }
    }

    public static <E> List<E> filterGeneric(List<E> list, Predicate<E> predicate) {
        return list.stream().filter(predicate).collect(Collectors.toList());
    }

    public static <E> List<E> filterGeneric2(List<E> list, Predicate<E> predicate, Comparator<E> comparator) {
        return list.stream().filter(predicate).collect(Collectors.toList());
    }


    public static void main(String[] args) {
        List<Circle> listaTest = new ArrayList<>();
        listaTest.add(new Circle(3));
        listaTest.add(new Circle(5));
        listaTest.add(new Circle(2));
        /*
        Arie<Circle> arieCircle = new Arie<Circle>() {
            @Override
            public double compute(Circle element) {
                return element.getRadius()*element.getRadius()*Math.PI;
            }
        };
        */
        /*    1.
        Arie<Circle> arieCircle = x -> x.getRadius()*x.getRadius()*Math.PI;
        TestFunctionalInterface.printArie(listaTest,arieCircle);
         */

        /*    2.
        Predicate<Circle> hasRadiusLessThan4 = x -> x.getRadius() < 4;
        Predicate<Circle> radiusIsEven = x -> x.getRadius() % 2 == 0;
        Predicate<Circle> lessThan4AndEven = hasRadiusLessThan4.and(radiusIsEven);
        printWithCondition(hasRadiusLessThan4, listaTest);  // .negate()
        printWithCondition(radiusIsEven, listaTest);
        printWithCondition(lessThan4AndEven, listaTest);
         */

        /*     3.
        Function<String, Integer> converterLambda = Integer::valueOf;
        Function<String, Integer> converterMethodReference = Integer::valueOf;
         */

        /*     4.
        Supplier<LocalDate> localDateSupplier = () -> LocalDate.now();
        Supplier<LocalDate> localDateSupplier2 = LocalDate::now;
        System.out.println(localDateSupplier2.get());
         */


        /*     5.
        List<Integer> list = Arrays.asList(1,4,2,5,7,5);
        List<Integer> list1 = List.of(1,2,3,43,4,5,6);
        Comparator<Integer> asscendingComparator = (x,y) -> Integer.compare(x,y);
        Comparator<Integer> descendingComparator = (x,y) -> Integer.compare(y,x);

        asscendingComparator.compare(1,2);
        System.out.println(list);
        list.sort(asscendingComparator);
        System.out.println(list);
        list.sort(descendingComparator.reversed());
        System.out.println(list);
        */

        List<Integer> lista = Arrays.asList(1,2,3,2,6,4,2,5,7,8,9,10);
        Predicate<Integer> predCheckEven = x -> x % 2 == 0;
        List<Integer> evenNumbers = filterGeneric(lista, predCheckEven);
        System.out.println(lista);
        System.out.println(evenNumbers);
    }
}