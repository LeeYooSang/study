#include <iostream>
#include "message.h"

using namespace std;

int main(){
	MessageBook mb;
	string menu, text;
	int num;
	while(1){
		cin >> menu;
		if(menu =="add"){
			cin >> num;
			getchar();
			getline(cin, text);	
			mb.AddMessage(num, text);
		}
		else if(menu == "print"){
			cin >> num;
			cout << mb.GetMessage(num) << endl;
		}
		else if(menu == "delete"){
			cin >> num;
			mb.DeleteMessage(num);
		}
		else if(menu == "list"){
			vector<int> vec;
			vec = mb.GetNumbers();
			for(int i=0;i<vec.size();i++){
				cout << vec[i] <<": "<< mb.GetMessage(vec[i]) << endl;
			}
			
		}
		else if(menu == "quit")
			return 0;
	}
	return 0;
}
