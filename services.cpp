#include "Menu.h"
#include <windows.h>


//Menu::main_menu();
//Menu::manager_menu();
//Menu::saleperson_menu();

//void run() {
//	cout << "hilo" << endl;
//	StatusContainer::current_user = User("innis2", "222");
//	cout << StatusContainer::current_user.username << "<<<" << endl;
//	cout << "************" << endl;
//}

void run() {
	int opt =  Menu::main_menu();
	system("cls");
	if (opt == 1) {
		int login_code =  Menu::login_page();
		if (login_code==100) {
			system("cls");
			cout << "Login success" << endl;
		}
		else {
			Sleep(2000);
			system("cls");
			run();
		}
		
	}
	else if (opt == 2) {
		int about_opt =  Menu::about_page();
		if (about_opt==1) {
			system("cls");
			run();
		}
	}
	else if (opt == 3) {
		exit(0);
	}
}