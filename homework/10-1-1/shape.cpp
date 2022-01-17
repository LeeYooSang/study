#include "shape.h"

using namespace std;
double Rectangle::getArea() {
	return this->width_ * this->height_;
}

double Triangle::getArea() {
	return this->width_ * this->height_ / 2;
}
