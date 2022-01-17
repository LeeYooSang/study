#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include "setfunc.h"
using namespace std;

int main(){
	set<int> s1;
	set<int> s2;
	string input;
	char menu;	
	while(1){
		cin >> menu;
		if(menu == '0')
			break;
		getline(cin,input,'}');
		s1 = parseSet(input);
		getline(cin,input,'{');
		string cmd = input;
		getline(cin,input,'}');
		s2 = parseSet(input);
		if(cmd == " + ")
			printSet(getIntersection(s1,s2));
		else if(cmd == " - ")
			printSet(getDifference(s1,s2));
		else if(cmd == " * ")
			printSet(getUnion(s1,s2));
	}
	return 0;
}
