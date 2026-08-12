/*
Casting Operators in C++:
class Base {
//...
};
class Derived {
//...
};

int main() {
 
    Base *p;
    p = new Derived(); // is it allowed? yes 100% but its will give an error at compile time because Derived is not a subclass of Base, so this cast is invalid.
    // so we need to inherit derived from base to make this cast valid.
    // so inheritance is necessary for static_cast<> to work between base and derived classes.

}
    
C++ cast ops:
1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast

1. static_cast:
    - it has 2 main uses
    - a. check inheritance relationship at compile time 
    - b. Safe alternative for c-style cast
        i=(int)f; // c-style cast
        if we want c-style cast to be safe, we can use static_cast<int>(f);
        C style cast is not safe because it can convert between unrelated types, which can lead to undefined behavior. static_cast<> is safer because it only allows conversions between related types, and will give a compile-time error if the types are not related.
        So instead of c-style cast, we should use static_cast<> for type conversions in C++.
        So we did Dervied *d = new Derived(); // d is type of derived*, which is a subclass of Base*, so this cast is valid.
    - used for converting between types that are related by inheritance.
    - can be used to convert between numeric types, pointer types, and reference types.
    - does not perform runtime type checking, so it is the programmer's responsibility to ensure that the cast is valid.
    - Static_cast can be used to perform upcasting (casting from a derived class to a base class) and downcasting (casting from a base class to a derived class).
    - usualy for upcasting we dont need any type of cast, but for downcasting we need to use static_cast<> or dynamic_cast<>.

    
class Base {
//
};
//class Derived {
class Derived : public Base {
    //
};

main() {
 
    Base *p;
    Derived *d = new Derived();
    p = static_cast<Base*>(d); // d is type of derived*, which is a subclass of Base*, so this cast is valid.
    // static_cast<> allows up-casting Derived* to Base* without any runtime overhead.
    // dowdncasting is Base* to Derived*
    // but even after this casting it will give an error.
    // we said only class dervied . So change to class derived : public base {
    // now it will work fine.
    // useusally upcasting ke liye koi cast ki jarurat nahi hoti, but downcasting ke liye static_cast<> or dynamic_cast<> ka use karna padta hai.
    // so inheritance is necessary for static_cast<> to work between base and derived classes.
}
*/

#include <iostream>
using namespace std;
/*
class base {
    // Base class
public:    
    int a;

    void base_display() {
        cout << "Base class display function" << endl;
    }
};
//class derived : {
class derived : public base {
// Derived class
public:
    int b;

    void derived_display() {
        cout << "Derived class display function" << endl;
    }
    

};

int main() {
    derived *d = new derived();// is it upcasting or downcasting? 
    base *b = static_cast<base*>(d); // it will fail to compile because derived is not a subclass of base, so this cast is invalid. invald conversion from 'derived*' to 'base*' [-fpermissive]
    // so we need to inherit derived from base to make this cast valid. so change to class derived : public base {
    // so inheritance is necessary for static_cast<> to work between base and derived classes.
    // upcasting automatically done by compiler, but downcasting needs to be done explicitly using static_cast<> or dynamic_cast<>.
    b->base_display(); // it will call base class display function why because b is of type base* and base class has a member function base_display() so it will call base class display function.
    // current exaple is of upcasting, object slicing    

    delete b; // free the memory allocated for base object (actually points to derived object)

    return 0;
}
*/

//how can we do downcasting?

class base {
    // Base class
public:    
    int a;

    void base_display() {
        cout << "Base class display function" << endl;
    }
};
//class derived : {
class derived : public base {
// Derived class
public:
    int b;

    void derived_display() {
        cout << "Derived class display function" << endl;
    }
    

};

void show_data(base* p) {
    p->base_display();
    // ...
    // new requirement: also call derived_display() which is not allowed by base class pointer. so we need to downcast base class pointer to derived class pointer to access derived class members. so we need to use static_cast<> or dynamic_cast<> to downcast base class pointer to derived class pointer.
    //. how to do it
    //derived* d = p; // compiler error: downcasting is not auto-supported.
    // to c type kre kya like
    // dervied* d = (derived*)p; // c-style cast is not safe because it can convert between unrelated types, which can lead to undefined behavior. static_cast<> is safer because it only allows conversions between related types, and will give a compile-time error if the types are not related.
    // so like below main use of static cast do dynmic cast 
    derived* d = static_cast<derived*>(p); // downcasting - inheritance reln checked at compile time because base *p is we dont what passed from main() - base obj or derived obj. so we need to check inheritance relationship at compile time. so static_cast<> is used for downcasting.
    // so casting correct hoga iski gaurantee nahi hai, so we need to check at runtime whether the cast is valid or not. so we need to use dynamic_cast<> for downcasting.
    // because if you see object of derived class is passed from main() then this cast is logically correct, but if base class object is passed from main() then this cast is logically incorrect. so we need to check at runtime whether the cast is valid or not. so we need to use dynamic_cast<> for downcasting.
    // like show_data(&b1); // base obj passed from main() then this cast is logically incorrect. so we need to check at runtime whether the cast is valid or not. so we need to use dynamic_cast<> for downcasting.
    // see diagram from sirs nots
    // if from main() derived obj is passed, then this cast is logically correct.
    // if from main() base obj is passed, then this cast is logically incorrect - 
    //  it may produce - unexpected results.
    // means base ke address ko direct derived ke address mai convert kar diya, so derived ke members ko access karne ki koshish kiya, but base ke members hi available hai, so it may produce unexpected results.
    // means derives object ptr pointing to base object, so it may produce unexpected results.
    // like every employee is person, but every person is not employee. so if we try to access employee specific members using person pointer, then it may produce unexpected results.
    // this is incorrect assignment.
    // static cast ka kaam hai ki o compile time pe check kare ki base and derived ke beech inheritance relationship hai ya nahi, but it will not check at runtime whether the cast is valid or not. so we need to use dynamic_cast<> for downcasting.
    // so that name is static so to resolve this problem we need to use dynamic_cast<> for downcasting.
    // static cast is only for compile time checking of inheritance relationship, but it will not check at runtime whether the cast is valid or not. so we need to use dynamic_cast<> for downcasting.
    // so that programmer resopinsibility to check at runtime whether the cast is valid or not. so we need to use dynamic_cast<> for downcasting.
    d->derived_display();
}
/*
int main() {
    base b1;
    derived d1;
    show_data(&d1); // will work
    //show_data(&b1); // will give unexpected results because base obj passed from main() then this cast is logically incorrect. so we need to check at runtime whether the cast is valid or not. so we need to use dynamic_cast<> for downcasting.
    return 0;
}

*/
// will se one more example
int main() {
    double d = 1.23;
    //int i = (int)d; // cast from bigger type to smaller type explicitly to improve readability
    // lekin c++ recommends static_cast<> instead of C-style casting because it is safer and more readable.
    // c style also allowed but c++ recommends static_cast<> instead of C-style casting because it is safer and more readable.
    int i = static_cast<int>(d); // C++ recommends static_cast<> instead of C-style casting
    cout << "i = " << i << endl; // 1
    // somtehing odd we see
    int x = 0x11223344; // 4-byte  hexadecimal value    
    //char* p = &x; // compiler error -- needs casting if to be done explicitly
    //char* p = static_cast<char*>(&x); // static_cast<> gives compiler error beacause it is not safe to convert from int* to char* because they are unrelated types. so we need to use reinterpret_cast<> for this conversion.
    //char* p = reinterpret_cast<char*>(&x); // reinterpret_cast<> is used for converting
    // according to C++, converting from int* to char* is not a safe option -> compiler error.
    // if programmer still want to do it, then he/she should choose other casting operator like reinterpret_cast<> which is used for converting between unrelated types. so we need to use reinterpret_cast<> for this conversion.
    // castting operator most used cast is static case in c++
    
    return 0;
}
 

