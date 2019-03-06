#pragma once
#include <iostream>
using namespace std;
class Matrix
{
private:
	int row, col;
	int **data;
public:
	Matrix(int = 0,int =0, int =0);
	~Matrix();
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);
	Matrix operator<<(int);
	Matrix operator>>(int);
	Matrix& operator=(Matrix&);
	int& operator()(int, int);
	int operator^(int);
	int Det(int n);
	friend ostream &operator<<(ostream &, Matrix &);
	friend istream &operator>>(istream &, Matrix &);
};

