#include <iostream>
#include<stdio.h>
#include <iomanip>
#include "Header.h"
#include <string>
using namespace std;
int main()
{
	int size = 0;
	char choice;
	delo* list = new delo[size];
	do
	{
		cout << "1 - Add task" << endl;
		cout << "2 - Edit task" << endl;
		cout << "3 - Find task" << endl;
		cout << "4 - Delete task" << endl;
		cout << "5 - Show task" << endl;
		cout << "6 - Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			list->Add(list, size);
			break;
		case '2':
			list->edit(list);
			break;
		case '3':
			cout << "1 - Find by name" << endl;
			cout << "2 - Find by priority" << endl;
			cout << "3 - Find by description" << endl;
			cout << "4 - Find by date" << endl;
			cout << "5 - Main menu" << endl;
			cin >> choice;
			if (choice == '1') {
				string n;
				cout << "Enter name:" << endl;
				cin >> n;
				list->find(list, size, n);
			}
			else if (choice == '2') {
				int p;
				cout << "Enter priority:" << endl;
				cin >> p;
				list->find(list, size, p);			
			}
			else if (choice == '3') {
				string d;
				cin.get();
				cout << "Enter description:" << endl;
				getline(cin, d);
				list->finddesc(list, size, d);
			}
			else if (choice == '4') {
				SYSTEMTIME dt;
				cout << "Enter day month year through spacebar:" << endl;
				cin >> dt.wDay >> dt.wMonth >> dt.wYear;
				list->find(list, size, dt);
			}
			else cout << "Main menu" << endl;
			break;
		case '4':
			list->del(list, size);
			break;
		case '5':
			list->Show(list, size);
			break;
		case '6':
			cout << "Bye!" << endl;
			break;
		default:
			cout << "Invalid operation" << endl;
			break;
		}
	} while (choice!='6');
		
	delete[] list;
}

