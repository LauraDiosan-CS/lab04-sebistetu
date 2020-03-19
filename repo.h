#ifndef REPO_H
#define REPO_H
#include "cheltuiala.h"

class Repo {

private:
	Cheltuiala cheltuieli[10];
	int nr_cheltuieli;
public:
	Repo();
	~Repo();
	void addElem(Cheltuiala& c);
	void getAll(Cheltuiala rez[], int &lung);
	int get_size();

};

#endif REPO_H