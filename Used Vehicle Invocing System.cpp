#include <iostream>
#include "FileHandler.h"

void tests();
void read_csv_test();
void read_csv_2D_test();
void get_lines_test();
void get_line_test();


int main()
{
    std::cout << "Hello World!\n";
    tests();
}

void tests() {
    //read_csv_test();
    //read_csv_2D_test();
    //get_lines_test();
    get_line_test();
}

void get_line_test() {
    vector<vector<string>> data = get_line("carlist.csv", 1);
    cout << data[0][1] << endl;
}


void get_lines_test(){
    vector<vector<string>> data = get_lines("carlist.csv", 0, 2);
    cout << data[1][0] << endl; 
}

void read_csv_2D_test() {
    vector<vector<string>> data = read_csv_2D("carlist.csv");
    cout << data[0][0] << endl;
}

void read_csv_test() {
    vector<string> data = read_csv("carlist.csv");
    cout << data[0] << endl;
}
