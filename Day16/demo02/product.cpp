#include "product.h"
#include <cstring>
#include <iostream>
using namespace std;

// class members definition
product::product(const char* title, double price) {
	strcpy(this->title, title);
	this->price = price;
}

//virtual:-> virtual not needed in definition, only in declaration
void product::accept() {
	cout << "title: ";
	cin >> title;
	cout << "price: ";
	cin >> price;
}

//virtual
void product::display() {
	cout << "title: " << title << endl;
	cout << "price: " << price << endl;
}

double product::get_price() {
	return this->price;
}

void product::set_price(double price) {
	this->price = price;
}

const char* product::get_title() {
	return this->title;
}

void product::set_title(const char* title) {
	strcpy(this->title, title);
}