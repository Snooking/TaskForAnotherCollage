#include "matrix.h"

int main() {
	Matrix matrix1(5, 5);
	matrix1.randomizeMatrix();
	Matrix matrix2(5, 5);
	matrix2.randomizeMatrix();
	cout.precision(3);
	cout << "First Matrix" << endl;
	matrix1.drawMatrix();
	putchar('\n');
	cout << "Second Matrix" << endl;
	matrix2.drawMatrix();
	putchar('\n');
	matrix1 = matrix1 + matrix2;
	cout << "matrix1 = matrix1 + matrix2" << endl;
	matrix1.drawMatrix();
	putchar('\n');
	matrix1 = matrix1 - matrix2;
	cout << "matrix1 = matrix1 - matrix2" << endl;
	matrix1.drawMatrix();
	putchar('\n');

	cout << "matrix3 = - matrix2" << endl;
	Matrix matrix3 = -matrix2;
	matrix3.drawMatrix();
	putchar('\n');

	cout << "matrix4 = + matrix2" << endl;
	Matrix matrix4 = +matrix2;
	matrix4.drawMatrix();
	putchar('\n');

	cout << "matrix1 = matrix1 * 2" << endl;
	matrix1 = matrix1 * 2;
	matrix1.drawMatrix();
	putchar('\n');

	cout << "matrix1 = matrix1 * matrix2" << endl;
	matrix1 = matrix1 * matrix2;
	matrix1.drawMatrix();
	putchar('\n');
	
	cout << "matrix1 += matrix2" << endl;
	matrix1 += matrix2;
	matrix1.drawMatrix();
	putchar('\n');

	cout << "matrix1 -= matrix2" << endl;
	matrix1 -= matrix2;
	matrix1.drawMatrix();
	putchar('\n');

	cout << "matrix1 *= 2" << endl;
	matrix1 *= 2;
	matrix1.drawMatrix();
	putchar('\n');

	cout << "matrix1 *= matrix2" << endl;
	matrix1 *= matrix2;
	matrix1.drawMatrix();
	putchar('\n');

	cout << "matrix1[2][1]" << endl;
	cout << matrix1[2][1] << endl;
	cout << "matrix1(1,2)" << endl;
	cout << matrix1(1, 2) << endl;

	if (matrix1 == matrix2) cout << "matrix1 jest rowne matrix2" << endl;
	else cout << "matrix1 nie jest rowne matrix2" << endl;

	if (matrix1 != matrix2) cout << "matrix1 jest rozne od matrix2" << endl;
	else cout << "matrix1 nie jest rozne od matrix2" << endl;
	putchar('\n');

	cin >> matrix1;

	cout << "Matrix 1, po wprowadzeniu" << endl;

	cout << matrix1;


	getchar();
	getchar();
	return 0;
}