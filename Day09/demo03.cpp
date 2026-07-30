#include <iostream>
using namespace std;

// to remove slack bytes / struct padding
#pragma pack(1)

class A {
public:
    int a;
    A() {
        a = 1;
        cout << "A() called" << endl;
    }
    A(int a) {
        this->a = a;
        cout << "A(int) called" << endl;
    }
    ~A() {
        cout << "~A() called" << endl;
    }
};

class B : public virtual A {
public:
    int b;
    B() {
        b = 2;
        cout << "B() called" << endl;
    }
    B(int a, int b) : A(a) {
        this->b = b;
        cout << "B(int, int) called" << endl;
    }
    ~B() {
        cout << "~B() called" << endl;
    }
};

class C : virtual public A {
public:
    int c;
    C() {
        c = 3;
        cout << "C() called" << endl;
    }
    C(int a, int c) : A(a) {
        this->c = c;
        cout << "C(int, int) called" << endl;
    }
    ~C() {
        cout << "~C() called" << endl;
    }
};

class D : public B, public C {
public:
    int d;
    D() {
        d = 4;
        cout << "D() called" << endl;
    }
    D(int a, int b, int c, int d)
        : B(a, b), C(a, c), A(a)
    {
        this->d = d;
        cout << "D(int, int, int, int, int) called" << endl;
    }
    ~D() {
        cout << "~D() called" << endl;
    }
};

class E : public D {
public:
    int e;
    E() {
        e = 50;
    }
};

int main() {
    E obj;
    cout << "&obj = " << (unsigned long)&obj << endl;
    cout << "&obj.b = " << (unsigned long)&obj.b << endl; // 
    cout << "&obj.c = " << (unsigned long)&obj.c << endl; // 
    cout << "&obj.d = " << (unsigned long)&obj.d << endl; // 
    cout << "&obj.a = " << (unsigned long)&obj.a << endl; // 
    cout << "&obj.e = " << (unsigned long)&obj.e << endl; // 
    return 0;
    /*
        so why we added class E which is inherited from class D? because we want to see the memory layout of class E object in case of diamond problem in c++.
        so the memory layout of class E object in case of diamond problem in c++ is as follows:
        +-------------------+
        |       A           |
        +-------------------+
        |       B           |
        +-------------------+
        |       C           |
        +-------------------+
        |       D           |
        +-------------------+
        |       E           |
        +-------------------+
        so the memory layout of class E object in case of diamond problem in c++ is as follows:
        if make object A then 4 bytes of memory will be allocated for class A object. | a | 4 bytes
        if make object B then 8 bytes of memory will be allocated for class B object. | a | b | 4 bytes + 4 bytes = 8 bytes
        if make object C then 8 bytes of memory will be allocated for class C object. | a | c | 4 bytes + 4 bytes = 8 bytes
        if make object D then 20 bytes of memory will be allocated for class D object. | a | b | c | d | 4 bytes + 4 bytes + 4 bytes + 4 bytes = 16 bytes
        if make object E then 24 bytes of memory will be allocated for class E object.
        so the memory layout of class E object in case of diamond problem in c++ is as follows:
₹
₹
         
    */
}

            
