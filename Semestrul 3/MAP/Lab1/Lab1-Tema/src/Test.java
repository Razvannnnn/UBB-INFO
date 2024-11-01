import domain.NumarComplex;
import domain.Operation;
import operatii.Adunare;
import operatii.Impartire;
import operatii.Inmultire;
import operatii.Scadere;

public class Test {
    private static void testNumarComplex() {
        NumarComplex n1 = new NumarComplex(1, 2);
        NumarComplex n2 = new NumarComplex(3.9, -4.1);
        assert n1.getIm() == 2;
        assert n1.getRe() == 1;

        assert n2.getIm() == -4.1;
        assert n2.getRe() == 3.9;

        NumarComplex adaugare = n1.adunare(n2);
        assert adaugare.getRe() == 4.9;
        assert adaugare.getIm() == -2.1;

        NumarComplex stergere = n1.scadere(n2);
        assert stergere.getRe() == 3.9;
        assert stergere.getIm() == -4.1;

        NumarComplex n3 = new NumarComplex(4, 8);
        NumarComplex n4 = new NumarComplex(2, 2);

        NumarComplex impartire = n3.impartire(n4);
        assert impartire.getIm() == 4;
        assert impartire.getRe() == 2;

        NumarComplex inmultire = n1.inmultire(n4);
        assert inmultire.getRe() == 2;
        assert inmultire.getIm() == 4;
    }

    private static void testComplexExpression() {
        NumarComplex n1 = new NumarComplex(1, 2);
        NumarComplex n2 = new NumarComplex(3.9, -4.1);
        NumarComplex n3 = new NumarComplex(4, 8);
        NumarComplex n4 = new NumarComplex(2, 2);

        NumarComplex[] numbers = {n1, n2, n3, n4};

        Adunare adunare = new Adunare(Operation.ADDITION, numbers);
        NumarComplex result = adunare.execute();
        assert result.getRe() == 11.9;
        assert result.getIm() == 3.9;

        Scadere scadere = new Scadere(Operation.SUBSTRACTION, numbers);
        result = scadere.execute();
        assert result.getRe() == -8.9;
        assert result.getIm() == 12.1;

        Inmultire inmultire = new Inmultire(Operation.MULTIPLICATION, numbers);
        result = inmultire.execute();
        assert result.getRe() == 0;
        assert result.getIm() == 0;

        Impartire impartire = new Impartire(Operation.DIVISION, numbers);
        result = impartire.execute();
        assert result.getRe() == 0.5;
        assert result.getIm() == 0;
    }


    public static void run() {
        testNumarComplex();
        testComplexExpression();
        System.out.println("Teste rulate cu succes!");
    }
}
