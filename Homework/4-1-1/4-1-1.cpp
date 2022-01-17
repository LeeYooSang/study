#include <iostream>
using namespace std;

int main(){
	int num;
	cin>>num;
	int *arr = new int[num];
        for(int i=0;i<num;i++){
		arr[i] = i;
		cout<<arr[i]<<" ";
	}
	cout<<endl;	
	delete[] arr;
	return 0;
}
