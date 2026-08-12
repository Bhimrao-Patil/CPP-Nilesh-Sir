#include <iostream>
#include <cstdlib>
using namespace std;

// developer 1
int divide(int num, int den) {
	if (den == 0) {
		// error checking - if error cannot be handled here, throw it back to the calling fn
		throw den;
	}
	return num / den;
}

// developer 2
int main() {
	int num1, num2, res;
	try {
		cout << "enter two numbers: ";
		cin >> num1 >> num2;
		res = divide(num1, num2);
		cout << "result = " << res << endl;
	}
	catch (int x) {
		cout << "divide error : " << x << endl;
	}
	return 0;
}
/*
exception represents - runtime problems that needs to handled gracefully(flexible)
typically when any fn detects such problem, it throws an exception to the calling fn, which can handle it gracefully.
- divide() fn is written by developer 1 and main() fn is written by developer 2
- so if developer 1 is not available, then developer 2 can not modify divide() fn to handle divide by zero error. so it is not usable.
- so we need to use exception handling to handle divide by zero error. so that developer 2 can handle divide by zero error without modifying divide() fn. 
- so that developer 1 and developer 2 can work independently without depending on each other. 
*/