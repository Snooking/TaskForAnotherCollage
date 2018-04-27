#include "matrix.h"

Matrix::Matrix() {
	_rows = 3;
	_columns = 3;
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++) {
			_matrix[i][j] = i + j;
		}
	}
}

Matrix::Matrix(float** matrix, int rows, int columns) {
	_rows = rows;
	_columns = columns;
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++)
		{
			_matrix[i][j] = matrix[i][j];
		}
	}
}

Matrix::Matrix(float** matrix, int rows, int columns, const Matrix& matrix1) {
	_rows = rows;
	_columns = columns;
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++)
		{
			if (j >= matrix1._rows || i >= matrix1._columns) _matrix[i][j] = matrix[i][j];
			else _matrix[i][j] = matrix1._matrix[i][j] + matrix[i][j];
		}
	}
}

Matrix::Matrix(int rows, int columns) {
	_rows = rows;
	_columns = columns;
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++) {
			_matrix[i][j] = (float)i + (float)j;
		}
	}
}

Matrix::Matrix(Matrix& matrix) {
	_columns = matrix._columns;
	_rows = matrix._rows;
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++) {
			_matrix[i][j] = matrix._matrix[i][j];
		}
	}
}

Matrix::~Matrix() {
	if (_matrix == nullptr) return;
	for (int i = 0; i < _columns; i++) {
		delete[] _matrix[i];
	}
	delete[] _matrix;
}

void Matrix::changeSize(int rows, int columns) {
	float**temp = new float*[columns];
	for (int i = 0; i < columns; i++) {
		temp[i] = new float[rows];
		for (int j = 0; j < rows; j++) {
			if (j >= _rows || i >= _columns) temp[i][j] = 0;
			else temp[i][j] = _matrix[i][j];
		}
	}
	for (int i = 0; i < _columns; i++) {
		delete[] _matrix[i];
	}
	delete[] _matrix;
	_rows = rows;
	_columns = columns;
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++) {
			_matrix[i][j] = temp[i][j];
		}
	}
	for (int i = 0; i < _columns; i++) {
		delete[] temp[i];
	}
	delete[] temp;
}

int Matrix::getColumns() {
	return _columns;
}

int Matrix::getRows() {
	return _rows;
}

void Matrix::randomizeMatrix() {
	srand(time(NULL));
	float number;
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < _rows; j++) {
			number = rand() % 10;
			number /= (float)10;
			_matrix[i][j] = number;
		}
	}
}

void Matrix::drawMatrix() {
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < _rows; j++) {
			cout << _matrix[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix Matrix::operator+()
{
	return *this;
}

Matrix Matrix::operator +(const Matrix& matrix)
{
	return Matrix(_matrix, _rows, _columns, matrix);
}

Matrix& Matrix::operator =(const Matrix& matrix)
{
	for (int i = 0; i < _columns; i++) {
		delete[] _matrix[i];
	}
	delete[] _matrix;
	this->_columns = matrix._columns;
	this->_rows = matrix._rows;
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++) {
			this->_matrix[i][j] = matrix._matrix[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator +=(const Matrix &matrix)
{
	for (int i = 0; i < _columns; i++)
	{
		if (i >= matrix._columns) break;
		for (int j = 0; j < _rows; j++) {
			if (j >= matrix._rows) break;
			_matrix[i][j] += matrix._matrix[i][j];
		}
	}
	return *this;
}
