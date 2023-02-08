#pragma once
#include <iostream>
#include <string>
using namespace std;


class Menu {
public:static int main_menu();
	  static int valid(string input, int max_num);
	  static int saleperson_menu();
	  static int manager_menu();
	  static int about_page();
	  static int login_page();
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
			cout << "Invalid Input" << endl;
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


	while (true)
	{
		cout << ">";
		cin >> input;
		int res = Menu::valid(input,5);
		if (res != -1) {
			//cout << "You choose: " << res;
			return res;
		}
		else {
			cout << "Invalid Input" << endl;
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


	while (true)
	{
		cout << ">";
		cin >> input;
		int res = Menu::valid(input, 4);
		if (res != -1) {
			//cout << "You choose: " << res;
			return res;
		}
		else {
			cout << "Invalid Input" << endl;
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
			cout << "Invalid Input" << endl;
		}
	}
}

int Menu::login_page() {
	cout << 
}
