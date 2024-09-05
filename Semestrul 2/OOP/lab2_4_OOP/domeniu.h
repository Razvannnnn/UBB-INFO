#ifndef LAB2_4_OOP_DOMENIU_H
#define LAB2_4_OOP_DOMENIU_H

struct Oferta{
    int id;
    char tip[30], adresa[40];
    int suprefata, pret;
};

int get_id(struct Oferta oferta);
/**
 * functia returneaza id-ul ofertei
 *
 * */

char *get_tip(struct Oferta* oferta);
/**
 * functia returneaza tipul ofertei
 * ex apel: get_tip(&oferta[0]);
 * */

char *get_adresa(struct Oferta* oferta);
/**
 * functia returneaza adresa ofertei
 * ex apel: get_adresa(&oferta[0]);
 * */

int get_suprafata(struct Oferta oferta);
/**
 * functia returneaza suprafata ofertei
 * */

int get_pret(struct Oferta oferta);
/**
 * functia returneaza pretul ofertei
 * */

void set_id(struct Oferta* oferta, int id);
/**
 * functia seteaza id-ul ofertei
 *
 * */

void set_tip(struct Oferta* oferta, char tip[]);
/**
 * functia seteaza tipul ofertei
 * ex apel:
 * */

void set_adresa(struct Oferta* oferta, char adresa[]);
/**
 * functia returneaza adresa ofertei
 * ex apel:
 * */

void set_suprafata(struct Oferta* oferta, int suprafata);
/**
 * functia suprafata suprafata ofertei
 * */

void set_pret(struct Oferta* oferta, int pret);
/**
 * functia seteaza pretul ofertei
 * */

struct Oferta* creareOferta(int id, char tip[], char adresa[], int suprafata, int pret);
 /**
 *
 * */

void distrugeOferta(struct Oferta* oferta);

#endif //LAB2_4_OOP_DOMENIU_H


/**
10. Agentie imobiliara

Creati o aplicatie care permite gestiunea ofertelor de la o agentie imobiliara.
Fiecare oferta are: tip (teren, casa, apartament), suprafata, adresa, pret

Aplicatia permite:
 a) Adaugarea de noi oferte.
 b) Actualizare oferte
 c) Stergere oferta
 d) Vizualizare oferete ordonat dupa pret, tip (crescator/descrescator)
 e) Vizualizare oferta filtrate dupa un criteriu (suprafata, tip, pret)
 **/