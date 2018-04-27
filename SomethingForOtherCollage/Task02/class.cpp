#include "class.h"

int Class::aktualnyRozmiar;
int Class::_ile = 0;
int Class::tab[rozmiar];

Class::Class() {
	_ile++;
}

Class::~Class() {
	_ile--;
}

int Class::set(int* tablica, int dlugosc) {
	if (dlugosc > rozmiar)
		return -1;
	aktualnyRozmiar = dlugosc;
	for (int i = 0; i < dlugosc; i++) {
		tab[i] = tablica[i];
	}
	return 0;
}

int Class::get(int indeks) {

	return indeks < aktualnyRozmiar ? tab[indeks] : -1;
}

int Class::ile() {
	return _ile;
}

void Class::wypisz(void) {
	for (int i = 0; i < aktualnyRozmiar; i++) {
		cout << tab[i] << ", ";
	}
	cout << endl;
}
