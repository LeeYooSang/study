#include "rect.h"
#include <iostream>
#include <string>

using namespace std;

int main(void){
	string str;
	int width, height;
	while(1){
		cin >> str;
		if(str == "quit")
			return 0;

		if(str == "nonsquare"){
			cin >> width >> height;
			NonSquare ns(width, height);
			ns.print();
		}

		else if(str == "square"){
			cin >> width;
			Square sq(width);
			sq.print();
		}
	}
	return 0;
}
