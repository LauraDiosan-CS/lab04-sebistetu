#include "repo.h"
#include "cheltuiala.h"
#include "test.h"
#include "service.h"
#include <assert.h>
#include <string.h>

void test_cheltuiala() {

	char* gaz = new char[4];
	strcpy_s(gaz, 4, "gaz");
	Cheltuiala c1, c2, c3;
	c1 = Cheltuiala(1, 4, 100, gaz);
	c2 = Cheltuiala(c1);
	assert(c2.get_suma() == 100);
	assert(strcmp(gaz, c2.get_tip()) == 0);
	c1.set_nr_apartament(10);
	assert(c1.get_nr_apartament() == 10);
	c3 = c1;
	assert(strcmp(gaz, c3.get_tip()) == 0);
}

void test_repo() {

	Repo repo;
	Cheltuiala lista[50];
	int lung = 0;
	char* gaz = new char[4];
	char* curent = new char[7];
	char* apa = new char[4];
	strcpy_s(gaz, 4, "gaz");
	strcpy_s(curent, 7, "curent");
	strcpy_s(apa, 4, "apa");
	Cheltuiala c1, c2, c3;
	c1 = Cheltuiala(1, 100, 2000, gaz);
	c2 = Cheltuiala(2, 200, 4000, curent);
	c3 = Cheltuiala(2, 200, 6000, apa);
	repo.addElem(c1);
	repo.addElem(c2);
	assert(repo.get_size() == 2);
	repo.updateElem(c3);
	repo.getAll(lista, lung);
	assert(lista[1] == c3);
	repo.delElem(1);
	assert(repo.get_size() == 1);
}

void test_service() {

	Cheltuiala lista[50];
	int lung;
	Service s;
	char* gaz = new char[4];
	char* curent = new char[7];
	char* apa = new char[4];
	strcpy_s(gaz, 4, "gaz");
	strcpy_s(curent, 7, "curent");
	strcpy_s(apa, 4, "apa");
	Cheltuiala c1, c2, c3;
	c1 = Cheltuiala(1, 100, 2000, gaz);
	c2 = Cheltuiala(2, 200, 4000, curent);
	c3 = Cheltuiala(2, 200, 6000, apa);
	s.addElem(1, 100, 2000, gaz);
	s.addElem(2, 200, 4000, curent);
	s.getAll(lista, lung);
	assert(lung == 2);
	s.updateElem(2, 200, 6000, apa);
	s.getAll(lista, lung);
	assert(lista[1] == c3);
	s.delElem(1);
	s.getAll(lista, lung);
	assert(lung == 1);
}