#include "demo.h"
#include <iostream>
using namespace std;

int outerspace::test = 123;

void outerspace::myclass::display() {
	cout << "myclass::display() called" << endl;
}