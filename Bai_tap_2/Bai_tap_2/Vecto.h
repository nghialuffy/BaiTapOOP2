#pragma once
#include<iostream>
using namespace std;
class Vecto
{
private:
	int Number;
	int *data;
public:
	Vecto(int = 2, int = 0);
	~Vecto();
	Vecto operator+(Vecto&);
	Vecto operator-(Vecto&);
	Vecto operator*(Vecto&);
	Vecto operator<<(int);
	Vecto operator>>(int);
	Vecto& operator=( const Vecto&);
	int& operator[](const int );
	double operator^(int);
	double mysqrt(int);
	double myfabs(double);
	friend ostream& operator<<(ostream&, Vecto&);
	friend istream& operator>>(istream&, Vecto&);
};

