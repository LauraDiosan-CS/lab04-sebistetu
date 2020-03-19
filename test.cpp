#include "repo.h"
#include "cheltuiala.h";
#include "test.h"
#include <assert.h>

void test_cheltuiala() {

	Cheltuiala c1, c2, c3;
	c1 = Cheltuiala(4);
	c2 = Cheltuiala(c1);
	assert(c2.get_nr_apartament() == 4);
	c1.set_nr_apartament(10);
	assert(c1.get_nr_apartament() == 10);
	c3 = c1;
	assert(c3.get_nr_apartament() == 10);
}

void test_repo() {

	Repo repo;
	Cheltuiala c1, c2;
	c1 = Cheltuiala(100);
	c2 = Cheltuiala(200);
	repo.addElem(c1);
	repo.addElem(c2);
	assert(repo.get_size() == 2);

}