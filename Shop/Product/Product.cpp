#include <iostream>
#include "Product.h"

using namespace std;

Produkt::Product(string name, string herkunft, int month, int year, int menge, short price) {
	this->name = name;
	this->herkunft = herkunft;
	this->haltbarkeit.month = month;
	this->haltbarkeit.year = year;
	this->menge = menge;
	this->price = price;
}

void Product::set_name(string x) {
	this->name = x;
}

void Product::set_herkunft(string x) {
	this->herkunft = x;
}

void Product::set_haltbarkeit_month(int x) {
	this->haltbarkeit.month = x;
}

void Product::set_haltbarkeit_year(int x) {
	this->haltbarkeit.year = x;
}

void Product::set_menge(int x) {
	this->menge = x;
}

void Product::set_price(short x) {
	this->price = x;
}

string Product::get_name() {
	return this->name;
}

string Product::get_herkunft() {
	return this->herkunft;
}

int Product::get_haltbarkeit_month() {
	return this->haltbarkeit.month;
}

int Product::get_haltbarkeit_year() {
	return this->haltbarkeit.year;
}


int Product::get_menge() {
	return this->menge;
}

short Product::get_price() {
	return this->price;
}