#pragma once
#include "parent_q.h"

class private_q : private parent_q
{
public:
	void calculate();
	private_q *copy();
	void sethead(el*val);
	void settail(el*val);
	el* gettail();
	el* gethead();
};

