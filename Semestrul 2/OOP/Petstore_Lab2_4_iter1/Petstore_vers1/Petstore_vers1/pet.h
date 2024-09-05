#pragma once

typedef struct {
	char type[30];
	char species[30];
	float price;
} Pet;

/*
Create a new pet
*/
Pet createPet(char* type, char* species, float price);

/*
 Dealocate memory occupied by pet
*/
void destroyPet(Pet* p);

void testCreateDestroy();

int valideaza(Pet);

