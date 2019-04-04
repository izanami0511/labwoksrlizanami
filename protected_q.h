#pragma once
#include "parent_q.h"

class protected_q : protected parent_q
{
public:
	void calculate();
	protected_q *copy();
	void sethead(el*val);
	void settail(el*val);
	el* gettail(void);
	el* gethead(void);
	int getnum(void);
};

