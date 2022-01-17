#include "rect.h"
#include <iostream>

using namespace std;

int Rectangle:: getArea(){
	return width_* height_;
}

int Rectangle:: getPerimeter(){
	return 2*(width_ + height_);
}

void Square::print(){
	cout << width_ << "x" << width_ << " Square"<<endl;
	cout << "Area: " << getArea() << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
}

void NonSquare::print(){
	cout << width_ << "x" << height_ << " NonSquare"<<endl;
	cout << "Area: " << getArea() << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
}
