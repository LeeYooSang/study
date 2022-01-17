#include "my_vector.h"

#include <string>

 

using namespace std;

int main() {

	int length;

	string fir, sec;

	char oper;

	MyVector a, b;

	while (1) {

		cin >> fir;

		if (fir == "new") {

			cin >> length;

			cout << "enter a" << endl;

			MyVector temp(length);

			a = temp;

			b = temp;

			cin >> a;

			cout << "enter b" << endl;

			cin >> b;

		}

		else {

			if (fir == "quit") {

				return 0;

			}

			cin >> oper >> sec;

			if (oper == '+') {

				if (fir == "a") {

					MyVector c;

					if (sec == "b") {

						c = a + b;

						cout << c << endl;

					}

					else if (sec == "a") {

						c = a + a;

						cout << c << endl;

					}

					else {

						int num = atoi(sec.c_str());

						c = a + num;

						cout << c << endl;

					}

				}

				else if (fir == "b") {

					MyVector c;

					if (sec == "a") {

						c = b + a;

						cout << c << endl;

					}

					else if (sec == "b") {

						c = b + b;

						cout << c << endl;

					}

					else {

						int num = atoi(sec.c_str());

						c = b + num;

						cout << c << endl;

					}

				}

			}

			if (oper == '-') {

				if (fir == "a") {

					MyVector c;

					if (sec == "b") {

						c = a - b;

						cout << c << endl;

					}

					else if (sec == "a") {

						c = a - a;

						cout << c << endl;

					}

					else {

						int num = atoi(sec.c_str());

						c = a - num;

						cout << c << endl;

					}

				}

				else if (fir == "b") {

					MyVector c;

					if (sec == "a") {

						c = b - a;

						cout << c << endl;

					}

					else if(sec == "b") {

						c = b - b;

						cout << c << endl;

					}

					else {

						int num = atoi(sec.c_str());

						c = b - num;

						cout << c << endl;

					}

				}

			}

		}

	}

	return 0;

}
