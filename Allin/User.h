#pragma once
#include "Customer.h"
#include "Seller.h"
#include <unordered_map>
class User
{
public:
	string name;
	string email;
	string password;
	string phoneNum;
	string address;
	Customer customer;
	Seller seller;

	User();
	User(string name,string email,string password,string phoneNum,string address);
	static void userSignUp(unordered_map<string, User>& user);
	static string userLogIn(unordered_map<string, User>& user);
	~User();
};
