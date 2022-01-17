#include <iostream>
using namespace std;

int main(){
	int arr_num, max, min;

	cin>>arr_num;
	int *arr = new int[arr_num];
	for(int i=0;i<arr_num;i++){
		cin>>arr[i];
		min = max = arr[0];
	}
	for(int i=0;i<arr_num;i++){
		if(arr[i]>max){
                        max = arr[i];
                }
                else if(arr[i]<min){
                        min = arr[i];
                }

	}
	cout<<"min: "<<min<<endl;
	cout<<"max: "<<max<<endl;

	delete[] arr;
	return 0;
}
