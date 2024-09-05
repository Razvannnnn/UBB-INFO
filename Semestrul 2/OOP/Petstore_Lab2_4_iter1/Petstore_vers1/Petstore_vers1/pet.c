#include "pet.h"

#include <string.h>
#include <assert.h>
/*
Create a new pet
*/
Pet createPet(char* type, char* species, float price) {
	Pet rez;
	strcpy_s(rez.type,sizeof(rez.type), type);
	strcpy_s(rez.species,sizeof(rez.type), species);
	rez.price = price;
	return rez;
}

/*
Dealocate memory occupied by pet
*/
void destroyPet(Pet* p) {
	//no memory is allocated on the heap
	//nothing to dealocate
	//mark that pet is destroyed, avoid accidental use after destroy
	p->type[0] = '\0';
	p->species[0] = '\0';
	p->price = -1;
}

int valideaza(Pet p) {
	if (strlen(p.species) == 0) {
		return 1;
	}
	if (strlen(p.type) == 0) {
		return 2;
	}
	if (p.price < 0) {
		return 3;
	}
	return 0;
}

void testCreateDestroy() {
	Pet p = createPet("dog", "buldog", 100);
	assert(strcmp(p.type, "dog") == 0);
	assert(strcmp(p.species, "buldog") == 0);
	assert(p.price == 100.0);

	destroyPet(&p);
	assert(strlen(p.type) == 0);
	assert(strlen(p.species) == 0);
	assert(p.price==-1);
}