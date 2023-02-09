#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <locale>
#include <iomanip>

float convert_currency_str_to_float(const std::string& currency_str) {
    std::stringstream ss;
    for (char c : currency_str) {
        if (c != ',') {
            ss << c;
        }
    }
    std::string cleanedStr = ss.str();
    return std::stof(cleanedStr);
}


string number_to_string(int number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}

int string_to_number(string str) {
	std::stringstream ss;
	ss << str;
	int number;
	ss >> number;
	return number;
}

//bool is_number(const string& data) {
//	for (char c : data) {
//		if (!isdigit(c)) {
//			return false;
//		}
//	}
//	return true;
//}