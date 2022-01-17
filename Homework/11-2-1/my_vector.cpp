#include "my_vector.h"
using namespace std;
MyVector::MyVector() {
	length = 0;
	a = nullptr;
}

MyVector::MyVector(int max_num) {
	this->length = max_num;
	a = new double[max_num];
}

MyVector::~MyVector() {
	if (a != nullptr) delete[] a;
}

MyVector& MyVector::operator=(const MyVector& b) {
	if (a != nullptr) delete[] a;
	this->length = b.length;
	this->a = new double[length];
	for (int i = 0; i < this->length; i++) {
		this->a[i] = b.a[i];
	}
	return *this;
}

MyVector MyVector::operator+(const MyVector& b) {
	MyVector temp(this->length);
	for (int i = 0; i < temp.length; i++) {
		temp.a[i] = this->a[i] + b.a[i];
	}
	return temp;
}

MyVector MyVector::operator-(const MyVector& b) {
	MyVector temp(this->length);
	for (int i = 0; i < temp.length; i++) {
		temp.a[i] = this->a[i] - b.a[i];
	}
	return temp;
}

MyVector MyVector::operator+(const int b) {
	MyVector temp(this->length);
	for (int i = 0; i < temp.length; i++) {
		temp.a[i] = this->a[i] + b;
	}
	return temp;
}

MyVector MyVector::operator-(const int b) {
	MyVector temp(this->length);
	for (int i = 0; i < temp.length; i++) {
		temp.a[i] = this->a[i] - b;
	}
	return temp;
}

ostream& operator<<(ostream& out, MyVector& b) {
	for (int i = 0; i < b.length; i++) {
		out << b.a[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, MyVector& b) {
	for (int i = 0; i < b.length; i++) {
		in >> b.a[i];
	}
	return in;
}
