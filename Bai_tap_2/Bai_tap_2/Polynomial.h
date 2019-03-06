#pragma once
#include<iostream>
using namespace std;
class Polynomial
{
private:
	int number;
	int *data;
public:
	Polynomial(int = 0, int = 0);
	~Polynomial();
	Polynomial operator+(Polynomial &);
	Polynomial operator-(Polynomial &);
	Polynomial operator*(Polynomial &);
	Polynomial operator<<(int);
	Polynomial operator>>(int);
	Polynomial &operator=(Polynomial &);
	int &operator[](const int);
	int operator()(int);
	friend ostream &operator<<(ostream &, Polynomial &);
	friend istream &operator>>(istream &, Polynomial &);
};

