#include "class.h"

int main() {
	int size = 5;
	int* tab = new int[size];
	for (int i = 0; i < size; i++) {
		tab[i] = i;
	}
	Class* klasa1 = new Class();
	klasa1->set(tab, size);
	cout << "klasa1->wypisz();" << endl;
	klasa1->wypisz();
	Class* klasa2 = new Class();
	cout << "klasa2->wypisz();" << endl;
	klasa2->wypisz();
	cout << "klasa2->get(size - 2);" << endl;
	cout << klasa2->get(size - 2) << endl;
	cout << "klasa2->get(size + 2);" << endl;
	cout << klasa2->get(size + 2) << endl;
	cout << "klasa2->ile();" << endl;
	cout << klasa2->ile() << endl;
	cout << "klasa1->ile();" << endl;
	cout << klasa1->ile() << endl;
	delete klasa2;
	cout << "klasa1->ile();" << endl;
	cout << klasa1->ile() << endl;
	return 0;
}