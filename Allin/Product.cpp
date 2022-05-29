#include "Product.h"
int Product::counter = 1000;
void Product::display()
{
	cout << "{ Name : " << name
		<< " , Price : " << price
		<< " , Category : " << category;
	if (quantity)cout << " , Quantity : " << quantity;
	else cout<< " , Out of Stock ";
	cout << " , sellerEmail : " << sellerEmail
		<< " , id : " << id
		<< " , rate : " << rate
		<< " }";
}
void Product::addRate(double r)
{
	rate = (rate * rateCounter + r) / (rateCounter + 1);
	rateCounter++;
}
void Product::removeRate(double r)
{
	rate = (rate * rateCounter - r) / (rateCounter - 1);
	rateCounter--;
}
