#include <iostream>
#include <vector>

using namespace std;
class A{
	public:
		virtual string test(){
			return "A::test()";
		}
};

class B:public A{
	public:
		 string test(){
			return "B::test()";
		}
};

class C:public B{
	public:
		string test(){
			return "C::test()";
		}
};

int main(){
	A* a = new A;
	B* b = new B;
	C* c = new C;
	vector<A*> arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	for(int i=0;i<arr.size();i++)
		cout << arr[i]->test() << endl;
	for(int i=0;i<arr.size();i++)
		delete arr[i];
}
