#include "repo.h"

//Constructor
Repo::Repo() {

	this->nr_cheltuieli = 0;
}

//Destrutor
Repo::~Repo() {

}

/*Adaugare cheltuiala
in: c, cheltuiala data
out: -
*/
void Repo::addElem(Cheltuiala& c) {

	this->cheltuieli[this->nr_cheltuieli++] = c;
}

/*Returneaza prin parametru lista de cheltuieli si numarul acestora
in:
-rez: lista de cheltuieli
-lung: int, transmis prin referinta, nr de cheltuieli
out: -
*/
void Repo::getAll(Cheltuiala rez[], int &lung) {

	for (int i = 0; i < this->nr_cheltuieli; ++i)
		rez[i] = this->cheltuieli[i];

	lung = this->nr_cheltuieli;
}

/*Retureaza numarul de cheltuieli
in: -
out: int, nr de cheltuieli
*/
int Repo::get_size() {

	return this->nr_cheltuieli;
}