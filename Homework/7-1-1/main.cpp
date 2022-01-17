#include <iostream>
#include <string.h>
#include "sorted.h"

using namespace std;

int main(){
	string input;
	SortedArray arr;	
	while(1){
		cin >> input;
		if(input == "quit"){
			return 0;
		}
		else if(input == "ascend"){
			vector<int> ascend = arr.GetSortedAscending();
			for(int i=0; i < ascend.size(); i++){
				cout << ascend[i] << " ";
			}
			cout << endl;
		}
		else if(input == "descend"){
			vector<int> descend = arr.GetSortedDescending();
			for(int i =0; i < descend.size(); i++){
				cout << descend[i] << " ";
			}
			cout << endl;
		}
		else if(input == "max"){
			int max = arr.GetMax();
			cout << max << endl;
		}
		else if(input == "min"){
			int min = arr.GetMin();
			cout << min << endl;
		}
		else{
			int num = atoi(input.c_str());
			arr.AddNumber(num);
		}
	}	
	return 0;
}
