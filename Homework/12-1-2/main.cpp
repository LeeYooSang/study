#include <string>

#include "my_container.h"

 

 

using namespace std;

 

int main() {

	for (int i = 0; i < 3; i++) {

		if (i == 0) {

			int num;

			cin >> num;

			MyContainer<int> mycon(num);

			cin >> mycon;

			cout << mycon << endl;

		}

		else if (i == 1) {

			int num;

			cin >> num;

			MyContainer<double> mycon(num);

			cin >> mycon;

			cout << mycon << endl;

		}

		else if (i == 2) {

			int num;

			cin >> num;

			MyContainer<string> mycon(num);

			cin >> mycon;

			cout << mycon << endl;

		}

	}
	return 0;
}
