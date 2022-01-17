#include<iostream>
using namespace std;

typedef struct{
	string name;
	int age;
}Person;
int main(){
	int num;
	cin>>num;
	Person* arr = new Person[num];
	for(int i=0;i<num;i++){
		cin >> arr[i]. name;
		cin >> arr[i]. age;
	}
	for(int i=0; i<num; i++){
		cout<<"Name:"<<arr[i].name<<", Age:"<<arr[i].age<<endl;
	}
	delete[] arr;

	return 0;
}
