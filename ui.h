#pragma once
#include "service.h"
#include "cheltuiala.h"

int convert(char* sir);

class UI {

private:
	Service service;
public:
	UI(Service& service);
	UI();
	void afisareMeniu();
	void uiAddElem(char comanda[]);
	void uiAfisare(char comanda[]);
	void uiStergere(char comanda[]);
	void uiModificare(char comanda[]);
	void uiSuma(char comanda[]);
	void uiMax(char comanda[]);
	void uiSortare(char comanda[]);
	void uiFiltrare(char comanda[]);
	void undo();
	void runUI();
};
