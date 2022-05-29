#pragma once
#include "Product.h"
using namespace std;
class Cart
{
public:
	vector<Product> items;
	int itemsCounter = 0;
	int totalPrice;

	void addItem(Product s);
	void removeItem(int s);
	void displayCart();
	void total();
};

