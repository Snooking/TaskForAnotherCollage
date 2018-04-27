#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <time.h>

using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix& other);
	~Matrix();
	void changeSize(int, int);
	int getColumns();
	int getRows();
	void randomizeMatrix();
	void drawMatrix();
	Matrix operator+(const Matrix&other);
	Matrix& operator=(const Matrix&other);
	Matrix operator-(const Matrix&other);
	Matrix operator+();
	Matrix operator-();
	Matrix operator*(const float&other);
	Matrix operator*(const Matrix&other);
	Matrix& operator+=(const Matrix&other);
	Matrix& operator-=(const Matrix&other);
	Matrix& operator*=(const float&other);
	Matrix& operator*=(const Matrix&other);
	bool operator==(const Matrix&other);
	bool operator!=(const Matrix&other);
	friend istream& operator>>(std::istream& is, Matrix&other);
	friend ostream& operator<<(std::ostream& os, const Matrix&other);
	float* operator[](int);
	float operator()(int, int);
private:
	Matrix(float**, int, int);
	float** _matrix;
	int _rows;
	int _columns;
};


#endif