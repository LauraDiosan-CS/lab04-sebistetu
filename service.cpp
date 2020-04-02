#include "repo.h"
#include "service.h"
#include "cheltuiala.h"
#include <string.h>
#include <algorithm>
#include <iostream>

//Constructor
Service::Service() {

	lungime_undo = 0;
}

//Constructor cu parametru
Service::Service(Repo r) {

	repo = r;
	lungime_undo = 0;
}

//Drestructor
Service::~Service() {

}

/*Adaugare cheltuiala
in:
-id: int
-nr: int
-suma: int
-tip: char* 
out: -*/
bool Service::addElem(int id, int nr, int suma, char* tip) {

	Cheltuiala c(id, nr, suma, tip);
	retinereUndo(1, c);
	return repo.addElem(c);
}

/*Stergere Cheltuiala dupa id, numar apartament sau dupa tip(care este nenul)
in:
-id: int
-nr_apartament: int
-tip: char* 
*/
bool Service::delElem(int id, int nr_apartament, char* tip) {
	
	if (nr_apartament == 0 and tip == NULL) {

		Cheltuiala c = repo.getElemDupaId(id);
		if (c.get_id())
			retinereUndo(2, c);
	}
	
	Cheltuiala c(id, nr_apartament, 0, tip);
	return repo.delElem(c);
}

/*Modificare cheltuiala dupa id
in:
-id: int
-nr: int
suma: int
-tip: char*
*/
bool Service::updateElem(int id, int nr, int suma, char* tip) {

	Cheltuiala c1(id, nr, suma, tip);
	Cheltuiala c = repo.getElemDupaId(id);
	if (c.get_id())
		retinereUndo(3, c);
	return repo.updateElem(c1);
}

/*Returneaza o lista de cheltuieli. Fie vor fi returnate toate, fie dupa suma sau tip sau nr apartament
in:
-lista: vector in care se va retine elementele
-lung_rez: int, nr de elemente din vector
-simbol: char, '>'sau '='
-valoare: int, valoare in functie de care se restrictioneaza suma cheltuielilor returnate
-nr: int, numarul aparamentului
-tip: char* tipul cheltuielilor
out: lista cu cheltuielile returnate in functie de datele de intrare
*/
void Service::getAll(Cheltuiala lista[50], int &lung_rez, char simbol, int valoare, int nr, char* tip) {

	lung_rez = 0;
	Cheltuiala cheltuieli[50];
	int lung = 0;
	repo.getAll(cheltuieli, lung);
	
	if (tip != NULL) {

		for (int idx = 0; idx < lung; ++idx) {
			if (strcmp(cheltuieli[idx].get_tip(), tip) == 0) {
				lista[lung_rez++] = cheltuieli[idx];
			}
		}
	}
	if (nr) {

		for (int idx = 0; idx < lung; ++idx)
			if (cheltuieli[idx].get_nr_apartament() == nr)
				lista[lung_rez++] = cheltuieli[idx];
	}

	if (simbol == '\0' and tip == NULL) {

		for (int idx = 0; idx < lung; ++idx)
			lista[idx] = cheltuieli[idx];
		lung_rez = lung;
	}
	else {
		for (int idx = 0; idx < lung; ++idx)
			if (simbol == '>') {
				if (cheltuieli[idx].get_suma() > valoare)
					lista[lung_rez++] = cheltuieli[idx];
			}
			else
				if (simbol == '=') {
					if (cheltuieli[idx].get_suma() == valoare)
						lista[lung_rez++] = cheltuieli[idx];
				}
	}
}

/*Returneaza suma tuturor cheltuielilor dupa un tip
in:
-tip: char* tipul
out:
-sum: int, nr cerut
*/
int Service::suma(char* tip) {

	int sum = 0;
	Cheltuiala lista[50];
	int lung = 0;
	repo.getAll(lista, lung);

	for (int idx = 0; idx < lung; ++idx)
		if (strcmp(lista[idx].get_tip(), tip) == 0)
			sum += lista[idx].get_suma();
	return sum;
}

//Functie de comparare a 2 cheltuieli ->descrescator dupa suma
bool cmp(Cheltuiala c1, Cheltuiala c2) {

	return (c1.get_suma() > c2.get_suma());
}

//Efectueaza sortarea cheltuielilor de un tip descrescator
//in: lista: lista de cheltuieli
//    lung: nr de cheltuieli
//    tip: tip ul dupa care se face sortarea
void Service::sortare(Cheltuiala lista[50], int& lung, char* tip) {

	getAll(lista, lung, '\0', 0, 0, tip);
	std::sort(lista, lista + lung, cmp);
}


//Filtreaza cheltuielile dupa un anumit tip
void Service::filtrare(Cheltuiala lista[50], int& lung, char* tip) {

	getAll(lista, lung, '\0', 0, 0, tip);
}

//Salveaza la fiecare operatie ce modifica lista tipul operatiei si elementul modificat
void Service::retinereUndo(int op, Cheltuiala c) {

	cod_undo[lungime_undo] = op;
	lista_undo[lungime_undo] = c;
	lungime_undo++;
}

//Efectueaza operatia undo
void Service::undo() {

	if (lungime_undo == 0)
		return;

	int op = cod_undo[lungime_undo - 1];
	Cheltuiala c = lista_undo[lungime_undo - 1];

	if (op == 1)
		repo.delElem(c);
	if (op == 2)
		repo.addElem(c);
	if (op == 3)
		repo.updateElem(c);
	lungime_undo--;
}


//Returneaza cheltuiala cea mai valoroasa de la un nr apartament
Cheltuiala Service::max(int nr){

	Cheltuiala lista[50];
	int lung = 0;
	repo.getAll(lista, lung);

	Cheltuiala max(0, 0, 0, NULL);
	int maxi = -1;
	for (int idx = 0; idx < lung; ++idx)
		if (lista[idx].get_nr_apartament() == nr)
			if (lista[idx].get_suma() > maxi) {

				maxi = lista[idx].get_suma();
				max = lista[idx];
			}
	return max;
}
