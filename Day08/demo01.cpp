/*
Mode of inheritance in C++:
- public inheritance: 
    - public members of base class become public members of derived class , so its accessible in same class.
    - protected members of base class become protected members of derived class, so its accesssible in derived class and its derived class.
    - private members of base class are never inherited, so its not accessible in derived class and its derived class.
- protected inheritance:
    - public members of base class become protected members of derived class, so its accessible in same class
    - protected members of base class become protected members of derived class, so its accessible in derived class and its derived class.
    - private members of base class are never inherited, so its not accessible in derived class and its derived class.

- private inheritance:
    - public members of base class become private members of derived class, so its accessible in same class
    - protected members of base class become private members of derived class, so its accessible in derived class and its derived class.
    - private members of base class are never inherited, so its not accessible in derived class and its derived class.


*/

#include <iostream>
using namespace std;
class Base {
    public:
     int a;
    protected:
     int b;
    private:
     int c;
};
class Derived1 : public Base { // here mode of inheritance is public, so all public and protected members of base class become public and protected members of derived class, so they are accessible in derived class and its derived class.
    public:
     void display() {
        a = 10; // accessible public member of base class
        b = 20; // accessible protected member of base class
        // c = 30; // not accessible, private member of base class
     }
};

class Derived2 : protected Base { // here mode of inheritance is protected, so all public and protected members of base class become protected members of derived class, so they are accessible in derived class and its derived class.
    public:
     void display() {
        a = 10; // accessible
        b = 20; // accessible
        // c = 30; // not accessible, private member of base class
     }
};
class Derived3 : private Base { // here mode of inheritance is private, so all public and protected members of base class become private members of derived class, so they are not accessible in derived class and its derived class.
    public:
     void display() {
        a = 10; // accessible
        b = 20; // accessible
        // c = 30; // not accessible, private member of base class
     }
};

int main() {
    Derived1 obj1;
    cout << obj1.a; // accessible, public member of base class
    // cout << obj1.b; // not accessible, protected member of base class
    // cout << obj1.c; // not accessible, private member of base class
    Derived2 obj2;
    // cout << obj2.a; // not accessible, protected member of base class
    // cout << obj2.b; // not accessible, protected member of base class
    // cout << obj2.c; // not accessible, private member of base class
    Derived3 obj3;
    // cout << obj3.a; // not accessible, private member of base class
    // cout << obj3.b; // not accessible, private member of base class
    // cout << obj3.c; // not accessible, private member of base class

    // eg : java and csharrp are inherated from c++
    
    return 0;
}