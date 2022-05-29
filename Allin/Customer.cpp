#include "Customer.h"
Customer::Customer()
{
}
bool Customer::search(vector<Product>& allProduct, vector<Product>& tmpProduct)
{
	string seachString;
	cout << "Search : ";
	cin >> seachString;
	for (unsigned int i = 0; i < allProduct.size(); i++)
	{
		int found;
		found = allProduct[i].name.find(seachString);
		if (found != string::npos)
		{
			tmpProduct.push_back(allProduct[i]);
		}
	}
	if (!tmpProduct.empty())
	{
		for (unsigned int i = 0; i < tmpProduct.size(); i++)
		{
			cout << i << " - ";
			tmpProduct[i].display();
			cout << endl;
		}
		return true;
	}
	else
	{
		cout << "Not Found\n";
		return false;
	}
}
bool Customer::selectCategory(vector<Product>& allProduct, vector<Product>& tmpProduct)
{
	cout << "category : 1 for Appliances, 2 for Cars, 3 for Clothing, 4 for Electronics, 5 for Toys \n";
	int choice;
	cin >> choice;
	for (int i = 0; i < allProduct.size(); i++)
	{
		if (choice == allProduct[i].category)
		{
			tmpProduct.push_back(allProduct[i]);
		}
	}
	for (int i = 0; i < tmpProduct.size(); i++)
	{
		cout << "number: " << i << "-";
		tmpProduct[i].display();
	}
	if (!tmpProduct.empty())
	{
		for (unsigned int i = 0; i < tmpProduct.size(); i++)
		{
			cout << i << " - ";
			tmpProduct[i].display();
			cout << endl;
		}
		return true;
	}
	else
	{
		cout << "Not Found\n";
		return false;
	}
}
Product Customer::selectItem(vector<Product>& allProduct, vector<Product>& tmpProduct)
{
	while (true)
	{
		cout << "enter number of the item you want to add or -1 to return\n";
		int choice;
		cin >> choice;
		if (choice >= 0 && choice < tmpProduct.size())
		{
			Product selectedItem = tmpProduct[choice];
			//Quantity
		enterQuantity:
			cout << "enter quantity\n";
			int quantity;
			cin >> quantity;
			//check available quantity
			if (quantity <= selectedItem.quantity && quantity > 0)
				selectedItem.quantity = quantity;
			else
			{
				cout << "the available quantity is: " << selectedItem.quantity << endl;
				goto enterQuantity;
			}
			//rate
			cout << "enter rating from 1 to 5\n";
			cin >> selectedItem.rate;
			//allProduct
			allProduct[choice].quantity -= selectedItem.quantity;
			allProduct[choice].addRate(selectedItem.rate);

			cart.addItem(selectedItem);
			return selectedItem;
		}
		else if (choice == -1)
			break;
		else
			cout << "enter a valid number";
	}
	tmpProduct.clear();
}
Product Customer::returnItem(vector<Product>& allProduct)
{
	Product returnedItem;
	cart.displayCart();
	cout << "enter number of item you want to remove\n" << endl;
	int choice;
	cin >> choice;
	returnedItem = cart.items[choice];
	cart.removeItem(choice);
	for (unsigned int i = 0; i < allProduct.size(); i++)
	{
		if (returnedItem.id == allProduct[i].id)
		{
			allProduct[i].quantity += returnedItem.quantity;
			allProduct[choice].removeRate(returnedItem.rate);
			break;
		}
	}
	return returnedItem;
}
Cart Customer::checkout()
{
	cart.displayCart();
	purchaseCarts.push(cart);
	cart = Cart();
	return purchaseCarts.top();
}
Customer::~Customer()
{
}
