#include "cheltuieli.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

cheltuiala createCheltuiala() {
    /*
     * Creeaza o cheltuiala
     * preconditii -
     * postconditii - c de tip cheltuiala
     */
    cheltuiala c;
    c.tip = (char*)malloc(sizeof(char) * 51);
    c.tip[0] = '\0';
    return c;
}

void destroyCheltuiala(cheltuiala* c) {
    /*
     * Distruge o cheltuiala
     * preconditii - cheltuiala pe care o distrugem
     * postconditii -
     */
    free(c->tip);
}
