package operatii;

import domain.NumarComplex;
import domain.Operation;

public class Adunare extends ComplexExpression {
    public Adunare(Operation operation, NumarComplex[] args) {
        super(operation, args);
    }

    @Override
    public NumarComplex executeOperation(NumarComplex a, NumarComplex b) {
        return a.adunare(b);
    }
}
