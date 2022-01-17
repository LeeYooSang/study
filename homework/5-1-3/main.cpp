#include <iostream>
#include "minmax.h"
using namespace std;

int main(int argc, char* argv[]){
	int* arr = new int[argc];
	int max,min;
	for(int i = 0; i < argc-1; i++){
		arr[i] = atoi(argv[i+1]);
	}
	getMinMax(&arr[0],argc-1,min,max);
	cout << "min: "<< min << endl << "max: " << max << endl;
	delete[] arr;
	return 0;
}
