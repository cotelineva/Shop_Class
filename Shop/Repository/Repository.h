#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Product.h"

using namespace std;

class Repository {
private:
	vector<Product> p;

public:
	Repository(vector<Product> p);
	Repository();
	
	bool add_product(Product x);
	bool delete_product(string name);

	vector<string> available_products(string identifier);
	void knapp(int x);
	vector<Product> haltbarkeit_sort();

	bool edit_name(string old_name, string new_name);
	bool edit_herkunft(string name, string new_herkunft);
	bool edit_haltbarkeit(string name, int new_month, int new_year);
	bool edit_menge(string name, int new_menge);
	bool edit_price(string name, short new_price);

	void print();
};