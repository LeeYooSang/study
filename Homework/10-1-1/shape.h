#pragma once
class Shape{
public:
	Shape() {};
	Shape(double width, double height) {
		this->width_ = width;
		this->height_ = height;
	}
	virtual ~Shape() {};
	virtual double getArea() = 0 ;
protected:
	double width_;
	double height_;
};
 
class Triangle :public Shape {
public:
	Triangle() {};
	Triangle(double width, double height) {
		this->width_ = width;
		this->height_ = height;
	}
	~Triangle() {};
	virtual double getArea();
};
 
class Rectangle :public Shape {
public:
	Rectangle() {};
	Rectangle(double width, double height) {
		this->width_ = width;
		this->height_ = height;
	}
	virtual double getArea();
	~Rectangle() {};
};
