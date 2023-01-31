#include "vehicle.h"
#include "bus.h"
#include "bus_c.h"
#include "bus_exp.h"
#include "tram.h"
#include "trolleybus.h"
#include "interface.h"
#include "ring.h"
#include "a.h"
#include "account.h"
#include "sha256.h"


int main()
{
	int ch, login_main;
	bool flag_exit_main = true;
	Interface<Vehicle> a;
	Account acc;
	do
	{
		system("cls");
		cout << "\t================== WELCOME TO OUR SOFTWARE ====================\n";
		cout << "\t| 0. EXIT                                                     |\n";
		cout << "\t| 1. LOGIN                                                    |\n";
		cout << "\t| 2. SIGN UP                                                  |\n";
		cout << "\t===============================================================\n";
		cout << "\n\t ENTER YOUR CHOICE: ";
		cin >> ch;
		switch (ch)
		{
		case 0:
			flag_exit_main = false;
			system("pause");
			break;
		case 1:
			login_main = acc.login();
			if (login_main == 1)
			{
				a.menu_admin();
			}
			else if (login_main == 2)
			{
				a.menu_user();
			}
			else break;
			break;
		case 2:
			acc.registerme();
			break;
		default:
			cout << "\t\t=============================================" << endl;
			cout << "\t\t|        RE-ENTER YOUR SELECTION!!!         |" << endl;
			cout << "\t\t=============================================" << endl << endl;
			system("pause");
			break;
		}
	} while (flag_exit_main != false);
	cout << "\tNEVER GIVE UP (^.^) .............." << endl;
	return 0;
}