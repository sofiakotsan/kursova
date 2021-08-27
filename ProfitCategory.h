#pragma once
#include <iostream>
#include "Category.h"

class ProfitCategory: public Category
{
public:
	/*ProfitCategory();*/
	virtual void showTotalAmount() const override;
};

