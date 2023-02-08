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

void run();
void go_to_second_menu();
void go_to_manager_menu();
void go_to_saleperson_menu();
void serach_vehicle();
void create_sale_invoice();
void create_bill_invoice();
void book_vehicle();
void manage_clinets();
void produce_report();
void logout();

void run() {
	int opt =  Menu::main_menu();
	system("cls");
	if (opt == 1) {
		int login_code =  Menu::login_page();
		if (login_code==100) {
			system("cls");
			go_to_second_menu();
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

void go_to_second_menu() {
	string role = StatusContainer::current_user.role;
	if (role == "manager") {
		go_to_manager_menu();
	}
	else if (role == "saleperson") {
		go_to_saleperson_menu();
	}
	else {
		cout << "Unknown role" << endl;
	}
}

void go_to_manager_menu() {
	int opt =  Menu::manager_menu();
	if (opt == 1) {
		serach_vehicle();
	}
	else if (opt == 2) {
		create_sale_invoice();
	}
	else if (opt == 3) {
		create_bill_invoice();
	}
	else if (opt == 4) {
		produce_report();
	}
	else if (opt == 5) {
		logout();
	}
}

void go_to_saleperson_menu(){
	int opt =  Menu::saleperson_menu(); 
	if (opt == 1) {
		serach_vehicle();
	}
	else if (opt == 2) {
		create_sale_invoice();
	}
	else if (opt == 3) {
		create_bill_invoice();
	}
	else if (opt == 4) {
		produce_report();
	}
	else if (opt == 5) {
		manage_clinets();
	}
	else if (opt == 6) {
		logout();
	}
}

void serach_vehicle() {
	
}

void create_sale_invoice() {
	
}

void create_bill_invoice()
{
	
}

void book_vehicle() {
	
}

void manage_clinets()
{
}

void produce_report()
{
	
}

void logout() {
	system("cls");
	StatusContainer::current_user = User("", "");
	run();
}