/*
2nd eg of object slicing

we have B, C and D class
B and C are derived from D class
Diagram of class hierarchy and I want B and c first in dagram and D class at the bottom of diagram and B and c are inheriting D class, so B and C are derived classes and D is base class.
     (-b)B   C(-c)
         \ /
          D(-d)
D obj; // add of obj is 100
B *pb  =. &obj; // ok, because B is a D 
C *pc  =. &obj; // ok, because C is a D
so from above diagram we can see that B and C are derived from D class, so B and C are derived classes and D is base class. So we can assign address of D class object to B and C class pointer, because B and C are derived from D class. But we can not assign address of B or C class object to D class pointer, because D is base class and B and C are derived classes. So we can only assign address of base class object to derived class pointer, but we can not assign address of derived class object to base class pointer.


*/
#include <iostream>
using namespace std;

// BackendDeveloper
class B {
public:
    int b;
    B(int b) {
        this->b = b;
    }
};

// FrontendDeveloper
class C {
public:
    int c;
    C(int c) {
        this->c = c;
    }
};

// FullStackDevloper
class D : public B, public C {
public:
    int d;
    D(int b, int c, int d) 
        : B(b), C(c)
    {
        this->d = d;
    }
};

int main() {
    D obj(10, 20, 30);
    D* pd = &obj; // not object slicing, because we are assigning D class object to D class pointer, so all data members of D class are accessible from D class pointer. So this is not called object slicing in c++.
    B* pb = &obj; //object slicing is happening here, because we are assigning D class object to B class pointer, so only B class data members are accessible from B class pointer, but D class data member is not accessible from B class pointer. So this is called object slicing in c++.
    C* pc = &obj; // object slicing is happening here, because we are assigning D class object to C class pointer, so only C class data members are accessible from C class pointer, but D class data member is not accessible from C class pointer. So this is called object slicing in c++.
    cout << "&obj = " << (unsigned)&obj << endl; // 100
    cout << "&pd = " << (unsigned)pd << endl; // 100
    cout << "&pb = " << (unsigned)pb << endl; // 100
    cout << "&pc = " << (unsigned)pc << endl; // 104
    // why address of pc is 104, because B class is first in memory and C class is second in memory, so address of C class object is 4 bytes after B class object, because B class has 4 bytes of data member, so address of C class object is 4 bytes after B class object. So address of pc is 104.
    cout << "pb->b = " << pb->b << endl; // 10
    cout << "pc->c = " << pc->c << endl; // 20
    cout << "pd->d = " << pd->d << endl; // 30
    cout << "pd->b = " << pd->b << endl; // 10
    cout << "pd->c = " << pd->c << endl; // 20
    // so we can see that we can access B and C class data members from D class object, because D class is derived from B and C classes. So we can access B and C class data members from D class object.
    // here where object slicing is happening, because we are assigning D class object to B and C class pointers, so only B and C class data members are accessible from B and C class pointers, but D class data member is not accessible from B and C class pointers. So this is called object slicing in c++.

    return 0;
}

            


