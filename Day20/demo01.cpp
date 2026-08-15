/*
Operator overloading: In Java its removed, but in C++ we can overload operators to provide custom implementation for operators for user defined data types (class/struct).
- Why operator overloading is required?
- Syntax: member fn/ frienf fn
- Different operator overloading
    - Arthimtaic operators, Relational opertor
    - Inc/Decr operator
    - Insertion and extraction operator
    - Assinment operator and copy constructor | deep copy and shallow copy
    - smart pointer
    - function objects
    - Index operator
    - Type conversion operator
    - new/delete operator

Prerequisite:
1. friend function
2. references
*/
#include <iostream>
using namespace std;

// [v0, v1, v2]
class Vector {
private:
    double arr[3];
public:
    Vector() {
        for (int i = 0; i < 3; i++)
            arr[i] = 0.0;
    }

    Vector(double v0, double v1, double v2) {
        arr[0] = v0;
        arr[1] = v1;
        arr[2] = v2;
    }
    ~Vector() {
    }
    void display() {
        cout << "[" << arr[0] << ", " << arr[1] << ", " << arr[2] << "]" << endl;
    }

};


int main() {
    Vector vec1;
    vec1.display();
    Vector vec2(3.0, 4.0, 5.0);
    vec2.display();
    return 0;
}