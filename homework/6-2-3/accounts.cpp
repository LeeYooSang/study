#include <iostream>
#include "accounts.h"

using namespace std;

void AccountManager::depositing(int ID, int amount){
	if(acc_arr[ID].balance + amount > 1000000)
	{
		cout << "Failure: Can't hold more than 1,000,000" << endl;
	}
	else 
	{
		acc_arr[ID].balance += amount;
		cout << "Success: Deposite to user "<< ID << " " << amount << endl; 
	}

}

void AccountManager::withdrawing(int ID, int amount){
	if(acc_arr[ID].balance - amount < 0)
	{
		cout << "Failure: Withdraw from user "<< ID << " " << amount << endl;
	}
	else
	{
		acc_arr[ID].balance -= amount;
		cout << "Success: Withdraw from user "<< ID << " " << amount << endl;
	}
}

void AccountManager::transferring(int ID, int ID_to, int amount){
	if(ID_to > num-1)
		cout << "Failure: Receiver does not exist"<<endl;
	else if(acc_arr[ID].balance - amount < 0)
	{
		cout << "Failure: Transfer from user " << ID <<" to user " << ID_to << " " << amount << endl;
	}
	else
	{
		if(acc_arr[ID_to].balance + amount > 1000000)
		{
			cout << "Receiver has too much money in his account"<<endl;
		}
		else{
			acc_arr[ID].balance -= amount;
			acc_arr[ID_to].balance += amount;
			cout << "Success: Transfer from user " << ID << " to user " << ID_to << " " <<amount;
		}
	}
}

void AccountManager::checking_balances(int ID){
	cout << "Balance of user " << ID <<": " << acc_arr[ID].balance << endl;}

void AccountManager::new_acc(int users){
	if(users > 10){
		cout << "Failure: Can't make any more" <<endl;
	}
	else{
		num = users;
		acc_arr[num-1].balance = 0;
		acc_arr[num-1].account_ID = num-1;
		cout << "Account for user "<<acc_arr[num-1].account_ID<< " registered" << endl;
	}
	checking_balances(num-1);
}
