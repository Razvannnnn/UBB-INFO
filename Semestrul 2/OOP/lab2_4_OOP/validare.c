#include <string.h>
#include "validare.h"


void validare_oferta(struct Oferta oferta, char erori[]){
    strcpy(erori, "");
    if (get_id(oferta) < 0)
        strcat(erori, "\nID invalid!");
    if (strcmp(get_tip(&oferta), "teren") != 0 && strcmp(get_tip(&oferta), "casa") != 0 && strcmp(get_tip(&oferta), "apartament") != 0)
        strcat(erori, "\nTip invalid!");
    if (strcmp(get_adresa(&oferta), "") == 0)
        strcat(erori, "\nAdresa invalida!");
    if (get_suprafata(oferta) < 1)
        strcat(erori, "\nSuprafata invalida!");
    if (get_pret(oferta) < 0)
        strcat(erori, "\nPret invalida!");
}