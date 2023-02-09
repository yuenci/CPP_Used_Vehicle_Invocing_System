#include "Menu.h"
#include <windows.h>
#include "Form.h"
#include "DateTime.h"


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
void go_to_main_menu();
void go_to_second_menu();
void go_to_manager_menu();
void go_to_saleperson_menu();
void serach_vehicle();
void create_sale_invoice();
void create_bill_receipt();
void book_vehicle();
void manage_clinets();
void produce_report();
void logout();

void run() {
	//go_to_main_menu();
	//go_to_saleperson_menu();
	//serach_vehicle();
	//showForm();
	create_sale_invoice();
}

void go_to_main_menu() {
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
			go_to_main_menu();
		}
		
	}
	else if (opt == 2) {
		int about_opt =  Menu::about_page();
		if (about_opt==1) {
			system("cls");
			go_to_main_menu();
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
		create_bill_receipt();
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
	system("cls");
	if (opt == 1) {
		serach_vehicle();
	}
	else if (opt == 2) {
		create_sale_invoice();
	}
	else if (opt == 3) {
		create_bill_receipt();
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
	string opt = Menu::serach_vehicle_page();
	string cond = "";
	cout << "Enter condition(>=1):" << endl << ">";
	cin >> cond;

	vector<int> res;
	if (cond.at(1) == '=') {
		string condition[] = { opt, cond.substr(0, 2), cond.substr(2) };
		res = query("carlist.csv", condition);
	}
	else {
		string condition[] = { opt, cond.substr(0, 1), cond.substr(1) };
		res = query("carlist.csv", condition);
	}

	
	
	if (res.size() == 0) {
		cout << "No result found" << endl;
		//system("cls");
		serach_vehicle();
	}
	else {
		cout << "Result found:" << endl;
		showForm(data_process(res));
	}
	int back_opt = Menu::back_to_previous_page();
	if (back_opt == 1) {
		system("cls");
		go_to_saleperson_menu();
	};
}

void create_sale_invoice() {
	cout << get_now() << endl;
}

void create_bill_receipt()
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
	go_to_main_menu();
}