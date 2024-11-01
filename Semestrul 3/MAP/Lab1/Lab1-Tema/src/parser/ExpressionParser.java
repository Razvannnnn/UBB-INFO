package parser;

import domain.NumarComplex;
import domain.Operation;
import factory.FactoryExpression;
import operatii.ComplexExpression;

import java.util.Objects;

public class ExpressionParser {

    private final String[] args;

    public ExpressionParser(String[] args) {
        this.args = args;
    }

    public ComplexExpression parse() {
        String op = args[1];
        NumarComplex[] argss = new NumarComplex[(args.length + 1) / 2];
        for (int i = 0; i < args.length; i++) { // pe pozitii pare sunt nr complexe, impare operanzii
            if (i % 2 == 0) { // nr complex
                String[] el = args[i].split("(?=[+-])", 2);
                double re = Double.parseDouble(el[0]);
                String[] IM = el[1].split("[*]", 2);
                double im;
                if(IM.length == 1) {
                    if(IM[0].contains("-")) {
                        im = -1;
                    } else {
                        im = 1;
                    }
                } else {
                    im = Double.parseDouble(IM[0]);
                }
                NumarComplex nr = new NumarComplex(re, im);
                argss[i / 2] = nr;
            } else {
                op = args[i];
                if (!Objects.equals(op, "+") && !Objects.equals(op, "-") && !Objects.equals(op, "*") && !Objects.equals(op, "/")) {
                    return null;
                }
            }
        }

        return switch (op) {
            case "+" -> FactoryExpression.getInstance().createExpression(Operation.ADDITION, argss);
            case "-" -> FactoryExpression.getInstance().createExpression(Operation.SUBSTRACTION, argss);
            case "*" -> FactoryExpression.getInstance().createExpression(Operation.MULTIPLICATION, argss);
            case "/" -> FactoryExpression.getInstance().createExpression(Operation.DIVISION, argss);
            default -> null;
        };
    }

}
