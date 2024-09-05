#ifndef LAB2_4_OOP_MYLIST_H
#define LAB2_4_OOP_MYLIST_H

typedef  void* Element;
typedef struct{
    Element* elems;
    int dimensiune;
    int capacitate;
}MyList;

MyList* creazaVector();
/**
 * functia returneaza un pointer catre lista creata
 * */

void distruge(MyList* lista);
/**
 * functia eliberea memora alocata pentru o lista
 * */

Element getOferta(MyList lista, int poz);
Element get(MyList* lista, int poz);
/**
 * functia returneazza elementul de pe pozitia poz
 * */

void adauga(MyList* lista, Element el);
/**
 * functia adauga in lista elemetul
 * */

void redimensionareLista(MyList* lista);
/**
 * functia redimensioneaza vectorul
 * */

void sterge(MyList* lista, int poz);
/**
 * functia sterge elementul de pe pozitia poz
 **/

int size(MyList *lista);
/**
 * functia returneaza numarul de elemente din lista
 * */

MyList* copyList(MyList* lista);
/**
 * functia copiaza lista
 * */

#endif //LAB2_4_OOP_MYLIST_H
