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
	bool addElem(Cheltuiala& c);
	bool updateElem(Cheltuiala);
	bool delElem(Cheltuiala);
	void getAll(Cheltuiala rez[], int &lung);
	int get_size();
	void reverse(Cheltuiala rez[], int& lung);
	Cheltuiala getElemDupaId(int);

};

#endif REPO_H