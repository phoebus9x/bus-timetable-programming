#include "account.h"
#include "sha256.h"

void delete_char(char str[], int n)
{
	for (size_t i = n + 1; i < strlen(str); i++)
	{
		str[i - 1] = str[i];
	}
	str[strlen(str) - 1] = '\0';
}
void Account::setRole(int role)
{
	this->role = role;
}
int Account::getRole()
{
	return this->role;
}
void Account::setSalt(string salt)
{
	this->salt = salt;
}
string Account::getSalt()
{
	return this->salt;
}
void Account::setHash(string hash)
{
	this->hash = hash;
}
string Account::getHash()
{
	return this->hash;
}
void Account::setUserName(char* username)
{
	strcpy_s(this->userName, strlen(username) + 1, username);
}
char* Account::getUserName()
{
	return this->userName;
}

void writeFileAccounts(Account a, string FILE_OF_DATA)
{
	ofstream fout(FILE_OF_DATA, ios::app);
	fout << a.userName << " " << a.salt << " " << a.hash << " " << a.role << endl;
	fout.close();
}

void writeFileAccountsAll(Account* a, int n, string FILE_OF_DATA)
{
	ofstream fout(FILE_OF_DATA, ios::out);
	for (int i = 0; i < n; i++)
	{
		fout << a[i].userName << " " << a[i].salt << " " << a[i].hash << " " << a[i].role << endl;
	}
	fout.close();
}

void readFileAccounts(Account* arr_of_accounts, int& number_of_accounts, string FILE_OF_DATA)
{
	ifstream fin(FILE_OF_DATA, ios::in);
	if (!fin.is_open()) cout << "The specified file does not exist!" << endl;
	else
	{
		while (!fin.eof())
		{
			for (size_t i = 0; i < number_of_accounts; i++)
			{
				fin >> arr_of_accounts[i].userName
					>> arr_of_accounts[i].salt
					>> arr_of_accounts[i].hash
					>> arr_of_accounts[i].role;
			}
			break;
		}
	}
	fin.close();
}

string getSymbolsForSalt()
{
	string symbols;
	symbols.reserve(SYMBOLS_SIZE);

	char little_letter = 'a';
	char big_letter = 'A';
	char number = '0';
	int i = 0;
	for (int k = 0; k < 26; k++)
	{
		symbols.push_back(little_letter++);
		symbols.push_back(big_letter++);
		if (k < 10) symbols.push_back(number++);
	}

	return symbols;
}

string generateSalt(int salt_size)
{
	string symbols = getSymbolsForSalt();
	cout << symbols << endl;

	srand(time(NULL));

	string salt;
	salt.reserve(salt_size);

	for (int i = 0; i < salt_size; i++)
	{
		salt.push_back(symbols[rand() % SYMBOLS_SIZE]);
	}

	return salt;
}

int getCountOfStucturesInFile(string file_path)
{
	ifstream file(file_path, ios::in);
	int number_of_strings = 0;
	if (file.is_open())
	{
		string buffer;
		while (getline(file, buffer))
			number_of_strings++;
	}
	file.close();
	return number_of_strings;
}

int Account::login()
{
	int LOGIN;
	int number_of_accounts_login;
	number_of_accounts_login = getCountOfStucturesInFile(FILE_OF_DATA_LOGIN);
	Account* arr_of_accounts_login = new Account[number_of_accounts_login];
	readFileAccounts(arr_of_accounts_login, number_of_accounts_login, FILE_OF_DATA_LOGIN);
	Account login;
	int loginAttempt = 0;
	bool flag_exit = false;
	do
	{
		system("cls");
		cout << "\t\t==============================================" << endl;
		cout << "\t\t|                   LOGIN                    |" << endl;
		cout << "\t\t==============================================" << endl << endl;
		cout << "\tPlease enter your user name: ";
		char userName[21];
		cin >> userName;
		login.setUserName(userName);
		char pass[11] = "";
		cout << "\tPlease enter the password: ";
		while (true)
		{
			char c = getch();
			if (c == 13 || c == 27)
			{
				if (strlen(pass) > 6)
				{
					break;
				}
			}
			else if (c == 8)
			{
				if (strlen(pass) > 0)
				{
					cout << "\b \b";
					delete_char(pass, strlen(pass) - 1);
				}
			}
			else
			{
				if (strlen(pass) < 10)
				{
					cout << "*";
					pass[strlen(pass)] = c;
					pass[strlen(pass)] = '\0';
				}
			}
		}
		string salt_login;
		for (size_t i = 0; i < number_of_accounts_login; i++)
		{
			if (strcmp(login.getUserName(), arr_of_accounts_login[i].getUserName()) == 0)
			{
				salt_login = arr_of_accounts_login[i].getSalt();
				string hash_pass_with_salt = sha256(pass + salt_login);
				if (hash_pass_with_salt == arr_of_accounts_login[i].getHash())
				{
					cout << "\n\t\t======================================" << endl;
					cout << "\t\t|            WELCOME!!!              |" << endl;
					cout << "\t\t======================================" << endl;
					system("pause");
					flag_exit = true;
					if (arr_of_accounts_login[i].getRole() == 1) return LOGIN = 1;
					else return LOGIN = 2;
				}
			}
		}
		if (flag_exit == false)
		{
			cout << "\n\tInvalid login attempt. Please try again.\n" << '\n';
			system("pause");
			loginAttempt++;
		}
		if (loginAttempt == 4)
		{
			cout << "\n\t!!! You entered incorrectly four times. Please try again later !!!" << endl << endl;
			cout << "\t\t================================" << endl;
			cout << "\t\t|   Thank you for logging in.  |" << endl;
			cout << "\t\t================================" << endl;
			system("pause");
		}
	} while (flag_exit != true && loginAttempt != 4);
	delete[]arr_of_accounts_login;
}

void Account::registerme()
{
	int number_of_accounts_login;
	number_of_accounts_login = getCountOfStucturesInFile(FILE_OF_DATA_LOGIN);
	Account* arr_of_accounts_login = new Account[number_of_accounts_login];
	readFileAccounts(arr_of_accounts_login, number_of_accounts_login, FILE_OF_DATA_LOGIN);

	int number_of_accounts_registration;
	number_of_accounts_registration = getCountOfStucturesInFile(FILE_OF_DATA_REGISTRATION);
	Account* arr_of_accounts_registration = new Account[number_of_accounts_registration];
	readFileAccounts(arr_of_accounts_registration, number_of_accounts_registration, FILE_OF_DATA_REGISTRATION);

	int confirmation;
	Account registration;
	bool ab1 = false;
	do
	{
		system("cls");
		cout << "\t\t==============================================" << endl;
		cout << "\t\t|                REGISTRATION                |" << endl;
		cout << "\t\t==============================================" << endl;
		cout << "\tPlease enter your username: ";
		char username[21];
		cin >> username;
		registration.setUserName(username);
		cout << "\tUsername - \"" << registration.getUserName() << "\"\n\tConfirm? \n\t[0] Exit \n\t[1] Yes\n\t[2] No\n\t";
		cin >> confirmation;
		switch (confirmation)
		{
		case 0:
			ab1 = true;
			break;
		case 1:
		{
			for (size_t i = 0; i < number_of_accounts_login; i++)
			{
				if (strcmp(registration.getUserName(), arr_of_accounts_login[i].getUserName()) == 0)
				{
					cout << "\t\t====================================================" << endl;
					cout << "\t\t|     USERNAME IS EXISTED. PLEASE RE-ENTER !!!     |" << endl;
					cout << "\t\t====================================================" << endl;
					system("pause");
					delete[]arr_of_accounts_login;
					delete[]arr_of_accounts_registration;
					registerme();
				}
			}
			for (size_t i = 0; i < number_of_accounts_registration; i++)
			{
				if (strcmp(registration.getUserName(), arr_of_accounts_registration[i].getUserName()) == 0)
				{
					cout << "\t\t====================================================" << endl;
					cout << "\t\t|     USERNAME IS EXISTED. PLEASE RE-ENTER !!!     |" << endl;
					cout << "\t\t====================================================" << endl;
					system("pause");
					delete[]arr_of_accounts_login;
					delete[]arr_of_accounts_registration;
					registerme();
				}
			}
			bool abc1 = true;
			int abc2 = 0;
			do
			{
				system("cls");
				char password1[11] = "";
				cout << "\tPlease enter the password (7-10 character): ";
				while (true)
				{
					char c = getch();
					if (c == 13 || c == 27)
					{
						if (strlen(password1) > 6)
						{
							break;
						}
					}
					else if (c == 8)
					{
						if (strlen(password1) > 0)
						{
							cout << "\b \b";
							delete_char(password1, strlen(password1) - 1);
						}
					}
					else
					{
						if (strlen(password1) < 10)
						{
							cout << "*";
							password1[strlen(password1)] = c;
							password1[strlen(password1)] = '\0';
						}
					}
				}

				char password2[11] = "";
				cout << "\n\tPlease renter your password (7-10 character): ";
				while (true)
				{
					char c = getch();
					if (c == 13 || c == 27)
					{
						if (strlen(password2) > 6)
						{
							break;
						}
					}
					else if (c == 8)
					{
						if (strlen(password2) > 0)
						{
							cout << "\b \b";
							delete_char(password2, strlen(password2) - 1);
						}
					}
					else
					{
						if (strlen(password2) < 10)
						{
							cout << "*";
							password2[strlen(password2)] = c;
							password2[strlen(password2)] = '\0';
						}
					}
				}
				cout << endl;
				if (strcmp(password1, password2) == 0)
				{
					int role_registration;
					string salt_registration = generateSalt(SALT_SIZE);
					string hash_pass_with_salt_registration = sha256(password1 + salt_registration);
					registration.setSalt(salt_registration);
					registration.setHash(hash_pass_with_salt_registration);
					system("cls");
					cout << "\tENTER ROLE -\n\t[1] admin \n\t[2] user\n\t";
					cin >> role_registration;
					if (role_registration == 1)
						registration.setRole(1);
					else
						registration.setRole(2);
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "\t\t================================================================" << endl;
					cout << "\t\t|       Sign up successfully. please wait for moderation       |" << endl;
					cout << "\t\t================================================================" << endl;
					abc1 = false;
					ab1 = true;
					writeFileAccounts(registration, FILE_OF_DATA_REGISTRATION);
					system("pause");

				}
				else
				{
					cout << "\n\tSorry invalid!!!" << endl;
					system("pause");
					abc2++;
				}
				if (abc2 == 3)
				{
					cout << "\t\t=============================================================================" << endl;
					cout << "\t\t|   You input wrong password three times. Please sign up one more time!!!   |" << endl;
					cout << "\t\t=============================================================================" << endl;
					system("pause");
				}
			} while (abc1 != false && abc2 != 3);
			break;
		}
		default:
		{
			cin.clear();
			cin.ignore(10000, '\n');
			delete[]arr_of_accounts_login;
			delete[]arr_of_accounts_registration;
			registerme();
		}
		}
	} while (ab1 != true);
}

void Account::fun_acc_registration()
{
	int number_of_accounts_registration;
	number_of_accounts_registration = getCountOfStucturesInFile(FILE_OF_DATA_REGISTRATION);
	Account* arr_of_accounts_registration = new Account[number_of_accounts_registration];
	readFileAccounts(arr_of_accounts_registration, number_of_accounts_registration, FILE_OF_DATA_REGISTRATION);
	int item_1;
	bool flag_exitACC = true;
	do
	{
		system("cls");
		cout << "\t============ MENU ACC REGISTRATION =============\n";
		cout << "\t| 0. EXIT                                      |\n";
		cout << "\t| 1. VIEW INFORMATION ACC                      |\n";
		cout << "\t| 2. DELETE ACC                                |\n";
		cout << "\t| 3. ADD ACC                                   |\n";
		cout << "\t================================================\n";
		cout << "\n\t ENTER YOUR CHOICE: ";
		cin >> item_1;
		switch (item_1)
		{
		case 0:
			flag_exitACC = false;
			break;
		case 1:
			system("cls");
			showAccountRegistration(arr_of_accounts_registration, number_of_accounts_registration);
			system("pause");
			break;
		case 2:
			system("cls");
			showAccountRegistration(arr_of_accounts_registration, number_of_accounts_registration);
			delACC(arr_of_accounts_registration, number_of_accounts_registration, FILE_OF_DATA_REGISTRATION);
			system("pause");
			break;
		case 3:
			system("cls");
			showAccountRegistration(arr_of_accounts_registration, number_of_accounts_registration);
			addAcc(arr_of_accounts_registration, number_of_accounts_registration);
			system("pause");
			break;
		default:
			cout << "\t\t=============================================" << endl;
			cout << "\t\t|        RE-ENTER YOUR SELECTION!!!         |" << endl;
			cout << "\t\t=============================================" << endl << endl;
			system("pause");
			break;
		}
	} while (flag_exitACC != false);
	delete[]arr_of_accounts_registration;
}

void Account::fun_acc_login()
{
	int number_of_accounts_login;
	number_of_accounts_login = getCountOfStucturesInFile(FILE_OF_DATA_LOGIN);
	Account* arr_of_accounts_login = new Account[number_of_accounts_login];
	readFileAccounts(arr_of_accounts_login, number_of_accounts_login, FILE_OF_DATA_LOGIN);
	int item_0;
	bool flag_exitACC_0 = true;
	do
	{
		system("cls");
		cout << "\t=============== MENU ACC LOGIN =================\n";
		cout << "\t| 0. EXIT                                      |\n";
		cout << "\t| 1. VIEW INFORMATION ACC                      |\n";
		cout << "\t| 2. DELETE ACC                                |\n";
		cout << "\t| 3. EDIT ACC                                  |\n";
		cout << "\t================================================\n";
		cout << "\n\t ENTER YOUR CHOICE: ";
		cin >> item_0;
		switch (item_0)
		{
		case 0:
			flag_exitACC_0 = false;
			break;
		case 1:
			system("cls");
			showAccountRegistration(arr_of_accounts_login, number_of_accounts_login);
			system("pause");
			break;
		case 2:
			system("cls");
			showAccountRegistration(arr_of_accounts_login, number_of_accounts_login);
			delACC(arr_of_accounts_login, number_of_accounts_login, FILE_OF_DATA_LOGIN);
			system("pause");
			break;
		case 3:
			system("cls");
			showAccountRegistration(arr_of_accounts_login, number_of_accounts_login);
			editACC(arr_of_accounts_login, number_of_accounts_login, FILE_OF_DATA_LOGIN);
			system("pause");
			break;
		default:
			cout << "\t\t=============================================" << endl;
			cout << "\t\t|        RE-ENTER YOUR SELECTION!!!         |" << endl;
			cout << "\t\t=============================================" << endl << endl;
			system("pause");
			break;
		}
	} while (flag_exitACC_0 != false);
	delete[]arr_of_accounts_login;
}

void showAccountRegistration(Account* arr_of_accounts, int number_of_accounts)
{
	cout << "\t+----+---------------------+--------+\n";
	cout << "\t| ID |      Username       |  role  |\n";
	cout << "\t+----+---------------------+--------+\n";
	for (size_t i = 0; i < number_of_accounts; i++)
	{
		if (arr_of_accounts[i].getRole() == 1)
		{
			cout << "\t|" << setw(3) << i + 1 << " |" << setw(20) << arr_of_accounts[i].getUserName() << " | admin  |" << endl;
			cout << "\t+----+---------------------+--------+\n";
		}
		else
		{
			cout << "\t|" << setw(3) << i + 1 << " |" << setw(20) << arr_of_accounts[i].getUserName() << " |  user  |" << endl;
			cout << "\t+----+---------------------+--------+\n";
		}
	}
}

void delACC(Account* arr_of_accounts, int& number_of_accounts, string FILE_OF_DATA)
{
	int acc, chosse;
	cout << "\n\tInput account of index which you want to delete: ";
	cin >> acc;
	acc--;
	cout << "\tConfirm? \n\t[1] Yes\n\t[2] No\n\t";
	cin >> chosse;
	if (chosse == 1)
	{
		if (acc >= 1 && acc < number_of_accounts)
		{
			for (size_t i = acc; i < number_of_accounts - 1; i++)
			{
				arr_of_accounts[i] = arr_of_accounts[i + 1];
			}
			number_of_accounts--;
			cout << "\tAccount of index " << acc + 1 << " that is deleted out of by list!!!" << endl;
		}
		else cout << "\tSorry invalid input, Please try again!!! " << endl;
	}
	else
	{
		cout << "\t\t==========================" << endl;
		cout << "\t\t|        EXIT!!!         |" << endl;
		cout << "\t\t==========================" << endl;
	}
	writeFileAccountsAll(arr_of_accounts, number_of_accounts, FILE_OF_DATA);
}

void addAcc(Account* arr_of_accounts_registration, int& number_of_accounts_registration)
{
	int chosse, acc;
	cout << "\n\tInput index of account that is inserted to list: ";
	cin >> acc;
	acc--;
	cout << "\tConfirm? \n\t[1] Yes\n\t[2] No\n\t";
	cin >> chosse;
	if (chosse == 1)
	{
		if (acc >= 1 && acc < number_of_accounts_registration)
		{
			writeFileAccounts(arr_of_accounts_registration[acc], FILE_OF_DATA_LOGIN);
			for (size_t i = acc; i < number_of_accounts_registration - 1; i++)
			{
				arr_of_accounts_registration[i] = arr_of_accounts_registration[i + 1];
			}
			number_of_accounts_registration--;
			cout << "\tIndex of account  " << acc + 1 << " which admin is inserted into list!!!" << endl;
		}
		else cout << "\tSorry invalid input, Please try again !!!" << endl;
	}
	else
	{
		cout << "\t\t==========================" << endl;
		cout << "\t\t|        EXIT!!!         |" << endl;
		cout << "\t\t==========================" << endl;
	}
	writeFileAccountsAll(arr_of_accounts_registration, number_of_accounts_registration, FILE_OF_DATA_REGISTRATION);
}

void editACC(Account* arr_of_accounts, int& number_of_accounts, string FILE_OF_DATA)
{
	int chosse, acc, chosse1;
	cout << "\n\tInput index of account that need edit: ";
	cin >> acc;
	acc--;
	cout << "\tConfirm? \n\t[1] Yes\n\t[2] No\n\t";
	cin >> chosse;
	if (chosse == 1)
	{
		if (acc >= 1 && acc < number_of_accounts)
		{
			cout << "\n\tThese account has been role of ";
			if (arr_of_accounts[acc].getRole() == 1) cout << "admin.\n";
			else cout << "user.\n";
			cout << "\tWhat role of account which you want to change: \n\t[1] ADMIN\n\t[2] USER\n\t";
			cin >> chosse1;
			if (chosse1 == 1)
			{
				arr_of_accounts[acc].setRole(1);
			}
			else
			{
				arr_of_accounts[acc].setRole(2);
			}
			cout << "\n\t\t============================" << endl;
			cout << "\t\t|        success!!!        |" << endl;
			cout << "\t\t============================" << endl;
		}
		else cout << "\tSorry invalid input, Please try again !!!" << endl;
	}
	else
	{
		cout << "\t\t==========================" << endl;
		cout << "\t\t|        EXIT!!!         |" << endl;
		cout << "\t\t==========================" << endl;
	}
	writeFileAccountsAll(arr_of_accounts, number_of_accounts, FILE_OF_DATA);
}