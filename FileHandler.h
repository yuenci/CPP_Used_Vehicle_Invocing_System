#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
using namespace std;

void printHi() {
	cout << "Hi" << endl;
}

vector<string> read_csv(const string& filename) {
    vector<string> data;
    ifstream file(filename, ios::in | ios::binary);
    file.imbue(locale(file.getloc(), new codecvt_utf8<char>));
    string line;
    bool first_line = true;
    while (getline(file, line)) {
        if (first_line) {
            first_line = false;
            continue;
        }
        data.push_back(line);
    }
    return data;
}

vector<vector<string>> read_csv_2D(const string& filename) {
	vector<string> data = read_csv(filename);
	vector<vector<string>> data_2D;
	for (int i = 0; i < data.size(); i++) {
		vector<string> row;
		string temp = "";
		for (int j = 0; j < data[i].size(); j++) {
			if (data[i][j] == ',') {
				row.push_back(temp);
				temp = "";
			}
			else {
				temp += data[i][j];
			}
		}
		row.push_back(temp);
		data_2D.push_back(row);
	}
	return data_2D;
}