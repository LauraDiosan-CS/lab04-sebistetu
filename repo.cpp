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

/*Modificare cheltuiala
in:
-ap: int, nr apartamentului la care se face modificarea
-suma: int, suma modificata
-tip: char*, noul tip
out: lista de elemente cu o cheltuiala modificata, daca este gasita
*/
void Repo::updateElem(Cheltuiala c) {

	for (int i = 0; i < nr_cheltuieli; ++i)
		if (cheltuieli[i].get_id() == c.get_id()) {

			cheltuieli[i].set_suma(c.get_suma());
			cheltuieli[i].set_tip(c.get_tip());
		}
}

/*Sterge cheltuiala aferenta unui id
in:
-id: int
out: -1 daca nu s a gasit cheltuiala si 0 in cazul in care s-a efectuat stergerea cu succes
*/
int Repo::delElem(int id) {

	for (int i = 0; i < nr_cheltuieli; ++i)
		if (cheltuieli[i].get_id() == id) {

			for (int j = i; j < nr_cheltuieli - 1; ++j)
				cheltuieli[j] = cheltuieli[j + 1];
			nr_cheltuieli--;
			return 0;
		}
	return -1;
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