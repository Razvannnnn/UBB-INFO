package operatii;

import domain.NumarComplex;
import domain.Operation;

import java.util.Arrays;
import java.util.Vector;

public abstract class ComplexExpression {
    private Operation operation;
    protected NumarComplex[] args;

    public ComplexExpression(Operation op, NumarComplex[] numere) {
        this.operation = op;
        this.args = numere;
    }

    public abstract NumarComplex executeOperation(NumarComplex a, NumarComplex b);

    public NumarComplex execute() {
        NumarComplex result = args[0];
        for(int i=1;i<args.length;i++) {
            result = executeOperation(result, args[i]);
        }
        return result;
    }

    @Override
    public String toString() {
        return "ComplexExpression{" +
                "operation=" + operation +
                ", args=" + args +
                '}';
    }
}
