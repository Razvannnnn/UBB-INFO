import domain.NumarComplex;
import operatii.ComplexExpression;
import parser.ExpressionParser;

public class Main {
    public static void main(String[] args) {
        Test.run();
        try {
            ExpressionParser parser = new ExpressionParser(args);
            ComplexExpression expression = parser.parse();
            NumarComplex result = expression.execute();
            System.out.println(result);
            // System.out.println(ExpressionParser.createExpression(args).execute().toString());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}