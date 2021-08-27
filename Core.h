#pragma once
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include "FoodSpendings.h"
#include "JobProfit.h"

class Core
{
	std::map<std::string, std::shared_ptr<Category>> spendings;
	std::map<std::string, std::shared_ptr<Category>> profit;

	double totalProfit;
	double totalSpendings;
	double currentBudget;
public:
	Core(double _currentBudget = 0);
	void updateProfit();
	void updateSpendings();
	void updateBudget();
	double getCurrentBudget() const;
	double getTotalProfit() const;
	double getTotalSpendings() const;
	void addSpending(double amount, std::string category = "no_category");
	void addProfit(double amount, std::string category = "no_category");
	std::vector<std::shared_ptr<Category>> getListAsc(const std::map<std::string, std::shared_ptr<Category>>& mapToSort);
	std::vector<std::shared_ptr<Category>> getListDesc(const std::map<std::string, std::shared_ptr<Category>>& mapToSort);
	void showList(std::vector<std::shared_ptr<Category>> list);
	void showProfitListAsc();
	void showProfitListDesc();
	void showSpendingsListAsc();
	void showSpendingsListDesc();
};

