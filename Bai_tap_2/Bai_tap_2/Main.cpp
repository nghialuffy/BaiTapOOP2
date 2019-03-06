#include<iostream>
#include"Vecto.h"
#include"Matrix.h"
#include"Polynomial.h"

using namespace std;
//----Class Vecto----//
ostream &operator<<(ostream &o, Vecto &v) {
	if (v.Number > 0) {
		o << "[";
		for (int i = 0; i < v.Number - 1; i++) {
			o << *(v.data + i) << ", ";
		}
		o << *(v.data + v.Number - 1) << "]" << endl;
	}
	else
	{
		o << "[]" << endl;
	}
	return o;
}
istream &operator>>(istream &input, Vecto &v) {
	cout << "So chieu cua Vecto : ";
	input >> v.Number;
	delete[] v.data;
	v.data = new int[v.Number];
	for (int i = 0; i < v.Number; i++) {
		cout << "Nhap tu thu " << i + 1 << " la : ";
		input >> *(v.data + i);
	}
	return input;
}
//----End Class Vecto----//

//----Class Matrix----//
ostream &operator<<(ostream &o, Matrix &m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			o << *(*(m.data + i) + j) << " ";
		}
		o << endl;
	}
	return o;
}
istream &operator>> (istream &in, Matrix &m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			in >> *(*(m.data + i) + j);
		}
	}
	return in;
}
//----End Class Matrix----//

//----Polynomial----//
ostream &operator<<(ostream &o, Polynomial &p) {
	for (int i = 0; i < p.number; i++) {
		o << *(p.data + i);
		if ((p.number - i - 1) > 1)
			o << "*x^" << (p.number - i - 1) << " ";
		else
			if ((p.number - i - 1) == 1) {
				o << "x" << " ";
			}
		if (*(p.data + i) >= 0 && i < p.number - 1) {
			o << "+";
		}
	}
	o << endl;
	return o;
}
istream &operator>>(istream &in, Polynomial &p) {
	for (int i = 0; i < p.number; i++) {
		cout << "Gia tri x^" << (p.number - i - 1) << " la : ";
		in >> *(p.data + i);

	}
	return in;
}
//----End Class Polynomial----//

int main() {
//=========================//
	///*
	//----Test lop Vecto----//
	Vecto v1, v2, v3;
	//Test toan tu nhap
	cout << "Nhap toa do vecto: " << endl;
	cin >> v1;
	cout << "Nhap toa do vecto: " << endl;
	cin >> v2;
	//Test toan tu xuat
	cout << v1;
	cout << v2;
	//Test toan tu cong
	cout << "Tong 2 vecto la: " << endl;
	cout << (v1 + v2);
	//Test toan tu tru
	cout << "Hieu 2 vecto la: " << endl;
	cout << (v1 - v2);
	//Test toan tu nhan
	cout << "Tich 2 vecto la: " << endl;
	cout << (v1*v2);
	//Test toan tu =
	cout << "Vecto v3 = v1: " << endl;
	v3 = v1;
	cout << v3;
	//Test toan tu ^
	cout << "Do dai cua v1 : " << (v1 ^ 1) << endl << "Do dai cua v2 : " << (v2 ^ 1) << endl;
	//Test toan tu []
	cout << "toa do cua v1 tai vi tri 0 la: " ;
	cout << v1[0] << endl;
	//Test toan tu <<
	cout << "dich v1 sang trai 2 don vi " << endl;
	cout << (v1 << 2);
	//Test toan tu >>
	cout << "dich v2 sang phai 2 don vi " << endl;
	cout << (v2 >> 2);
	//----End Vecto----//
	//*/
//========================//
	///*
	//----Matrix----//
	Matrix m1(3,3), m2(3,3), m3;
	//Test toan tu nhap
	cout << "Nhap ma tran m1:" << endl;
	cin >> m1;
	cout << "Nhap ma tran m2:" << endl;
	cin >> m2;
	//Test toan tu xuat
	cout << "Xuat ma tran m1:" << endl;
	cout << m1;
	cout << "Xuat ma tran m1:" << endl;
	cout << m2;
	//Test toan tu cong
	cout << "Tong 2 ma tran" << endl;
	cout << (m1 + m2);
	//Test toan tu tru
	cout << "Hieu 2 ma tran" << endl;
	cout << (m1 - m2);
	//Test toan tu nhan
	cout << "Tich 2 ma tran" << endl;
	cout << (m1*m2);
	//Test toan tu =
	cout << "Ma tran m3 = m1:" << endl;
	m3 = m1;
	cout << m3;
	//Test toan tu ^
	cout << "Gia tri dinh thuc m1 : " << (m1 ^ 1) << endl << "Gia tri dinh thuc m2 : " << (m2 ^ 1) << endl;
	//Test toan tu ()
	cout << "Toa do cua m1 tai vi tri (0,0): " ;
	cout << m1(0,0) << endl;
	//Test toan tu <<
	cout << "dich m1 sang trai 4 don vi " << endl;
	cout << (m1 << 4);
	cout << "dich m2 sang trai 4 don vi " << endl;
	cout << (m2 << 4);
	//Test toan tu >>
	cout << "dich m1 sang phai 4 don vi " << endl;
	cout << (m1 >> 4);
	cout << "dich m2 sang phai 4 don vi " << endl;
	cout << (m2 >> 4);
	//----End Matrix----//
	//*/
//=============================//
	///*
	//----Polynomial----//
	Polynomial p1(5), p2(6), p3;
	//Test toan tu nhap
	cout << "Nhap da thuc p1 : " << endl;
	cin >> p1;
	cout << "Nhap da thuc p2 : " << endl;
	cin >> p2;
	//Test toan tu xuat
	cout << "Xuat da thuc p1 : " << endl;
	cout << p1;
	cout << "Xuat da thuc p2 : " << endl;
	cout << p2;
	//Test toan tu cong
	cout << "Tong 2 da thuc: " << endl;
	cout << (p1 + p2);
	//Test toan tu tru
	cout << "Hieu 2 da thuc: " << endl;
	cout << (p1 - p2);
	//Test toan tu nhan
	cout << "Tich 2 da thuc: " << endl;
	cout << (p1*p2);
	//Test toan tu =
	cout << "Da thuc p3 = p1" << endl;
	p3 = p1;
	cout << p3;
	//Test toan tu []
	cout << "Toa do tai vi tri 0" << endl;
	cout << p1[0] << endl;
	//Test toan tu ()
	cout << "Gia tri p1 voi x=0" << endl;
	cout << p1(0) << endl;
	cout << "Gia tri p2 voi x=1" << endl;
	cout << p2(1) << endl;
	//Test toan tu <<
	cout << "dich p1 sang trai 2 don vi " << endl;
	cout << (p1 << 2);
	cout << "dich p2 sang trai 2 don vi " << endl;
	cout << (p2 << 2);
	//Test toan tu >>
	cout << "dich p1 sang phai 2 don vi " << endl;
	cout << (p1 >> 2);
	cout << "dich p2 sang phai 2 don vi " << endl;
	cout << (p2 >> 2);
	//----End Matrix----//
	//*/
	system("pause");
	return 0;
}