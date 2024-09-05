#include "ui.h"
#include <stdio.h>
#include <malloc.h>


void print_main_menu(){
    printf("\nMENIUL PRINCIPAL\n");
    printf("\n1. Adaugare oferta:");
    printf("\n2. Actulizare oferta:");
    printf("\n3. Stergere oferta:");
    printf("\n4. Ordonare dupa pret, tip:");
    printf("\n5. Filtrare dupa un criteriu:");
    printf("\n6. Undo:");
    printf("\n7. Filtrare suma minima:");
    printf("\n0. Exit:");
}

void afisare_oferta(struct Oferta oferta){
    printf("\n\nID: %d \nTip: %s \nAdresa: %s \nSuprafata: %d \nPret: %d", oferta.id, oferta.tip, oferta.adresa, oferta.suprefata, oferta.pret);

}

void read_char(char mesaj[], char text[]){
    printf("%s", mesaj);
    scanf("%s", text);
}

int read_int(char mesaj[]){
    int alege;

    while (1){
        printf("%s", mesaj);
        int v = scanf("%d", &alege);

        if (v == 1)
            break;
        else{
            printf("\nNu ai introdus un numar intreg!\n");
            while (getchar() != '\n');
        }
    }

    return alege;
}

void adaugare_oferta_ui(MyList* repo, MyList* undolist){
    int id = read_int("\nIntroduce id:");
    char tip[40], adresa[50];
    read_char("\nIntroduce tipul:", tip);
    read_char("\nIntroduce adresa:", adresa);
    int suprafata = read_int("\nIntroduce suprafata:");
    int pret = read_int("\nIntrodece pretul:");

    adaugareOferte(repo, undolist, id, tip, adresa, suprafata, pret);
}

void acatualizare_oferta(MyList* repo, MyList* undolist){
    int id = read_int("\nIntroduce id:");
    char tip[40], adresa[50];
    read_char("\nIntroduce tipul:", tip);
    read_char("\nIntroduce adresa:", adresa);
    int suprafata = read_int("\nIntroduce suprafata:");
    int pret = read_int("\nIntrodece pretul:");

    modificareOferta(repo, undolist, id, tip, adresa, suprafata, pret);
}

void stergere_oferta_ui(MyList* repo, MyList* undolist){
    int id = read_int("\nIntroduce id:");
    stergereOferta(repo, undolist, id);
}

void ordonare(MyList* repo){
    printf("\n1.Crescator: \n2.Descrescator:");
    int alege = 1;
    scanf("%d", &alege);
    int dim; Dim(repo, &dim);
    struct Oferta* lista = (struct Oferta*)malloc(dim * sizeof(struct Oferta));
    if (alege == 1) {
        printf("\n1.Selection sort: \n2.Bubble sort:");
        int sort = 1;
        scanf("%d", &sort);
        if (sort == 1) {
            odonareOferteDupaPretTip(repo, lista, sort_cresc_verif);
            for (int i = 0; i < dim; i ++)
                afisare_oferta(lista[i]);
        }
        else if(sort == 2) {
            ordonareBubble(repo, lista, sort_cresc_verif);
            for (int i = 0; i < dim; i ++)
                afisare_oferta(lista[i]);
        }
        else printf("Optiune invalida!\n");
    }
    else if(alege ==2) {
        printf("\n1.Selection sort: \n2.Bubble sort:");
        int sort = 1;
        scanf("%d", &sort);
        if (sort == 1) {
            odonareOferteDupaPretTip(repo, lista, sort_descresc_verif);
            for (int i = 0; i < dim; i ++)
                afisare_oferta(lista[i]);
        }
        else if (sort == 2) {
            ordonareBubble(repo, lista, sort_descresc_verif);
            for (int i = 0; i < dim; i ++)
                afisare_oferta(lista[i]);
        }
        else printf("Optiune invalida!\n");
    }
    else printf("Optiune invalida!\n");
    free(lista);
}

void filtrare(MyList* repo){
    printf("1.Suprafata: \n2.Tip: \n3.Pret: ");
    int alege = 1;
    scanf("%d", &alege);
    int dim; Dim(repo, &dim);
    struct Oferta* lista = (struct Oferta*)malloc(dim * sizeof(struct Oferta));
    if (alege == 1){
        int suprafata = read_int("\nIntroduce suprafata:");
        filtrareDupaUnCriteriu(repo, lista, &dim, 1, suprafata, "", 0);
    }
    else if (alege == 2){
        char tip[40];
        read_char("\nIntroduce tipul:", tip);
        filtrareDupaUnCriteriu(repo, lista, &dim, 2, 0, tip, 0);
    }
    else if (alege == 3){
        int pret = read_int("\nIntroduce pretul:");
        filtrareDupaUnCriteriu(repo, lista, &dim, 3, 0, "", pret);
    }
    for (int i = 0; i < dim; i ++)
        afisare_oferta(lista[i]);
    free(lista);
}

void filtrareNoua_ui(MyList* repo) {
    int dim;
    Dim(repo, &dim);
    struct Oferta* lista = (struct Oferta*)malloc(dim * sizeof (struct Oferta));
    int pret;
    pret = read_int("\nPretul minim:");
    filtrareNoua(repo, lista, &dim, pret);
    for (int i = 0; i < dim; i ++)
        afisare_oferta(lista[i]);
    free(lista);
}

MyList* undo(MyList* repo, MyList* undolist) {
    if(undolist->dimensiune == 0) {
        printf("Nu se mai poate efectua undo!\n");
    }
    else {
        repo = get(undolist, undolist->dimensiune-1);
        sterge(undolist, undolist->dimensiune-1);
        printf("Undo s-a efectuat!\n");
    }
    return repo;
}

void main_menu(MyList* repo, MyList* undolist) {
    int terminaat = 1;
    while (terminaat) {
        print_main_menu();
        int alege = read_int("\nAlege optiunea:");

        if (alege == 1)
            adaugare_oferta_ui(repo, undolist);
        else if (alege == 2)
            acatualizare_oferta(repo, undolist);
        else if (alege == 3)
            stergere_oferta_ui(repo, undolist);
        else if (alege == 4)
            ordonare(repo);
        else if (alege == 5)
            filtrare(repo);
        else if (alege == 6)
            repo = undo(repo, undolist);
        else if (alege == 7)
            filtrareNoua_ui(repo);
        else if (alege == 0)
            terminaat = 0;
    }
    distrugeLista(repo);
    distrugeListaUndo(undolist);
}
