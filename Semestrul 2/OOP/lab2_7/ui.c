#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "repo.h"
#include "service.h"
#include "cheltuieli.h"
#include "service.h"
#include "valid.h"
#include "ui.h"

void Afisare(Lista lista_cheltuieli) {
    /*
     * Functie ce afiseaza toate cheltuielile dintr o lista de cheltuieli
     * preconditii: lista_cheltuieli - de tip Lista
     * postconditii: -
     */
    for(int i=0;i<lista_cheltuieli.len;i++)
    {
        printf("%d %d %s\n", lista_cheltuieli.array[i].nr, lista_cheltuieli.array[i].suma, lista_cheltuieli.array[i].tip);
    }
}

cheltuiala citire_cheltuiala() {
    cheltuiala c = createCheltuiala();
    printf("NR apartament:");
    scanf("%d", &c.nr);
    printf("Suma:");
    scanf("%d", &c.suma);
    printf("Tip:");
    scanf("%s", c.tip);

    return c;
}

void consola(Lista* lista_cheltuieli) {
    while (1)
    {
        printf("1. Adaugare cheltuiala in lista\n");
        printf("2. Stergere cheltuiala din lista\n");
        printf("3. Modificare cheltuiala din lista\n");
        printf("4. Filtrare dupa o proprietate (nr, suma, tip)\n");
        printf("5. Ordonare dupa suma sau tip (crescator/descrescator)\n");
        printf("6. Lista cheltuieli\n");
        printf("0. Inchidere aplicatie\n");

        int comanda = 0, nr, propr, proprietate, mod;
        cheltuiala c;
        printf("\nScrieti comanda:");
        scanf("%d", &comanda);

        switch(comanda) {
            case 0:
                destroyLista(lista_cheltuieli);
                return;
            case 1:
                c = citire_cheltuiala();
                if(srv_adaugare(lista_cheltuieli, c) == 1) printf("Cheltuiala a fost adaugata!\n");
                else printf("Cheltuiala invalida!\n");
                break;
            case 2:
                printf("NR apartament:");
                scanf("%d", &nr);
                srv_stergere(lista_cheltuieli, nr);
                break;
            case 3:
                c = citire_cheltuiala();
                if(srv_modificare(lista_cheltuieli, c) == 1) printf("Cheltuiala a fost adaugata!\n");
                else printf("Cheltuiala invalida!\n");
                break;
            case 4:
                printf("Alege proprietatea:\n");
                printf("1. NR APT\n");
                printf("2. SUMA\n");
                printf("3. TIP\n");
                scanf("%d", &propr);
                if(propr == 1) {
                    int nrfilt;
                    printf("NR APT.=");
                    scanf("%d", &nrfilt);
                    if(nrfilt < 1) printf("NR APT. Invalid!\n");
                    else {
                        Lista new_list = filtrare_propr_nr(lista_cheltuieli, nrfilt);
                        Afisare(new_list);
                        destroyLista(&new_list);
                    }
                }
                else if(propr == 2) {
                    int sumafilt;
                    printf("SUMA=");
                    scanf("%d", &sumafilt);
                    if(sumafilt < 0) printf("SUMA Invalida!\n");
                    else {
                        Lista new_list = filtrare_propr_suma(lista_cheltuieli, sumafilt);
                        Afisare(new_list);
                        destroyLista(&new_list);
                    }
                }
                else if(propr == 3) {
                    char tipfilt[51];
                    printf("TIP=");
                    scanf("%s", tipfilt);
                    if(strcmp(tipfilt, "apa") != 0 && strcmp(tipfilt, "canal") !=0 && strcmp(tipfilt, "incalzire") != 0 && strcmp(tipfilt, "gaz") != 0) printf("TIP Invalid!\n");
                    else {
                        Lista new_list = filtrare_propr_tip(lista_cheltuieli, tipfilt);
                        Afisare(new_list);
                        destroyLista(&new_list);
                    }
                }
                else {
                    printf("Optiune invalida!\n");
                }
                break;
            case 5:
                printf("Sortare dupa suma(1) sau tip(2):");
                scanf("%d", &proprietate);
                if(proprietate == 1) {
                    printf("Sortare crescatoare(1) sau descrescatoare(2):");
                    scanf("%d", &mod);
                    if(mod == 1) Afisare(sortare2(*lista_cheltuieli, sort_cresc));
                    else if(mod == 2) Afisare(sortare2(*lista_cheltuieli, sort_descresc));
                    else printf("Mod de sortare invalid!\n");
                }
                else if(proprietate == 2) {
                    printf("Sortare crescatoare(1) sau descrescatoare(2):");
                    scanf("%d", &mod);
                    if(mod == 1) Afisare(sortare(*lista_cheltuieli, 0, 1));
                    else if(mod == 2) Afisare(sortare(*lista_cheltuieli, 0, 0));
                    else printf("Mod de sortare invalid!\n");
                }
                else printf("Sortare invalida!\n");
                break;
            case 6:
                Afisare(*lista_cheltuieli);
                break;
        }
    }
}