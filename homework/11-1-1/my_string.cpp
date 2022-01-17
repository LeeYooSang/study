#include "my_string.h"

using namespace std;

MyString& MyString::operator=(const MyString& b) {
	str = b.str;
	return *this;
}

MyString MyString::operator+(const MyString& b) {
	str += b.str;
	return *this;
}
 
MyString MyString::operator*(const int b) {
	string str_ = str;
	for (int i = 1; i < b; i++) {
		str = str + str_;
	}
	return *this;
}

ostream& operator<<(ostream& out, MyString& my_string) {
	out << my_string.str << endl;
	return out;
}
 
istream& operator>>(istream& in, MyString& my_string){
	in >> my_string.str;
	return in;
}
