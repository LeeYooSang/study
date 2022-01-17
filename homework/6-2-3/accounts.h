class Account
{	
public:
	int account_ID;
	int balance;	
};

class AccountManager
{
public:	
	int num = 0;
	Account* acc_arr = new Account[10];
	
public:
	void depositing(int ID, int amount);
	void withdrawing(int ID, int amount);
	void transferring(int ID, int ID_to, int amount);
	void checking_balances(int ID);
	void new_acc(int users);	
	~AccountManager(){delete[] acc_arr;};
};
