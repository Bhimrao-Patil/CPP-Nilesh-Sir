#include <iostream>
using namespace std;

class myclass {
private:
    int a;
    int *p;
public:
    myclass() {
        a = 1;
        p = new int;
        cout << "myclass() called" << endl;
    }
    // ...
    void display() {
        cout << "display() - a = " << a << endl;
    }
    ~myclass() {
        delete p;
        cout << "~myclass() called" << endl;
    }
};

int divide(int num1, int num2) {
    // interview question - what will happen if num2 is 0? it will throw an exception to the calling function. so we need to handle it in the calling function.
    // stack unwinding - if num2 is 0, then it will throw an exception to the calling function. so we need to handle it in the calling function.
    // when exception is thrown from a fn, it will jump to nearest available catch block
    // in same fn or caller fn or caller's fn an so on until main() fn. if no catch block is found, then it will terminate the program.
    // in this proocess all fn activation records until catch is found ar destroyed i.e. all local objs are also detsryored
    // if imp, dtors called 
    if (num2 == 0)
        throw "divide by zero";
    return num1 / num2;
}

void myfunction() {
    myclass obj;
    obj.display();
    int num, den;
    cout << "enter two numbers: ";
    cin >> num >> den;
    int res = divide(num, den);
    cout << "division result: " << res << endl;
}
// if we not write try catch in above fun it will crash because we are throwing exception from divide() fn and not handling it in myfunction() fn. so we need to handle it in main() fn.
// handle it in called or in main


int main() {
    try {
        myfunction();
    }
    catch (const char* err) {
        cout << "ERROR: " << err << endl;
    }
    return 0;
}

            
