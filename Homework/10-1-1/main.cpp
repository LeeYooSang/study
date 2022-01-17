#include <iostream>
#include <vector>
#include "shape.h"

using namespace std;
int main() {
	vector<Shape*> arr;
	char shape_;
	double width, height;
	while (1) {
		cin >> shape_;
		if (shape_ == 'r') {
			cin >> width >> height;
			Rectangle* rec = new Rectangle(width, height);
			arr.push_back(rec);
		}
		else if (shape_ == 't') {
			cin >> width >> height;
			Triangle* tri = new Triangle(width, height);
			arr.push_back(tri);
		}
		else if (shape_ == '0') {
			for (int i = 0; i < arr.size(); i++) {
				cout << arr[i]->getArea() << endl;
			}
			break;
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		delete arr[i];
	}
	return 0;
}
