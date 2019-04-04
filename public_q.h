#pragma once
#include "parent_q.h"

class public_q : public parent_q
{
public:
	void calculate();
	public_q *copy();
	void sethead(el*val);
	void settail(el*val);
};

