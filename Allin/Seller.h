#pragma once
#include "Product.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Seller
{
public:
	string email;
	int categoryList[5] = { 1,2,3,4,5 };
	vector<Product> products;
	vector<Product> soldProducts;

	Seller();
	void addProduct();
	void displayProducts();
	void displaySoldProducts();
	void deleteProduct();
	void updateProduct();
	void sellItem(Product selectedItem);
	void returnItem(Product returnedItem);
	~Seller();
};

