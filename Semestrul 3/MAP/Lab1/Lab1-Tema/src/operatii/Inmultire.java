package operatii;

import domain.NumarComplex;
import domain.Operation;

public class Inmultire extends ComplexExpression {
    public Inmultire(Operation operation, NumarComplex[] args) {
        super(operation, args);
    }

    @Override
    public NumarComplex executeOperation(NumarComplex a, NumarComplex b) {
        return a.inmultire(b);
    }
}
