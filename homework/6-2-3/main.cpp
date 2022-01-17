#include <iostream>
#include "accounts.h"

using namespace std;

int main(void){
	AccountManager am;
	int ID, ID_to, amount,users,tmp;
	users = 0;
	char job;
	cout << endl;
	while(1)
	{
		cout << endl << "Job?"<<endl;
		cin >> job;
		if(users == 0){
			if(job == 'T')
			{
				cin >> tmp >> tmp >> tmp;
				cout << "Account does not exist"<<endl;
			}
			else if(job == 'N')
			{
				users++;
				am.new_acc(users);
			}
			else if(job == 'D' || job == 'W')
			{
				cin >> tmp >> tmp;
				cout << "Account does not exist" << endl;
			}
			else if(job == 'Q') 
				break;
		}
		else 
		{
			if(job == 'N')
			{	
				users++;
				am.new_acc(users);
			}	
			else if( job =='D')
			{
				cin >> ID >> amount;
				am.depositing(ID, amount);
			}
			else if(job == 'W')
			{
				cin >> ID >> amount;
				am.withdrawing(ID, amount);
			}
			else if(job == 'T')
			{
				cin >> ID >> ID_to >> amount;
				am.transferring(ID, ID_to, amount);
			}
			else if(job == 'Q')
				break;

		}

	}
}
