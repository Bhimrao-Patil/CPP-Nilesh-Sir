#include <iostream>
using namespace std;
#pragma pack(1) //  bytes alignment
class A
{
public:
    int a;

    A()
    {
        a = 1;
        this->f2(); // calls A::f2() because f2 is virtual and this is a direct call from A's context
        // Early binding or Late binding => early binding
        // why early binding? because it is called from A's context, so it is early binding
        // A::f2 or B::f2 called? => A::f2 -- when obj is of B (objB)
        cout << "A::A() constructor" << endl;
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

    B()
    {
        b = 2;
        this->f2(); // calls B::f2() because f2 is virtual and this is a direct call from B's context
        // Early binding or Late binding => early binding
        // why early binding? because it is called from B's context, so it is early binding
        // A::f2 or B::f2 called? => B::f2 -- when obj is of B (objB)
        // in few compilers, it is called as late binding because it is called on this pointer which is of type B, so it is late binding, but in MSVS it is called as early binding because it is called from B's context, so it is early binding
        // o/p may differ from compiler to compiler, so it is compiler dependent, so it is not a good practice to call virtual function in constructor or destructor
        // so they said virtual fun called on this pointer in constructor or destructor is called as early binding, 
        // this is exeception to the rule.
        cout << "B::B() constructor" << endl;
    }

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
    //A objA; // which cntor calls here -> A::A() because objA is of type A, so only A's constructor is called
    // A obj -> A constructor is called-> obj.vfptr-> A:: vftable

    B objB; 
    // we have no gaurannty vptr is initialized to B::vftable or A::vftable, it is compiler dependent, but in MSVS it is initialized to A::vftable because MSVS calls base class constructor first and then derived class constructor, so after construction, objB.vfptr points to B::vftable
    // so its absoulely weird behavior
    // so one exeception is virtual fn called on this pointer in constructor 
    // so it is called on B object, but funA() is defined in A, so it calls A::f2() because f2 is virtual and this is a direct call from A's context
    // so it early binding or late binding? it is early binding because it is called from A's context,

    cout << "Size of A: " << sizeof(A) << endl; // 12 bytes (4 bytes for int a + 4 bytes for padding + 8 bytes for vptr)
    cout << "Size of B: " << sizeof(B) << endl; // 16 bytes (4 bytes for int a + 4 bytes for int b + 8 bytes for vptr)
    return 0;
}
