#include "my_string.h"

using namespace std;

int main() {
	string menu;
	MyString mystr1, mystr2;
	string str1, str2, str3;
	MyString add, mul;
	int num;
	cin >> menu;
	if (menu == "new") {
		cout << "enter a" << endl;
		cin >> mystr1;
		cout << "enter b" << endl;
		cin >> mystr2;
		while (1) {
			cin >> str1;
			if (str1 == "quit") {
				break;
			}
			else if (str1 == "a") {
				cin >> str2;
				if (str2 == "*") {
					cin >> num;
					MyString mul_ = mystr1;
					mul = mul_ * num;
					cout << mul;
				}
				else if (str2 == "+") {
					cin >> str3;
					MyString add_ = mystr1;
					if (str3 == "a") {
						add = add_ + mystr1;
					}
					else if (str3 == "b") {
						add = add_ + mystr2;
					}
					cout << add;
				}
			}
			else if (str1 == "b") {
				cin >> str2;
				if (str2 == "*") {
					cin >> num;
					MyString mul_ = mystr2;
					mul = mul_ * num;
					cout << mul;
				}
				else if (str2 == "+") {
					cin >> str3;
					MyString add_ = mystr2;
					if (str3 == "a") {
						add = add_ + mystr1;
					}
					else if (str3 == "b") {
						add = add_ + mystr2;
					}
					cout << add;
				}
			}
		}
	}
}
