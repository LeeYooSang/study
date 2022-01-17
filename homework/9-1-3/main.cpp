#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A
{
	public:
		A(){}		
		A(int num){
			memberA = new int;
			*memberA = num;
			cout << "new memberA" << endl;
		}
		virtual ~A(){
			delete memberA;
			cout << "delete memberA" << endl;
		}
		virtual void print(){
			cout << "*memberA " <<  *memberA << endl;
		}
	private:
		int* memberA;
};

class B:public A
{
	public:	
		B(){}
		B(double num) : A(1){
			memberB = new double;
			*memberB = num;
			cout << "new memberB" << endl;
		}
		virtual ~B(){
			delete memberB;
			cout << "delete memberB" << endl;
		}
		void print(){
			A::print();
			cout << "*memberB " << *memberB << endl;
		}
	private:
		double* memberB;
};

class C:public B
{
	public:
		C(){}
		C(const string& str) : B(1.1) {
			memberC = new string;
			*memberC = str;
			cout << "new memberC" << endl;
		}
		~C(){
			delete memberC;
			cout << "delete memberC" << endl;
		}
		void print(){
			B::print();
			cout << "*memberC " << *memberC << endl;
		}
	private:
		string* memberC;
};

int main(){
	int num;
	double r_num;
	string str;
	cin >> num >> r_num >> str;
	A* a = new A(num);
	B* b = new B(r_num);
	C* c = new C(str);
	vector<A*> arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	for(int i=0;i<arr.size();i++){
		arr[i]->print();
	}
	for(int i=0; i<arr.size();i++)
		delete arr[i];
}
