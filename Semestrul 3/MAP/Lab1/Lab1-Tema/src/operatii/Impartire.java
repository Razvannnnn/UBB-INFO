package operatii;

import domain.NumarComplex;
import domain.Operation;

public class Impartire extends ComplexExpression {
    public Impartire(Operation operation, NumarComplex[] args) {
        super(operation, args);
    }

    @Override
    public NumarComplex executeOperation(NumarComplex a, NumarComplex b) {
        return a.impartire(b);
    }
}
