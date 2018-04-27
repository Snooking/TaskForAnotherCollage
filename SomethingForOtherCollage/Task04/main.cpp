#include "matrix.h"

int main() {
	const int columns = 5;
	const int rows = 10;
	Matrix* matrix1 = new Matrix();
	Matrix* matrix2 = new Matrix(rows, columns);
	float** temp = new float*[columns];
	for (int i = 0; i < columns; i++) {
		temp[i] = new float[rows];
		for (int j = 0; j < rows; j++) {
			temp[i][j] = i + j;
		}
	}
	Matrix* matrix3 = new Matrix(temp, rows, columns);
	Matrix* matrix4 = new Matrix(*matrix1);
	cout << "matrix1" << endl;
	matrix1->drawMatrix();
	cout << "matrix2" << endl;
	matrix2->drawMatrix();
	cout << "matrix2 rows: " << matrix2->getRows() << endl;
	cout << "matrix2 columns: " << matrix2->getColumns() << endl;
	cout << "matrix2 after random: " << endl;
	matrix2->randomizeMatrix();
	matrix2->drawMatrix();
	cout << "matrix2 after size changed: " << endl;
	matrix2->changeSize(10,10);
	matrix2->drawMatrix();
	cout << "matrix3" << endl;
	matrix3->drawMatrix();
	cout << "matrix4" << endl;
	matrix4->drawMatrix();
	for (int i = 0; i < columns; i++) {
		delete[] temp[i];
	}
	delete[] temp;
	delete matrix1;
	delete matrix2;
	delete matrix3;
	delete matrix4;
}