// Exception handling :

#include <iostream>
#include <cstdlib>
using namespace std;

// developer 1
// case 1
/*
int divide(int num, int den) {
	return num / den;
}
*/
// case 2
int divide(int num, int den) {
	if (den == 0) {
		// error checking
		cout << "divide by zero error" << endl;
		exit(1); // terminate the appln -- hardcoded exit is bad practice - not usable
	}
	return num / den;
}

// developer 2
int main() {
	int num1, num2, res;
	cout << "enter two numbers: ";
	cin >> num1 >> num2;
	res = divide(num1, num2);
	cout << "result = " << res << endl;
	return 0;
}
/*
what is in above code?
- divide() fn is written by developer 1 and main() fn is written by developer 2
- so if developer 1 is not available, then developer 2 can not modify divide() fn to handle divide by zero error. so it is not usable.
- so we need to use exception handling to handle divide by zero error. so that developer 2 can handle divide by zero error without modifying divide() fn. 
- so that developer 1 and developer 2 can work independently without depending on each other. 
*/