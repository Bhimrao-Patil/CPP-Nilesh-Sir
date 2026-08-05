/*
Today’s Agenda:
- Virtual destructor
- ⁠Abstract class
- ⁠Interface

*/

#include <iostream>
using namespace std;

class A {
public:
    int* pa;
    A() {
        cout << "A constructor called" << endl;
        pa = new int[3];
        for (int i = 0; i < 3; i++)
            pa[i] = 1;
    }
    void display() {
        for (int i = 0; i < 3; i++)
            cout << "pa - " << i << " ele = " << pa[i] << endl;
    }
 /*
     ~A() {
        delete[] pa;
        pa = NULL;
        cout << "A destructor called" << endl;
    }
 */   
    virtual ~A() {
        delete[] pa;
        pa = NULL;
        cout << "A destructor called" << endl;
    }
};

class B : public A {
public:
    int* pb;
    B() {
        cout << "B constructor called" << endl;
        pb = new int[3];
        for (int i = 0; i < 3; i++)
            pb[i] = 2;
    }
    void display() {
        A::display();
        for (int i = 0; i < 3; i++)
            cout << "pb - " << i << " ele = " << pb[i] << endl;
    }
    ~B() {
        delete[] pb;
        pb = NULL;
        cout << "B destructor called" << endl;
    }
};

int main() {
    B* objB = new B(); 
    //or
    // A* p = new B();
    objB->display();
    delete objB;
    // delete p; // if we use this then it will call only A destructor and not B destructor as destructor is not virtual in class A. so memory leak will occur for pb.
    return 0;
}

/*
what we will be the execution of the above code:
1. When the object `objB` of class `B` is created using `new`, the constructor of class `B` is called first. This constructor initializes the member `pb` and also calls the constructor of the base class `A`, which initializes the member `pa`. The output will show the messages indicating that the constructors of both classes have been called.
2. When `delete objB;` is executed, the destructor of class `B` is called first, which deallocates the memory for `pb`. Then the destructor of class `A` is called, which deallocates the memory for `pa`. The output will show the messages indicating that the destructors of both classes have been called.
3. After both destructors have completed, the memory for the object `objB` deleted via delete, and it is removed from the heap. This ensures that all dynamically allocated memory is properly freed, preventing memory leaks.
4. if we do not use delete, then memory leak will occur as memory allocated on heap will not be freed and it will remain allocated until the program terminates.
5. what it is called memory leak? Memory leak is a situation where a program allocates memory on the heap but fails to release it back to the operating system when it is no longer needed. This can lead to increased memory usage over time, potentially causing the program to run out of memory and crash or slow down.

and what about the flow of execution for the above code ->  AA* p = new B();
1. The constructor of class B is called, which in turn calls the constructor of class A.
2. The constructor of class A allocates memory for the array `pa` and initializes its elements to 1.
3. Control returns to the constructor of class B, which allocates memory for the array `pb` and initializes its elements to 2.
4. The `display` method of class B is called, which first calls the `display` method of class A to print the elements of `pa`.
5. The `display` method of class B then prints the elements of `pb`.
6. When the object `p` goes out of scope, the destructor of class B is called, which deallocates the memory for `pb`. Then the destructor of class A is called, which deallocates the memory for `pa`.
7. After both destructors have completed, the memory for the object `p` itself is released, and it is removed from the heap. This ensures that all dynamically allocated memory is properly freed, preventing memory leaks.

- Now real quetion is delete p -> it will delete mem and before it need to call its destructor, but which destructor will be called? A or B?
- In the case of `A* p = new B();`, when you call `delete p;`, only the destructor of class A will be called if the destructor in class A is not virtual. 
- This will result in a memory leak for the memory allocated in class B. means destructor of class B will not be called, and the memory allocated for `pb` will not be freed, leading to a memory leak.
- To ensure that the destructor of class B is also called, the destructor in class A should be declared as virtual.

- When base class pointer points to dynamically allocated derived class object, 
the delete on such (base class) pointer will 1st call the destructor of base class only 
and then release dynamically allocated whole derived class object memory.

In this case derivied class destrutor never called
if derived class dtor is deleting any memory that memory will not be released and it will lead to memory leak.

delete p: // p is A* --- calling ~A() only, ~B() never called, so memory allocated for pb will not be released and it will lead to memory leak.
dtor is called depending on the type of pointer, not the type of object it points to.
ideally dtor should be called depending on the type of object it points to, not the type of pointer.
so to achieve this we need to make base class destructor as virtual.

when destructor needs to be virtual?
- When a base class pointer is used to point to a derived class object, and the derived class has its own destructor that needs to be called when the object is deleted, the base class destructor should be declared as virtual. This ensures that the correct destructor is called for the derived class object,
- When a class is intended to be used as a base class for inheritance, and it has resources that need to be released in the derived class destructor, the base class destructor should be declared as virtual. This allows the derived class destructor to be called when the object is deleted through a base class pointer, ensuring that all resources are properly released.

one cofusion here
fn overriding rule
- sign of fn in derived class must be same sign of virtual fn in base class, otherwise it will be treated as new fn in derived class and not overriding fn of base class.
-
destructor overriding rule
- except for the sign of destructor in derived class, all other rules of overriding are same as fn overriding rules.
- note : interanally compiler will give same name to the destructor of derived class as that of base class, so it will be treated as overriding fn of base class and not new fn in derived class.

- constuctor is speciaal mem fn, that is always called when object is created, 
- The object can be creatd statically or dynamically, but constructor is always called when object is created.
- In either case we are creating obj by the name of the class(and not the base class pointer)
- SO its gauranted to call the respective class ctor
- In this exaple -- derived class ctor (B) is called and it always calls the base class ctor - in odrer to init object fully

- Virtual constructor is not possible, as constructor is always called when object is created and it is not possible to create object by the name of base class pointer, so virtual constructor is not possible.
- Intiazation of vptr itself is done on ctor
- Assuem ctor it self virtual as vptr is not yet init(to be init in ctor itself)
- it will not be able to perform virtual dispatching, so virtual constructor is not possible.
- hence ctror can not be virtual, but destructor can be virtual, as it is called when object is deleted and vptr is already init, so it can perform virtual dispatching.

*/