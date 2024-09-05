#pragma once

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