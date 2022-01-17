#include <iostream>
#include "intset.h"

using namespace std;

int main(){
	string menu;
	int num;
	IntegerSet arr;
	while(1){
		cin >> menu;
		if( menu == "quit")
			return 0;
		cin >> num;
		if(menu == "add")
		{	
			vector<int> add;
			arr.AddNumber(num);
			add = arr.GetAll();
			for(int i = 0; i < add.size();i++){
				cout << add[i] << " ";
			}
			cout << endl;
		}
		
		else if(menu == "del")
		{
			vector<int> del;
			arr.DeleteNumber(num);
			del = arr.GetAll();
			for(int i = 0; i < del.size(); i++){
				cout << del[i] << " ";
			}
			cout << endl;
		}
		
		else if(menu == "get")
		{	
			int get;
			get = arr.GetItem(num);
			cout << get << endl;
		}
	}
}
