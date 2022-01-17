#include <iostream>
#include "shapes.h"
using namespace std;

int main(){	
	while(1)
	{
		int num1, num2 ,num3, num4;
		char shape;
		cout << endl <<  "shape?" <<endl;
		cin >> shape;
		if(shape == 'C'){
			Circle circle;
			cin >> num1 >> num2 >> num3;
			circle.setXY(num1,num2,num3);
			cout << "area: " << circle.area() << ", perimeter: "<< circle.perimeter() << endl;
		}
		else if(shape == 'R'){
			Rectangle rectangle;
			cin >> num1 >> num2 >> num3 >> num4;
			rectangle.setXY(num1, num2, num3, num4);
			cout << "area: "<< rectangle.area() <<  ", perimeter: "<< rectangle.perimeter() << endl;
		}
		else if(shape == 'Q'){
			break;
		}	
	}
	return 0;
}
