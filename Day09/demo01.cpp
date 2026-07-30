/*
yesterday we talked about mode of inheritance in c++ and we also discussed about the types of inheritance in c++.
and today we will discuss about multiple inheritance in c++.
- multiple inheritance is a feature of C++ in which a class can inherit from more than one base class. This allows a derived class to combine the properties and behaviors of multiple base classes, enabling more complex and flexible designs.
- example of multiple inheritance in C++:

- Today we will discuss about diamond problem in c++ and how to solve it using virtual inheritance.
- diagram of diamond problem in c++:

          A
         / \
        B   C
         \ /
          D
-  here if you create an object of class D and call a method that is defined in class A, it will be ambiguous because both class B and class C have inherited from class A. This is known as the diamond problem.
-  a special case of hybrid inheritance is diamond problem in c++.
- if base class members are inherited into dervied class via multiple inherited paths, then ambiguity arises. This is known as diamond problem in c++.
*/

#include <iostream>
using namespace std;

class A
{
public:
    int a;

    A()
    {
        cout << "Constructor of class A () called" << endl;
        a = 1;
    }
    A (int A)
    {
        cout << "Parameterized Constructor of class A () called" << endl;
        this->a = A;
    }
    ~A()
    {
        cout << "Destructor of class A () called" << endl;
    }
};

class B : public A
{
public:
    int b;
    B()
    {
        cout << "Constructor of class B () called" << endl;
        b = 2;
    }
    B(int a, int b) : A(a)
    {
        cout << "Parameterized Constructor of class B () called" << endl;
        this->b = b ;
    }
    ~B()
    {
        cout << "Destructor of class B () called" << endl;
    }
};

class C : public A
{
public:
    int c;
    C()
    {
        cout << "Constructor of class C () called" << endl;
        c = 3;
    }
    C(int a, int c) : A(a)
    {
        cout << "Parameterized Constructor of class C () called" << endl;
        this->c = c ;
    }

    ~C()
    {
        cout << "Destructor of class C () called" << endl;
    }
};
class D : public B, public C
{
public:
    int d;
    D()
    {
        cout << "Constructor of class D () called" << endl;
        d = 4;
    }
    D(int a1, int b, int a2, int c, int d) : B(a1, b), C(a2, c)
    {
        cout << "Parameterized Constructor of class D () called" << endl;
        this->d = d ;
    }
    ~D()
    {
        cout << "Destructor of class D () called" << endl;
    }

};

int main()
{
/*
    D obj;
    cout << "sizeof(obj) = " << sizeof(obj) << endl;
    cout << "obj.d = " << obj.d << endl;
    cout << "obj.b = " << obj.b << endl;
    cout << "obj.c = " << obj.c << endl;
    // cout << "obj.a = " << obj.a << endl; // This will cause ambiguity error
    */
    
/*
    how memory is allocated for class D object in case of diamond problem in c++?
    the memory layout of class D object in case of diamond problem in c++ is as follows:
    +-------------------+
    |       A           |
    +-------------------+
    |       B           |
    +-------------------+
    |       C           |
    +-------------------+
    |       D           |
    +-------------------+
    so, the memory layout of class D object in case of diamond problem in c++ is as follows:
    if make object A then 4 bytes of memory will be allocated for class A object. | a | 4 bytes
    if make object B then 8 bytes of memory will be allocated for class B object. | a | b | 4 bytes + 4 bytes = 8 bytes
    if make object C then 8 bytes of memory will be allocated for class C object. | a | c | 4 bytes + 4 bytes = 8 bytes
    if make object D then 20 bytes of memory will be allocated for class D object. | a | b | a | c | d | 4 bytes + 4 bytes + 4 bytes + 4 bytes + 4 bytes = 20 bytes
    if execute the code then the output will be as follows: 

    Constructor of class A () called
    Constructor of class B () called
    Constructor of class A () called
    Constructor of class C () called 
    Constructor of class D () called
    Destructor of class D () called
    Destructor of class C () called
    Destructor of class A () called
    Destructor of class B () called
    Destructor of class A () called

    if you see the output then you will find that constructor of class A is called twice and destructor of class A is also called twice. 
    This is because class D has two base classes B and C, and both B and C have inherited from class A. 
    So, when we create an object of class D, it will call the constructor of class A twice, 
    once for B and once for C. 
    Similarly, when we destroy the object of class D, it will call the destructor of class A twice, once for B and once for C.
    what if we add parameterized constructor in class A and call it from class B and class C constructor using member initializer list in c++?
    if we add parameterized constructor in class A and call it from class B and class C constructor using member initializer list in c++, then we will get an error because class A has a parameterized constructor and it does not have a default constructor. 
    So, when we create an object of class D, it will call the constructor of class A twice, once for B and once for C. But since class A does not have a default constructor, it will give an error.
*/
    D obj2(10, 20, 11, 30, 40);
    cout << "obj2.d = " << obj2.d << endl; // 40
    cout << "obj2.c = " << obj2.c << endl; // 30
    cout << "obj2.b = " << obj2.b << endl; // 20
    // cout << "obj2.a = " << obj2.a << endl; // ambiguity error because class D has two base classes B and C, and both B and C have inherited from class A. So, when we try to access the member 'a' of class A, it will give an ambiguity error because it is not clear which 'a' we are trying to access, the one from class B or the one from class C. 
    // soltion on this is scope resolution operator in c++.
    cout << "obj2.B::a = " << obj2.B::a << endl; // 10
    cout << "obj2.C::a = " << obj2.C::a << endl; // 11

    return 0;



}