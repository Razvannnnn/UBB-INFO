#ifndef LAB2_7_CHELTUIELI_H
#define LAB2_7_CHELTUIELI_H

//Definim structura cheltuiala
typedef struct {
    int nr;
    int suma;
    char *tip;
} cheltuiala;

//Creeaza o noua cheltuiala
cheltuiala createCheltuiala();

//Distruge o cheltuiala
void destroyCheltuiala(cheltuiala *c);

#endif