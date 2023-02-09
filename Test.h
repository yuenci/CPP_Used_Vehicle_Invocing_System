#pragma once
#include "FileHandler.h"
#include "Authentication.h"
#include "User.h"
#include "Menu.h"

void tests();
void showMenu();
void read_csv_test();
void read_csv_2D_test();
void get_lines_test();
void get_line_test();
void get_cols_test();
void get_col_test();
void get_cell_test();
void append_csv_test();
void write_cell_test();
void update_csv_test();
void delete_csv_test();
void get_col_num_test();
void query_test();
void login_test();
void user_class_test();
void menu_class_test();

void tests() {
	//read_csv_test();
	//read_csv_2D_test();
	//get_lines_test();
	//get_line_test();
	//get_cols_test();
	//get_col_test;
	//get_cell_test();
	//append_csv_test();
	//update_csv_test();
	//write_cell_test();
	//delete_csv_test();
	//get_col_num_test();
	//query_test();
	//login_test();
	//user_class_test();
	//menu_class_test();
}
void menu_class_test() {
	Menu::main_menu();
}

void user_class_test() {
	User user =  User("innis1", "111");
	cout << user.phone << endl;
	cout << user.login_status << endl;
	
}


void login_test() {
	int res = login("innis1", "111");
	cout << res << endl;
}


void query_test() {
	string condition[] = { "Registration Date", "==", "2007" };
	vector<int> res = query("carlist.csv", condition);
	cout << res.size() << endl;
	cout << res[0] << endl;
	cout << res[1] << endl;
}

void get_col_num_test() {
	// Case insensitive
	int res = get_col_num("carlist.csv", "Price");
	cout << res << endl;
	res = get_col_num("carlist.csv", "mileage");
	cout << res << endl;

}

void append_csv_test() {
	vector<string> data = { "1", "2", "3" };
	bool res = append_line("carlist.csv", data);
	cout << res;
}

void  update_csv_test() {
	vector<string> data = { "1", "2", "3" };
	bool res = update_line("carlist.csv", data, 0);
	cout << res;
}

void write_cell_test() {
	bool res = update_cell("carlist.csv", "666", 0, 0);
	cout << res;
}

void delete_csv_test() {
	bool res = delete_line("carlist.csv", 0);
	cout << res;
}

void get_cell_test() {
	string data = get_cell("carlist.csv", 1, 2);
	cout << data << endl;
}

void get_col_test() {
	vector<vector<string>> data = get_col("carlist.csv", 0);
	cout << data[0][0] << endl;
}

void get_cols_test() {
	vector<vector<string>> data = get_cols("carlist.csv", 0, 2);
	cout << data[7][1] << endl;
}

void get_line_test() {
	vector<vector<string>> data = get_line("carlist.csv", 1);
	cout << data[0][2] << endl;
}

void get_lines_test() {
	vector<vector<string>> data = get_lines("carlist.csv", 0, 2);
	cout << data[0][0] << endl;
}

void read_csv_2D_test() {
	vector<vector<string>> data = read_csv_2D("carlist.csv");
	cout << data[0][0] << endl;
}

void read_csv_test() {
	vector<string> data = read_csv("carlist.csv");
	cout << data[0] << endl;
}

void showMenu() {
	std::vector<std::string> options = { "Option 1", "Option 2", "Option 3", "Quit" };

	std::cout << "请选择你的选项：" << std::endl;
	for (int i = 0; i < options.size(); i++) {
		std::cout << i + 1 << ". " << options[i] << std::endl;
	}

	int choice;
	std::cin >> choice;

	system("cls");

	switch (choice) {
	case 1:
		std::cout << "你选择了选项 1" << std::endl;
		break;
	case 2:
		std::cout << "你选择了选项 2" << std::endl;
		break;
	case 3:
		std::cout << "你选择了选项 3" << std::endl;
		break;
	case 4:
		exit(0);
	default:
		std::cout << "无效选项" << std::endl;
		break;
	}
}