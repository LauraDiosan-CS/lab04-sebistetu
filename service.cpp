#include "repo.h"
#include "service.h"
#include "cheltuiala.h"

Service::Service() {

}

Service::Service(Repo r) {

	repo = r;
}

Service::~Service() {

}

void Service::addElem(int id, int nr, int suma, char* tip) {

	Cheltuiala c(id, nr, suma, tip);
	repo.addElem(c);
}

int Service::delElem(int nr) {

	return repo.delElem(nr);
}

void Service::updateElem(int id, int nr, int suma, char* tip) {

	Cheltuiala c(id, nr, suma, tip);
	repo.updateElem(c);
}

void Service::getAll(Cheltuiala lista[50], int &lung) {

	repo.getAll(lista, lung);
}