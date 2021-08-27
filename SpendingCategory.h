#pragma once
#include <iostream>
#include "Category.h"

class SpendingCategory: public Category
{
public:
	//SpendingCategory();
	virtual void showTotalAmount() const override;
};

