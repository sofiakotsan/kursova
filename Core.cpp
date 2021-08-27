#include "Core.h"
using namespace std;

Core::Core(double _currentBudget) : currentBudget{ _currentBudget }, totalProfit{ 0 }, totalSpendings{0}
{
	spendings["no_category"] = std::shared_ptr<Category>{ new SpendingCategory };
	spendings["food"] = std::shared_ptr<Category>{ new FoodSpendings };

	profit["no_category"] = std::shared_ptr<Category>{ new ProfitCategory };
	profit["job"] = std::shared_ptr<Category>{ new JobProfit };
}

void Core::updateBudget()
{
	currentBudget = totalProfit - totalSpendings;
}

double Core::getCurrentBudget() const {
	return currentBudget;
}

double Core::getTotalProfit() const {
	return totalProfit;
}

double Core::getTotalSpendings() const {
	return totalSpendings;
}

void Core::addSpending(double amount, std::string category)
{
	*spendings[category] += amount;
	totalSpendings += amount;
	updateBudget();
}

void Core::addProfit(double amount, std::string category)
{
	*profit[category] += amount;
	totalProfit += amount;
	updateBudget();
}

std::vector<shared_ptr<Category>> Core::getListAsc(const std::map<std::string, std::shared_ptr<Category>>& mapToSort)
{
	std::vector<shared_ptr<Category>> list;

	for (auto& category : mapToSort)
	{
		list.push_back(category.second);
	}

	std::sort(list.begin(), list.end());
	return list;
}

std::vector<shared_ptr<Category>> Core::getListDesc(const std::map<std::string, std::shared_ptr<Category>>& mapToSort)
{

	std::vector<shared_ptr<Category>> list;

	for (auto& category : mapToSort)
	{
		list.push_back(category.second);
	}

	std::sort(list.begin(), list.end(), [](const shared_ptr<Category> cat1, const shared_ptr<Category> cat2) {
		return *cat1 > *cat2;
	});
	return list;
}

void Core::showList(vector < shared_ptr<Category> > list)
{
	for (auto& category : list)
	{
		category->showTotalAmount();
	}
}

void Core::showProfitListAsc()
{
	showList(getListAsc(profit));
}

void Core::showProfitListDesc()
{
	showList(getListDesc(profit));
}

void Core::showSpendingsListAsc()
{
	showList(getListAsc(spendings));
}

void Core::showSpendingsListDesc()
{
	showList(getListDesc(spendings));
}