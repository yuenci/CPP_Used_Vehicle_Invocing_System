#pragma once
#include <iostream>
#include <iomanip>
#include "FileHandler.h"

using namespace std;

int showForm(vector<vector<string>> data) {
    cout << "------------------------------------------------------------------------" << endl;
    
    cout << setiosflags(ios::left) << setw(30) << "Title"  << "|" << resetiosflags(ios::left)
        << setiosflags(ios::right) << setw(9) << "Price" << "|" << setw(18) <<"Registration Date" << "|"
        << setiosflags(ios::right) << setw(9) << "Mileage" << "|" << setw(10) << "Fuel Type" << "|"
        << setiosflags(ios::right) << setw(12) <<"Transmission" << "|" << setw(12) << "Engine Size" << "|"
        << setiosflags(ios::right) << setw(5) << "Doors" << "|" << setw(15) << "Colour" << "|"
        << setiosflags(ios::right) << setw(10) << "Hatchback" << "|" << setw(30) << "URL" << "|"
        << resetiosflags(ios::right) << setw(12) << "Sale Date" << "|" << endl;
    
    cout << "------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << setiosflags(ios::left) << setw(30) << data[i][0] << "|" << resetiosflags(ios::left)
            << setiosflags(ios::right) << setw(9) << data[i][1] << "|" << setw(18) << data[i][2] << "|"
            << setiosflags(ios::right) << setw(9) << data[i][3] << "|" << setw(10) << data[i][4] << "|"
            << setiosflags(ios::right) << setw(12) << data[i][5] << "|" << setw(12) << data[i][6] << "|"
            << setiosflags(ios::right) << setw(5) << data[i][7] << "|" << setw(15) << data[i][8] << "|"
            << setiosflags(ios::right) << setw(10) << data[i][9] << "|" << setw(30) << data[i][10] << "|"
            << resetiosflags(ios::right) << setw(12) << data[i][11] << "|" << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
    return 1;
}


vector<vector<string>> data_process(vector<int> data) {
	vector<vector<string>> cars = read_csv_2D("carlist.csv");
	vector<vector<string>> result;
	for (int i = 0; i < data.size(); ++i) {
		int car_name_length = cars[data[i]][0].length();
		int car_url = cars[data[i]][10].length();
        if (car_name_length > 30) {
            cars[data[i]][0] = cars[data[i]][0].substr(0, 30);
        }
		if (car_url > 30) {
			cars[data[i]][10] = cars[data[i]][10].substr(0, 30);
		}
		result.push_back(cars[data[i]]);
	}
	return result;
}