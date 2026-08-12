// demo03.cpp : This file contains the 'main' function. Program execution begins and ends there.
// const_cast

#include <iostream>
#include <cstring>
using namespace std;

// when fn arg is "const int*", it is expected that the "int" will not be modified in the fn.
void my_function(const int* p) {
	cout << "in my_function(): p = " << *p << endl; // read-only access to the value pointed by p
    // but if you want to modify the value pointed by p, then you can use const_cast<> to remove the const-ness of the pointer temp.
    // const_cast<> is used to remove const-ness of the pointer temp.
	// new requirement -- modify the int (in some rare situation)
	// if(rare_condition)
	//*p = 20; // compiler error
	int* q = const_cast<int*>(p); // temporary pointer q is created which is not const, so it can be used to modify the value pointed by p.
	// const_cast<> is used to remove const-ness of the pointer temp.
	*q = 20; // allowed
}

int main()
{
	int a = 10;
	cout << "before fn call: a = " << a << endl; // a = 10
	my_function(&a);
	cout << " after fn call: a = " << a << endl; // a = 20
    // how it works internally
    /*
    - compiler creates a temporary pointer q which is not const, so it can be used to modify the value pointed by p.
    - const_cast<> is used to remove const-ness of the pointer temp.
    - q is a temporary pointer which is not const, so it can be used to modify the value pointed by p.
    - but where const p value is storesd in memory? it is stored in stack memory, so it can be modified by q.
    - so const_cast<> is used to remove const-ness of the pointer temp.
    - but if p is pointing to a const value, then it is undefined behavior to modify the value pointed by p using q. so it is not recommended to use const_cast<> to modify the value pointed by p. it is better to use const_cast<> only to remove const-ness of the pointer temp, but not to modify the value pointed by p.
    - so const_cast<> is used to remove const-ness of the pointer temp, but not to modify the value pointed by p. it is better to use const_cast<> only to remove const-ness of the pointer temp, but not to modify the value pointed by p.
    */
	return 0;
}