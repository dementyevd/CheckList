#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<stdio.h>
using namespace std;
bool CheckDate(SYSTEMTIME date);
struct delo
{
	string name;
	string description;
	int priority;
	SYSTEMTIME date;
	void Add(delo*& list, int &size) {
		cin.get();
		string n,d;
		int p;
		SYSTEMTIME dt;
		delo* newList = new delo[size+1];
		cout << "Enter description:" << endl;
		getline(cin, d);
		cout << "Enter name:" << endl;
		cin >> n;
		cout << "Enter priority (1 - high, 0 - usual):" << endl;
		cin >> p;
		do {
			cout << "Enter date and time of deadline (through spacebar day, month, year, hour, minute):" << endl;
			cin >> dt.wDay >> dt.wMonth >> dt.wYear >> dt.wHour >> dt.wMinute;
		} while (!CheckDate(dt));
		if (size == 0) {
			newList[size].description = d;
			newList[size].name = n;
			newList[size].priority = p;
			newList[size].date.wDay = dt.wDay;
			newList[size].date.wMonth = dt.wMonth;
			newList[size].date.wYear = dt.wYear;
			newList[size].date.wHour = dt.wHour;
			newList[size].date.wMinute = dt.wMinute;
		}		
		else {
			for (int i = 0; i < size; i++) {
				newList[i] = list[i];
			}
			newList[size].description = d;
			newList[size].name = n;
			newList[size].priority = p;
			newList[size].date.wDay = dt.wDay;
			newList[size].date.wMonth = dt.wMonth;
			newList[size].date.wYear = dt.wYear;
			newList[size].date.wHour = dt.wHour;
			newList[size].date.wMinute = dt.wMinute;
		}
		size++;
		delete[] list;
		list = newList;
	}
	void Show(delo* list, int size) {
		char choice;
		int k = 0;
		SYSTEMTIME st;
		GetLocalTime(&st);
		long dweek = st.wDay * 1440 + st.wMonth * 43200 + st.wYear * 525600 + st.wHour * 60 + st.wMinute + 10080;
		long dmonth = st.wDay * 1440 + st.wMonth * 43200 + st.wYear * 525600 + st.wHour * 60 + st.wMinute + 43200;
		delo* newList = new delo[size];
		cout << "1 - Show all tasks" << endl;
		cout << "2 - Today tasks" << endl;
		cout << "3 - Tasks for a week" << endl;
		cout << "4 - Tasks for a month" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			for (int i = 0; i < size; i++) {
				newList[i] = list[i];
				cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
				cout << "Description: " << newList[i].description << endl << endl;
			}
			do
			{
				cout << "1 - Sort by priority" << endl;
				cout << "2 - Sort by date" << endl;
				cout << "3 - Main menu" << endl;
				cin >> choice;
				switch (choice)
				{
				case '1':
					for (int i = 1; i < size; i++) {
						for (int j = 0; j < size - 1; j++) {
							if (newList[j].priority < newList[j + 1].priority) swap(newList[j], newList[j + 1]);
						}
					}
					for (int i = 0; i < size; i++) {
						cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
						cout << "Description: " << newList[i].description << endl << endl;
					}
					break;
				case '2':
					for (int i = 1; i < size; i++) {
						for (int j = 0; j < size - 1; j++) {
							if ((newList[j].date.wDay * 1440 + newList[j].date.wMonth * 43200 + newList[j].date.wYear * 525600 + newList[j].date.wHour * 60 + newList[j].date.wMinute) > (newList[j + 1].date.wDay * 1440 + newList[j + 1].date.wMonth * 43200 + newList[j + 1].date.wYear * 525600 + newList[j + 1].date.wHour * 60 + newList[j + 1].date.wMinute)) swap(newList[j], newList[j + 1]);
						}
					}
					for (int i = 0; i < size; i++) {
						cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
						cout << "Description: " << newList[i].description << endl << endl;
					}
					break;
				case '3':
					cout << "Main menu" << endl;
					break;
				default:
					cout << "Invalid operation" << endl;
					break;
				}
			} while (choice!='3');
			break;
		case '2':			
			for (int i = 0; i < size; i++) {
				if (list[i].date.wDay == st.wDay && list[i].date.wMonth == st.wMonth && list[i].date.wYear == st.wYear) {
					newList[k] = list[i];
					k++;
				}
			}
			for (int i = 0; i < k; i++) {
				cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
				cout << "Description: " << newList[i].description << endl << endl;
			}
			do
			{
				cout << "1 - Sort by priority" << endl;
				cout << "2 - Sort by date" << endl;
				cout << "3 - Main menu" << endl;
				cin >> choice;
				switch (choice)
				{
				case '1':
					for (int i = 1; i < k; i++) {
						for (int j = 0; j < k - 1; j++) {
							if (newList[j].priority < newList[j + 1].priority) swap(newList[j], newList[j + 1]);
						}
					}
					for (int i = 0; i < k; i++) {
						cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
						cout << "Description: " << newList[i].description << endl << endl;
					}
					break;
				case '2':
					for (int i = 1; i < k; i++) {
						for (int j = 0; j < k - 1; j++) {
							if ((newList[j].date.wDay * 1440 + newList[j].date.wMonth * 43200 + newList[j].date.wYear * 525600 + newList[j].date.wHour * 60 + newList[j].date.wMinute) > (newList[j + 1].date.wDay * 1440 + newList[j + 1].date.wMonth * 43200 + newList[j + 1].date.wYear * 525600 + newList[j + 1].date.wHour * 60 + newList[j + 1].date.wMinute)) swap(newList[j], newList[j + 1]);
						}
					}
					for (int i = 0; i < k; i++) {
						cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
						cout << "Description: " << newList[i].description << endl << endl;
					}
					break;
				case '3':
					cout << "Main menu" << endl;
					break;
				default:
					cout << "Invalid operation" << endl;
					break;
				}
			} while (choice != '3');
			break;
		case '3':
			for (int i = 0; i < size; i++) {
				if (list[i].date.wDay * 1440 + list[i].date.wMonth * 43200 + list[i].date.wYear * 525600 + list[i].date.wHour * 60 + list[i].date.wMinute <= dweek) {
					newList[k] = list[i];
					k++;
				}
			}
			for (int i = 0; i < k; i++) {
				cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
				cout << "Description: " << newList[i].description << endl << endl;
			}
			do
			{
				cout << "1 - Sort by priority" << endl;
				cout << "2 - Sort by date" << endl;
				cout << "3 - Main menu" << endl;
				cin >> choice;
				switch (choice)
				{
				case '1':
					for (int i = 1; i < k; i++) {
						for (int j = 0; j < k - 1; j++) {
							if (newList[j].priority < newList[j + 1].priority) swap(newList[j], newList[j + 1]);
						}
					}
					for (int i = 0; i < k; i++) {
						cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
						cout << "Description: " << newList[i].description << endl << endl;
					}
					break;
				case '2':
					for (int i = 1; i < k; i++) {
						for (int j = 0; j < k - 1; j++) {
							if ((newList[j].date.wDay * 1440 + newList[j].date.wMonth * 43200 + newList[j].date.wYear * 525600 + newList[j].date.wHour * 60 + newList[j].date.wMinute) > (newList[j + 1].date.wDay * 1440 + newList[j + 1].date.wMonth * 43200 + newList[j + 1].date.wYear * 525600 + newList[j + 1].date.wHour * 60 + newList[j + 1].date.wMinute)) swap(newList[j], newList[j + 1]);
						}
					}
					for (int i = 0; i < k; i++) {
						cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
						cout << "Description: " << newList[i].description << endl << endl;
					}
					break;
				case '3':
					cout << "Main menu" << endl;
					break;
				default:
					cout << "Invalid operation" << endl;
					break;
				}
			} while (choice != '3');
			break;
		case '4':
			for (int i = 0; i < size; i++) {
				if (list[i].date.wDay * 1440 + list[i].date.wMonth * 43200 + list[i].date.wYear * 525600 + list[i].date.wHour * 60 + list[i].date.wMinute <= dmonth) {
					newList[k] = list[i];
					k++;
				}
			}
			for (int i = 0; i < k; i++) {
				cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
				cout << "Description: " << newList[i].description << endl << endl;
			}
			do
			{
				cout << "1 - Sort by priority" << endl;
				cout << "2 - Sort by date" << endl;
				cout << "3 - Main menu" << endl;
				cin >> choice;
				switch (choice)
				{
				case '1':
					for (int i = 1; i < k; i++) {
						for (int j = 0; j < k - 1; j++) {
							if (newList[j].priority < newList[j + 1].priority) swap(newList[j], newList[j + 1]);
						}
					}
					for (int i = 0; i < k; i++) {
						cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
						cout << "Description: " << newList[i].description << endl << endl;
					}
					break;
				case '2':
					for (int i = 1; i < k; i++) {
						for (int j = 0; j < k - 1; j++) {
							if ((newList[j].date.wDay * 1440 + newList[j].date.wMonth * 43200 + newList[j].date.wYear * 525600 + newList[j].date.wHour * 60 + newList[j].date.wMinute) > (newList[j + 1].date.wDay * 1440 + newList[j + 1].date.wMonth * 43200 + newList[j + 1].date.wYear * 525600 + newList[j + 1].date.wHour * 60 + newList[j + 1].date.wMinute)) swap(newList[j], newList[j + 1]);
						}
					}
					for (int i = 0; i < k; i++) {
						cout << i + 1 << ". " << newList[i].name << "\t" << newList[i].date.wDay << "." << newList[i].date.wMonth << "." << newList[i].date.wYear << "\t" << newList[i].date.wHour << ":" << newList[i].date.wMinute << "\t" << "Priority: " << newList[i].priority << endl;
						cout << "Description: " << newList[i].description << endl << endl;
					}
					break;
				case '3':
					cout << "Main menu" << endl;
					break;
				default:
					cout << "Invalid operation" << endl;
					break;
				}
			} while (choice != '3');
			break;
		default:
			cout << "Invalid operation" << endl;
			break;
		}
		delete[] newList;
	}
	void del(delo*& list, int& size) {
		delo* newList = new delo[size - 1];
		int index;
		cout << "Enter number of task to be deleted:" << endl;
		cin >> index;
		for (int i = 0; i < size-1; i++) {
			if (i < index - 1) newList[i] = list[i];
			else newList[i] = list[i + 1];
		}
		delete[] list;
		list = newList;
		size--;
	}
	void edit(delo*& list) {
		int index;
		string n, d;
		int p;
		SYSTEMTIME dt;
		cout << "Enter task number:" << endl;
		cin >> index;
		cin.get();
		cout << "Enter new description:" << endl;
		getline(cin, d);
		cout << "Enter new name:" << endl;
		cin >> n;
		cout << "Enter new priority (1 - high, 0 - usual):" << endl;
		cin >> p;
		do {
			cout << "Enter new date and time of deadline (through spacebar day, month, year, hour, minute):" << endl;
			cin >> dt.wDay >> dt.wMonth >> dt.wYear >> dt.wHour >> dt.wMinute;
		} while (!CheckDate(dt));
		list[index - 1].description = d;
		list[index - 1].name = n;
		list[index - 1].priority = p;
		list[index - 1].date.wDay = dt.wDay;
		list[index - 1].date.wMonth = dt.wMonth;
		list[index - 1].date.wYear = dt.wYear;
		list[index - 1].date.wHour = dt.wHour;
		list[index - 1].date.wMinute = dt.wMinute;
	}
	void find(delo* list, int size, string name) {
		bool flag = false;
		for (int i = 0; i < size; i++) {
			if (list[i].name == name) {
				cout << i + 1 << ". " << list[i].name << "\t" << list[i].date.wDay << "." << list[i].date.wMonth << "." << list[i].date.wYear << "\t" << list[i].date.wHour << ":" << list[i].date.wMinute << "\t" << "Priority: " << list[i].priority << endl;
				cout << "Description: " << list[i].description << endl << endl;
				flag = true;
			}
		}
		if (!flag) cout << "Nothing found!" << endl;
	}
	void find(delo* list, int size, int priority) {
		bool flag = false;
		for (int i = 0; i < size; i++) {
			if (list[i].priority == priority) {
				cout << i + 1 << ". " << list[i].name << "\t" << list[i].date.wDay << "." << list[i].date.wMonth << "." << list[i].date.wYear << "\t" << list[i].date.wHour << ":" << list[i].date.wMinute << "\t" << "Priority: " << list[i].priority << endl;
				cout << "Description: " << list[i].description << endl << endl;
				flag = true;
			}
		}
		if (!flag) cout << "Nothing found!" << endl;
	}
	void find(delo* list, int size, SYSTEMTIME date) {
		bool flag = false;
		for (int i = 0; i < size; i++) {
			if (list[i].date.wDay == date.wDay && list[i].date.wMonth == date.wMonth && list[i].date.wYear == date.wYear) {
				cout << i + 1 << ". " << list[i].name << "\t" << list[i].date.wDay << "." << list[i].date.wMonth << "." << list[i].date.wYear << "\t" << list[i].date.wHour << ":" << list[i].date.wMinute << "\t" << "Priority: " << list[i].priority << endl;
				cout << "Description: " << list[i].description << endl << endl;
				flag = true;
			}
		}
		if (!flag) cout << "Nothing found!" << endl;
	}
	void finddesc(delo* list, int size, string description) {
		bool flag = false;
		for (int i = 0; i < size; i++) {
			if (list[i].description == description) {
				cout << i + 1 << ". " << list[i].name << "\t" << list[i].date.wDay << "." << list[i].date.wMonth << "." << list[i].date.wYear << "\t" << list[i].date.wHour << ":" << list[i].date.wMinute << "\t" << "Priority: " << list[i].priority << endl;
				cout << "Description: " << list[i].description << endl << endl;
				flag = true;
			}
		}
		if (!flag) cout << "Nothing found!" << endl;
	}
};
