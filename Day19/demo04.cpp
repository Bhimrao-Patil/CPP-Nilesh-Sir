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

    if (num2 == 0)
        throw "divide by zero";
    return num1 / num2;
}
void myfunction() {
    myclass obj;
    obj.display();
    int* ptr = new int[4]; // dynamic memory allocation
    // ...
/*
in stack unwinding :
here objs created on ctack (local obj) are detroyed
however if any ptr refering to dynamically allocated mem.
the corrosponding delete op may not be called
that mem get leaked and not returned to OS
so that concept is pre-requvisite for smart ptrs
smart ptr is pretty old concept in modern c++ some extra classes are provided in std lib to manage dynamic mem automatically
see sirs notes for more details: Exception unwinding

throwing exception from constructor and destructor is not good practice because it will cause stack unwinding and may lead to memory leak if any dynamically allocated memory is not freed before throwing exception. so it is better to handle exception in constructor and destructor and not throw exception from them.
still in construtor is possible but in destructor it is not possible because destructor is called when object is destroyed and if exception is thrown from destructor, then it will cause stack unwinding and may lead to memory leak if any dynamically allocated memory is not freed before throwing exception. so it is better to handle exception in constructor and destructor and not throw exception from them.
can destructor throw exception:
- through it is legal to throw exception from destructor, it is not expected
- if at all exception arising in destructor, it must be handled there try catch

can constructor throw exception:
- constructor may throw exception indicating obj is not properly initialized
e.g. "db_connection" class constructor may throw exception if db connection is not established properly
// see sirs notes for more details: from image
*/    
    int num, den;
    cout << "enter two numbers: ";
    cin >> num >> den;
    int res = divide(num, den);
    cout << "division result: " << res << endl;
    delete[] ptr; // dynamic memory de-allocation
}
int main() {
    try {
        myfunction();
    }
    catch(const char *err) {
        cout << "ERROR: " << err << endl;
    }
    return 0;
}
