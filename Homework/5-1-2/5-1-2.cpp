#include <iostream>
using namespace std;

typedef struct
{
	string name;
	double score;
} Person;

int main(int argc, char* argv[]){
	int n = argc/2;
	int k = 1;
	Person* person = new Person[n];
	for(int i=0; i<n; i++){
		person[i].name = argv[k];
		k++;
		person[i].score = atof(argv[k]);
		k++;
	}
	for(int i=0; i<n; i++){
		cout<<"Name:"<<person[i].name<<", Score:"<<person[i].score<<endl;
	}
	delete[] person;
	return 0;
}
