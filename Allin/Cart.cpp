#include "Cart.h"

void Cart::addItem(Product addedProduct)
{
	bool addedBefore = false;
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (addedProduct.id == items[i].id)
		{
			addedBefore = true;
			items[i].quantity += addedProduct.quantity;
			break;
		}
	}
	if (!addedBefore) {
		items.push_back(addedProduct);
		totalPrice += addedProduct.price;
		itemsCounter++;
	}
}
void Cart::removeItem(int s)
{
	totalPrice -= items[s].price;
	items.erase(items.begin() + s);
	itemsCounter--;
}
void Cart::total()
{
	float total = 0;
	float r;
	cout << "\n";
	for (unsigned int n = 0; n < items.size(); n++)
	{
		r = items[n].price * items[n].quantity;
		cout << items[n].name <<" * " << items[n].quantity << "=" << r << endl;
		total += r;
	}
	cout << "\n\ntotal:" << total << endl;
	r = total + (total * 0.14);
	cout << "tax:" << float(total * 0.14) << endl;
	cout << "grandtotal:" << r << endl;
	items.clear();
}
void Cart::displayCart()
{
	for (int n = 0; n < items.size(); n++)
	{
		cout << n << "-";
		items[n].display();
		cout << endl;
	}
}