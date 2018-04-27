#ifndef CLASS
#define CLASS

#include <iostream>

using namespace std;

class Class {
public:
	Class(void);
	~Class(void);
	int set(int*, int);
	int get(int);
	static int ile(void);
	void wypisz(void);
private:
	const static int rozmiar = 100;
	static int aktualnyRozmiar;
	static int tab[rozmiar];
	static int _ile;

};

#endif