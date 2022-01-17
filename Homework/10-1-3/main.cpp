#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
class B
{
public:
	virtual ~B() {}
};
 
class C : public B
{
public:
	void test_C() { std::cout << "C::test_C()" << std::endl; }
};
 
class D : public B
{
public:
	void test_D() { std::cout << "D::test_D()" << std::endl; }
};
 
int main() {
	vector<B*> arr;
	string str;
	while (1) {
		cin >> str;
		if (str == "B") {
			B* b = new B;
			arr.push_back(b);
		}
		else if (str == "C") {
			C* c = new C;
			arr.push_back(c);
		}
		else if (str == "D") {
			D* d = new D;
			arr.push_back(d);
		}
		else if (str == "0") {
			for (int i = 0; i < arr.size(); i++) {
				C* pc = dynamic_cast<C*>(arr[i]);
				D* pd = dynamic_cast<D*>(arr[i]);
				if (pc)
					pc->test_C();
				else if (pd)
					pd->test_D();
			}
			break;
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		delete arr[i];
	}
}
