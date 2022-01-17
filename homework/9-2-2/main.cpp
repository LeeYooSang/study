#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "canvas.h"

using namespace std;
int main(){
	int can_wid, can_hei, nx, ny, width, height;
	char brush;
	string menu,input_shape;
	cin >> can_wid >> can_hei;
	Canvas* canvas = new Canvas(can_wid, can_hei);
	canvas->Print();
	vector<Shape*> shape;
	while(1){
		cin >> menu;
		if(menu == "quit")
			return 0;
		else if(menu == "add"){
			cin >>input_shape;
			if(input_shape == "rect"){
				cin >> nx >> ny >> width >> height >> brush;
				shape.push_back(new Rectangle(nx, ny, width, height, brush));
			}
			else if(input_shape == "diamond"){
				cin >> nx >> ny >> width >> brush;
				shape.push_back(new Diamond(nx, ny, width, brush));
			}
			else if(input_shape == "tri_up"){
				cin >> nx >> ny >> width >> brush;
				shape.push_back(new Diamond(nx, ny, width, brush));
			}
			else if(input_shape == "tri_down"){
				cin >> nx >>ny >> width >>brush;
				shape.push_back(new DownTriangle(nx, ny, width, brush));
			}
		}
		else if(menu == "delete"){
			int a;
			cin >> a;
			if(a >= shape.size())
				continue;
			else 
				shape.erase(shape.begin()+a);
		}
		else if(menu == "dump"){
			for(int i=0; i<shape.size(); i++){
				cout << i << " ";
				shape[i]->showInfo();
			}
		}
		else if(menu == "resize"){
			int new_width, new_height;
			cin >> new_width >> new_height;
			canvas->Resize(new_width, new_height);
		}
		else if(menu == "draw"){
			for(int i=0; i<shape.size();i++){
				shape[i]->Draw(canvas);
			}
			canvas -> Print();
		}
	}
	delete canvas;
	for(int i=0; i < shape.size(); i++){
		delete shape[i];
	}
	return 0;
}
