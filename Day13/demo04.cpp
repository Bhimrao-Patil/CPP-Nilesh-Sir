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
// exaple of hierarchical inheritance
#include <iostream>
#include <cstring>
using namespace std;

#pragma pack(1)

class employee {
public:
	char name[40];
	int age;
	double sal;
public:
	employee() {
		strcpy(name, "");
		age = 0;
		sal = 0.0;
	}
	employee(const char *nm, int a, double s) {
		strcpy(name, nm);
		age = a;
		sal = s;
	}
	int calc_gross_sal() {
		return sal;
	}

    // ...
};

class manager : public employee {
public:
	double bonus;
public:
	manager() {
		bonus = 0.0;
	}
	manager(const char* nm, int a, double s, double b) 
		:employee(nm, a, s)
	{
		bonus = b;
	}
	int calc_gross_sal() {
		return sal + bonus;
	}
	// ...
};

class salesman: public employee {
public:
	double comm;
public:
	salesman() {
		comm = 0.0;
	}
	salesman(const char* nm, int a, double s, double c)
		:employee(nm, a, s)
	{
		comm = c;
	}
	int calc_gross_sal() {
		return sal + comm;
	}
	// ...
};

class labor : public employee {
	// ...
};

class clerk : public employee {
	// ...
};

int main()
{
	employee e; // ideally employee obj is not present/applicable in real world. 
	// in oops, this is done by making a class as "abstract class".
	// abstract class - represents conceptual entity (not real-world entity)
	//	may have data members and member fns --> reused in derived class.
	manager m; // okay
	salesman s; // okay
	labor l; // okay 
	clerk c; // okay
	return 0;
}

            
