
// RTTI = Run Time Type Identification
#include <iostream>
using namespace std;

/*
int main()
{
	int a = 10;
	double b = 2.2;
	const char* s = "Nilesh";

	// C compiler provides limited info about a type = its size
	cout << "sizeof a = " << sizeof(a) << endl; // 4
	cout << "sizeof b = " << sizeof(b) << endl; // 8
	cout << "sizeof s = " << sizeof(s) << endl; // 8

	// C++ compiler also provides additional info about a type = its name / code-name
	//	C++ has typeid() operator --> returns type_info object ref.
	const type_info &type_a = typeid(a); // no one can modify 
	cout << "type a = " << type_a.name() << endl; // int
	const type_info& type_b = typeid(b);
	cout << "type b = " << type_b.name() << endl; // double
	const type_info& type_s = typeid(s);
	cout << "type s = " << type_s.name() << endl; // const char*
    
    // typeid() is c++ operator which returns type_info inform of "type_info" object
    // The type_info is a predefined struct
    // char *name() --> returns the name of the type as a string
    // operator==() & operator!=() --> compares two type_info objects for equality or inequality

	int x = 20;
	if (typeid(a) == typeid(x)) // int == int
		cout << "a & x both are of same type." << endl;
	else
		cout << "a & x both are of diff type." << endl;
	return 0;
}
*/

/*
class Base1
{
public:
	void fun1() {
		cout << "fun1() called" << endl;
	}
};

class Derived1 : public Base1 {

};

int main() {
/*	
    Base1* p = new Base1;
    p->fun1();
    const type_info& p_type = typeid(p);
    cout << "pointer p type = " << p_type.name() << endl; // class Base1 *
    delete p;
/*
/*
    Base1* p = new Base1;
    p->fun1();
    const type_info& pval_type = typeid(*p);
    cout << "value at p type = " << pval_type.name() << endl; // class Base1
    delete p;
/*

	Base1* p = new Derived1; // Upcasting or (Object slicing)
	p->fun1();
	
	const type_info& p_type = typeid(p);
	cout << "pointer p type = " << p_type.name() << endl; // class Base1 *

	const type_info& pval_type = typeid(*p);
	cout << "value at p type = " << pval_type.name() << endl; // class Base1

	delete p;
	return 0;
}
*/
// making method virtual 
class Base2
{
public:
	virtual void fun2() {
		cout << "fun2() called" << endl;
	}
};

class Derived2 : public Base2 {

};

int main() {
	//Base2* p = new Base2;
	Base2* p = new Derived2; // Upcasting (Object slicing)
	p->fun2();

	const type_info& p_type = typeid(p);
	cout << "pointer p type = " << p_type.name() << endl; // class Base2 *

	const type_info& pval_type = typeid(*p);
	cout << "value at p type = " << pval_type.name() << endl; // class Base1

	delete p;
	return 0;
    // if your class has virtual function, then typeid() operator will return the actual type of the object being pointed to by the pointer, even if the pointer is of base class type. This is because the virtual function mechanism allows the derived class to override the base class function, and thus the actual type of the object is preserved at runtime.
    // RTTI means Run Time Type Identification, which is a mechanism that allows the type of an object to be determined at runtime. It is used in C++ to support polymorphism and dynamic casting. The typeid() operator is one of the features of RTTI, which allows you to get the actual type of an object at runtime, even if it is being accessed through a base class pointer or reference.
    // How RTTI works internally
    /*
    - Compiler by default creates one type_info obj for evry type- pre-defined or user-defined too
    - eg int, double, char, class A, Base1, Derived1, Base2, Derived2 etc
    - Most cases, this created obj is linked durinig compile time, but in case of polymorphism, this obj is linked during run time.
    - If class contains at least one virtual function or pure virtual fn(called polymorphic class), 
    - In case the object type (ponted by a ptr i.e. *ptr) is determined at runtimes RTTI
    - line no 103
    - type_info Base2 ke liye bhi hoga and derived2 ke liye bhi
    - vftable bhi hoga with 1 entry for fun2() fn
    - vftable is created at compile time, but the actual linking of the vftable entry to the function implementation is done at runtime, based on the actual type of the object being pointed to by the pointer. This is what allows for dynamic dispatch and polymorphism in C++.
    - typeid() operator uses the vftable to determine the actual type of the object at runtime, and returns the corresponding type_info object for that type.
    - vtable Base2 aur Dervied2 ko mai bhi hoga but fun overiding ke case mai vtable Derived2 ke liye hi hoga, kyuki fun2() fn Derived2 mai override ho gaya hai.
    - if our class has vtable, then the compiler adds a hidden pointer to the class called vptr (virtual pointer) which points to the vtable.
    
    see notes as well for more details
    */
}