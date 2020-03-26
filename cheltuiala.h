#ifndef CHELTUIALA_H
#define CHELTUIALA_H

class Cheltuiala {

private:
	int id;
	int nr_apartament;
	int suma;
	char* tip;
public:
	Cheltuiala();
	Cheltuiala(int id, int nr_apartament, int suma, char* tip);
	Cheltuiala(const Cheltuiala& c);
	~Cheltuiala();
	int get_id();
	int get_nr_apartament();
	int get_suma();
	char* get_tip();
	void set_nr_apartament(int nr);
	void set_suma(int suma);
	void set_tip(char* t);
	Cheltuiala& operator=(const Cheltuiala& c);
	bool operator==(const Cheltuiala& c);
};
#endif CHELTUIALA_H
