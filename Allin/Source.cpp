#include "User.h"
#include <queue>

unordered_map<string, User> user;
vector<Product> allProduct;
vector<Product> tmpProduct;
queue<pair<string, Cart>> toBeDeliver;

void startUp();
void copyAllProducts();
void customerProgram(Customer& customer);
void sellerProgram(Seller& seller);

int main()
{
	startUp();
	return 0;
}

void startUp()
{
	while (true)
	{
		system("cls");
		cout << "Welcome to Allin Marketplace !!\n";
		cout << "press 1 to log in, 2 to sign up and any other number to exit\n";
		int n;
		cin >> n;
		if (n == 1)
		{
			string mail = User::userLogIn(user);
			if (mail != "") {
				system("cls");
				cout << "WELCOME " << user[mail].name << " !!\n";
				cout << "press 1 for Customers, 2 for Sellers and any other number to exit\n";
				int choice;
				cin >> choice;
				if (choice == 1)
					customerProgram(user[mail].customer);
				else if (choice == 2)
					sellerProgram(user[mail].seller);
				continue;
			}
		}
		else if (n == 2)
		{
			User::userSignUp(user);
			continue;
		}
		else
			break;

	}
}
void customerProgram(Customer& customer)
{
	copyAllProducts();
start:
	tmpProduct.clear();
	cout << "press 1 to search by name, 2 to browse by category, 3 to display cart, 4 to delete from cart, 5 to calculate total & checkout\n";
	int browseChoice;
	cin >> browseChoice;
	switch (browseChoice)
	{
	case 1:
		if (customer.search(allProduct, tmpProduct)) {
			Product selectedItem = customer.selectItem(allProduct, tmpProduct);
			user[selectedItem.sellerEmail].seller.sellItem(selectedItem);
		}
		goto start;
		break;
	case 2:

		if (customer.selectCategory(allProduct, tmpProduct)) {
			Product selectedItem = customer.selectItem(allProduct, tmpProduct);
			user[selectedItem.sellerEmail].seller.sellItem(selectedItem);
		}
		goto start;
		break;

	case 3:

		system("cls");
		customer.cart.displayCart();
		if (customer.cart.items.empty())
			cout << "your cart is empty\n";
		goto start;
		break;

	case 4:
		if (customer.cart.items.empty()) {
			system("cls");
			cout << "your cart is empty\n";
		}
		else {
			Product returnedItem = customer.returnItem(allProduct);
			user[returnedItem.sellerEmail].seller.returnItem(returnedItem);
		}
		goto start;
		break;

	case 5:
		if (!customer.cart.items.empty()) {
			system("cls");
			customer.cart.total();
			cout << "To checkout press 1" << endl;
			int choice;
			cin >> choice;
			if (choice == 1) {
				pair<string, Cart> order;
				order.first = customer.email;
				order.second = customer.checkout();
				toBeDeliver.push(order);
			}
			else
				goto start;
		}
		else
		{
			system("cls");
			cout << "your cart is empty add items" << endl;
			goto start;
		}
		break;
	default:
		break;

	}
}
void sellerProgram(Seller& seller)
{
start:
	cout << "press 1 to add product, 2 to remove product, 3 to update product, 4 to display products\nand any other number to exit\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case  1:

		seller.addProduct();
		goto start;
		break;

	case 2:

		seller.deleteProduct();
		goto start;
		break;

	case 3:

		seller.updateProduct();
		goto start;
		break;

	case 4:

		seller.displayProducts();
		goto start;
		break;

	default:
		break;

	}
}
void copyAllProducts()
{
	unordered_map<string, User>::iterator it;
	it = user.begin();

	for (it = user.begin(); it != user.end(); it++)
	{
		Seller s = it->second.seller;
		for (int i = 0; i < s.products.size(); i++)
			allProduct.push_back(s.products[i]);
	}
}