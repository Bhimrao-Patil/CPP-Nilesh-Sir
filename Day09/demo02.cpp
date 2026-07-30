/*
we have employees 
        EMP
            empid
            empname
            empsalary

Sales                        Manager 
- commission                   - bonus

            SalesManager
                - incentive
- here if you see the above hierarchy, we have a problem of diamond inheritance.
- if we create an object of SalesManager class then the memory layout of SalesManager object will be as follows:
  Salemanager
    +-------------------+
    | empid             |
    +-------------------+
    | empname           |
    +-------------------+
    | empsalary         |
    +-------------------+
    | commission        |
    +-------------------+
    | empid             |
    +-------------------+
    | empname           |
    +-------------------+
    | empsalary         |
    +-------------------+
    | bonus             |
    +-------------------+
    | incentive         |
    +-------------------+
- here we have two copies of empid, empname and empsalary in SalesManager class object. 
- here if see one employee has two empid, empname and empsalary 
- its technically wrong, because one employee can have only one empid, empname and empsalary.
- So it will create ambiguity problem in c++.
- there should be only single copy of empid, empname and empsalary inherited into  SalesManager class object.
- So its better to have direct copy of empid, empname and empsalary in SalesManager class object without having two copies of empid, empname and empsalary in SalesManager class object.
- diagram of diamond inheritance is as follows:
        EMP
        /  \
       /    \
      /      \
     /        \
    Sales     Manager
      \        /
       \      /
        \    /
         \  /
          SalesManager
- here if we create an object of SalesManager class then the memory layout of SalesManager object will be as follows:
- UML diagram of direct copy of empid, empname and empsalary in SalesManager class object is as follows: 
- diagram I want emp to salemaneger 

*/

#include <iostream>
using namespace std;
// to. remove structure padding we can use #pragma pack(1) before class declaration and #pragma pack() after class declaration.
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
        : B(a, b), C(a, c)
    {
        this->d = d;
        cout << "D(int, int, int, int) called" << endl;
    }
    ~D() {
        cout << "~D() called" << endl;
    }  
};

int main() {
    D obj;
    cout << "sizeof(D) = " << sizeof(obj) << endl; // 40 bytes
    cout << "obj.d = " << obj.d << endl; // 4
    cout << "obj.c = " << obj.c << endl; // 3
    cout << "obj.b = " << obj.b << endl; // 2
    cout << "obj.a = " << obj.a << endl; // there is no ambiguity error because we have only one copy of a in D class object.
    // A contructor is called only once because we have only one copy of a in D class object diretly.
    // here from B and C class object we are not calling A class constructor because we have only one copy of a in D class object directly.
    // how one copy of a in D class object is created directly? because we have used virtual keyword while inheriting A class in B and C class.
    // so what is the use of virtual keyword in c++? virtual keyword is used to avoid ambiguity problem in c++.
    // means if we have multiple inheritance in c++ and if we have same base class in multiple derived classes then we can use virtual keyword to avoid ambiguity problem in c++.
    // if we make object of b then A class constructor will be called because we have only one copy of a in D class object directly.
    // if we make object of c then A class constructor will be called because we have only one copy of a in D class object directly.
    // now in below
    //D obj1(10, 20, 30, 40, 50);
    // here we dont need to call 5 parameters constructor of A class because we have only one copy of a in D class object directly.
    D obj2(10,20,30,40);
    cout << "obj2.d = " << obj2.d << endl; // 40
    cout << "obj2.c = " << obj2.c << endl; // 30
    cout << "obj2.b = " << obj2.b << endl; // 20
    cout << "obj2.a = " << obj2.a << endl; // 1

    //why obj2.a = 1 because we have not called A class constructor in D class constructor because we have only one copy of a in D class object directly.
    // so A class constructor is called only once when we create object of D class.
    // so the value of obj2.a is 1 as set by the A class default constructor.
    // so if we want to set the value of obj2.a then we need to call A class constructor in D class constructor.
    // how to call A class constructor in D class constructor? we can call A class constructor in D class constructor using member initializer list.
    // example of calling A class constructor in D class constructor using member initializer list is as follows:  
    // D(int a, int b, int c, int d)
    //     : A(a), B(a, b), C(a, c)
    // {
    //     this->d = d;
    //     cout << "D(int, int, int, int) called" << endl;
    // }
    /*
    - when A is inherited to B & C virtually then only single coy of A will be available to D. 
    - So virtual inheritance it is direct inheritance of base A() class (virtually inherited) into its (C/B) derived(D) class.
    */
   /*
    if we create an object of D class then the memory layout of D class object will be as follows:
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
    if make object D then 20 bytes of memory will be allocated for class D object. | a | b | c | d | 4 bytes + 4 bytes + 4 bytes + 4 bytes = 16 bytes
    if execute the code then the output will be as follows:
    A() called
    B() called
    C() called
    D() called
    obj.d = 4
    obj.c = 3
    obj.b = 2
    obj.a = 1
    D(int, int, int, int) called
    obj2.d = 40
    obj2.c = 30
    obj2.b = 20
    obj2.a = 1
    ~D() called
    ~C() called
    ~B() called
    ~A() called

   */
  /*
    So what are the possibibilty to access A ?
    So we have one hidden member pointer in D class object which is pointing to A class object. So we can access A class object using this hidden member pointer in D class object.
    So we can access A class object using this hidden member pointer in D class object.
    called virtual table pointer. So we can access A class object using this virtual table pointer in D class object.
    So we can access A class object using this virtual table pointer in D class object.
    | vbptr | b | vbptr | c | d |
    |  8    | 4 |  8    | 4 | 4 |
    | 28 bytes | 16 bytes 
    So we can access A class object using this virtual table pointer in D class object.
    but vbptr poining to array 
    so why size of d is 32 bytes? because we have used #pragma pack(1) before class declaration and #pragma pack() after class declaration. So the size of D class object is 32 bytes.
    if we remove #pragma pack(1) before class declaration and #pragma pack() after class declaration then the size of D class object will be 40 bytes.
    But how the calculation of size of D class object is 32 bytes? 
    because when we call sizeof(D) then it will return the size of D class object which is 32 bytes.
    So the size of D class object is 32 bytes.
    */
    cout << "&obj = " << (unsigned long)&obj << endl;
    cout << "&obj.b = " << (unsigned long)&obj.b << endl; // 
    cout << "&obj.c = " << (unsigned long)&obj.c << endl; // 
    cout << "&obj.d = " << (unsigned long)&obj.d << endl; // 
    cout << "&obj.a = " << (unsigned long)&obj.a << endl; // 
    /*
    &obj = 6160475932
    &obj.b = 6160475940
    &obj.c = 6160475952
    &obj.d = 6160475956
    &obj.a = 6160475960
    */
    return 0;
}

            
