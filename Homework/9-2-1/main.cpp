#include <iostream>
#include <string>
#include <vector>
#include "animal.h"

using namespace std;

int main(){
	vector<Animal*> animal;
	char ani;
	int age, stripes;
	string name, toy;
	while(1){
		cin >> ani;
		if(ani == 'z'){
			cin >> name >>age >>stripes;
			animal.push_back(new Zebra(name, age, stripes));
		}
		else if(ani == 'c'){
			cin >> name >> age >> toy;
			animal.push_back(new Cat(name, age, toy));
		}
		else if(ani == '0')
			break;
	}
	for(int i=0; i<animal.size(); i++){
		animal[i]->printInfo();
	}
	for(int i=0; i<animal.size();i++){
		delete animal[i];
	}
	return 0;
}
