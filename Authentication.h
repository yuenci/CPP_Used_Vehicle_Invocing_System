#pragma once
#define USER_FILE "users.csv"
#define USER_Name_ROW 0
#define USER_Password_ROW 2
#include "FileHandler.h"


/// <summary>
/// user login function
/// </summary>
/// <param name="username"></param>
/// <param name="password"></param>
/// <returns>
/// 100 success 
/// 200 can't find user
/// 300 password incorrect
/// 400 unknown error
///</returns>
int login(string username, string password) {
	vector<vector<string>> data = read_csv_2D(USER_FILE);
	bool found = false;
	bool pwd_correct = false;
	for (int i = 0; i < data.size(); i++) {
		if (data[i][USER_Name_ROW] == username) {
			found = true;
			if (data[i][USER_Password_ROW] == password) {
				pwd_correct = true;
				return 100;
			}
		}
	}
	if (!found) {
		return 200;
	}
	else if (found && !pwd_correct) {
		return 300;
	}
	return 400;
}
