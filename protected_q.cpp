#include "protected_q.h"
#include <iostream>
using namespace std;

el* protected_q::gethead(void) {
	return parent_q::gethead();
}
el* protected_q::gettail(void) {
	return parent_q::gettail();
}
int protected_q::getnum(void) {
	return parent_q::getnum();
}


void protected_q::calculate() {

	double sum = 0;
	double chis = 0;
	double element_chis = 0;
	int res = 0;
	int n = 0;
	el*temp = gettail();

	while (temp != NULL){

		element_chis = 1.0 / temp->value;
		chis += element_chis;
		temp = temp->Previous;
		n++;
	}
	
	sum = n / chis;
	temp = gettail();

	while (temp->Previous != NULL) {
		if (temp->value > sum)
		{
			res++;
		}
		temp = temp->Previous;
	} 

	cout << "Elements which are more than average sum are: " << res << endl;
}

protected_q* protected_q::copy() {
	protected_q copy;
	protected_q *a;
	el*temp = gettail();
	int k = getnum() - 1;
	int *mas = new int[getnum()];
	for (int i = 0; i < getnum(); ++i)
	{
		mas[k--] = temp->value;
		temp = temp->Previous;
	}
	for (k = 0; k < getnum(); k++)
	{
		copy.add(mas[k]);
	}
	a = &copy;
	return a;
	delete[] mas;
	mas = nullptr;
}

void protected_q::sethead(el*val) {
	parent_q::sethead(val);
}
void protected_q::settail(el*val) {
	parent_q::settail(val);
}
