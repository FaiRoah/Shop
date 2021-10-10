#pragma once
#include "Purchase.h"
class Check : public Purchase
{
public:
	Check(string name, int amount, double price, double amountPrice);
	virtual void printInfo();
};

