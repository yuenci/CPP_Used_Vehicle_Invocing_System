#include <iostream>
#include "FileHandler.h"

int main()
{
    std::cout << "Hello World!\n";
    printHi();
    vector<vector<string>> data = read_csv_2D("carlist.csv");
	cout << data[0][0] << endl;
}

