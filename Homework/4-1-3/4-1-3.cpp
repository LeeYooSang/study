#include <iostream>
using namespace std;

void swapInt(int& n1, int& n2){
	int tmp;
	tmp = n1;
	n1 = n2;
	n2 = tmp;
}

void swapString(string& s1, string& s2){
	string s;
	s = s1;
	s1 = s2;
	s2 = s;
}
int main (){
	int n1, n2;
	string s1, s2;
	cin>>n1>>n2;
	cin>>s1>>s2;
	cout<<"n1: "<<n1<<", n2: "<<n2<<", s1: "<<s1<<", s2: "<<s2<<endl;
	swapInt(n1,n2);
	swapString(s1, s2);
	cout<<"n1: "<<n1<<", n2: "<<n2<<", s1: "<<s1<<", s2: "<<s2<<endl;
	return 0;
}
