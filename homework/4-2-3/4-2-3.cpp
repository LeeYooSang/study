#include <iostream>
using namespace std;

void magicSquare(int** mat,int size){
	int i,j;
	i=0;
	j=(size-1)/2;
	for(int k=1; k<(size*size)+1; k++){
		mat[i][j] = k;
		if(mat[(i+size-1)%size][(j+1)%size]==0){
			i=(i+size-1)%size;
			j=(j+size+1)%size;
		}
		else{
		i=(i+1)%size;
		}
	}
}

int main(){
	int size;
	cin>>size;
	if(size>=3 && size % 2 != 0){
		int** mat = new int*[size];
		for(int i=0; i<size; i++){
			mat[i] = new int [size];
		}
		for(int i=0; i<size; i++){
			for(int j=0;j<size;j++){
				mat[i][j] = 0;
			}
		}
		magicSquare(mat, size);
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=0; i < size; i++){
			delete[] mat[i];
		}	
		delete[] mat;
	}
	return 0;
}
