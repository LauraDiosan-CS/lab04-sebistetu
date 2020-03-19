#ifndef CHELTUIALA_H
#define CHELTUIALA_H

class Cheltuiala {

private:
	int nr_apartament;
public:
	Cheltuiala();
	Cheltuiala(int nr_apartament);
	Cheltuiala(const Cheltuiala& c);
	~Cheltuiala();
	int get_nr_apartament();
	void set_nr_apartament(int nr);
	Cheltuiala& operator=(const Cheltuiala& c);
};
#endif CHELTUIALA_H
