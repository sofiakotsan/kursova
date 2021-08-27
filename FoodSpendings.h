#pragma once
#include "SpendingCategory.h"

class FoodSpendings: public SpendingCategory
{
public:
	virtual void showTotalAmount() const override;

};

