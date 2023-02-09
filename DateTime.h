#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string get_now() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::tm tm;
    localtime_s(&tm, &in_time_t);

    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %X");

    return ss.str();
}