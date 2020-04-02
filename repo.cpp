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
out: true, daca s-a efecutat adaugarea, flase altfel
*/
bool Repo::addElem(Cheltuiala& c) {

	for (int i = 0; i < nr_cheltuieli; ++i)
		if (cheltuieli[i].get_id() == c.get_id())
			return false;

	this->cheltuieli[this->nr_cheltuieli++] = c;
	return true;
}

/*Modificare cheltuiala
in:
-c: cheltuiala noua
out: lista de elemente cu o cheltuiala modificata, daca este gasita
	true, daca s-a efecutat modificarea, false altfel
*/
bool Repo::updateElem(Cheltuiala c) {

	for (int i = 0; i < nr_cheltuieli; ++i)
		if (cheltuieli[i].get_id() == c.get_id()) {

			cheltuieli[i].set_nr_apartament(c.get_nr_apartament());
			cheltuieli[i].set_suma(c.get_suma());
			cheltuieli[i].set_tip(c.get_tip());
			return true;
		}
	return false;
}

/*Sterge cheltuiala aferenta unui id
in:
-c: cheltuiala ce trebuie stearsa
out: false daca nu s a gasit cheltuiala si true in cazul in care s-a efectuat stergerea cu succes
*/
bool Repo::delElem(Cheltuiala c) {

	for (int i = 0; i < nr_cheltuieli; ++i)
		if (cheltuieli[i] == c) {

			for (int j = i; j < nr_cheltuieli - 1; ++j)
				cheltuieli[j] = cheltuieli[j + 1];
			nr_cheltuieli--;
			return true;
		}
	return false;
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

Cheltuiala Repo::getElemDupaId(int id) {

	for (int i = 0; i < nr_cheltuieli; ++i)
		if (cheltuieli[i].get_id() == id)
			return cheltuieli[i];

	return Cheltuiala(0, 0, 0, 0);
}

