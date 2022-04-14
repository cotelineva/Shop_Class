#include <iostream>
#include "Product.h"
#include "Repository.h"
#include "Controller.h"
#include "ui.h"

using namespace std;


void menu(){
	Product apple("apple", "romania", 7, 2020, 1, 3);
	Product pear("pear", "germany", 9, 2021, 4, 5);
	Product orange("orange", "grece", 1, 2022, 11, 9);
	Product banana("banana", "afrika", 10, 2021, 9, 10);
	Product ananas("ananas", "afrika", 10, 2022, 18, 10);
	Product grape("grape", "bulgaria", 7, 2020, 30, 14.5);
	Product melon("melon", "turkey", 12, 2021, 100, 20);
	Product strawberry("strawberry", "romania", 2, 2022, 40, 10.9);
	Product blackberry("blackberry", "spain", 3, 2020, 101, 20.99);
	Product cranberry("cranberry", "austria", 4, 2022, 300, 9.99);

	Repository r;
	r.Repository::Repository();
	Controller c(r);

	c.add_product(apple);
	c.add_product(pear);
	c.add_product(orange);
	c.add_product(banana);
	c.add_product(ananas);
	c.add_product(grape);
	c.add_product(melon);
	c.add_product(strawberry);
	c.add_product(blackberry);
	c.add_product(cranberry);


	int x, z;

	cout << "\tHallo zum Obstladen!\n\n";

	cout << "MAIN MENU\nWas wollen Sie tun?\n\t";
	cout << "Press\n";
	cout << "\t1 - to add produkt\n";
	cout << "\t2 - to delete produkt\n";
	cout << "\t3 - to show produkt with name (or part of it)\n";
	cout << "\t4 - to show few in stock produkts\n";
	cout << "\t5 - to edit produkt\n";
	cout << "\t6 - to show products with ascending expiring date\n";
	cout << "\t0 - to exit main menu\n";

	cout << "Your key:";
	cin >> x;
	while (x < 0 || x>6) {
		cout << "\nKey must be between 0 and 6! Try again: ";
		cin >> x;
	}
	cout << endl;
	

	while (x != 0) {
		if (x == 1) {
			string name, land;
			int month, year, quantity;
			short price;
			bool ok;

			cout << "Name of produkt: \n";
			cin >> name;
			cout << "Herkunft of produkt: \n";
			cin >> land;
			cout << "Expire month of produkt: \n";
			cin >> month;
			while (month < 1 || month>12) {
				cout << "Month can be only between 1 and 12. Try again: ";
				cin >> month;
			}
			cout << "Expire year of produkt: \n";
			cin >> year;
			while (year < 2020) {
				cout << "Year must be at least 2020. Try again: ";
				cin >> year;
			}
			cout << "Menge of produkt: \n";
			cin >> quantity;
			while (quantity < 1) {
				cout << "Quantity must be at least 1. Try again: ";
				cin >> quantity;
			}
			cout << "Price of produkt: \n";
			cin >> price;
			while (price <= 0) {
				cout << "Price must be higher than 0. Try again: ";
				cin >> price;
			}

			Produkt p(name, land, month, year, quantity, price);
			ok = c.add_product(p);
			if (ok == true) {
				cout << "Produkt has been added!\n";
			}
			else {
				cout << "Produkt already existed. Quantity was increased!\n";
			}
			
			
			cout << "MAIN MENU\nWas wollen Sie tun?\n\t";
			cout << "Press\n";
			cout << "\t1 - to add produkt\n";
			cout << "\t2 - to delete produkt\n";
			cout << "\t3 - to show produkt with name (or part of it)\n";
			cout << "\t4 - to show few in stock produkts\n";
			cout << "\t5 - to edit produkt\n";
			cout << "\t6 - to show products with ascending expiring date\n";
			cout << "\t0 - to exit main menu\n";

			cout << "\nEnter a new key: ";
			cin >> z;
			while (z < 0 || z > 6) {
				cout << "\nKey must be between 0 and 6! Try again: ";
				cin >> z;
			}
			x = z;
		}


		if (x == 2) {
			string name;
			bool ok;

			cout << "Name of produkt: \n";
			cin >> name;

			ok = c.delete_product(name);
			if (ok == true) {
				cout << "Produkt was deleted!\n";
			}
			else {
				cout << "Quantity was decreased or product does not exist!\n";
			}
			
			cout << "MAIN MENU\nWas wollen Sie tun?\n\t";
			cout << "Press\n";
			cout << "\t1 - to add produkt\n";
			cout << "\t2 - to delete produkt\n";
			cout << "\t3 - to show produkt with name (or part of it)\n";
			cout << "\t4 - to show few in stock produkts\n";
			cout << "\t5 - to edit produkt\n";
			cout << "\t6 - to show products with ascending expiring date\n";
			cout << "\t0 - to exit main menu\n";

			cout << "\nEnter a new key: ";
			cin >> x;
			while (x < 0 || x>6) {
				cout << "\nKey must be between 0 and 6! Try again: ";
				cin >> x;
			}
		}


		if (x == 3) {
			string name;
			vector<string> new_vect;
			
			cout << "Write name or part of a name \n";
			cin >> name;

			new_vect = c.available_products(name);
			cout << "\nAVALABLE PRODUKTS:\n";
			if (new_vect.size() == 0) {
				cout << "NONE\n\n";
			}
			else {
				for (int i = 0; i < new_vect.size(); i++) {
					cout << new_vect[i] << "\n";
				}
			}

			cout << "MAIN MENU\nWas wollen Sie tun?\n\t";
			cout << "Press\n";
			cout << "\t1 - to add produkt\n";
			cout << "\t2 - to delete produkt\n";
			cout << "\t3 - to show produkt with name (or part of it)\n";
			cout << "\t4 - to show few in stock produkts\n";
			cout << "\t5 - to edit produkt\n";
			cout << "\t6 - to show products with ascending expiring date\n";
			cout << "\t0 - to exit main menu\n";

			cout << "\nEnter a new key: ";
			cin >> x;
			while (x < 0 || x>6) {
				cout << "\nKey must be between 0 and 6! Try again: ";
				cin >> x;
			}
		}


		if (x == 4) {
			int nr;

			cout << "You want the show the produkts with quantity less than: \n";
			cin >> nr;

			c.knapp(nr);

			cout << "MAIN MENU\nWas wollen Sie tun?\n\t";
			cout << "Press\n";
			cout << "\t1 - to add produkt\n";
			cout << "\t2 - to delete produkt\n";
			cout << "\t3 - to show produkt with name (or part of it)\n";
			cout << "\t4 - to show few in stock produkts\n";
			cout << "\t5 - to edit produkt\n";
			cout << "\t6 - to show products with ascending expiring date\n";
			cout << "\t0 - to exit main menu\n";

			cout << "\nEnter a new key: ";
			cin >> x;
			while (x < 0 || x>6) {
				cout << "\nKey must be between 0 and 6! Try again: ";
				cin >> x;
			}
		}


		if (x == 5) {
			int y;
			string name, land, name2;
			int month, year, quantity;
			short price;
			bool ok;


			cout << "Press:\t";
			cout << "1 - to edit name\n\t";
			cout << "2 - to edit herkunft\n\t";
			cout << "3 - to edit expire date\n\t";
			cout << "4 - to edit menge\n\t";
			cout << "5 - to edit preis\n\t";
			cout << "0 - to exit editing\n";
			cout << "Your key:";

			cin >> y;
			while (y < 0 || y > 5) {
				cout << "Key MUST be between 0 and 5! Try again:";
				cin >> y;
			}
			cout << endl;

			while (y != 0) {


				if (y == 1) {
					cout << "\nWhat is the name of the produkt?\n";
					cin >> name;
					cout << "\nEnter a new name: ";
					cin >> name2;
					ok = c.edit_name(name, name2);
					if (ok == true) {
						cout << "\nChanged!\n";
					}
					else {
						cout << "\nProdukt with that name does not exist!\n";
					}
				}


				if (y == 2) {
					cout << "\nWhat is the name of the produkt?\n";
					cin >> name;
					cout << "\nEnter a new herkunft: ";
					cin >> land;
					ok = c.edit_herkunft(name, land);
					if (ok == true) {
						cout << "\nChanged!\n";
					}
					else {
						cout << "\nProdukt with that name does not exist!\n";
					}
				}


				if (y == 3) {
					cout << "\nWhat is the name of the produkt?\n";
					cin >> name;

					cout << "\nEnter a new expiring month: ";
					cin >> month;
					while (month < 1 || month > 12) {
						cout << "Month must be between 1 and 12! Enter new:";
						cin >> month;
					}

					cout << "\nEnter a new expiring year: ";
					cin >> year;
					while (year < 2020) {
						cout << "Year must be at least 2020! Enter new:";
						cin >> year;
					}
					
					ok = c.edit_haltbarkeit(name, month, year);
					if (ok == true) {
						cout << "\nChanged!\n";
					}
					else {
						cout << "\nProdukt with that name does not exist!\n";
					}
				}


				if (y == 4) {
					cout << "\nWhat is the name of the produkt?\n";
					cin >> name;

					cout << "\nEnter new menge:\n";
					cin >> quantity;
					while (quantity < 1) {
						cout << "Menge must be at least 1! Try again: ";
						cin >> quantity;
					}
					ok = c.edit_menge(name, quantity);
					if (ok == true) {
						cout << "\nChanged!\n";
					}
					else {
						cout << "\nProdukt with that name does not exist!\n";
					}
				}


				if (y == 5) {
					cout << "\nWhat is the name of the produkt?\n";
					cin >> name;

					cout << "Enter new preis:";
					cin >> price;
					while (price <= 0) {
						cout << "Price must be higher than 0! Try again:";
						cin >> price;
					}
					
					ok = c.edit_price(name, price);
					if (ok == true) {
						cout << "\nChanged!\n";
					}
					else {
						cout << "\nProdukt with that name does not exist!\n";
					}
				}

				cout << "Press:\t";
				cout << "1 - to edit name\n\t";
				cout << "2 - to edit herkunft\n\t";
				cout << "3 - to edit expire date\n\t";
				cout << "4 - to edit menge\n\t";
				cout << "5 - to edit preis\n\t";
				cout << "0 - to exit editing\n";
				cout << "Your key:";

				cin >> y;
				while (y < 0 || y > 5) {
					cout << "Key MUST be between 0 and 5! Try again:";
					cin >> y;
				}
				cout << endl;
			}

			cout << "MAIN MENU\nWas wollen Sie tun?\n\t";
			cout << "Press\n";
			cout << "\t1 - to add produkt\n";
			cout << "\t2 - to delete produkt\n";
			cout << "\t3 - to show produkt with name (or part of it)\n";
			cout << "\t4 - to show few in stock produkts\n";
			cout << "\t5 - to edit produkt\n";
			cout << "\t6 - to show products with ascending expiring date\n";
			cout << "\t0 - to exit main menu\n";

			cout << "\nEnter a new key: ";
			cin >> x;
			while (x < 0 || x>6) {
				cout << "\nKey must be between 0 and 6! Try again: ";
				cin >> x;
			}
		}


		if (x == 6) {
			cout << "The Produkt are:\n\n";
			c.haltbarkeit_sort();
			c.print();

			cout << "MAIN MENU\nWas wollen Sie tun?\n\t";
			cout << "Press\n";
			cout << "\t1 - to add produkt\n";
			cout << "\t2 - to delete produkt\n";
			cout << "\t3 - to show produkt with name (or part of it)\n";
			cout << "\t4 - to show few in stock produkts\n";
			cout << "\t5 - to edit produkt\n";
			cout << "\t6 - to show products with ascending expiring date\n";
			cout << "\t0 - to exit main menu\n";

			cout << "\nEnter a new key: ";
			cin >> x;
			while (x < 0 || x>6) {
				cout << "\nKey must be between 0 and 6! Try again: ";
				cin >> x;
			}
		}
	}

}