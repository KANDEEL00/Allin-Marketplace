#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Product
{
public:
	int id;
	string name;
	double price;
	int category;
	int quantity;
	string sellerEmail;
	static int counter;
	double rate = 0;
	int rateCounter = 0;

	void display();
	void addRate(double r);
	void removeRate(double r);
};

