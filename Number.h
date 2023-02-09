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