#include "shapes.h"

void Circle::setXY(int a, int b, int c){
	x=a;
	y=b;
	radius = c;
}

float Circle::area(){
	return radius * radius * 3.14;
}

float Circle::perimeter(){
	return radius * 2 * 3.14;
}

void Rectangle::setXY(int a, int b, int c, int d){
	if(a>c){
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
	else if(c>a){
		x1 = c;
		y1 = d;
		x2 = a;
		y2 = b;
	}
}
float Rectangle::area(){
	return (x1-x2)*(y2-y1);
}
float Rectangle::perimeter(){
	return 2 * (y2-y1) + 2 * (x1 - x2); 
}

