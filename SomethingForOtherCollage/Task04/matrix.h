#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <time.h>

using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(float**, int, int);
	Matrix(float**, int, int, const Matrix&);
	Matrix(int, int);
	Matrix(Matrix&);
	~Matrix();
	void changeSize(int, int);
	int getColumns();
	int getRows();
	void randomizeMatrix();
	void drawMatrix();

	Matrix operator +();
	Matrix operator +(const Matrix&);
	Matrix& operator =(const Matrix&);
	Matrix& operator +=(const Matrix&);
private:	
	float** _matrix;
	int _rows;
	int _columns;
};

#endif