#include "User.h"
User::User()
{
	seller.email = email;
	customer.email = email;
}
User::User(string name, string email, string password, string phoneNum, string address)
{
	this->name = name;
	this->email = email;
	this->password = password;
	this->phoneNum = phoneNum;
	this->address = address;
	this->customer = customer;
	seller.email = email;
	customer.email = email;
}
void User::userSignUp(unordered_map<string, User>& user)
{
	User tmpUser;
	cout << "enter name\n";
	cin >> tmpUser.name;
start:
	cout << "enter email\n";
	cin >> tmpUser.email;
	transform(tmpUser.email.begin(), tmpUser.email.end(), tmpUser.email.begin(), tolower);
	if (user[tmpUser.email].email != "")
	{
		cout << "this email already exists\n";
		goto start;
	}
	tmpUser.seller.email = tmpUser.email;
	tmpUser.customer.email = tmpUser.email;
	cout << "enter password\n";
	cin >> tmpUser.password;
	cout << "enter phoneNum\n";
	cin >> tmpUser.phoneNum;
	cout << "enter address\n";
	cin >> tmpUser.address;
	user[tmpUser.email] = tmpUser;
}
string User::userLogIn(unordered_map<string, User>& user)
{
	string mail, pass;
	cout << "enter email:";
	cin >> mail;
	cout << "enter password:";
	cin >> pass;
	transform(mail.begin(), mail.end(), mail.begin(), tolower);

	if (user[mail].email != "")
	{
		if (user[mail].password == pass){
			return mail;
		}
		else
			cout << "wrong password" << endl;
	}
	else
		cout << "wrong email" << endl;
	return "";
}
User::~User()
{
}