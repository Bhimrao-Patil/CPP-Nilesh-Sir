#include <iostream>
using namespace std;
#include "product.h"
//#include "product.h". // if we have not written #pragma once in product.h then we can use this line to include product.h file
int main() {
	product p1;
	p1.accept();
	p1.display();
	return 0;
}