/*
Zadanie Drugie - Cwiczenie: konstruktory, destruktory, przeladowanie operatorow, funkcje
konwertujace
*/
#include <iostream>
#include <cstring>
#include "series.h"
using namespace std;

const int BUFFERSIZE = 1024;

Series operator+(const Series& _this, const Series& other) {
	char* newSeries = new char[_this.dl() + other.dl() + 1];
	int i = 0;
	for (i = 0; i < _this.dl(); i++) {
		newSeries[i] = _this._series[i];
	}
	for (int j = i, k = 0; j < _this.dl() + other.dl() + 1; j++, k++) {
		newSeries[j] = other._series[k];
	}
	return Series(newSeries);
}

ostream& operator<<(ostream& os, const Series& other) {
	os << other._series;
	return os;
}

istream& operator >> (istream& is, Series& other) {
	char* temp = new char[BUFFERSIZE];
	is >> temp;
	int i = 0;
	while (temp[i] != '\0') {
		i++;
	}
	other._series = new char[i + 1];
	for (int j = 0; j < i; j++) {
		other._series[j] = temp[j];
	}
	other._series[i] = '\0';
	other.isSeriesUsed = true;
	return is;
}



int main() {
	Series A("_ciag_A_");
	Series B;
	B = "_ciag_B_";
	B += A;
	cout << "istnieja : " << Series::ile() << " ciagi" << endl;
	Series C;
	cout << "Podaj ciag C : ";
	cin >> C;
	Series D;
	D = A + B + "_cos_";
	cout << "istnieja : " << Series::ile() << " ciagi" << endl;
	A += "_dodaje_zwykly_ciag_";
	C += A;
	cout << A << endl << B << endl << C << endl << D << endl;
	cout << "dlugosc A " << A.dl() << endl;
	cout << "dlugosc B " << B.dl() << endl;
	cout << "dlugosc C " << C.dl() << endl;
	cout << "dlugosc D " << D.dl() << endl;
	{
		Series ZZ;
		cout << "powstal ciag lokalny i istnieja : " << Series::ile()
			<< " ciagi" << endl;
	}
	cout << "a teraz znowu sa : " << A.ile() << " ciagi" << endl;
	cout << "dziala operator konwersji i funkcja C strlen "
		<< strlen(A) << endl;
	cout << "dziala operator konwersji i funkcja C strlen "
		<< strlen(B) << endl;
	cout << "dziala operator konwersji i funkcja C strlen "
		<< strlen(C) << endl;
	cout << "dziala operator konwersji i funkcja C strlen "
		<< strlen(D) << endl;
	return 0;
}
