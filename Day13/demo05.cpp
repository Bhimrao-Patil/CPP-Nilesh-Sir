/*
Today’s Agenda:
- Virtual destructor
- ⁠Abstract class
- ⁠Interface

Abstart class - represents conceptual entity (not real-world entity)
- may have data members and member fns --> reused in derived class.
- In c++ , if virtual fun doents have suitable imple or have partial impl
- then the virtual fn shoud be declared as pure virtual fn.
- pure virtual fn is declared by using =0 in the declaration of virtual fn.
- class having atleast one pure virtual fn is called abstract class.
- abstract class can not be used to create object, but it can be used as base class
- abstract class can have data members and member fns, which can be reused in derived class
- pure virtual fn also called as abstract fn, which can be overridden in derived class.
- abstact class doent allowed to create object, but it can be used as base class for inheritance.
- abstract class can have constructor and destructor, which can be used to initialize and cleanup the data members of abstract class.
- abstract class can have member fns with implementation, which can be reused in derived class.
- if pure virtual fn is not overridden in derived class, then derived class also becomes abstract class and can not be used to create object of derived class.
- In other words dervied class also be come abstract class if pure virtual fn is not overridden in derived class.
- Thus derived class is forced to override pure virtual fn of base class, 
- if it want to create object of derived class. otherwise it will become abstract class and can not be used to create object of derived class.



*/
#include <iostream>
#include <cstring>
using namespace std;

class product {
private:
	char title[20];
protected:
	float price;
public:
	product() {
		strcpy(title, "");
		price = 0;
	}
	product(const char* t, int p) {
		strcpy(title, t);
		price = p;
	}
	virtual void accept() = 0 {
		cout << "title: ";
		cin >> title;
		cout << "price: ";
		cin >> price;
	}
	virtual void display() = 0 
	{
		cout << "title: " << title << endl;
		cout << "price: " << price << endl;
	}
	int get_price() {
		return price;
	}
};

class book : public product {
private:
	int pages;
public:
	book() {
		pages = 0;
	}
	book(const char* t, int p, int pg) : product(t, p) {
		pages = pg;
	}
	virtual void accept() {
		product::accept(); // early binding
		cout << "pages: ";
		cin >> pages;
	}
	virtual void display() {
		product::display(); // early binding
		cout << "pages: " << pages << endl;
	}
};

class tape : public product {
private:
	int duration;
public:
	tape() {
		duration = 0;
	}
	tape(const char* t, int p, int d) : product(t, p) {
		duration = d;
	}
	virtual void accept() {
		product::accept(); // early binding
		cout << "duration: ";
		cin >> duration;
	}
	virtual void display() {
		product::display(); // early binding
		cout << "duration: " << duration << endl;
	}
};

int main() {
	product* p = NULL;
	int choice;
	cout << "\n1. book\n2. tape\nenter choice: ";
	cin >> choice;
	switch (choice) {
	case 1: // book
		p = new book;
		break;
	case 2: // tape
		p = new tape;
		break;
	default:
		//p = new product; // product is conceptual entity - make it abstract class - at least one pure virtual
		cout << "invalid choice" << endl;
	}
	if (p != NULL) {
		p->accept(); // runtime (virtual fn)
		p->display(); // runtime (virtual fn)
		cout << "original price: " << p->get_price() << endl; // compiler decide the call (non-virtual fn)
		delete p;
	}
	return 0;
}
            
/*
if a class virtual fn doent have suitable impl or partial impl
then make it pure virtual fn by using =0 in the declaration of virtual fn.
- Pure virtual fun may not have body
- Pure virtual fn must be overridden in derived class, otherwise derived class also becomes abstract class and can not be used to create object of derived class.
- If class contains at least one pure virtual fn, then that class is called abstract class.
- If object of class is not applicable/desirable, then class should be abstract class.
- Abstarct class can have data members and other members fn as well (along with pure virtual fn) which an be resused by derived class.
- They can also have ctor and destructor, which can be used to initialize and cleanup the data members of abstract class.
- product ke vtable mai how many entries honge? 3
- product ke vtable mai 2 entries honge, accept(), display() and that will be null
- it will get assigned in derived class, so that derived class can be used to create object.
*/