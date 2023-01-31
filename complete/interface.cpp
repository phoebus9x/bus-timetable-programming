#include "interface.h"
#include "account.h"

template <class T>
void Interface<T>::fun_admin(string FILE)
{
	Ring<T> ring;
	ring.read_file(FILE);
	char a[5];
	T value;
	int pos;
	int ch;
	string stop;
	do
	{
		system("cls");
		cout << "\t================= MENU ==================\n";
		cout << "\t| 0. EXIT                               |\n";
		cout << "\t| 1. INSERT BEGIN                       |\n";
		cout << "\t| 2. INSERT END                         |\n";
		cout << "\t| 3. INSERT POSITION                    |\n";
		cout << "\t| 4. POP                                |\n";
		cout << "\t| 5. DELETE POSITION                    |\n";
		cout << "\t| 6. SEARCH STOP                        |\n";
		cout << "\t| 7. SEARCH ID NUMBER                   |\n";
		cout << "\t| 8. UPDATE                             |\n";
		cout << "\t| 9. SORT ID                            |\n";
		cout << "\t| 10. LENGTH                            |\n";
		cout << "\t| 11. SHOW                              |\n";
		cout << "\t=========================================\n" << endl;
		cout << "Enter your choose: ";
		cin >> ch;
		switch (ch)
		{
		case 0:
			system("pause");
			ring.write_file(FILE);
			break;
		case 1:
			system("cls");
			cout << "Enter the element to be inserted: " << endl;
			cin >> value;
			ring.insert_begin(value);
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Enter the element to be inserted: " << endl;
			cin >> value;
			ring.insert_end(value);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Enter the element to be inserted: " << endl;
			cin >> value;
			cout << "Enter the position of element inserted: ";
			cin >> pos;
			ring.insert_pos(value, pos);
			system("pause");
			break;
		case 4:
			system("cls");
			ring.pop();
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "Enter the position of element to be deleted: ";
			cin >> pos;
			ring.delete_pos(pos);
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "Enter the element to be searched: ";
			cin.ignore();
			getline(cin, stop);
			cout << endl;
			cout << "\n====================== RESULT ======================" << endl << endl;
			ring.search_stop(stop);
			system("pause");
			break;
		case 7:
			system("cls");
			cout << "Enter the ID element to be searched: " << endl;
			cin.ignore();
			cin.getline(a, 5);
			cout << "\n====================== RESULT ======================" << endl << endl;
			ring.search_ID(a);
			system("pause");
			break;
		case 8:
			system("cls");
			cout << "Enter the position of node to be updated: ";
			cin >> pos;
			cout << "Enter the new value: " << endl;
			cin >> value;
			ring.update(value, pos);
			system("pause");
			break;
		case 9:
			system("cls");
			ring.sort_ID();
			cout << "\tarranged!!!" << endl;
			system("pause");
			break;
		case 10:
			system("cls");
			cout << "Length= " << ring.getLength() << endl << endl;
			system("pause");
			break;
		case 11:
			system("cls");
			ring.display();
			system("pause");
			break;
		default:
			cout << "\t\t=============================================" << endl;
			cout << "\t\t|        RE-ENTER YOUR SELECTION!!!         |" << endl;
			cout << "\t\t=============================================" << endl << endl;
			system("pause");
			break;
		}
	} while (ch != 0);
}

template <class T>					
void Interface<T>::fun_user(string FILE)
{
	Ring<T> ring;
	ring.read_file(FILE);
	char a[5];
	T value;
	int pos;
	int ch;
	string stop;
	do
	{
		system("cls");
		cout << "\t================= MENU ==================\n";
		cout << "\t| 0. EXIT                               |\n";
		cout << "\t| 1. SEARCH STOP                        |\n";
		cout << "\t| 2. SEARCH ID NUMBER                   |\n";
		cout << "\t| 3. SHOW                               |\n";
		cout << "\t=========================================\n" << endl;
		cout << "Enter your choose: ";
		cin >> ch;
		switch (ch)
		{
		case 0:
			system("pause");
			break;
		case 1:
			system("cls");
			cout << "Enter the element to be searched: ";
			cin.ignore();
			getline(cin, stop);
			cout << endl;
			cout << "\n====================== RESULT ======================" << endl << endl;
			ring.search_stop(stop);
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Enter the ID element to be searched: " << endl;
			cin.ignore();
			cin.getline(a, 5);
			cout << "\n====================== RESULT ======================" << endl << endl;
			ring.search_ID(a);
			system("pause");
			break;
		case 3:
			system("cls");
			ring.display();
			system("pause");
			break;
		default:
			cout << "\t\t=============================================" << endl;
			cout << "\t\t|        RE-ENTER YOUR SELECTION!!!         |" << endl;
			cout << "\t\t=============================================" << endl << endl;
			system("pause");
			break;
		}
	} while (ch != 0);
}

template<class T>
void Interface<T>::menu_admin()
{
	Account acc;
	string FILE_OF_DATA_BUS_EXP = "bus_exp.txt";
	string FILE_OF_DATA_BUS_SCHOOL = "bus_school.txt";
	string FILE_OF_DATA_TRAM = "tram.txt";
	string FILE_OF_DATA_TROLLEYBUS = "trolleybus.txt";
	Interface<Bus_exp> obj_1;
	Interface<Bus_school> obj_2;
	Interface<Trolleybus> obj_3;
	Interface<Tram> obj_4;
	int choose;
	do
	{
		system("cls");
		cout << "\t================== MENU ====================\n";
		cout << "\t| 0. EXIT                                  |\n";
		cout << "\t| 1. WORK WITH THE BUS_EXP                 |\n";
		cout << "\t| 2. WORK WITH THE BUS_SCHOOL              |\n";
		cout << "\t| 3. WORK WITH THE TROLLEYBUS              |\n";
		cout << "\t| 4. WORK WITH THE TRAM                    |\n";
		cout << "\t| 5. MANAGE ACCOUNTS PENDING               |\n";
		cout << "\t| 6. MANAGE ACCOUNTS HAVE BEEN APPROVED    |\n";
		cout << "\t============================================\n" << endl;
		cout << "Enter your choose: ";
		cin >> choose;
		switch (choose)
		{
		case 0:
			system("pause");
			break;
		case 1:
			system("cls");
			obj_1.fun_admin(FILE_OF_DATA_BUS_EXP);
			system("pause");
			break;
		case 2:
			system("cls");
			obj_2.fun_admin(FILE_OF_DATA_BUS_SCHOOL);
			system("pause");
			break;
		case 3:
			system("cls");
			obj_3.fun_admin(FILE_OF_DATA_TROLLEYBUS);
			system("pause");
			break;
		case 4:
			system("cls");
			obj_4.fun_admin(FILE_OF_DATA_TRAM);
			system("pause");
			break;
		case 5:
			system("cls");
			acc.fun_acc_registration();
			system("pause");
			break;
		case 6:
			system("cls");
			acc.fun_acc_login();
			system("pause");
			break;
		default:
			cout << "\t\t=============================================" << endl;
			cout << "\t\t|        RE-ENTER YOUR SELECTION!!!         |" << endl;
			cout << "\t\t=============================================" << endl << endl;
			system("pause");
			break;
		}
	} while (choose != 0);
}

template<class T>
void Interface<T>::menu_user()
{
	string FILE_OF_DATA_BUS_EXP = "bus_exp.txt";
	string FILE_OF_DATA_BUS_SCHOOL = "bus_school.txt";
	string FILE_OF_DATA_TRAM = "tram.txt";
	string FILE_OF_DATA_TROLLEYBUS = "trolleybus.txt";
	Interface<Bus_exp> obj_1;
	Interface<Bus_school> obj_2;
	Interface<Trolleybus> obj_3;
	Interface<Tram> obj_4;
	int choose;
	do
	{
		system("cls");
		cout << "\t================= MENU ==================\n";
		cout << "\t| 0. EXIT                               |\n";
		cout << "\t| 1. WORK WITH THE BUS_EXP              |\n";
		cout << "\t| 2. WORK WITH THE BUS_SCHOOL           |\n";
		cout << "\t| 3. WORK WITH THE TROLLEYBUS           |\n";
		cout << "\t| 4. WORK WITH THE TRAM                 |\n";
		cout << "\t=========================================\n" << endl;
		cout << "Enter your choose: ";
		cin >> choose;
		switch (choose)
		{
		case 0:
			system("pause");
			break;
		case 1:
			system("cls");
			obj_1.fun_user(FILE_OF_DATA_BUS_EXP);
			system("pause");
			break;
		case 2:
			system("cls");
			obj_2.fun_user(FILE_OF_DATA_BUS_SCHOOL);
			system("pause");
			break;
		case 3:
			system("cls");
			obj_3.fun_user(FILE_OF_DATA_TROLLEYBUS);
			system("pause");
			break;
		case 4:
			system("cls");
			obj_4.fun_user(FILE_OF_DATA_TRAM);
			system("pause");
			break;
		default:
			cout << "\t\t=============================================" << endl;
			cout << "\t\t|        RE-ENTER YOUR SELECTION!!!         |" << endl;
			cout << "\t\t=============================================" << endl << endl;
			system("pause");
			break;
		}
	} while (choose != 0);
}