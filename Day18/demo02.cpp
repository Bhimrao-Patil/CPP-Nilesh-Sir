// dynamic casting
#include <iostream>
using namespace std;

class base {
public:
    int a;
    void base_display() {
        cout << "base_display() called." << endl;
    }
    virtual ~base() {
        // ...
    }
};

class derived : public base {
public:
    int b;
    void derived_display() {
        cout << "derived_display() called." << endl;
    }
};

void show_data(base* p) {
    p->base_display();
    // ...
    // new requirement: also call derived_display()
    //derived* d = p; // compiler error: downcasting is not auto-supported.
    derived* d = dynamic_cast<derived*>(p); // downcasting
        // dynamic_cast<> at runtime confirms if the casting is logically correct
        // i.e. derived object is pointed by the derived* or base*; but not reverse.
        // if casting is logically correct, then it returns casted/coverted pointer.
        // if casting is logically incorrect, then it returns NULL pointer.
        // dynamic cast internally use RTTI feature to check if the casting is logically correct.
        //  so it requires polymorphic hierarchy; (at least one virtual or pure virtual function) without this dynamic_cast<> is compiler error.
        // koi fun virtula nhi krna to destructor ko virtual kr do, so that dynamic_cast<> can work.
        // runtime overehead -> less efficient than static_cast<>; but more safe and secure.
        // use dynmic_cast<> only when absolute necessary
        // if you are sure that the casting is logically correct, then use static_cast<>; which is more efficient than dynamic_cast<>.
        // not every environment supports dynamic_cast<>; so use it only when necessary. like in embedded systems, dynamic_cast<> is not supported. so use static_cast<> in such environment.

    if(d != NULL)
        d->derived_display();
}

int main() {
    base b1;
    derived d1;
    //show_data(&d1); // will work as expected
    show_data(&b1); // will work as expected
    return 0;
}