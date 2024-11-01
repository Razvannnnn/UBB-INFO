package factory;

import domain.NumarComplex;
import domain.Operation;
import operatii.ComplexExpression;
import operatii.*;

public class FactoryExpression {
    private static FactoryExpression instance = new FactoryExpression();

    private FactoryExpression() {}

    public static FactoryExpression getInstance() {
        return instance;
    }

    public ComplexExpression createExpression(Operation operation, NumarComplex[] numere) {
        switch (operation) {
            case Operation.ADDITION:
                return new Adunare(operation, numere);
            case Operation.SUBSTRACTION:
                return new Scadere(operation, numere);
            case Operation.MULTIPLICATION:
                return new Inmultire(operation, numere);
            case Operation.DIVISION:
                return new Impartire(operation, numere);
            default:
                return null;
        }
    }

}
