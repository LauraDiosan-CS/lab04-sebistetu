#pragma once
#include "repo.h"
#include "cheltuiala.h"
#include "service.h"

class Service {
private:
	Repo repo;
public:
	Service();
	Service(Repo);
	~Service();
	void addElem(int, int, int, char*);
	int delElem(int);
	void updateElem(int, int, int, char*);
	void getAll(Cheltuiala lista[50], int& lung);
};