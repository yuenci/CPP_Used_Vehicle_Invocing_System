#pragma once
#include <iostream>
#include "Authentication.h"
#include "FileHandler.h"
using namespace std;


class User {
public:
	string username;
	string role = "unknown";
	string password;
	string phone = "";
	int login_status;
	User(string username, string password);
	void init_user();
};

User::User(string username, string password) {
	this->username = username;
	this->password = password;
	int res =  login(username, password);
	if (res == 100) {
		login_status = 100;
		init_user();
	}
	else if (res == 200) {
		login_status = 200;
	}
	else if (res == 300) {
		login_status = 300;
	}
	else {
		login_status = 400;
	}
}

void User::init_user() {
	if (login_status != 100) return;
	vector<vector<string>> data = read_csv_2D(USER_FILE);
	for (int i = 0; i < data.size(); i++) {
		if (data[i][USER_Name_ROW] == username) {
			role = data[i][1];
			phone = data[i][3];
			return;
		}
	}
}