#include "Polynomial.h"
//Ham Khoi tao
Polynomial::Polynomial(int number, int val)
{
	this->number = number;
	this->data = new int[this->number];
	for (int i = 0; i < this->number; i++) {
		*(this->data + i) = val;
	}
}
//Ham huy
Polynomial::~Polynomial()
{/*
	delete[] this->data;
*/
}
//Da nang hoa toan tu +
Polynomial Polynomial::operator+(Polynomial &p) {
	if (this->number == p.number) {
		static Polynomial temp(this->number);
		for (int i = 0; i < p.number; i++) {
			*(temp.data + i) = *(this->data + i) + *(p.data + i);
		}
		return temp;
	}
	if (this->number > p.number) {
		Polynomial temp(this->number);
		for (int i = this->number - 1; i >= this->number - p.number; i--) {
			*(temp.data + i) = *(this->data + i) + *(p.data + i - this->number + p.number);
		}
		for (int i = this->number - p.number  - 1; i >= 0; i--) {
			*(temp.data + i) = *(this->data + i);
		}
		return temp;
	}
	else {
		Polynomial temp(p.number);
		for (int i = p.number - 1; i >= p.number - this->number; i--) {
			*(temp.data + i) = *(p.data + i) + *(this->data + i - p.number + this->number);
		}
		for (int i = p.number - this->number - 1; i >= 0; i--) {
			*(temp.data + i) = *(p.data + i);
		}
		return temp;
	}
}
//Da nang hoa toan tu -
Polynomial Polynomial::operator-(Polynomial &p) {
	if (this->number == p.number) {
		static Polynomial temp(this->number);
		for (int i = 0; i < p.number; i++) {
			*(temp.data + i) = *(this->data + i) - *(p.data + i);
		}
		return temp;
	}
	if (this->number > p.number) {
		Polynomial temp(this->number);
		for (int i = this->number - 1; i >= this->number - p.number; i--) {
			*(temp.data + i) = *(this->data + i) - *(p.data + i - this->number + p.number);
		}
		for (int i = this->number - p.number - 1; i >= 0; i--) {
			*(temp.data + i) = *(this->data + i);
		}
		return temp;
	}
	else {
		Polynomial temp(p.number);
		for (int i = p.number - 1; i >= p.number - this->number; i--) {
			*(temp.data + i) = *(p.data + i) - *(this->data + i - p.number + this->number);
		}
		for (int i = p.number - this->number - 1; i >= 0; i--) {
			*(temp.data + i) = 0 - *(p.data + i);
		}
		return temp;
	}
}
//Da nang hoa toan tu *
Polynomial Polynomial::operator*(Polynomial &p) {

	Polynomial temp((this->number) + (p.number) - 1);
	for (int i = 0; i < this->number; i++) {
		for (int j = 0; j < p.number; j++) {
			*(temp.data + (this->number - i - 1) + (p.number - j - 1)) += *(this->data + i) * *(p.data + j);
		}
	}
	return temp;
}
//Da nang hoa toan tu <<
Polynomial Polynomial::operator<<(int val) {
	Polynomial temp = *this;
	for (int i = 0; i < this->number; i++) {
		if (i + val < this->number) {
			*(temp.data + i) = *(this->data + i + val);
		}
		else
			*(temp.data + i) = 0;
	}
	return temp;
}
//Da nang hoa toan tu >>
Polynomial Polynomial::operator>>(int val) {
	Polynomial temp = *this;
	for (int i = this->number - 1; i >= 0; i--) {
		if (i - val >= 0) {
			*(temp.data + i) = *(this->data + i - val);
		}
		else
			*(temp.data + i) = 0;

	}
	return temp;
}
//Da nang hoa toan tu =
Polynomial &Polynomial::operator=(Polynomial &p) {
	this->number = p.number;
	delete[] this->data;
	this->data = new int[this->number];
	for (int i = 0; i < this->number; i++) {
		*(this->data + i) = *(p.data + i);
	}
	return *this;
}
//Da nang hoa toan tu ()
int Polynomial::operator()(int x) {
	if (this->number == 1) {
		return *(this->data + 0);
	}
	else if (this->number > 1) {
		int x0 = x;
		static int res = *(this->data + this->number - 1);
		for (int i = this->number - 2; i >= 0; i--) {
			res += *(this->data + i)*x0;
			x0 *= x;
		}
		return res;
	}
	return 0;
}
//Da nang hoa toan tu []
int& Polynomial::operator[](const int i) {
	static int temp = 0;
	return (i >= 0 && i < this->number) ? (*(this->data + this->number - i - 1)) : temp;
}
