#pragma once
#include "a.h"
#include "sha256.h"

const int SALT_SIZE = 16;
const int SYMBOLS_SIZE = 62;
const string FILE_OF_DATA_LOGIN = "login.txt";
const string FILE_OF_DATA_REGISTRATION = "registration.txt";

class Account
{
private:
	int role;
	string salt;
	string hash;
	char userName[21];

public:

	Account()
	{

	}
	~Account()
	{

	}
	void setRole(int role);	
	int getRole();	
	void setSalt(string salt);	
	string getSalt();	
	void setHash(string hash);
	string getHash();
	void setUserName(char* username);
	char* getUserName();
	int login();
	void registerme();
	void fun_acc_login();
	void fun_acc_registration();
	friend void writeFileAccounts(Account, string);
	friend void writeFileAccountsAll(Account*, int, string);
	friend void readFileAccounts(Account*, int&, string);
	friend string generateSalt(const int);
	friend string getSymbolsForSalt();
	friend int getCountOfStucturesInFile(string file_path);
	friend void showAccountRegistration(Account*, int);
	friend void delACC(Account*, int&, string);
	friend void addAcc(Account*, int&);
	friend void editACC(Account*, int&, string);
};
