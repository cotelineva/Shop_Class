#pragma once
#include <iostream>
#include <string>

using namespace std;

struct date {
	int month;
	int year;
};

class Product {
private:
	string name;
	string herkunft;
	date haltbarkeit;
	int menge;
	short price;

public:
	Product(string name, string herkunft, int month, int year, int menge, short price);

	void set_name(string x);
	void set_herkunft(string x);
	void set_haltbarkeit_month(int x);
	void set_haltbarkeit_year(int x);
	void set_menge(int x);
	void set_price(short x);

	string get_name();
	string get_herkunft();
	int get_haltbarkeit_month();
	int get_haltbarkeit_year();
	int get_menge();
	short get_price();

};