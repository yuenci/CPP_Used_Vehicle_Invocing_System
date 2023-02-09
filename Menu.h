#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Authentication.h"
#include "StatusContainer.h"
#include "DateTime.h"
#include "String.h"
#include "Console.h"

using namespace std;


class Menu {
public:static int main_menu();
	  static int valid(string input, int max_num);
	  static int saleperson_menu();
	  static int manager_menu();
	  static int about_page();
	  static int login_page();
	  static string serach_vehicle_page();
	  static int back_to_previous_page();
	  static vector<string> sale_invoice_page();
	  static vector<string> manage_clinets_page();
};

/// <summary>
/// valid i-nput 
/// </summary>
/// <param name="input"></param>
/// <param name="max_num"></param>
/// <returns>
/// -1: incorrect input
/// 1- max: correct input
/// </returns>
int Menu::valid(string input, int max_num) {
	// if input is number
	for (char c : input) {
		if (!isdigit(c)) {
			return -1;
		}
	}

	// covert input to number
	int num = stoi(input);
	if (num <= max_num) {
		return num;
	}
	else {
		return -1;
	}
}


int Menu::main_menu() {
	string input = "";
	cout << "********************************************" << endl;
	cout << "************                  **************" << endl;
	cout << "************    buycar.com    **************" << endl;
	cout << "************                  **************" << endl;
	cout << "********************************************" << endl;
	cout << "Welcome to the Used Vehicle Invoicing System" << endl;
	cout << "Please select an option:" << endl;
	cout << "1. Login" << endl;
	cout << "2. About" << endl;
	cout << "3. Exit" << endl;
	

	while (true)
	{
		cout << ">";
		cin >> input;
		int res = Menu::valid(input, 3);
		if (res != -1) {
			//cout << "You choose: " << res;
			return res;
		}
		else {
			Console::warning("Incorrect input, please try again");
		}
	}
}

int Menu::saleperson_menu() {
	string input = "";
	cout << "********************************************" << endl;
	cout << "**********                       ***********" << endl;
	cout << "**********    Saleperson Menu    ***********" << endl;
	cout << "**********                       ***********" << endl;
	cout << "********************************************" << endl;
	cout << "Welcome to the Used Vehicle Invoicing System" << endl;
	cout << "Please select an option:" << endl;
	cout << "1. Search vehicle" << endl;
	cout << "2. Create sale invoice" << endl;
	cout << "3. Create bill receipt" << endl;
	cout << "4. Book the vehicle" << endl;
	cout << "5. Manage clients" << endl;
	cout << "6. Logout" << endl;


	while (true)
	{
		cout << ">";
		cin >> input;
		int res = Menu::valid(input,6);
		if (res != -1) {
			//cout << "You choose: " << res;
			return res;
		}
		else {
			Console::warning("Incorrect input, please try again");
		}
	}
}

int Menu::manager_menu() {
	string input = "";
	cout << "********************************************" << endl;
	cout << "************                   *************" << endl;
	cout << "************   Manager Menu    *************" << endl;
	cout << "************                   *************" << endl;
	cout << "********************************************" << endl;
	cout << "Welcome to the Used Vehicle Invoicing System" << endl;
	cout << "Please select an option:" << endl;
	cout << "1. Search vehicle" << endl;
	cout << "2. Create sale invoice" << endl;
	cout << "3. Create bill receipt" << endl;
	cout << "4. Produce report" << endl;
	cout << "5. Logout" << endl;


	while (true)
	{
		cout << ">";
		cin >> input;
		int res = Menu::valid(input, 5);
		if (res != -1) {
			//cout << "You choose: " << res;
			return res;
		}
		else {
			Console::warning("Incorrect input, please try again");
		}
	}
}

int Menu::about_page() {
	string input = "";
	cout << "********************************************" << endl;
	cout << "************                  **************" << endl;
	cout << "************    buycar.com    **************" << endl;
	cout << "************                  **************" << endl;
	cout << "********************************************" << endl;
	cout << "Buycar.com is a leading used car reseller located in Seri Kembangan, \
	Selangor, Malaysia.Our mission is to provide customers with high quality pre-\
	owned vehicles at affordable prices." << endl;
	cout << "Press 1 to back to main menu..." << endl;


	while (true)
	{
		cout << ">";
		cin >> input;
		int res = Menu::valid(input, 1);
		if (res != -1) {
			//cout << "You choose: " << res;
			return res;
		}
		else {
			Console::warning("Incorrect input, please try again");
		}
	}
}

int Menu::login_page() {
	string username;
	string password;

	cout << "Enter your username: " << endl;
	while (true)
	{
		cout << ">";
		cin >> username;
		if (username != "") {
			break;
		}
		else {
			Console::warning("Incorrect input, please try again");
		}
	}
	
	cout << "Enter your password: " << endl ;
	while (true)
	{
		cout << ">";
		cin >> password;
		if (password != "") {
			break;
		}
		else {
			Console::warning("Incorrect input, please try again");
		}
	}
	int login_code = login(username, password);
	
	if (login_code == 100) {
		StatusContainer::current_user = User(username, password);
	}
	else if (login_code == 200) {
		cout << "Can't find user";
	}
	else if (login_code == 300) {
		cout << "Password incorrect";
	}
	else if (login_code == 400) {
		cout << "Unknown error";
	}
	return login_code;
}

string Menu::serach_vehicle_page() {
	string input;
	
	map<int, string> opts({
		{1,"Price"},
		{2,"Mileage"},
		{3,"Doors"},
		{4,"Quit"}
	});

	cout << "Choose a filter: " << endl;
	cout << "1. Price" << endl;
	cout << "2. Mileage" << endl;
	cout << "3. Doors" << endl;
	cout << "4. Quit" << endl;
	while (true)
	{
		cout << ">";
		cin >> input;
		int res = Menu::valid(input, 4);
		if (res != -1) {
			//cout << "You choose: " << res;
			return opts[res];
		}
		else {
			Console::warning("Incorrect input, please try again");
		}
	}
}

int Menu::back_to_previous_page() {
	string input = "";
	cout << "Press 1 to back to previous page..." << endl;
	while (true)
	{
		cout << ">";
		cin >> input;
		int res = Menu::valid(input, 1);
		if (res != -1) {
			return res;
		}
		else {
			Console::warning("Incorrect input, please try again");
		}
	}
	return 1;
}

vector<string> Menu::sale_invoice_page() {
	
	cout << "Enter the vehicle ID: " << endl;
	string input;
	int vehicle_id;

	while (true) {
		cout << ">";
		std::getline(std::cin, input);
		std::stringstream ss(input);

		if (ss >> vehicle_id) {
			break;
		}
		else {
			std::cout << "Invalid value" << std::endl;
			ss.clear();
		}
	}
	
	int id = get_lines_num("trade.csv");
	string trade_id = zfill(id, 8);
	
	string time = get_now();
	
	return vector<string>({ trade_id, input,time });
}

vector<string> Menu::manage_clinets_page() {
	string username = "";
	string password = "";
	string phone = "";

	cout << "Enter username: " << endl ;
	while (true)
	{
		cout << ">";
		cin >> username;
		if (username.length() < 6) {
			Console::warning("Username must be at least 6 characters");
		}
		else {
			break;
		}
	}

	cout << "Enter password: " << endl;
	while (true)
	{
		cout << ">";
		cin >> password;
		if (password.length() < 8) {
			Console::warning("Password must be at least 8 characters");
		}
		else {
			break;
		}
	}

	cout << "Enter phone: " << endl;
	while (true)
	{
		cout << ">";
		cin >> phone;
		if (phone.length() != 11) {
			Console::warning("Phone must be 11 characters");
		}
		else {
			break;
		}
	}

	return vector<string>({ username, password, phone });
}