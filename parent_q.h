/*�������� ������ parent_q � ��� �������*/
#pragma once
#include "Elem.h"

class parent_q
{
	el*Head; // ��������� �� ������ �������
	el*Tail; // ��������� �� ����� �������
	int num; // ���-�� ��������� �������

public:
	parent_q();
	~parent_q();
	
	void del();
	void add(int user_value);
	void print_q();
	void copy_q(parent_q &op1);
	parent_q* merge(parent_q &op1);

	el *gethead();
	el *gettail();
	int getnum();
	

	void sethead(el *val);
	void settail(el *val);
};

