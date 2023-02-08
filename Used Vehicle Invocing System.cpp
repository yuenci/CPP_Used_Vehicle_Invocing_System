#include <iostream>
#include "FileHandler.h"
using namespace std;

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

int main()
{
	int a;
    cout << "Hello World!\n";
	//showMenu();
    tests();
}


void tests() {
	//read_csv_test();
	//read_csv_2D_test();
	//get_lines_test();
	//get_line_test();
	//get_cols_test();
	//get_col_test;
	//get_cell_test();
	//append_csv_test();
	update_csv_test();
	//write_cell_test();
	//delete_csv_test();
}

void append_csv_test() {
	vector<string> data = { "1", "2", "3" };
	bool res =  append_csv("carlist.csv", data);
	cout << res;
}
void  update_csv_test() {
	vector<string> data = { "1", "2", "3" };
	bool res = update_csv("carlist.csv", data, 0);
	cout << res;
}
void write_cell_test() {
	bool res = write_cell("carlist.csv", "666", 0, 0);
	cout << res;
}

void delete_csv_test() {
	bool res = delete_csv("carlist.csv", 0);
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
	vector<vector<string>> data = get_cols("carlist.csv", 0,2);
	cout << data[7][1] << endl;
}

void get_line_test() {
    vector<vector<string>> data = get_line("carlist.csv", 1);
    cout << data[0][2] << endl;
}


void get_lines_test(){
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