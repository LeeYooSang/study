#include "my_string2.h"
using namespace std;

int main() {
	string menu;
	MyString2 mystr1, mystr2;
	string str1, str2, str3;
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
					MyString2 mul_(mystr1);
					MyString2 mul(mul_ * num);
					cout << mul;
				}
				else if (str2 == "+") {
					cin >> str3;
					MyString2 add_(mystr1);
					if (str3 == "a") {
						MyString2 add(add_ + mystr1);
						cout << add;
					}
					else if (str3 == "b") {
						MyString2 add(add_ + mystr2);
						cout << add;
					}
				}
			}
			else if (str1 == "b") {
				cin >> str2;
				if (str2 == "*") {
					cin >> num;
					MyString2 mul_(mystr2);
					MyString2 mul(mul_ * num);
					cout << mul;
				}
				else if (str2 == "+") {
					cin >> str3;
					MyString2 add_(mystr2);
					if (str3 == "a") {
						MyString2 add(add_ + mystr1);
						cout << add;
					}
					else if (str3 == "b") {
						MyString2 add(add_ + mystr2);
						cout << add;
					}
				}
			}
		}
	}
}
