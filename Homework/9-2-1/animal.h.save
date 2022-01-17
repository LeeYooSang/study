#pragma once
#include <string>
#include <iostream>
using namespace std;

class Animal{
	public:
		Animal(){};
		Animal(string str, int age){
			this-> age = age;
			this-> name = str;
		}
		virtual ~Animal(){};
		virtual void printInfo(){};
	protected:
		string name;
		int age;
};

class Zebra:public Animal{
	public:
		Zebra(){};
		Zebra(string str, int age, int numStripes){
			this-> age = age;
			this-> name = str;
			this-> numStripes = numStripes;
		}
		~Zebra(){};
		void printInfo();
	protected:
		int numStripes;
};

class Cat:public Animal{
	public:
		Cat(){};
		Cat(string name, int age, string favoriteToy){
			this-> age = age;
			this-> name = name;
			this-> favoriteToy = favoriteToy;
		}
		~Cat(){};
		void printInfo();
	protected:
		string favoriteToy;

};
