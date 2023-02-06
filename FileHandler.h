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

int get_lines_num(const string& filename) {
	vector<string> data = read_csv(filename);
	return data.size();
}

int get_cols_num(const string& filename) {
	vector<vector<string>> data = read_csv_2D(filename);
	return data[0].size();
}

/// <summary>
/// Get lines from CSV
/// start = 0, get CSV line 2, it's first valid data line in CSV, fir
/// mode = "2d" -> 2D vector, mode = "1d" -> 1D vector
/// </summary>
vector<vector<string>> get_data(
	const string& filename,
	int start,
	int range,
	int start_col,
	int range_col
) {
	vector<vector<string>> data = read_csv_2D(filename);
	vector<vector<string>> data_2D;
	for (int i = start; i < start + range; i++) {
		vector<string> row;
		for (int j = start_col; j < start_col + range_col; j++) {
			row.push_back(data[i][j]);
		}
		data_2D.push_back(row);
	}
	return data_2D;
}

vector<vector<string>> get_lines(
	const string& filename,
	int start,
	int range
) {
	return get_data(filename, start, range, 0, get_cols_num(filename));
}

vector<vector<string>> get_line(const string& filename, int line) {
	return get_data(filename, line, 1, 0, get_cols_num(filename));
}

vector<vector<string>> get_cols(
	const string& filename,
	int start,
	int range
) {
	return get_data(filename, 0, get_lines_num(filename), start, range);
}

vector<vector<string>> get_col(const string& filename, int col) {
	return get_data(filename, 0, get_lines_num(filename), col, 1);
}

string get_cell(const string& filename, int line, int col) {
	vector<vector<string>> data = read_csv_2D(filename);
	return data[line][col];
}