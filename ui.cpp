#include "service.h"
#include "ui.h"
#include "cheltuiala.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int convert(char* sir) {

	int idx = 0, suma = 0;
	while (sir[idx]) {

		suma = suma * 10 + int(sir[idx] - '0');
		idx++;
	}
	return suma;
}

UI::UI(Service& service) {

	this->service = service;
}

UI::UI() {


}
void UI::afisareMeniu() {

		cout << "\nScrie pentru adaugare: adaugare [id] [nr_apartament] [suma] [tip] \n"; //*
		cout << "Scrie pentru afisare totala: afisare \n";
		cout << "Scrie pentru afisarea cheltuielilor pt un nr de apartament: afisare [nr_apartament] \n";
		cout << "Scrie pentru afisarea cheltuielilor cu o suma mai mare decat o suma data: afisare suma > [suma data]\n";
		cout << "Scrie pentru afisarea cheltuielilor cu o suma egala cu o suma data: afisare suma = [suma data]\n";
		cout << "Scrie pentru stergerea unei cheltuieli dupa id: stergere id [id]\n"; // *
		cout << "Scrie pentru stergerea tuturor cheltuielilor pt un apartament: stergere [nr_apartament]\n"; // *
		cout << "Scrie pentru stergerea tuturor cheltuielilor cu un anumit tip: stergere [tip]\n"; // *
		cout << "Scrie pentru modificarea unei cheltuieli: modificare [id] [nr_apartament] [suma] [tip]"; // *
		cout << "Scrie pentru suma totala pt un tip de cheltuiala: suma [tip]\n";
		cout << "Scrie pentru afisarea celei mai valoroase cheltuieli pt un apartament: max [nr_apartament]\n";
		cout << "Scrie pentru sortarea descrescatoare a cheltuielilor cu un anumit tip: sortare [tip]\n";
		cout << "Scrie pentru filtrarea cheltuielilor cu un anumit tip: filtrare [tip]\n";
		cout << "Scrie pentru undo: undo\n";
		cout << "Scrie pentru iesire din program: exit\n";
}
	
void UI::uiAddElem(char comanda[])  {

	char* n;
	char* p = strtok_s(comanda, " ", &n);
	
	if (strcmp(p, "adaugare"))
		return;
	char* tip = new char[20];
	int id, nr, suma;

	p = strtok_s(NULL, " ", &n);
	id = convert(p);
	p = strtok_s(NULL, " ", &n);
	nr = convert(p);
	p = strtok_s(NULL, " ", &n);
	suma = convert(p);
	p = strtok_s(NULL, " ", &n);
	strcpy_s(tip, strlen(p) + 1, p);
	p = strtok_s(NULL, " ", &n);

	bool rez = service.addElem(id, nr, suma, tip);
	if (rez == true)
		cout << "Adaugare efectuata!\n";
	else
		cout << "ID-ul exsta deja!\n";
	delete[] tip;
}

void UI::uiAfisare(char comanda[]) {

	Cheltuiala cheltuieli[50];
	int lung = 0, valoare = -1, nr = 0;
	char simbol = '\0';
	
	char* n;
	char* p = strtok_s(comanda, " ", &n);
	if (strcmp(p, "afisare"))
		return;
	p = strtok_s(NULL, " ", &n);

	if (p) {

		if (isdigit(p[0])) {

			nr = convert(p);
		}
		else {
			simbol = p[0];

			p = strtok_s(NULL, " ", &n);
			valoare = convert(p);

			p = strtok_s(NULL, " ", &n);
		}
	}

	service.getAll(cheltuieli, lung, simbol, valoare, nr, NULL);

	if (lung == 0) {
		cout << "Nu exista elemente!\n";
		return;
	}
	
	for (int i = 0; i < lung; ++i)
		cout << cheltuieli[i].get_id() << " " << cheltuieli[i].get_nr_apartament() << " " << cheltuieli[i].get_suma() << " " << cheltuieli[i].get_tip() << "\n";
}

void UI::uiStergere(char comanda[]) {

	char* n;
	char* p = strtok_s(comanda, " ", &n);
	int nr = 0, id = 0;
	char* tip = NULL;
	if (strcmp(p, "stergere"))
		return;
	p = strtok_s(NULL, " ", &n);

	if (isdigit(p[0]))
		nr = convert(p);
	else
		if (strcmp(p, "id") == 0) {

			p = strtok_s(NULL, " ", &n);
			id = convert(p);
		}
		else {

			tip = new char[20];
			strcpy_s(tip, strlen(p) + 1, p);
		}

	bool r = service.delElem(id, nr, tip);
	if(tip)
		delete[] tip;

	if (r == false)
		cout << "Obietul nu a fost gasit!\n";
	else
		cout << "Stergere efectuata cu succes!\n";
}

void UI::uiModificare(char comanda[]) {

	int id = 0, nr = 0, suma = 0;
	char* tip = NULL;

	char* n;
	char* p = strtok_s(comanda, " ", &n);
	if (strcmp(p, "modificare"))
		return;

	p = strtok_s(NULL, " ", &n);
	id = convert(p);

	p = strtok_s(NULL, " ", &n);
	nr = convert(p);

	p = strtok_s(NULL, " ", &n);
	suma = convert(p);

	p = strtok_s(NULL, " ", &n);
	tip = new char[20];
	strcpy_s(tip, strlen(p) + 1, p);

	bool rez = service.updateElem(id, nr, suma, tip);
	if (rez == false)
		cout << "Nu s-a gasit id-ul!\n";
	else
		cout << "Modificare efectuata cu succes!\n";
}

void UI::uiSuma(char comanda[]) {

	char* n;
	char* p = strtok_s(comanda, " ", &n);
	if (strcmp(p, "suma"))
		return;

	p = strtok_s(NULL, " ", &n);
	char* tip = new char[20];
	strcpy_s(tip, strlen(p) + 1, p);

	int suma = service.suma(tip);
	cout << "Suma pentru tipul " << tip << " este: " << suma;
}

void UI::uiMax(char comanda[]) {

	char* n;
	char* p = strtok_s(comanda, " ", &n);
	if (strcmp(p, "max"))
		return;

	p = strtok_s(NULL, " ", &n);
	int nr = convert(p);

	Cheltuiala c = service.max(nr);
	if (c.get_id() == 0)
		cout << "Nu exista cheltuieli cu acest numar de apartament!\n";
	else
		cout << c.get_id() << " " << c.get_nr_apartament() << " " << c.get_suma() << " " << c.get_tip() << '\n';
}

void UI::uiSortare(char comanda[]) {

	Cheltuiala cheltuieli[50];
	int lung = 0;
	char* n;
	char* p = strtok_s(comanda, " ", &n);
	if (strcmp(p, "sortare"))
		return;

	p = strtok_s(NULL, " ", &n);
	char* tip = new char[20];
	strcpy_s(tip, strlen(p) + 1, p);

	service.sortare(cheltuieli, lung, tip);

	for (int i = 0; i < lung; ++i)
		cout << cheltuieli[i].get_id() << " " << cheltuieli[i].get_nr_apartament() << " " << cheltuieli[i].get_suma() << " " << cheltuieli[i].get_tip() << "\n";

}

void UI::uiFiltrare(char comanda[]) {

	Cheltuiala cheltuieli[50];
	int lung = 0;
	char* n;
	char* p = strtok_s(comanda, " ", &n);
	if (strcmp(p, "filtrare"))
		return;

	p = strtok_s(NULL, " ", &n);
	char* tip = new char[20];
	strcpy_s(tip, strlen(p) + 1, p);

	service.filtrare(cheltuieli, lung, tip);

	for (int i = 0; i < lung; ++i)
		cout << cheltuieli[i].get_id() << " " << cheltuieli[i].get_nr_apartament() << " " << cheltuieli[i].get_suma() << " " << cheltuieli[i].get_tip() << "\n";

}

void UI::undo() {

	service.undo();
	cout << "Undo efecuat!\n";
}

void UI::runUI() {

	bool run = true;
	char comanda[100];
	while (run) {

		afisareMeniu();
		cout << "Dati comanda: ";
		cin.getline(comanda, 100);
		cout << '\n';
		if (strstr(comanda, "adaugare"))
			uiAddElem(comanda);
		else
			if (strstr(comanda, "afisare"))
				uiAfisare(comanda);
			else
				if (strstr(comanda, "stergere"))
					uiStergere(comanda);
				else
					if (strstr(comanda, "modificare"))
						uiModificare(comanda);
					else
						if (strstr(comanda, "suma"))
							uiSuma(comanda);
						else
							if (strstr(comanda, "sortare"))
								uiSortare(comanda);
							else
								if (strstr(comanda, "filtrare"))
									uiFiltrare(comanda);
								else
									if (strcmp(comanda, "undo") == 0)
										undo();
									else
										if (strstr(comanda, "exit"))
											return;
										else
											cout << "Comanda invalida!";
	}

}


