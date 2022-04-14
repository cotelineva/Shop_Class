#include <iostream>
#include "Controller.h"
#include "Product.h"
#include "Repository.h"

using namespace std;


Controller::Controller(Repository repo) {
	this->repo = repo;
}

bool Controller::add_product(Product x) {
	return this->repo.add_product(x);
}

bool Controller::delete_product(string name) {
	return this->repo.delete_product(name);
}

vector<string> Controller::available_products(string identifier) {
	return this->repo.available_products(identifier);
}

void Controller::knapp(int x) {
	this->repo.knapp(x);
}

vector<Produkt> Controller::haltbarkeit_sort() {
	return this->repo.haltbarkeit_sort();
}

bool Controller::edit_name(string old_name, string new_name) {
	return this->repo.edit_name(old_name, new_name);
}

bool Controller::edit_herkunft(string name, string new_herkunft) {
	return this->repo.edit_herkunft(name, new_herkunft);
}

bool Controller::edit_haltbarkeit(string name, int new_month, int new_year) {
	return this->repo.edit_haltbarkeit(name, new_month, new_year);
}

bool Controller::edit_menge(string name, int new_menge) {
	return this->repo.edit_menge(name, new_menge);
}

bool Controller::edit_price(string name, short new_price) {
	return this->repo.edit_price(name, new_price);
}

void Controller::print() {
	this->repo.print();
}