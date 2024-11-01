package ubb.scs.map.functionalinterface;

class FormulaHelper{
    private double a;
    private double b;
    public FormulaHelper(double a, double b) { this.a = a;this.b = b; }


    public double distanta(double x, double y){
        return Math.sqrt(Math.pow(x-a,2) +Math.pow(y-b,2));
    }


    public static double modul(double v, double v1) {
        return Math.sqrt(v*v + v1*v1);
    }
}
