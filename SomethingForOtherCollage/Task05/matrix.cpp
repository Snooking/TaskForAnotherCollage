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

Matrix::Matrix(float** matrix, int rows, int columns)
	:_matrix(matrix), _rows(rows), _columns(columns) {}


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


Matrix::Matrix(const Matrix& other) :
	_rows(other._rows),
	_columns(other._columns) {
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; ++i) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; ++j)
			_matrix[i][j] = other._matrix[i][j];
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

Matrix Matrix::operator+(const Matrix& other) {
	float ** newMatrix = new float*[_columns];
	for (int i = 0; i < _columns; ++i) {
		newMatrix[i] = new float[_rows];
		for (int j = 0; j < _rows; ++j) {
			newMatrix[i][j] = other._matrix[i][j] + _matrix[i][j];
		}
	}
	return Matrix(newMatrix, _rows, _columns);
}

Matrix& Matrix::operator=(const Matrix& other) {

	for (int i = 0; i < _columns; ++i) 
		delete[] _matrix[i];
	delete[] _matrix;
	_columns = other._columns;
	_rows = other._rows;
	_matrix = new float*[_columns];
	for (int i = 0; i < _columns; ++i) {
		_matrix[i] = new float[_rows];
		for (int j = 0; j < _rows; ++j)
			_matrix[i][j] = other._matrix[i][j];
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix & other)
{
	float ** newMatrix = new float*[_columns];
	for (int i = 0; i < _columns; ++i) {
		newMatrix[i] = new float[_rows];
		for (int j = 0; j < _rows; ++j) {
			newMatrix[i][j] = _matrix[i][j] - other._matrix[i][j];
		}
	}
	return Matrix(newMatrix, _rows, _columns);
}

Matrix Matrix::operator+()
{
	float** newMatrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		newMatrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++) {
			_matrix[i][j] >= 0 ? newMatrix[i][j] = _matrix[i][j] : newMatrix[i][j] = -_matrix[i][j];
		}
	}
	return Matrix(newMatrix, _rows, _columns);
}

Matrix Matrix::operator-()
{
	float** newMatrix = new float*[_columns];
	for (int i = 0; i < _columns; i++) {
		newMatrix[i] = new float[_rows];
		for (int j = 0; j < _rows; j++) {
			newMatrix[i][j] = -_matrix[i][j];
		}
	}
	return Matrix(newMatrix, _rows, _columns);
}

Matrix Matrix::operator*(const float & other)
{
	float ** newMatrix = new float*[_columns];
	for (int i = 0; i < _columns; ++i) {
		newMatrix[i] = new float[_rows];
		for (int j = 0; j < _rows; ++j) {
			newMatrix[i][j] = other * _matrix[i][j];
		}
	}
	return Matrix(newMatrix, _rows, _columns); 
}

Matrix Matrix::operator*(const Matrix & other)
{
	if (_rows != other._columns) return *this;
	float ** newMatrix = new float*[_columns];
	for (int i = 0; i < _columns; ++i) {
		newMatrix[i] = new float[other._rows];
		for (int j = 0; j < other._rows; ++j) {
			newMatrix[i][j] = 0;
			for (int k = 0; k < _rows; k++) {
				newMatrix[i][j] += _matrix[i][k] * other._matrix[k][j];
			}
		}
	}
	return Matrix(newMatrix, _rows, _columns);
}

Matrix& Matrix::operator+=(const Matrix& other) {
	Matrix matrix = *this + other;
	*this = matrix;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
	Matrix matrix = *this - other;
	*this = matrix;
	return *this;
}

Matrix& Matrix::operator*=(const float& other) {
	Matrix matrix = *this * other;
	*this = matrix;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
	Matrix matrix = *this * other;
	*this = matrix;
	return *this;
}

bool Matrix::operator==(const Matrix & other)
{
	if (_columns != other._columns || _rows != other._rows) return false;
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < _columns; j++) {
			if (_matrix[i][j] != other._matrix[i][j]) return false;
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix & other)
{
	if (_columns != other._columns || _rows != other._rows) return true;
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < _columns; j++) {
			if (_matrix[i][j] != other._matrix[i][j]) return true;
		}
	}
	return false;
}

istream& operator >> (std::istream& is, Matrix& other)
{
	is >> other._columns;
	is >> other._rows;
	for (int i = 0; i < other._columns; i++) {
		for (int j = 0; j < other._columns; j++) {
			is >> other._matrix[i][j];
		}
	}
	return is;
}

ostream & operator<<(std::ostream & os, const Matrix & other)
{
	for (int i = 0; i < other._columns; i++) {
		for (int j = 0; j < other._columns; j++) {
			os << other._matrix[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

float* Matrix::operator[](int index)
{
	return _matrix[index];
}

float Matrix::operator()(int index1, int index2)
{
	if (index1 > _columns || index2 > _rows) return _matrix[0][0];
	return _matrix[index1][index2];
}
