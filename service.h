#pragma once
#include "repo.h"
#include "cheltuiala.h"
#include "service.h"
#include <vector>
using namespace std;

bool cmp(Cheltuiala c1, Cheltuiala c2);
class Service {
private:
	Repo repo;
	Cheltuiala lista_undo[100];
	int cod_undo[100];
	int lungime_undo;
public:
	Service();
	Service(Repo);
	~Service();
	bool addElem(int, int, int, char*);
	bool delElem(int, int, char*);
	bool updateElem(int, int, int, char*);
	void getAll(Cheltuiala lista[50], int& lung, char simbol, int valoare, int nr, char* tip);
	int suma(char*);
	void sortare(Cheltuiala lista[50], int& lung, char* tip);
	void filtrare(Cheltuiala lista[50], int& lung, char* tip);
	void retinereUndo(int op, Cheltuiala c);
	void undo();
	Cheltuiala max(int);
};