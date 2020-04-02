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

	repo.delElem(c1);
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
	Cheltuiala c1, c2, c3, c4, c5;
	c1 = Cheltuiala(1, 100, 2000, gaz);
	c2 = Cheltuiala(2, 200, 4000, curent);
	c3 = Cheltuiala(2, 200, 6000, apa);
	c4 = Cheltuiala(3, 300, 20000, gaz);
	c5 = Cheltuiala(4, 100, 10000, gaz);

	s.addElem(1, 100, 2000, gaz); // 1
	s.addElem(2, 200, 4000, curent); // 1 2 
	s.getAll(lista, lung, '\0', 0, 0, NULL);
	assert(lung == 2);

	s.updateElem(2, 200, 6000, apa); // 1 3 
	s.getAll(lista, lung, '\0', 0, 0, NULL);
	assert(lista[1] == c3);

	s.addElem(4, 100, 10000, gaz); // 1 3 5
	assert(s.max(100) == c5);

	s.delElem(1, 0, NULL); // 3 5
	s.getAll(lista, lung, '\0', 0, 0, NULL);
	assert(lung == 2);
	
	Cheltuiala lista_2[50];
	int lung_2 = 0;
	s.addElem(3, 300, 20000, gaz); // 3 5 4
	s.sortare(lista_2, lung_2, gaz);
	assert(lista_2[0] == c4);

	s.filtrare(lista_2, lung_2, apa);
	assert(lung_2 == 1);
	
}