#pragma once
#include "ProfitCategory.h"

class JobProfit: public ProfitCategory
{
public:
	virtual void showTotalAmount() const override;
};

