#include <iostream>
#include <algorithm>
#include "Product.h"
#include "Repository.h"
#include "Controller.h"

using namespace std;

Repository::Repository() {

}

Repository::Repository(vector<Product> p) {
	this->p = {};
}

bool Repository::add_product(Product x) {
	//wenn wir das Produkt noch nicht haben, return true
	//wenn das Produkt schon existiert, dann wachst die menge, return false

	bool ok = false;
	for(int i=0; i<this->p.size();i++){
		if (this->p[i].get_name() == x.get_name()) {
			this->p[i].set_menge(this->p[i].get_menge() + x.get_menge());
			ok = true;
		}
	}
	if (ok != true) {
		this->p.emplace_back(x);
		return true;
	}
	return false;
}

bool Repository::delete_product(string name) {
	//wenn produkt geloscht wird, return true
	//wenn menge des produkts decrementiert wird, return false

	for (int i = 0; i < this->p.size(); i++) {
		if (this->p[i].get_name() == name) {

			if (this->p[i].get_menge() != 0) {
				this->p[i].set_menge(this->p[i].get_menge() - 1);
				return false;
			}
			else {
				this->p.erase(this->p.begin() + i);
				return true;
			}
		}
	}
	return false;
}

vector<string> Repository::available_products(string identifier) {
	vector<string> new_list = {};
	bool ok = true;

	for (int i = 0; i < this->p.size(); i++) {
		if (this->p[i].get_name().find(identifier) != string::npos && ok == true) {
			new_list.emplace_back(this->p[i].get_name());
		}
		if (identifier == "1") {
			ok = false;
			for (int j = 0; j < this->p.size(); j++) {
				new_list.emplace_back(this->p[j].get_name());
			}
			sort(new_list.begin(), new_list.end());
			return new_list;
		}
	}
	sort(new_list.begin(), new_list.end());

	return new_list;
}

void Repository::knapp(int x) {
	vector<Product> new_list;
	for (int i = 0; i < this->p.size(); i++) {
		if (this->p[i].get_menge() <= x) {
			new_list.emplace_back(this->p[i]);
		}
	}
	for (int i = 0; i < new_list.size(); i++) {
		cout << "Name:" << new_list[i].get_name() << "\n";
		cout << "\tHerkunft:" << new_list[i].get_herkunft() << "\n";
		cout << "\tHaltbarkeit:" << new_list[i].get_haltbarkeit_month() << "/" << new_list[i].get_haltbarkeit_year() << "\n";
		cout << "\tMenge:" << new_list[i].get_menge() << "\n";
		cout << "\tPreis:" << new_list[i].get_price() << "\n";
		cout << endl;
	}
}
vector<Product> Repository::haltbarkeit_sort() {
	Product aux("", "", 0, 0, 0, 0);
	vector<Produkt> new_v;

	for (int i = 0; i < this->p.size() - 1; i++) {
		for (int j = i + 1; j < this->p.size(); j++) {
			if (this->p[i].get_haltbarkeit_year() > this->p[j].get_haltbarkeit_year()) {
				aux = this->p[i];
				this->p[i] = this->p[j];
				this->p[j] = aux;
			}
			else {
				if (this->p[i].get_haltbarkeit_year() == this->p[j].get_haltbarkeit_year()) {
					if (this->p[i].get_haltbarkeit_month() > this->p[j].get_haltbarkeit_month()) {
						aux = this->p[i];
						this->p[i] = this->p[j];
						this->p[j] = aux;
					}
				}
			}
		}
	}

	new_v = this->p;
	return new_v;
}

bool Repository::edit_name(string old_name, string new_name){
	bool ok = false;
	for (int i = 0; i < this->p.size(); i++) {
		if (this->p[i].get_name() == old_name) {
			this->p[i].set_name(new_name);
			ok = true;
		}
	}
	if (ok == true)
		return true;
	else
		return false;
}

bool Repository::edit_herkunft(string name, string new_herkunft){
	bool ok = false;
	for (int i = 0; i < this->p.size(); i++) {
		if (this->p[i].get_name() == name) {
			this->p[i].set_herkunft(new_herkunft);
			ok = true;
		}
	}
	if (ok == true)
		return true;
	else
		return false;
}

bool Repository::edit_haltbarkeit(string name, int new_month, int new_year){
	bool ok = false;
	for (int i = 0; i < this->p.size(); i++) {
		if (this->p[i].get_name() == name) {
			this->p[i].set_haltbarkeit_month(new_month);
			this->p[i].set_haltbarkeit_year(new_year);
			ok = true;
		}
	}
	if (ok == true)
		return true;
	else
		return false;
}

bool Repository::edit_menge(string name, int new_menge){
	bool ok = false;
	for (int i = 0; i < this->p.size(); i++) {
		if (this->p[i].get_name() == name) {
			this->p[i].set_menge(this->p[i].get_menge() + new_menge);
			ok = true;
		}
	}
	if (ok == true)
		return true;
	else
		return false;
}

bool Repository::edit_price(string name, short new_price){
	bool ok = false;
	for (int i = 0; i < this->p.size(); i++) {
		if (this->p[i].get_name() == name) {
			this->p[i].set_price(new_price);
			ok = true;
		}
	}
	if (ok == true)
		return true;
	else
		return false;
}

void Repository::print() {
	for (int i = 0; i < this->p.size(); i++) {
		cout << "Name:" << this->p[i].get_name() << "\n";
		cout << "\tHerkunft:" << this->p[i].get_herkunft() << "\n";
		cout << "\tHaltbarkeit:" << this->p[i].get_haltbarkeit_month() << "/" << this->p[i].get_haltbarkeit_year() << "\n";
		cout << "\tMenge:" << this->p[i].get_menge() << "\n";
		cout << "\tPreis:" << this->p[i].get_price() << "\n";
		cout << endl;
	}
}