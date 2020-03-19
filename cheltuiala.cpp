#include "cheltuiala.h"

/*
Constructor
in: -
out: o cheltuiala goala
*/
Cheltuiala::Cheltuiala() {

	this->nr_apartament = 0;
}

/*
Constructor cu parametru
in:
-nr_apartament: int
out:
-un obiect de tip Cheltuiala care contine datele date
*/
Cheltuiala::Cheltuiala(int nr_apartament) {

	this->nr_apartament = nr_apartament;
}

/*
Constructor
in:
-c: un obiect de tip Cheltuiala
out: un obiect de tip Cheltuiala care contine aceleasi date ca si c
*/
Cheltuiala::Cheltuiala(const Cheltuiala& c) {

	this->nr_apartament = c.nr_apartament;
}

//Destructor
Cheltuiala::~Cheltuiala() {

}

/*Getter numar apartament
in: -
out: int
*/
int Cheltuiala::get_nr_apartament() {

	return this->nr_apartament;
}

/*Setter nr_apartament
in:
-nr: int, noul nr de apartament
out: acelasi obiect, dar cu alt nr apartament
*/
void Cheltuiala::set_nr_apartament(int nr) {

	this->nr_apartament = nr;
}

/*Operatorul =
in: 2 obiecte de tip Cheltuiala(c si this)
out: noua stare a obiectului cufrent(this)
*/
Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c) {

	this->set_nr_apartament(c.nr_apartament);
	return *this;
}