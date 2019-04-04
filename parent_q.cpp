/*Реализация методов класса parent_q*/

#include "parent_q.h"
#include <iostream>

using namespace std;

parent_q::parent_q() {
	Head = nullptr;
	Tail = nullptr;
	num = 0;
}
parent_q::~parent_q() {
	el*temp = Tail;
	while (temp != nullptr) {
		temp = Tail->Previous;
		delete Tail;
		Tail = temp;
	}
}
void parent_q::add(int user_value) {
	el *temp = new el;
	if (num == 0)
	{
		temp->value = user_value;
		temp->Previous = nullptr;
		Head = temp;
		Tail = temp;
	}
	else
	{
		temp->value = user_value;
		temp->Previous = Tail;
		Tail = temp;
	}
	num++;
}
void parent_q::del() {
	el*temp = Tail;
	while (temp->Previous != Head) {
		temp = temp->Previous;
	}
	delete Head;
	Head = temp;
	num--;
}
void parent_q::print_q() {
	el *temp = Tail;
	int *mas = new int[num];
	int k = num - 1;
	for (int i = 0; i < num; ++i)
	{
		mas[k--] = temp->value;
		temp = temp->Previous;
	}
	for (int i = 0; i < num; ++i)
	{
		i != num - 1 ? cout << mas[i] << " << " : cout << mas[i] << endl;
	}
	cout << "num = " << num << endl;
	delete[]  mas;
}
void parent_q::copy_q(parent_q &op1) {
	el*temp = Tail;
	int *mas = new int[num];
	int k = num - 1;
	for (int i = 0; i < num; ++i)
	{
		mas[k--] = temp->value;
		temp = temp->Previous;
	}
	for (k = 0; k < num; k++) 
	{
		op1.add(mas[k]);
	}
	delete[] mas;
}
parent_q* parent_q::merge(parent_q &op1) 
{
	parent_q *res = new parent_q;
	el *temp = Tail;
	int *mas_1 = new int[num];
	int *mas_2 = new int[num];
	int k = num - 1;
	for (int i = 0; i < num; ++i)
	{
		mas_1[k--] = temp->value;
		temp = temp->Previous;
	}
	temp = op1.Tail;
	k = num - 1;
	for (int i = 0; i < num; ++i)
	{
		mas_2[k--] = temp->value;
		temp = temp->Previous;
	}
	for (int i = 0; i < num; ++i)
		res->add(mas_1[i]);
	for (int i = 0; i < num; ++i)
		res->add(mas_2[i]);
	delete[] mas_1;
	delete[] mas_2;
	mas_1 = nullptr;
	mas_2 = nullptr;
	return res;

}

el *parent_q::gethead() {
	return Head;
}
el *parent_q::gettail() {
	return Tail;
}
int parent_q::getnum() {
	return num;
}

void parent_q::sethead(el *val) {
	Head = val;
}
void parent_q::settail(el *val) {
	Tail = val;
}