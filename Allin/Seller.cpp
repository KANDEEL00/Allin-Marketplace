#include "Seller.h"
Seller::Seller()
{
}
void Seller::addProduct()
{
	Product newProd;
	cout << "name : ";
	cin >> newProd.name;
	cout << "price : ";
	cin >> newProd.price;
	cout << "category : 1 for Appliances, 2 for Cars, 3 for Clothing, 4 for Electronics, 5 for Toys\n";
	int n;
	cin >> n;
	newProd.category = categoryList[n - 1];
	cout << "quantity : ";
	cin >> newProd.quantity;
	newProd.sellerEmail = email;
	newProd.id = newProd.counter;
	newProd.counter++;
	products.push_back(newProd);
}
void Seller::displayProducts()
{
	for (int i = 0; i < products.size(); i++) {
		cout << i << " - ";
		products[i].display();
		cout << endl;
	}
}
void Seller::displaySoldProducts()
{
	for (unsigned int i = 0; i < soldProducts.size(); i++) {
		cout << i << " - ";
		soldProducts[i].display();
		cout << endl;
	}
}
void Seller::deleteProduct()
{
	displayProducts();
	if (!products.empty())
	{
		cout << "enter number of the product you want to delete" << endl;
		int i;
		cin >> i;
		products.erase(products.begin() + i);
	}
	else
		cout << "you have no products\n";
}
void Seller::updateProduct()
{
	bool otherProduct = 1;
	if (products.empty())
	{
		otherProduct = 0;
		cout << "you have no products\n";
	}
	else
		displayProducts();

	while (otherProduct)
	{
		int i;
		cout << "enter number of the product you want to update" << endl;
		cin >> i;
		bool otherUpdate = 1;
		while (otherUpdate)
		{
			cout << "select what do you want to edit" << endl;
			cout << " 1 -  name , 2 - Price  , 3 - category  , 4 - quantity " << endl;
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
				cout << "name : " << endl;
				cin >> products[i].name;
				break;
			case 2:
				cout << "price : " << endl;
				cin >> products[i].price;
				break;
			case 3:
				cout << "category : " << endl;
				cin >> products[i].category;
				break;
			case 4:
				cout << "quantity : " << endl;
				cin >> products[i].quantity;
				break;
			default:
				break;
			}
			cout << "if you want update something else press 1 if not press 0" << endl;
			cin >> otherUpdate;
		}
		cout << "if you want to update another product press 1 if not press 0" << endl;
		cin >> otherProduct;
	}
}
void Seller::sellItem(Product selectedItem)
{
	for (unsigned int j = 0; j < products.size(); j++)
	{
		if (selectedItem.id == products[j].id)
		{
			products[j].quantity -= selectedItem.quantity;
			products[j].addRate(selectedItem.rate);
			break;
		}
	}
	bool soldBefore = false;
	for (unsigned int j = 0; j < soldProducts.size(); j++) {
		if (selectedItem.id == soldProducts[j].id)
		{
			soldBefore = true;
			soldProducts[j].quantity += selectedItem.quantity;
			soldProducts[j].addRate(selectedItem.rate);
			break;
		}
	}
	if (!soldBefore)
		soldProducts.push_back(selectedItem);
}
void Seller::returnItem(Product returnedItem)
{
	for (unsigned int j = 0; j < products.size(); j++)
	{
		if (returnedItem.id == products[j].id)
		{
			products[j].quantity += returnedItem.quantity;
			products[j].removeRate(returnedItem.rate);
			break;
		}
	}
	for (unsigned int j = 0; j < soldProducts.size(); j++) {
		if (returnedItem.id == soldProducts[j].id)
		{
			soldProducts[j].quantity -= returnedItem.quantity;
			soldProducts[j].removeRate(returnedItem.rate);
			break;
		}
	}
}
Seller::~Seller()
{
}

