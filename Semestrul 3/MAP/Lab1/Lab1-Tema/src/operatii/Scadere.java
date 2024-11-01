package operatii;

import domain.NumarComplex;
import domain.Operation;

public class Scadere extends ComplexExpression {
    public Scadere(Operation operation, NumarComplex[] numere) {
        super(operation, numere);
    }

    @Override
    public NumarComplex executeOperation(NumarComplex a, NumarComplex b) {
        return a.scadere(b);
    }
}
