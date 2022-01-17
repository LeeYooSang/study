#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

void Zebra::printInfo(){
	cout << "Zebra, Name: " << this->name << ", Age: " << this->age <<", Number of stripes: " << this->numStripes << endl;	
}

void Cat::printInfo(){
	cout << "Cat, Name: " << this->name << ", Age: " << this->age << ", Favorite toy: " << this->favoriteToy << endl; 
}
