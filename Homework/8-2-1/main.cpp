#include <iostream>
#include <string>
#include "shapes.h"

using namespace std;

int main(){
	int can_height, can_width;
	int x,y;
	char brush;
	string ch;
	cin >> can_height >> can_width;
	while(true){
		cin>>ch;
		if(ch == "quit")
			return 0;
		else{
			cin >> x >> y;
			if(ch == "square"){
				int sq_width;
				cin >> sq_width >> brush;
				Square sq(x, y, sq_width, brush);
				cout << "Area: " << sq.GetArea() << endl;
				cout << "perimeter: " << sq.GetPerimeter() << endl;
			       sq.Draw(can_width,can_height);	
			}
			else if(ch == "rect"){
				int rc_width, rc_height;
				cin >> rc_width >> rc_height >> brush;
				Rectangle rc(x, y, rc_width, rc_height, brush);
				cout << "Area: " << rc.GetArea() << endl;
				cout << "Perimeter: " << rc.GetPerimeter()<<endl;
				rc.Draw(can_width, can_height);
			}
			else if(ch == "diamond"){
				int dis;
				cin >> dis >> brush;
				Diamond d(x, y, dis, brush);
				cout << "Area: " << d.GetArea() << endl;
				cout << "Perimeter: " << d.GetPerimeter() << endl;
				d.Draw(can_width, can_height);
			}
		}
	}
	return 0;
}
