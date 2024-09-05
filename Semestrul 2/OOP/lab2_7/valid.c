#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "valid.h"
#include "cheltuieli.h"

int validare_cheltuiala(cheltuiala c) {
    /*
     * Functie ce verifica daca o cheltuiala este valida
     * preconditii: c - cheltuiala
     * postconditii: 1 - daca este valida
     *               0 - daca nu este valida
     */
    if(c.nr < 1) return 0;
    if(c.suma < 0) return 0;
    if(strcmp(c.tip, "apa") != 0 && strcmp(c.tip, "canal") !=0 && strcmp(c.tip, "incalzire") != 0 && strcmp(c.tip, "gaz") != 0) return 0;
    return 1;
}


