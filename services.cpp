#include "Menu.h"

//Menu::main_menu();
//Menu::manager_menu();
//Menu::saleperson_menu();


void run() {
	int opt =  Menu::main_menu();
	system("cls");
	if (opt == 1) {
		// login
	}
	else if (opt == 2) {
		int about_opt =  Menu::about_page();
		if (about_opt==1) {
			system("cls");
			Menu::main_menu();
		}
	}
	else if (opt == 3) {
		exit(0);
	}
}