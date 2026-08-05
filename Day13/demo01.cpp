/*
Today’s Agenda:
- Virtual destructor
- ⁠Abstract class
- ⁠Interface

*/

#include <iostream>
using namespace std;

class A {
public:
    int* pa;
    A() {
        pa = new int[3];
    }
    void display() {
        for (int i = 0; i < 3; i++)
            cout << "pa - " << i << " ele = " << pa[i] << endl;
    }
    ~A() {
        delete[] pa;
        pa = NULL;
    }
};

int main() {
    A objA; // object is created by using class name A, so constructor of class A will be called
    return 0;
}

            
