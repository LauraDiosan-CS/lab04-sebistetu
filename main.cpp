#include "cheltuiala.h"
#include "repo.h"
#include "test.h"
#include <iostream>

using namespace std;

void afisare_meniu() {

	cout << "--Cheltuiei--\n";
	cout << "1. Adaugare\n";
	cout << "2. Afisare\n";
	cout << "3. Modfifcare\n";
	cout << "4. Stergere\n";
	cout << "5. Nr de cheltuieli\n";
	cout << "0. Exit\n";
}

int main() {

	test_cheltuiala();
	test_repo();
	test_service();
	
	char op;
	Repo rep;
	int lung, l;
	int nr, suma, id;
	Cheltuiala cheltuieli[10];
	Cheltuiala c;
	char* tip = new char[100];

	while (1) {

		afisare_meniu();
		cout << "Dati operatia: ";
		cin >> op;
		
		switch (op) {

		case '1':
			cout << "Dati id-ul apartamentului: \n";
			cin >> id;

			cout << "Dati numarul apartamentului: \n";
			cin >> nr;

			cout << "Dati suma: \n";
			cin >> suma;

			cout << "Dati tipul: \n";
			cin >> tip;
			c = Cheltuiala(id, nr, suma, tip);
			rep.addElem(c);
			cout << "Adaugare efectuata!\n";
			break;
		case '2':
			rep.getAll(cheltuieli, lung);
			for (int i = 0; i < lung; ++i)
				cout << cheltuieli[i].get_id() << " " << cheltuieli[i].get_nr_apartament() << " " << cheltuieli[i].get_suma() << " " << cheltuieli[i].get_tip()<< "\n";
			break;
		case '3':
			cout << "Dati id-ul apartamentului: \n";
			cin >> id;

			cout << "Dati numarul apartamentului nou: \n";
			cin >> nr;

			cout << "Dati suma noua: \n";
			cin >> suma;

			cout << "Dati tipul nou: \n";
			cin >> tip;
			c = Cheltuiala(id, nr, suma, tip);
			cout << "Modificare efectuata!\n";
			rep.updateElem(c);
			break;
		case '4':
			cout << "Dati id-ul apartamentului pt stergere: \n";
			cin >> id;
			rep.delElem(id);
			cout << "Stergere efectuata!\n";
			break;
		case '5':
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