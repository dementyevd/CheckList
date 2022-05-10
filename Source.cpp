#include <iostream>
#include <string>
#include "Header.h"
#include <iomanip>
#include<stdio.h>
using namespace std;

bool CheckDate(SYSTEMTIME date) {
	if (date.wDay > 31 || date.wDay < 1 || date.wMonth < 1 || date.wMonth>12 || date.wHour < 0 || date.wHour>24 || date.wMinute < 0 || date.wMinute>60) {
		cout << "Incorrect date!" << endl;
		return false;
	}
	else
		return true;
}