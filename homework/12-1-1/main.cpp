#include <iostream>
#include <string>

using namespace std;
 
template<typename T>
void myswap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
	cout << "After calling myswap(): " << a << " " << b << endl;
}
int main() {
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			int a, b;
			cin >> a >> b;
			myswap(a, b);
		}
		else if (i == 1) {
			double a, b;
			cin >> a >> b;
			myswap(a, b);
		}
		else if (i == 2) {
			string a, b;
			cin >> a >> b;
			myswap(a, b);
		}
	}
	return 0;
}
