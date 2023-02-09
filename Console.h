#pragma once
#include<iostream>
#include<windows.h>
using namespace std;


class Console {
private:static void set_color(int fore, int back);
public:static void  error(string message);
	  static void success(string message);
	  static void warning(string meesage);
};

void Console::set_color(int fore = 7, int back = 0)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (back << 4) + fore);
}

void Console::error(string message) {
	set_color(4, 0);
	cout << message << endl;
	set_color();
}

void Console::success(string message) {
	set_color(2, 0);
	cout << message << endl;
	set_color();
}

void Console::warning(string message) {
	set_color(6, 0);
	cout << message << endl;
	set_color();
}



