#include <stdio.h>

int prim(int x)
{
    /*
     * Functie ce verifica daca un numar x este prim
     * preconditii: x numar de tip int
     * postconditii: 1 daca x este prim
     *               0 daca x nu este prim
     */
    if(x<=1) return 0;
    if(x==2) return 1;
    if(x%2==0) return 0;
    for(int i=3;i<x;i=i+2)
    {
        if(x%i==0) return 0;
    }
    return 1;
}

void descompunere(int n)
{
    /*
     * Functie ce descompune un numar n in factorii sai primi
     * preconditii: n un numar natural nenul
     * postconditii: se afiseaza divizorii primi si puterea la care sunt
     */
    int p, d=2;
    while(n!=1)
    {
        p=0;
        while(n%d==0 && prim(d)==1)
        {
            n=n/d;
            p++;
        }
        if(p>0) printf("Factor: %d Puterea: %d \n", d, p);
        d++;
    }
    printf("\n\n");
}

void sir(int n){
    /*
     * Functie ce afiseaza primii n termeni din sirul 1, 2,1, 3,2,1, 4,2,2, 5,4,3,2,1, 6,2,2,3,3,3, 7,6, ...
     * preconditii: n un numar natural
     * postconditii: se vor afisa primii n termeni ai sirului
     */
    int x = 0;
    for (int i = 1; i <= n; i++) {
        ++x;
        printf("%d ", x);
        if (prim(x) == 1) {
            int j = x - 1;
            while (i <= n && j > 0) {
                i++;
                printf("%d ", j);
                j--;
            }
        }
        if (prim(x) == 0) {
            for (int j = 2; j <= x / 2; j++) {
                if (x % j == 0) {
                    int k = j;
                    while (i <= n && k != 0) {
                        i++;
                        printf("%d ", j);
                        k--;
                    }
                }
            }
        }
    }
}

int main() {
    char optiune;
    int n;
    do{
        printf("*MENU*\n");
        printf("1. Tipareste un numar precizat de termeni din sirul\n"
               "   1, 2,1, 3,2,1, 4,2,2, 5,4,3,2,1, 6,2,2,3,3,3, 7,6, ...\n");
        printf("2. Descompune in factori primi un numar natural nenul dat.\n");
        printf("0. Inchiderea aplicatiei\n");
        printf("Introdu optiunea dorita: ");
        scanf(" %c", & optiune);
        printf("\n");
        switch(optiune) {
            case '1':
                printf("Numarul de termeni:");
                scanf("%d", &n);
                sir(n);
                printf("\n\n");
                break;
            case '2':
                printf("Numar natural nenul:");
                scanf("%d", &n);
                descompunere(n);
                break;
            case '0':
                break;
            default:
                printf("**Optiune invalida\n\n");
        }
    } while (optiune!='0');
    return 0;
}


//Problema 13