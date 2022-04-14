#pragma once
#include <iostream>
#include "Produkt.h"
#include "Repository.h"

using namespace std;

class Controller {
private:
	repository repo;
public:

	Controller(repository repo);
	bool add_product(Product x);
	bool delete_product(string name);

	vector<string> available_products(string identifier);
	void knapp(int x);
	vector<Produkt> haltbarkeit_sort();

	bool edit_name(string old_name, string new_name);
	bool edit_herkunft(string name, string new_herkunft);
	bool edit_haltbarkeit(string name, int new_month, int new_year);
	bool edit_menge(string name, int new_menge);
	bool edit_price(string name, short new_price);

	void print();

};
