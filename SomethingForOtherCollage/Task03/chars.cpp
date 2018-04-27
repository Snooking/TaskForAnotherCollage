#include "chars.h"

void Chars::get(){
	cout << "Podaj nazwe pliku" << endl;
	cin >> name;
	cout << "Podaj ciag do zamienienia" << endl;
	cin >> first;
	cout << "Podaj ciag zamienny" << endl;
	cin >> second;
}

void Chars::doThis(){
	get();
	fstream fileFrom;
	fileFrom.open(name, ios::in);
	if (!fileFrom.good()) return;
	fstream fileTo;
	string nameTo;
	for (int i = 0; i < name.length(); i++) {
		if (i == name.length() - 4) nameTo += "_nowy";
		nameTo += name[i];
	}
	fileTo.open(nameTo, ios::out);
	string temp;
	while (getline(fileFrom, temp)) {
		if (temp == first) {
			fileTo << second;
		}
		else {
			fileTo << temp;
		}
		fileTo << "\n";
	}
	fileFrom.close();
	fileTo.close();
}
