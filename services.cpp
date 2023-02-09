#include "Menu.h"
#include <windows.h>
#include "Form.h"
#include "Console.h"
#include "Number.h"
//#include "DateTime.h"
#define SLEEP_TIME 2000

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
	go_to_main_menu();
	//go_to_saleperson_menu();
	//serach_vehicle();
	//showForm();
	//create_sale_invoice();
	//create_bill_receipt();
	//book_vehicle();
	//manage_clinets();
	//produce_report();
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
			Sleep(SLEEP_TIME);
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
	system("cls");
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
	else if (opt ==4) {
		book_vehicle();
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
	if (opt == "Quit") {
		go_to_second_menu();
	}
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
		Console::warning("No result found");
		//system("cls");
		serach_vehicle();
	}
	else {
		Console::success("Result found:");
		showForm(data_process(res));
	}
	int back_opt = Menu::back_to_previous_page();
	if (back_opt == 1) {
		go_to_second_menu();
	};
}

string get_car_price_form_id(int id) {
	vector<string> car = get_line("carlist.csv",id-1);
	//cout << id<< "-" << car[1] << endl;
	return car[1];
}



void create_sale_invoice() {
	vector<string> res = Menu::sale_invoice_page();
	string car_id = zfill(res[1],5);
	string condition[] = { "car_id","==",car_id };
	vector<int> query_res = query("trade.csv", condition);
	if (query_res.size() ==0) {
		Console::warning("Car not found");
		Sleep(SLEEP_TIME);
		go_to_second_menu();
	}
	else {
		string price = get_car_price_form_id(stoi(res[1]));
		vector<string> car = get_line("trade.csv", query_res[0]);
		vector<string> data = vector<string>({
		car[0],car[2],res[2],price
		});
		show_invoice(data);
		int back_opt =  Menu::back_to_previous_page();
		if (back_opt ==1) {
			go_to_second_menu();
		}
	}
	
}

void create_bill_receipt()
{
	vector<string> res = Menu::sale_invoice_page();
	string car_id = zfill(res[1], 5);
	string condition[] = { "car_id","==",car_id };
	vector<int> query_res = query("trade.csv", condition);
	if (query_res.size() == 0) {
		Console::warning("Car not found");
		Sleep(SLEEP_TIME);
		go_to_second_menu();
	}
	else {
		string price = get_car_price_form_id(stoi(res[1]));
		vector<string> car = get_line("trade.csv", query_res[0]);
		vector<string> data = vector<string>({
		car[0],car[2],res[2],price
			});
		show_invoice(data,"receipt");
		update_cell("trade.csv", "finished", query_res[0], 2);
		int back_opt = Menu::back_to_previous_page();
		if (back_opt == 1) {
			go_to_second_menu();
		}
	}
}

void book_vehicle() {
	vector<string> res = Menu::sale_invoice_page();
	string car_id = zfill(res[1], 5);
	string condition[] = { "car_id","==",car_id };
	vector<int> query_res = query("trade.csv", condition);
	if (query_res.size() != 0) {
		Console::warning("Car already sold");
		Sleep(SLEEP_TIME);
		go_to_second_menu();
	}
	else {
		int trade_num = get_lines_num("trade.csv") + 1;
		int car_num = get_lines_num("carlist.csv") ;
		string trade_num_str = zfill(trade_num,8);
		vector<string> newline = vector<string>({
			 trade_num_str,zfill(res[1],5),
			 "booking",StatusContainer::current_user.username,res[2]
			});
		if (car_num>= stoi(res[1])) {
			append_line("trade.csv", newline);
			Console::success("Booking success!");
		}
		int back_opt = Menu::back_to_previous_page();
		if (back_opt == 1) {
			go_to_second_menu();
		}
	}
}

void manage_clinets()
{
	vector<string> res = Menu::manage_clinets_page();

	vector<string> client = vector<string>({
		res[0],"client",res[1],res[2]
		});
	bool append_res=  append_line("users.csv", client);
	if (append_res) {
		Console::success("Client added successfully");
		Sleep(SLEEP_TIME);
		go_to_second_menu();
	}
	
}

void produce_report()
{
	vector<vector<string>> data = read_csv_2D("trade.csv");
	map<string, float > sale_data = map<string, float >({
			{"01",0}, {"02",0}, {"03",0}, {"04",0}, {"05",0}, {"06",0}, {"07",0}, {"08",0}, {"09",0}, {"10",0}, {"11",0}, {"12",0}
		});
	for (int i = 0; i < data.size(); i++) {
		if (data[i][2] == "finished") {
			string month = data[i][4].substr(5, 2);
			int price = convert_currency_str_to_float(get_car_price_form_id(stoi(data[i][1])));
			sale_data[month] += price;
		}
	}
	vector<float> sale_data_vec = vector<float>(
		{ sale_data["01"],sale_data["02"],sale_data["03"],sale_data["04"],sale_data["05"],sale_data["06"],
		sale_data["07"],sale_data["08"],sale_data["09"],sale_data["10"],sale_data["11"],sale_data["12"] }
		);
	show_sale_report(sale_data_vec);
	int back_opt = Menu::back_to_previous_page();
	if (back_opt == 1) {
		go_to_second_menu();
	}
}

void logout() {
	system("cls");
	StatusContainer::current_user = User("", "");
	go_to_main_menu();
}