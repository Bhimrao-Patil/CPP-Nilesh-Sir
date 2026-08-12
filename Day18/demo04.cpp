#include <iostream>
using namespace std;

/*
int main()
{
	int a = 0x11223344;
	//char* p = static_cast<char*>(&a); // compiler error - not safe cast int * to char* because they are unrelated types. so we need to use reinterpret_cast<> for this conversion.
    // but sometimes we need to convert between unrelated types, so we need to use reinterpret_cast<> for this conversion.
	char* p = reinterpret_cast<char*>(&a); // compiler allows any cast ...
		// programmer's responsibility to cast appropriately
	cout << "*p = " << hex << (int)*p << endl;
	return 0;
}
*/

class myclass {
private:
	int a;
	int b;
public:
	myclass() {
		a = 10;
		b = 20;
	}
	void display() {
		cout << "myclass.a = " << a << endl;
		cout << "myclass.b = " << b << endl;
	}
};

int main() {
	myclass obj;
	obj.display(); // a = 10
	//obj.a = 100; // compiler error -- private members are not accessible outside the class.
    // requirement: modify private member a of obj from outside the class. so we need to use reinterpret_cast<> to convert obj to int* and then modify the value of a.
	
    int* ptr = reinterpret_cast<int*>(&obj);
	*ptr = 100; // normal c programm code 10 ke jagah 100 change krega
	obj.display(); // a = 100
	return 0;
}