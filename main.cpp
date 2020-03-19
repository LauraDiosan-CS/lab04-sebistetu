#include "cheltuiala.h"
#include "repo.h"
#include "test.h"
#include <iostream>

using namespace std;

void afisare_meniu() {

	cout << "--Cheltuiei--\n";
	cout << "1. Adaugare\n";
	cout << "2. Afisare\n";
	cout << "3. Nr de cheltuieli\n";
	cout << "0. Exit\n";
}

int main() {

	test_cheltuiala();
	test_repo();

	char op;
	Repo rep;
	int lung, l;
	Cheltuiala cheltuieli[10];
	Cheltuiala c;

	while (1) {

		afisare_meniu();
		cout << "Dati operatia: ";
		cin >> op;
		
		switch (op) {

		case '1':
			int nr;
			cout << "Dati numarul apartamentului: ";
			cin >> nr;
			c = Cheltuiala(nr);
			rep.addElem(c);
			cout << "Adaugare efectuata!\n";
			break;
		case '2':
			rep.getAll(cheltuieli, lung);
			for (int i = 0; i < lung; ++i)
				cout << cheltuieli[i].get_nr_apartament() << "\n";
			break;
		case '3':
			l = rep.get_size();
			cout << "Nr de cheltuieli este: " << l << "\n";
			break;
		case '0':
			return 0;
		default:
			cout << "Comanda invalida!";
			break;
		}
	}
}