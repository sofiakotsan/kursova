#include "Category.h"

Category::Category() : totalAmount{0}
{
}

double Category::getTotalAmount() const
{
	return totalAmount;
}

double& Category::operator+=(const double& amount)
{
	totalAmount += amount;
	return totalAmount;
}

bool Category::operator> (const Category& category)
{
	return totalAmount > category.totalAmount;
}

bool Category::operator== (const Category& category)
{
	return totalAmount == category.totalAmount;
}

bool Category::operator< (const Category& category)
{
	return !(totalAmount > category.totalAmount) && !(totalAmount == category.totalAmount);
}