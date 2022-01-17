#include <iostream>
using namespace std;

void bubblesort (int* arr, int num){
	for(int i=0; i < num-1; i++){
		for(int j=0; j < num-1; j++){
			int temp = 0;
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}	
}
int main(){
	int num;
	cin>>num;
	if(num>0){
		int* arr = new int[num];
		for(int i=0; i<num; i++){
			//cout << "num : "<<num <<endl;
			cin>>arr[i];
		}
		bubblesort(arr,num);
		for(int i=0; i<num; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		delete[] arr;
	}

	return 0;
}
