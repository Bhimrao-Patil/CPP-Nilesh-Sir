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
        //f2(); // calls A::f2() because f2 is virtual and this is a direct call from A's context
        // or
        this->f2();
        // Early binding or Late binding => Late binding
        // A::f2 or B::f2 called? => B::f2 -- when obj is of B (objB)
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

    objB.funA();
    // this called on B object, but funA() is defined in A, so it calls A::f2() because f2 is virtual and this is a direct call from A's context
    // so it is which binding?  its calling on this->f2() so it is late binding,
    // so which f2() will be called? it will be B::f2() because it is called on this pointer which is of type B, so it is late binding

    // if its
    objA.funA();
    // this called on A object, so it calls A::f2() because f2 is virtual and this is a direct call from A's context
    // so it is which binding?  its calling on this->f2() so it is late binding,
    // so which f2() will be called? it will be A::f2() because it is called on this pointer which is of type A, so it is late binding
    return 0;
}
