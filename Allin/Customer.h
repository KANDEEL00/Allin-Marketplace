#pragma once
#include <algorithm>
#include "Cart.h"
#include <stack>
using namespace std;
class Customer
{
public:
	string email;
	Cart cart;
	stack<Cart> purchaseCarts;

	Customer();
	bool search(vector<Product>& allProduct, vector<Product>& tmpProduct);
	bool selectCategory(vector<Product>& allProduct, vector<Product>& tmpProduct);
	Product selectItem(vector<Product>& allProduct, vector<Product>& tmpProduct);
	Product returnItem(vector<Product>& allProduct);
	Cart checkout();
	~Customer();
};

