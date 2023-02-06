#include <iostream>
#include "FileHandler.h"

void tests();
void read_csv_test();
void read_csv_2D_test();
void get_lines_test();
void get_line_test();
void get_cols_test();
void get_col_test();
void get_cell_test();


int main()
{
    std::cout << "Hello World!\n";
    tests();
}

void tests() {
    //read_csv_test();
    //read_csv_2D_test();
    //get_lines_test();
    //get_line_test();
    //get_cols_test();
    //get_col_test;
    get_cell_test();
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
