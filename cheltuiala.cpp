#include "cheltuiala.h"
#include <string.h>

/*
Constructor
in: -
out: o cheltuiala goala
*/
Cheltuiala::Cheltuiala() {

	id = 0;
	this->nr_apartament = 0;
	this->suma = 0;
	this->tip = NULL;
}

/*
Constructor cu parametru
in:
-id: int
-nr_apartament: int
-suma: int
-tip: sir de caractere
out:
-un obiect de tip Cheltuiala care contine datele date
*/
Cheltuiala::Cheltuiala(int id, int nr_apartament, int suma, char* tip) {

	this->id = id;
	this->nr_apartament = nr_apartament;
	this->suma = suma;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

/*
Constructor
in:
-c: un obiect de tip Cheltuiala
out: un obiect de tip Cheltuiala care contine aceleasi date ca si c
*/
Cheltuiala::Cheltuiala(const Cheltuiala& c) {

	this->id = c.id;
	this->nr_apartament = c.nr_apartament;
	this->suma = c.suma;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
}

//Destructor
Cheltuiala::~Cheltuiala() {

	delete[] this->tip;
}

/*getter id
in: -
out: int
*/
int Cheltuiala::get_id() {

	return id;
}

/*Getter numar apartament
in: -
out: int
*/
int Cheltuiala::get_nr_apartament() {

	return this->nr_apartament;
}

/*Getter suma
in: -
out: int
*/
int Cheltuiala::get_suma() {

	return this->suma;
}

/*Getter tip
in: -
out: char*
*/
char* Cheltuiala::get_tip() {

	return this->tip;
}

/*Setter nr_apartament
in:
-nr: int, noul nr de apartament
out: acelasi obiect, dar cu alt nr apartament
*/
void Cheltuiala::set_nr_apartament(int nr) {

	this->nr_apartament = nr;
}

/*Setter suma
in:
-nr: int, noua suma
out: acelasi obiect, dar cu alta suma
*/
void Cheltuiala::set_suma(int suma) {

	this->suma = suma;
}

/*Setter tip
in:
-nr: char*, noul tip
out: acelasi obiect, dar cu alt tip
*/
void Cheltuiala::set_tip(char* tip) {

	if (this->tip)
		delete[] this->tip;

	if (tip == NULL)
		this->tip = NULL;
	else {

		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);
	}
}

/*Operatorul =
in: 2 obiecte de tip Cheltuiala(c si this)
out: noua stare a obiectului cufrent(this)
*/
Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c) {

	this->id = c.id;
	this->set_nr_apartament(c.nr_apartament);
	this->set_suma(c.suma);
	this->set_tip(c.tip);
	return *this;
}

/*Operatorul ==
in: 2 obiecte de tip Cheltuiala
out: true, daca cele doua obiecte sunt egale, false altfel
*/
bool Cheltuiala::operator==(const Cheltuiala &c) {

	return ((this->id == c.id) and (this->nr_apartament == c.nr_apartament) and (strcmp(this->tip, c.tip) == 0) and (this->suma == c.suma));
}