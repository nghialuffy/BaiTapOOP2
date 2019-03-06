#include "Vecto.h"
#include<iostream>
using namespace std;
//Ham Khoi Tao
Vecto::Vecto(int number, int Val)
{
	this->Number = number;
	this->data = new int[this->Number];
	for (int i = 0; i < this->Number; i++) {
		*(this->data + i) = Val;
	}
}
//Ham Huy
Vecto::~Vecto()
{
}
//Da nang hoa toan tu cong
Vecto Vecto::operator+( Vecto &v) {

	if (this->Number == v.Number) 
	// Neu vecto hien tai co so phan tu be hon
	{
		Vecto temp(this->Number);
		for (int i = 0; i < this->Number; i++) {
			*(temp.data + i) = *(this->data + i) + *(v.data + i);
		}
		return temp;
	}
	else {
		Vecto temp0(0, 0);
		return temp0;
	}
}
//Da nang hoa toan tu -
Vecto Vecto::operator- (Vecto &v) {
	if (this->Number == v.Number)
	{
		Vecto temp(this->Number);
		for (int i = 0; i < this->Number; i++) {
			*(temp.data + i) = *(this->data + i) - *(v.data + i);
		}
		return temp;
	}
	else
	{
		Vecto temp0(0, 0);
		return temp0;
	}
	
}
//Da nang hoa toan tu nhan
Vecto Vecto::operator* (Vecto &v) {
	if (this->Number == v.Number && this->Number > 2) {
		Vecto res(this->Number);
		*(res.data + 0) = *(this->data + this->Number - 2) * *(v.data + this->Number - 1) - *(this->data + this->Number - 1)* *(v.data + this->Number - 2);
		*(res.data + this->Number - 1) = *(this->data + 0) * *(v.data + 1) - *(this->data + 1)* *(v.data + 0);
		for (int i = 1; i < this->Number - 1; i++) {
			*(res.data + i) = -(*(this->data + i - 1)**(v.data + i + 1) - *(this->data + i + 1)**(v.data + i - 1));
		}
		return res;
	}
	else {
		Vecto res0(2, 0);
		return res0;
	}
}
//Da nang hoa toan tu <<
Vecto Vecto::operator<<(int val) {
	Vecto temp = *this;
	for (int i = 0; i < this->Number; i++) {
		if (i + val < this->Number) {
			*(temp.data + i) = *(this->data + i + val);
		}
		else
			*(temp.data + i) = 0;
	}
	return temp;
}
//Da nang hoa toan tu >>
Vecto Vecto::operator>>(int val) {
	Vecto temp = *this;
	for (int i = this->Number-1; i >= 0; i--) {
		if (i - val >= 0) {
			*(temp.data + i) = *(this->data + i - val);
		}
		else
			*(temp.data + i) = 0;

	}
	return temp;
}
//Da nang hoa toan tu bang
Vecto& Vecto::operator=(const Vecto &v) {
	this->Number = v.Number;
	delete[] this->data;
	this->data = new int[this->Number];
	for (int i = 0; i < this->Number; i++) {
		*(this->data + i) = *(v.data + i);
	}
	return *this;
}
//Da nang hoa toan tu truy cap []
int& Vecto::operator[]( const int i) {
	static int temp = 0;
	return (i >= 0 && i < this->Number) ? *(this->data + i) : temp;
}
//Da nang hoa toan tu ^
double Vecto::operator^(int i) {
	static int res = 0;
	for (int j = 0; j < this->Number; j++) {
		res += *(this->data + j)* *(this->data + j);
	}
	return (res != 0) ? mysqrt(res) : 0;
}
double Vecto::mysqrt(int x) {
	double s = 1;
	while (myfabs(s*s - x)/x >= 0.0000001) {
		s += (x / s - s) / 2;
	}
	return s;
}
double Vecto::myfabs(double x) {
	return (x > 0) ? x : -x;
}

