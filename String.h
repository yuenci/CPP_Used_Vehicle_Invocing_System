#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

std::string zfill(std::string data, int length, char fill = '0') {
    std::stringstream ss;
    ss << std::setfill(fill) << std::setw(length) << data;
    return ss.str();
}

std::string zfill(int data, int length, char fill = '0') {
    std::stringstream ss;
    ss << std::setfill(fill) << std::setw(length) << data;
    return ss.str();
}

//string toLowerCase(string str) {
//    for (char& c : str) {
//        c = tolower(c);
//    }
//    return str;
//}