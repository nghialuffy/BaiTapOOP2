#include "Matrix.h"
#include <iostream>
using namespace std;
//Ham Khoi tao
Matrix::Matrix(int row, int col, int val)
{
	this->row = row;
	this->col = col;
	this->data = new int*[this->row];
	for (int i = 0; i < this->row; i++) {
		*(this->data + i) = new int[this->col];
	}
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			*(*(this->data + i) + j) = val;
		}
	}
}
//Ham Huy
Matrix::~Matrix()
{
	/*
	for (int i = 0; i < this->row; i++) {
		delete[] *(this->data + i);
	}
	delete this->data;
	*/
}
//Da nang hoa toan tu +
Matrix Matrix::operator+( Matrix &m) {

	if ((this->col == m.col)&&(this->row == m.row)) {
		static Matrix res(this->row, this->col, 0);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				*(*(res.data + i) + j) += *(*(this->data + i) + j) + *(*(m.data + i) + j);
			}
		}
		return res;
	}
	static Matrix res0(0, 0);
	return res0;
}
//Da nang hoa toan tu -
Matrix Matrix::operator-(Matrix &m) {

	if ((this->col == m.col) && (this->row == m.row)) {
		static Matrix res(this->row, this->col);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				*(*(res.data + i) + j) = *(*(this->data + i) + j) - *(*(m.data + i) + j);
			}
		}
		return res;
	}
	static Matrix res0(0, 0);
	return res0;

}
//Da nang hoa toan tu *
Matrix Matrix::operator*(Matrix &m) {

	if ((this->col == m.row) && (this->row == m.col)) {
		static Matrix res(this->row, m.col);
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < m.col; j++) {
				*(*(res.data + i) + j) = 0;
				for (int k = 0; k < this->col; k++) {
					*(*(res.data + i) + j) += *(*(this->data + i) + k) * *(*(m.data + k) + j);
				}
			}
		}
		return res;
	}
	static Matrix res0(0, 0);
	return res0;
}
//Da nang hoa toan tu <<
Matrix Matrix::operator<<(int val) {
	Matrix temp(this->row, this->col, 0);
	int val0 = 0;
	if (val / this->col >= 1) {
		val0 = val / this->col;
		val %= this->col;
	}
	for (int i = 0; i < this->row - val0; i++) {
		for (int j = 0; j < this->col ; j++) {
			if (i + 1 + val0 < this->row) {
				if (j + val < this->col) {
					*(*(temp.data + i) + j) = *(*(this->data + i) + j + val);
				}
				else {
					*(*(temp.data + i) + j) = *(*(this->data + i + 1) + j + val - this->col);
				}
			}
			else {
				if (j + val < this->col) {
					*(*(temp.data + i) + j) = *(*(this->data + i) + j + val);
				}
				else {
					*(*(temp.data + i) + j) = 0;
				}
			}
		}
	}
	
	return temp;
}
//Da nang hoa toan tu >>
Matrix Matrix::operator>>(int val) {
	Matrix temp(this->row, this->col, 0);
	int val0 = 0;
	if (val / this->col >= 1) {
		val0 = val / this->col;
		val %= this->col;
	}
	for (int i = this->row - 1; i >= 0 + val0; i--) {
		for (int j = this->col - 1; j >= 0; j--) {
			if (i - 1 - val0 >= 0) {
				if (j - val >= 0) {
					*(*(temp.data + i) + j) = *(*(this->data + i) + j - val);
				}
				else {
					*(*(temp.data + i) + j) = *(*(this->data + i - 1) + j - val + this->col);
				}
			}
			else {
				if (j - val >= 0) {
					*(*(temp.data + i) + j) = *(*(this->data + i) + j - val);
				}
				else {
					*(*(temp.data + i) + j) = 0;
				}
			}
		}
	}

	return temp;
}
//Da nang hoa toan tu =
Matrix& Matrix::operator=(Matrix &m) {

	for (int i = 0; i < this->row; i++) {
		delete[] * (this->data + i);
	}
	delete this->data;

	this->row = m.row;
	this->col = m.col;

	this->data = new int*[this->row];
	for (int i = 0; i < this->row; i++) {
		*(this->data + i) = new int[this->col];
	}
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			*(*(this->data + i) + j) = *(*(m.data + i) + j);
		}
	}
	return *this;
}
//Da nang hoa toan tu ()
int& Matrix::operator()(int x, int y) {
	static int temp = 0;
	return ((x >= 0 && x < this->row) && (y >= 0 && y < this->col)) ? *(*(this->data + x) + y) : temp;
}
//Da nang hoa toan ^
int Matrix::operator^(int i) {
	if (this->row == this->col) {
		return this->Det(this->row);
	}
	return 0;
}
int Matrix::Det(int n) {
	int s, res = 0;
	if (n == 1) return *(*(this->data + 0) + 0);
	if (n == 2) return (*(*(this->data + 0) + 0) * *(*(this->data + 1) + 1) - *(*(this->data + 0) + 1) * *(*(this->data + 1) + 0));
	for (int k = 0; k < n; k++) {
		static Matrix temp(this->row, this->col, 0);
		for (int i = 0; i< n; i++) {
			for (int j = 1; j< n; j++) {
				if (i < k) 
					*(*(temp.data + i) + j - 1) = *(*(this->data + i) + j);
				else 
					if (i > k)
						*(*(temp.data + i - 1) + j - 1) = *(*(this->data + i) + j);
			}
		}
		(k % 2 == 0) ? (s = 1) : (s = -1);
		res += *(*(this->data + k) + 0) * s* temp.Det(n - 1);
	}
	return res;
}