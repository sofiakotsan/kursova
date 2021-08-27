#pragma once
class Category abstract
{
protected:
	double totalAmount;
public:
	Category();
	double getTotalAmount() const;
	virtual void showTotalAmount() const = 0;

	double& operator+= (const double& amount);
	bool operator> (const Category& category);
	bool operator< (const Category& category);
	bool operator== (const Category& category);
};

