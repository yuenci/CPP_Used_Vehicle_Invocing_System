#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include <cstdarg>
#include <sstream>
using namespace std;

/* Read */

vector<string> read_csv(const string& filename,bool keep_header = false) {
    vector<string> data;
    ifstream file(filename, ios::in | ios::binary);
    //file.imbue(locale(file.getloc(), new codecvt_utf8<char>));
	if (!file) {
		cerr << "Error: unable to open file!" << std::endl;
		throw exception("Error: unable to open file!");
	}
    string line;
	if (keep_header) {
		while (getline(file, line)) {
			data.push_back(line);
		}
		return data;
	}
	else {
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
}

vector<string> split_string_to_vector(string str, char delimiter) {
	vector<string> result;
	string temp = "";
	bool quote_start = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '"') {
			quote_start = !quote_start;
		}
		else if (str[i] == delimiter && !quote_start) {
			result.push_back(temp);
			temp = "";
		}
		else {
			temp += str[i];
		}
	}
	result.push_back(temp);
	return result;
}

string join_vector_to_string(const vector<string>& vec, char delimiter = ','){
	string result = "";
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].find(delimiter) != string::npos) {
			result += '"';
			result += vec[i];
			result += '"';
		}
		else {
			result += vec[i];
		}
		if (i != vec.size() - 1) {
			result += delimiter;
		}
	}
	return result;
}

vector<vector<string>> read_csv_2D(const string& filename, bool keep_header = false) {
	vector<string> data = read_csv(filename, keep_header);
	vector<vector<string>> data_2D;
	for (int i = 0; i < data.size(); i++) {
		vector<string> row = split_string_to_vector(data[i], ',');
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
vector<vector<string>> get_data( const string& filename, int start, int range, int start_col, int range_col) 
{
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

vector<vector<string>> get_lines( const string& filename, int start, int range ) {
	return get_data(filename, start, range, 0, get_cols_num(filename));
}

vector<vector<string>> get_line(const string& filename, int line) {
	return get_data(filename, line, 1, 0, get_cols_num(filename));
}

vector<vector<string>> get_cols( const string& filename, int start, int range ) 
{
	return get_data(filename, 0, get_lines_num(filename), start, range);
}

vector<vector<string>> get_col(const string& filename, int col) {
	return get_data(filename, 0, get_lines_num(filename), col, 1);
}

string get_cell(const string& filename, int line, int col) {
	vector<vector<string>> data = read_csv_2D(filename);
	return data[line][col];
}

/* Write */

bool append_csv(const string& filename, vector<string> data) {
	ofstream file(filename, ios::app | ios::binary);
	file.imbue(locale(file.getloc(), new codecvt_utf8<char>));
	if (file.is_open()) {
		file << join_vector_to_string(data) << endl;
		file.close();
		return true;
	}
	else {
		return false;
	}
}

// private
bool write_csv(const string& filename, const vector<string>& data) {
	ofstream file(filename, ios::binary);
	//file.imbue(locale(file.getloc(), new codecvt_utf8<char>));
	if (file.is_open()) {
		for (int i = 0; i < data.size(); i++) {
			file << data[i] << endl;
		}
		file.close();
		return true;
	}
	else {
		return false;
	}
}

bool write_cell(const string& filename, string value, int line, int row)
{
	line += 1;
	vector<string> lines = read_csv(filename, true);
	if (line < 0 || line >= lines.size()) {
		return false;
	}
	vector<string> data = split_string_to_vector(lines[line], ',');
	if (row < 0 || row >= data.size()) {
		return false;
	}
	data[row] = value;
	lines[line] = join_vector_to_string(data);
	return write_csv(filename, lines);
}

bool update_csv(const string& filename, vector<string> data, int line) {
	line += 1;
	vector<string> lines = read_csv(filename,true);
	if (line < 0 || line >= lines.size()) {
		return false;
	}
	lines[line] = join_vector_to_string(data);
	return write_csv(filename, lines);
}

bool delete_csv(const string& filename, int line, int range =1 ) {
	line += 1;
	vector<string> lines = read_csv(filename, true);
	if (line < 0 || line >= lines.size()) {
		return false;
	}
	lines.erase(lines.begin() + line, lines.begin() + line + range);
	return write_csv(filename, lines);
}

/* sort */
string toLowerCase(string str) {
	for (char& c : str) {
		c = tolower(c);
	}
	return str;
}

bool is_number(const string& data) {
	for (char c : data) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}


int get_col_num(const string& filename, const string& col_name) {
	vector<vector<string>> data = read_csv_2D(filename,true);
	for (int i = 0; i < data[0].size(); i++) {
		if (toLowerCase(data[0][i]) == toLowerCase(col_name)) {
			return i;
		}
	}
	return -1;
}



/* query */
double toFloat(const string& s) {
	stringstream ss(s);
	double result;
	ss >> result;
	return result;
}


vector<int> query(const string& filename, string condition[]) {
	// string condition[] = { "Price", "==", "2250" };
	//cout << condition[0] << " " << condition[1] << " " << condition[2] << endl;
	vector<vector<string>> data = read_csv_2D(filename);
	vector<int> res;
	int col_num = get_col_num(filename, condition[0]);
	if (col_num == -1) {
		return res;
	}
	for (int i = 0; i < data.size(); i++)
	{
		string value = data[i][col_num];
		if (condition[1] == "==") {
			if (value == condition[2]) {
				res.push_back(i);
			}
		}
		else if (condition[1] == "!=") {
			if (value != condition[2]) {
				res.push_back(i);
			}
		}
		else if (condition[1] == ">") {
			if (toFloat(value) > toFloat(condition[2])) {
				res.push_back(i);
			}
		}
		else if (condition[1] == "<") {
			if (toFloat(value) < toFloat(condition[2])) {
				res.push_back(i);
			}
		}
		else if (condition[1] == ">=") {
			if (toFloat(value) >= toFloat(condition[2])) {
				res.push_back(i);
			}
		}
		else if (condition[1] == "<=") {
			if (toFloat(value) <= toFloat(condition[2])) {
				res.push_back(i);
			}
		}
	}
	return res;
}