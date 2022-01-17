#include "my_vector2.h"

#include <string>

 

using namespace std;

int main() {

	int length;

	string fir, sec;

	char oper;

	cin >> fir;

	while (1) {

		if (fir == "quit")

			break;

		if (fir == "new") {

			cin >> length;

			MyVector2 a(length);

			MyVector2 b(length);

			cout << "enter a" << endl;

			cin >> a;

			cout << "enter b" << endl;

			cin >> b;

			while (1) {

				cin >> fir;

				if (fir == "quit"|| fir == "new") {

					break;

				}

				cin >> oper >> sec;

				if (oper == '+') {

					if (fir == "a") {

						if (sec == "b") {

							MyVector2 c = a + b;

							cout << c << endl;

						}

 

						else if (sec == "a") {

							MyVector2 c = a + a;

							cout << c << endl;

						}

						else {

							int num = atoi(sec.c_str());

							MyVector2 c = a + num;

							cout << c << endl;

						}

					}

					else if (fir == "b") {

						if (sec == "a") {

							MyVector2 c = b + a;

							cout << c << endl;

						}

						else if (sec == "b") {

							MyVector2 c = b + b;

							cout << c << endl;

						}

						else {

							int num = atoi(sec.c_str());

							MyVector2 c = b + num;

							cout << c << endl;

						}

					}

				}

				else if (oper == '-') {

					if (fir == "a") {

						if (sec == "b") {

							MyVector2 c = a - b;

							cout << c << endl;

						}

 

						else if (sec == "a") {

							MyVector2 c = a - a;

							cout << c << endl;

						}

						else {

							int num = atoi(sec.c_str());

							MyVector2 c = a - num;

							cout << c << endl;

						}

					}

					else if (fir == "b") {

						if (sec == "a") {

							MyVector2 c = b - a;

							cout << c << endl;

						}

						else if (sec == "b") {

							MyVector2 c = b - b;

							cout << c << endl;

						}

						else {

							int num = atoi(sec.c_str());

							MyVector2 c = b - num;

							cout << c << endl;

						}

					}

				}

			}

		}

	}

	return 0;

}
