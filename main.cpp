#include <iostream>
#include <conio.h>
#include <windows.h>
#include "parent_q.h"
#include "private_q.h"
#include "public_q.h"
#include "protected_q.h"

using namespace std;

int main()
{
	parent_q q1;
	parent_q q_copy; //создание очереди типа класс для копированной очереди
	parent_q buf;
	parent_q *q_new; //создание очереди типа класс для слияния очереди
	private_q priv;
	public_q publ;
	protected_q prot;

	int user_value = 0;
	char menu_choise;
	char submenu_choise;
	q_new = &buf;
	do
	{
		system("cls");
		cout << "What do you want to do?" << endl;
		cout << "1.Add element to the Queue." << endl;
		cout << "2.Extract element from the Queue." << endl;
		cout << "3.Print Queue on the screen." << endl;
		cout << "4.Calculate amount of elements," << endl;
		cout << "larger than harmonic value." << endl;
		cout << "5.Create copy of the Queue." << endl; 
		cout << "6.Merge Queues (only if you do a copy!)." << endl;
		cout << "7. Exit" << endl;
		cout << ">";
		cin >> menu_choise;
	
		switch (menu_choise) {
		case '1':
			system("cls");
			cout<<"Enter value of element:"<< endl;
			cout << ">";
			cin >> user_value;
			q1.add(user_value);
			break; 
		case '2':
			system("cls");
			q1.del();
			cout << "Element was extracted!" << endl;
			system("Pause");
			break;
		case '3':
			system("cls");
			q1.print_q();
			cout << "Queue was printed!(if you create it)" << endl;
			system("Pause");
			break;
		case '4':
			system("cls");
			cout << "Choose modifier." << endl;
			cout << "1.Private." << endl;
			cout << "2.Protected." << endl;
			cout << "3.Public." << endl;
			cout << ">";
			cin >> submenu_choise;
			switch (submenu_choise) {
			case '1':
				system("cls");
				priv.sethead(q1.gethead());
				priv.settail(q1.gettail());
				priv.calculate();
				system("Pause");
				break;
			case '2':
				system("cls");
				prot.sethead(q1.gethead());
				prot.settail(q1.gettail());
				prot.getnum();
				prot.calculate();
				system("Pause");
				break;
			case '3':
				system("cls");
				publ.sethead(q1.gethead());
				publ.settail(q1.gettail());
				publ.calculate();
				system("Pause");
				break;
			default:
				break;
			}
			break;
		case '5':
			system("cls");
			q1.copy_q(q_copy);
			cout << "Copy was created!" << endl;
			system("Pause");
			break;
		case '6':
			system("cls");
			q_new = q1.merge(q_copy);
			q_new->print_q();
			cout << "Queues was merged!" << endl;
			system("Pause");
			break;
		case '7':
			menu_choise = 7;
			break;
		default:
			break;
		}
		
	} while (menu_choise != 7);
	delete q_new;
	q_new = nullptr;
	return 0;
}