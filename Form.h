#pragma once
#include <iostream>
#include <iomanip>
#include "FileHandler.h"
#define SIGN "-"

using namespace std;

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

string center_print(string message, string sign, int length) {
    int size = message.length();
    int space = length - size;
    int left = space / 2;
    int right = space - left;
    string result = "";

    for (int i = 0; i < left; i++) {
        result += sign;
    }
    result += message;
    for (int i = 0; i < right; i++) {
        result += sign;
    }

    return result;
}

int showForm(vector<vector<string>> data) {
    int len = 184;
	string divider = "";
    for (int i = 0; i < len; i++)
    {
		divider += SIGN;
    }
    cout << center_print("Search Result", SIGN,len) <<endl;
    cout << divider << endl;
    
    cout << setiosflags(ios::left) 
        << setw(30) << "Title"  << "|" 
        << resetiosflags(ios::left)
        << setiosflags(ios::right) 
        << setw(9) << "Price" << "|" 
        << setw(18) <<"Registration Date" << "|"
        << setw(9) << "Mileage" << "|" 
        << setw(10) << "Fuel Type" << "|"
        << setw(12) <<"Transmission" << "|" 
        << setw(12) << "Engine Size" << "|"
        << setw(5) << "Doors" << "|" 
        << setw(15) << "Colour" << "|"
        << setw(10) << "Hatchback" << "|" 
        << setw(30) << "URL" << "|"
        << setw(12) << "Sale Date" << "|"
        << resetiosflags(ios::right)  << endl;
    
    cout << divider << endl;

    for (int i = 0; i < 5; ++i) {
        cout << setiosflags(ios::left)
            << setw(30) << data[i][0] << "|"
            << resetiosflags(ios::left)
            << setiosflags(ios::right)
            << setw(9) << data[i][1] << "|"
            << setw(18) << data[i][2] << "|"
            << setw(9) << data[i][3] << "|"
            << setw(10) << data[i][4] << "|"
            << setw(12) << data[i][5] << "|"
            << setw(12) << data[i][6] << "|"
            << setw(5) << data[i][7] << "|"
            << setw(15) << data[i][8] << "|"
            << setw(10) << data[i][9] << "|"
            << setw(30) << data[i][10] << "|"
            << setw(12) << data[i][11] << "|"
            << resetiosflags(ios::right) << endl;
    }
    cout << divider << endl;
    return 1;
}


int show_invoice(vector<string> data,string type = "invoice"){
    int len = 61;
    string divider = "";
    for (int i = 0; i < len; i++)
    {
        divider += SIGN;
    }
    if (type == "receipt") {
        cout << center_print("Receipt", SIGN, len) << endl;
    }
    else {
        cout << center_print("Invoice", SIGN, len) << endl;
    }
    
    cout << divider << endl;
    cout << setiosflags(ios::left) 
        << setw(12) << "Invoice ID" << "|" 
        << resetiosflags(ios::left)
        << setiosflags(ios::right) 
        << setw(10) << "car ID" << "|" 
        << setw(25) << "Booking Time" << "|"
        << setw(10) << "Price" << "|"  
        << resetiosflags(ios::right) << endl;
    
    cout << divider << endl;
    cout << setiosflags(ios::left)
        << setw(12) << data[0] << "|"
        << resetiosflags(ios::left)
        << setiosflags(ios::right)
        << setw(10) << data[1] << "|"
        << setw(25) << data[2] << "|"
        << setw(10) << data[3] << "|"
        << resetiosflags(ios::right) << endl;
    cout << divider << endl;
    return 1;
}