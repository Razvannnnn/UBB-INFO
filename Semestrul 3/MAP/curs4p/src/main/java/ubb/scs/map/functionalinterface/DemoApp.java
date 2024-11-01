package ubb.scs.map.functionalinterface;

import ubb.scs.map.domain.Utilizator;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Predicate;

public class DemoApp {
    public static void main(String[] args) {

        // method reference
        AritmeticExpression ex1 = FormulaHelper::modul;

        double distOrig= ex1.calculate(2,2);
        System.out.println(distOrig);

        FormulaHelper h = new FormulaHelper(1, 1);
        AritmeticExpression ex2 = h::distanta;
        double distOrg2 = ex2.calculate(3,3);
        System.out.println(distOrg2);


        // lambda function

        AritmeticExpression ex3 = (double x, double y)->{
            return x + y;
        };
        AritmeticExpression ex4 = (x, y)-> x * x + y * y;
        double rez1 = ex3.calculate(3, 5);
        double rez2 = ex3.calculate(10,3);
        System.out.println(rez1);
        System.out.println(rez2);

        // [captare](parametrii){}

        List<String> list1= new ArrayList(Arrays.asList("ane", "are","o","atitudine","impozanta"));
        list1.removeIf(x->x.startsWith("a"));
        list1.forEach(System.out::println);




//        list1.forEach(System.out::println);

    }
}
