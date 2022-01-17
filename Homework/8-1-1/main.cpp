#include <iostream>
#include <string>
#include "number.h"

using namespace std;

int main(void){
	Cube cube;
	string str;
	int num;
	while(1){
		cin >> str;
		if (str == "quit")
			break;
		cin >> num;
		if(str == "number"){
			cube.setNumber(num);
			cout << "getNumber(): " << cube.getNumber() << endl;
		}
		else if( str == "square"){
			cube.setNumber(num);
			cout << "getNumber(): " << cube.getNumber() << endl;
			cout << "getSquare(): " << cube.getSquare() << endl;
		}
		else if( str == "cube"){
			cube.setNumber(num);
			cout << "getNumber(): " << cube.getNumber() << endl;
			cout << "getSquare(): " << cube.getSquare() << endl;
			cout << "getCube(): " << cube.getCube() << endl;
		}
	}
	return 0;
}
