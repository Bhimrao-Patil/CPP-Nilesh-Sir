/*
Virtual function table and virtual function pointer demo.
This code matches the class structure shown in notes.
- for interview perpective, it is important to understand the concept of virtual function table and virtual function pointer.

*/

#include <iostream>
using namespace std;

class A
{
public:
    int a;

    A()
    {
        a = 1;
    }

    void f1()
    {
        cout << "A::f1 (non-virtual)" << endl;
    }

    virtual void f2()
    {
        cout << "A::f2 (virtual)" << endl;
    }

    void f3()
    {
        cout << "A::f3 (non-virtual)" << endl;
    }

    virtual void f4()
    {
        cout << "A::f4 (virtual)" << endl;
    }

    void funA()
    {
        cout << "A::funA (non-virtual)" << endl;
    }
    
};

class B : public A
{
public:
    int b;

    B() : b(2) {}

    void f1()
    {
        cout << "B::f1 (non-virtual)" << endl;
    }

    void f2()
    {
        cout << "B::f2 (overrides virtual A::f2)" << endl;
    }

    virtual void f3()
    {
        cout << "B::f3 (new virtual in B)" << endl;
    }

    void f5()
    {
        cout << "B::f5 (non-virtual)" << endl;
    }

    virtual void f6()
    {
        cout << "B::f6 (virtual)" << endl;
    }

};



int main()
{
    A objA; // which cntor calls here -> A::A() because objA is of type A, so only A's constructor is called
    // A obj -> A constructor is called-> obj.vfptr-> A:: vftable

    B objB; 
/*
    which cntor calls here -> A::A() and B::B() because B is derived from A, so first A's constructor is called and then B's constructor is called
    B obj -> A constructor is called-> obj.vfptr-> A:: vftable, then B constructor is called-> obj.vfptr-> B:: vftable
    Finally after obj construct/init is completed, objB.vfptr points to B::vftable
    during contruction, objB.vfptr points to A::vftable, but after construction, objB.vfptr points to B::vftable
    means it not initiallly ovrides but after construction, it overrides the vftable of A with vftable of B
    during B object creation, first A's constructor is called, so it initalize objB.vfptr points to A::vftable, then B's constructor is called, so objB.vfptr points to B::vftable
    so here it overrides the vftable of A with vftable of B, so after construction, objB.vfptr points to B::vftable
    But when B ctror is executed latest it will overrwrites vfptrs with address of B's vftable, so after construction, objB.vfptr points to B::vftable
    so after compplet obj initialization, objB.vfptr will definately point to B::vftable, so it overrides the vftable of A with vftable of B, so after construction, objB.vfptr points to B::vftable
    vfptr init code is added by compiler into ctor of the class / default ctor . 
    however this code maybe at the start of the ctor or at the end of the ctor
    depending on the compiler implemention IN MSVS it is at start of ctor, in GCC it is at the end of ctor, so after construction, objB.vfptr points to B::vftable

*/    
    return 0;
}

