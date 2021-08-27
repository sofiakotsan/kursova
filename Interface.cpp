#include "Interface.h"
using namespace std;

void Interface::showMenu()
{
	cout << "\tMenu" << endl;
	cout << "1 - add profit" << endl;
	cout << "2 - add spending" << endl;
	cout << "3 - show profit asc" << endl;
	cout << "4 - show profit desc" << endl;
	cout << "5 - show spendings asc" << endl;
	cout << "6 - show spendings desc" << endl;
	cout << "7 - show current budget" << endl;
	cout << "8 - show total profit" << endl;
	cout << "9 - show total spendings" << endl;
	cout << "0 - exit" << endl;
}

void Interface::run()
{
	while (true)
	{
		system("cls");

		showMenu();
		int action;
		cout << "Your choise: ", cin >> action;

		int amount;
		char addCategory;
		string category = "no_category";
		system("cls");


		switch (action)
		{
		case 0:
			return;
		case 1:
			cout << "Enter profit: ", cin >> amount;
			cout << "Do you wan to add category? y/n: ", cin >> addCategory;
			if (addCategory == 'y')
			{
				cout << "Name of category: ", cin >> category;
			}
			core.addProfit(amount, category);
		break;
		case 2:
			cout << "Enter spending: ", cin >> amount;
			cout << "Do you wan to add category? y/n: ", cin >> addCategory;
			if (addCategory == 'y')
			{
				cout << "Name of category: ", cin >> category;
			}
			core.addSpending(amount, category);
		break;
		case 3:
			core.showProfitListAsc();
		break;
		case 4:
			core.showProfitListDesc();
		break;
		case 5:
			core.showSpendingsListAsc();
			break;
		case 6:
			core.showSpendingsListDesc();
		break;
		case 7:
			cout << "Current budget: " << core.getCurrentBudget() << endl;
		break;
		case 8:
			cout << "Total profit: " << core.getTotalProfit() << endl;
		break;
		case 9:
			cout << "Total spendings: " << core.getTotalSpendings() << endl;
		break;
		default:
			break;
		}
		system("pause");
	}
}
