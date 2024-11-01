package domain;

public class NumarComplex {

    double re;
    double im;

    public NumarComplex(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public double getIm() {
        return im;
    }

    public double getRe() {
        return re;
    }

    public NumarComplex adunare(NumarComplex numarComplex) {
        double re = this.re + numarComplex.re;
        double im = this.im + numarComplex.im;
        return new NumarComplex(re, im);
    }

    public NumarComplex scadere(NumarComplex numarComplex) {
        double re = this.re - numarComplex.re;
        double im = this.im - numarComplex.im;
        return new NumarComplex(re, im);
    }

    public NumarComplex inmultire(NumarComplex numarComplex) {
        double re = this.re * numarComplex.re - this.im * numarComplex.im;
        double im = this.re * numarComplex.im + this.im * numarComplex.re;
        return new NumarComplex(re, im);
    }

    public NumarComplex impartire(NumarComplex numarComplex) {
        double numitor = numarComplex.re * numarComplex.re + numarComplex.im * numarComplex.im;
        double re = (this.re * numarComplex.re + this.im * numarComplex.im) / numitor;
        double im = (this.im * numarComplex.re - this.re * numarComplex.im) / numitor;
        return new NumarComplex(re, im);
    }

    @Override
    public String toString() {
        return re + " + " + im + "*i";
    }

}
