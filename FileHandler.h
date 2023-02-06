#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
using namespace std;

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
		bool quote_start = false;
		for (int j = 0; j < data[i].size(); j++) {
			if (data[i][j] == '"') {
				quote_start = !quote_start;
			}
			else if (data[i][j] == ',' && !quote_start) {
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

/// <summary>
/// Get lines from CSV
/// start = 0, get CSV line 2, it's first valid data line in CSV, fir
/// mode = "2d" -> 2D vector, mode = "1d" -> 1D vector
/// </summary>
/// <param name="filename"></param>
/// <param name="start"></param>
/// <param name="range"></param>
/// <param name="mode"></param>
/// <returns></returns>
vector<vector<string>> get_lines(const string& filename, int start, int range,string mode ="2d") {
	if (mode != "2d" && mode != "1d") {
		cout << "Invalid mode" << endl;
		throw "Invalid mode";
	}
	
	if (mode == "2d") {
		vector<vector<string>> data = read_csv_2D(filename);
		vector<vector<string>> data_2D;
		for (int i = start; i < start + range; i++) {
			data_2D.push_back(data[i]);
		}
		return data_2D;
	}
	else if (mode == "1d") {
		vector<string> data = read_csv(filename);
		vector<vector<string>> data_2D;
		for (int i = start; i < start + range; i++) {
			vector<string> row;
			row.push_back(data[i]);
			data_2D.push_back(row);
		}
		return data_2D;
	}
}

vector<vector<string>> get_line(const string& filename, int lineNum, string mode = "2d") {
	vector<vector<string>> data = get_lines(filename, lineNum,  1,mode);
	return data;
}