/*

Agenda of the day:
1. Virtual Functions
    - use cases/ applications
    - early & late binding
    - internals

Employee and student class inheritaed from person class.
- diagram:
            Person
           /      \
          /        \
     Employee      Student
- if disaplay() fn in person and employee
- Employee e;
- person *p = &e; // p->display() will call person class display fn
- p->display() will call employee class display fn if display() is virtual fn in person class
- for function overriding, the function signature should be same in both base and derived class
- in needs to be virtual fn in base class to achieve late binding
- functioon overriding:
    - fn virtual in base class
    - must redifine the fn in derived class with same signature
- so virtual fn is always called based on the object type, not pointer type/ or reference type
- we have a person pointer
    Person *pp = new Employee();
    pp->display(); // will call employee class display fn if display() is virtual in person class
- this will eventually call fn of employee class, if display() is virtual in person class
    pp = new Student();
    pp->display(); // will call student class display fn if display() is virtual in person class
- so virtual fn is always called based on the object type, not pointer type/ or reference type
- so what is main use of virtual fn?
    - to achieve runtime polymorphism
    - to achieve late binding
- what is runtime polymorphism?
    - when we have a base class pointer or reference pointing to derived class object, and we call a virtual function, the function that gets called is determined at runtime based on the actual object type, not the pointer type. This allows for more flexible and dynamic behavior in programs.
- what is late binding?
    - late binding, also known as dynamic binding, is the process of determining which function to call at runtime rather than at compile time. In C++, this is achieved through the use of virtual functions. When a base class pointer or reference points to a derived class object and a virtual function is called, the actual function that gets executed is determined based on the type of the object being pointed to, allowing for more flexible and dynamic behavior in programs.    
- So late binding and runtime polymorphism are closely related concepts in object-oriented programming, particularly in C++. Late binding refers to the mechanism of determining which function to call at runtime, while runtime polymorphism is the ability of a program to exhibit different behaviors based on the actual object type at runtime. Virtual functions enable both late binding and runtime polymorphism, allowing for more flexible and dynamic behavior in programs.
- example
- problem- shop sell 2 types of products,
    - Book and tape
- in both we have differnt tax rates, so we need to calculate tax based on product type
- On counter we need to bill the customer based on product type, so we need to calculate tax based on product type
- and we pay and will go
- so how we write in program?
- every product has different rate and tax rate
- so we need to write biiling application 
- we have a product class which is base class and we have 2 derived classes book and tape
- diagram with arrow:
            Product
              |
           /      \
          /        \
         Book      Tape

-  Product have:
    - id
    - title
    - price
- Book have:
    - pages
- tape have:
    - duration
- how we can fit it practically in our billing application?
- let us see the code for this example 
*/

#include <iostream>
using namespace std;

class Product
{
private:
    char title[20];
protected:
    float price;
public:
    Product() 
    {
        strcpy(title, " ");
        price = 0.0;
    }
    Product(char *t, float p)
    {
        strcpy(title, t);
        price = p;
    }
/*
    void accept() {
		cout << "title: ";
		cin >> title;
		cout << "price: ";
		cin >> price;
	}
 
    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

*/
     // when a method is declared as virtual in base class,
	//	then it remains virtual in all its derived classes.
    // using virtual keyword for that method in derived classes is optional.
    virtual void accept() {
		cout << "title: ";
		cin >> title;
		cout << "price: ";
		cin >> price;
	}
 
    virtual void display()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
    virtual float calc_total_price() {
		// price + tax (0%)
		return price;
	}
    float get_price() {
		return price;
	}
};
// book is product
class Book : public Product
{
private:
    int pages;

public:
    Book() : pages(0) {}
    //Book(char *t, float p, int pg) : Product(t, p), pages(pg) {}
    //or
    /*
    Book(char *t, float p, int pg)
    {
        Product::setData(t, p);
        pages = pg;
    }
    */
    // or 
    Book(char *t, float p, int pg) : Product(t, p)
    {
        pages = pg;
    }
    
    virtual void accept() {
        Product::accept();
        cout << "Pages: ";
        cin >> pages;
    }

    virtual void display()
    {
        Product::display();
        cout << "Pages: " << pages << endl;
    }

    virtual float calc_total_price() {
		// price + tax (5%)
		return price + price * 0.05;
	}

};

class Tape : public Product
{
private:
    float duration;

public:
    Tape() : duration(0.0) {}
    Tape(char *t, float p, float d) : Product(t, p)
    {
        duration = d;
    } 

    virtual void accept() {
        Product::accept();
        cout << "Duration: ";
        cin >> duration;
    }
    virtual void display()
    {
        Product::display();
        cout << "Duration: " << duration << endl;
    }
    virtual float calc_total_price() {
		// price + tax (5%)
		return price + price * 0.10;

	}
};

int main()
{
    // now person purchases product but selleer dont know which product is purchased, so he will have a product pointer and based on the product type he will call display fn
    // assignment - every customer purchase 5 products - total bill
	//	product *arr[5];
    Product *p = NULL;
    cout << "Enter product type (1 for Book, 2 for Tape): ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1: // Book
        p = new Book;
    
        break;
    case 2: // Tape
        p = new Tape;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 1;

    }
    if (p != NULL) {
        p->get_price(); // compiler decide the call (non-virtual fn)
		p->accept(); // here we are calling accept() fn of product class, but we want to call accept() fn of book or tape class based on the product type, so we need to make accept() fn virtual in product class
		// runtime polymorphism - late binding - virtual fn
        p->display(); // so to resolve this problem we need to make accept() and display() fn virtual in product class, so that based on the product type the correct fn will be called
		// runtime (virtual fn)
        cout << "bill amount: " << p->calc_total_price() << endl;
        delete p;
	}
    // here if we see overiding is happening but we dont need to add any override

    // Detailed class diagram (with all data and functions):
    //
    //                        +-------------------------------+
    //                        |            Product            |
    //                        +-------------------------------+
    //                        | - title: char[20]            |
    //                        | # price: float               |
    //                        +-------------------------------+
    //                        | + Product()                  |
    //                        | + Product(char*, float)      |
    //                        | + virtual accept(): void     |
    //                        | + virtual display(): void    |
    //                        | + virtual calc_total_price() |
    //                        |   : float                    |
    //                        +---------------+---------------+
    //                                        ^
    //                           inherits     |     inherits
    //                                +-------+-------+
    //                                |               |
    //                +---------------+---+       +---+----------------+
    //                |      Book         |       |        Tape        |
    //                +-------------------+       +--------------------+
    //                | - pages: int      |       | - duration: float  |
    //                +-------------------+       +--------------------+
    //                | + Book()          |       | + Tape()           |
    //                | + Book(char*,     |       | + Tape(char*,      |
    //                |   float, int)     |       |   float, float)    |
    //                | + accept(): void  |       | + accept(): void   |
    //                | + display(): void |       | + display(): void  |
    //                | + calc_total_price|       | + calc_total_price |
    //                |   (): float       |       |   (): float        |
    //                |   tax = 5%        |       |   tax = 10%        |
    //                +-------------------+       +--------------------+
    //
    // Runtime polymorphism in main:
    // Product* p = new Book / new Tape;
    // p->accept(); p->display(); p->calc_total_price();
/*
    display() fun:
    - same name but different implementation in base and derived class
    - so we called as polymorphism
    - Poly -> many
    - morphism -> taking forms
    - so many forms of display() fn in base and derived class
    - so we called as polymorphism
    - so we have 2 types of polymorphism
    - compile time polymorphism (early binding) or static type polymorphism
        - function overloading
            - function name same but different signature
            - compiler decide which function to call based on the function signature
            - and its depending on name mangling
            - name mangling is a technique used by C++ compilers to encode additional information about functions, such as their parameter types and namespaces, into their names. This allows the compiler to differentiate between functions with the same name but different signatures (i.e., function overloading). When a function is called, the compiler uses the mangled name to determine which specific function to invoke based on the provided arguments. Name mangling is essential for supporting features like function overloading and templates in C++.
            - inteview question - what is name mangling?
            - for comipler its diff name then how we call polymarphism?
            - called as false  polymorphism
            - what is false polymorphism? false polymorphism is a term used to describe a situation where a function or method appears to exhibit polymorphic behavior (i.e., the ability to take on multiple forms) but does not actually achieve true polymorphism. This can occur when a function has the same name but different signatures (parameters) in different contexts, leading to function overloading. In such cases, the compiler determines which version of the function to call based on the provided arguments at compile time, rather than at runtime. As a result, the behavior is not truly dynamic or flexible, and it does not demonstrate the full capabilities of polymorphism as seen in object-oriented programming with virtual functions and inheritance.
            - example: 
                class Base {
                    void display(int x) { }
                };
                class Derived : public Base {
                    void display(double y) { }
                };
                int main() {
                    Derived d;
                    d.display(5); // calls Derived::display(double), not Base::display(int)
                }
            - who descides which function to call? compiler decide which function to call based on the function signature
            - so its called as early binding or static type polymorphism or compile time polymorphism or false polymorphism
        - operator overloading
            - operator same but different signature
    - run time polymorphism (late binding) or dynamic type polymorphism
        - function overriding
            - function in base class and derived class have same name and signature
            - base class function should be virtual
            - so we called as true polymorphism
            - fn called at runtimes depending on the object type, not pointer type
            - vtable & vptr -> also called as true polymorphism
            - what is meaning of true polymorphism? True polymorphism is a concept in object-oriented programming that refers to the ability of a function or method to behave differently based on the actual object type it is called on, rather than the type of reference or pointer used to invoke it. This is typically achieved through the use of virtual functions and inheritance. In true polymorphism, when a base class pointer or reference points to a derived class object and a virtual function is called, the actual function that gets executed is determined at runtime based on the type of the object being pointed to, allowing for more flexible and dynamic behavior in programs.
            - who decides which function to call? compiler decide which function to call based on the object type at runtime
            - so we called as late binding or dynamic type polymorphism or run time polymorphism or true polymorphism

 - here exactly where or on which binding we are talking about?
 - when I am talking about binding : here fn ka call to fuction defination takla binding mhantat. that is called early binding
    - here we know fn call with its defination at compile time, so we called as early binding
    - so its called as early binding or static type polymorphism or compile time polymorphism or false polymorphism
 - so what is late binding which we need to call if we dont know the product type at compile time, so we need to call the fn based on the object type at runtime, so we need to make accept() and display() fn virtual in product class, so that based on the product type the correct fn will be called
 - called as late binding or dynamic type polymorphism or run time polymorphism or true polymorphism
  - but here compiler dont know which fn to call at compile time, so it will create a vtable for the class and vptr for the object, so that at runtime based on the object type the correct fn will be called
  - so he doesnt know exact address of the fn to call at compile time, so he will create a vtable for the class and vptr for the object, so that at runtime based on the object type the correct fn will be called
  - comipler doesnt know exacty which fn to call at compile time, so it will create a vtable for the class and vptr for the object, so that at runtime based on the object type the correct fn will be called

  see sirs notes for more details on it:
  Early binding vs late binding
-- Late binding:
    case 1 : virtual function
    case 2 : called on pointer/reference to base class
    
- early binding:
    case 1 : non-virtual function
    case 2 : called on object of base class

    obj.fn() -> early binding
    ptr->fn() -> late binding (fn virtual in base class and need to call on pointer/reference to base class)
- if function is not overridden in ojects class, then inherited fn of base class is called, so we called as early binding



*/

/*
    see the sirs notes for more details on it
*/

/*
        Early binding vs Late binding (as in notes)

        - Virtual function invoked using pointer or reference is always late binding
            (call is resolved at runtime). Rest all are early binding
            (call is resolved at compile time).

        - In early binding, function is called from the caller's class;
            while in late binding function is called from object's class.

        - In case of late binding execution plan is still prepared at compile time
            (as vtable is created by the compiler).

            Steps:
            1) Find index of function in vftable (n).
            2) Go to object address.
            3) Read vfptr (first 8 bytes) and get vftable.
            4) Call nth function from vftable.

        Conditions for late binding:
            1) Function must be virtual in base class.
            2) Function must be called using base pointer/reference.

        Examples:
            obj.fun();   // early binding (object call)
            ptr->fun();  // late binding (base ptr/ref + virtual)

        Note:
            if function is not overridden in object's class,
            inherited function of base class is called.
*/

/*
    Slide example: Early binding vs Late binding

    class A {
    public:
        void f1() {}
        virtual void f2() {}
        void f3() {}
        virtual void f4() {}
    };

    class B : public A {
    public:
        void f1() {}
        void f2() {}
        virtual void f3() {}
        void f5() {}
        virtual void f6() {}
    };

    A objA;
    objA.f1(); // E, A::f1
    objA.f2(); // E, A::f2
    objA.f3(); // E, A::f3
    objA.f4(); // E, A::f4
    objA.f5(); // compiler error
    objA.f6(); // compiler error

    B objB;
    objB.f1(); // E, B::f1
    objB.f2(); // E, B::f2
    objB.f3(); // E, B::f3
    objB.f4(); // E, A::f4
    objB.f5(); // E, B::f5
    objB.f6(); // E, B::f6

        Reasons:
        - objA.f1(): objA type is A and f1 is non-virtual, so early binding to A::f1.
        - objA.f2(): objA type is A; virtual exists but call is on object, so A::f2.
        - objA.f3(): f3 is non-virtual in A, so early binding to A::f3.
        - objA.f4(): f4 is virtual in A, but object type is A itself, so A::f4.
        - objA.f5(): compiler error because class A has no member f5.
        - objA.f6(): compiler error because class A has no member f6.

        - objB.f1(): B defines f1 with same signature; object is B, so B::f1.
        - objB.f2(): B overrides virtual f2 from A; object is B, so B::f2.
        - objB.f3(): B defines virtual f3; object is B, so B::f3.
        - objB.f4(): B does not override f4, so inherited A::f4 is called.
        - objB.f5(): f5 exists only in B, so B::f5.
        - objB.f6(): f6 exists in B and is virtual, so B::f6.

        Note:
        - Here objA/objB are direct object calls. Virtual dispatch is most visible when
            calling through base pointer/reference (A* / A&).
*/

/*
    Slide example (pointer calls):

    A *pA = new A;
    pA->f1(); // E, A::f1
    pA->f2(); // L, A::f2
    pA->f3(); // E, A::f3
    pA->f4(); // L, A::f4
    pA->f5(); // compiler error
    pA->f6(); // compiler error

    B *pB = new B;
    pB->f1(); // E, B::f1
    pB->f2(); // L, B::f2
    pB->f3(); // L, B::f3
    pB->f4(); // L, A::f4
    pB->f5(); // E, B::f5
    pB->f6(); // L, B::f6

    Reasons:
    - pA->f1(): pA type is A* and f1 is non-virtual, so early binding to A::f1.
    - pA->f2(): f2 is virtual and call is through pointer, so late binding; runtime target is A::f2 (object is A).
    - pA->f3(): non-virtual in A, so early binding to A::f3.
    - pA->f4(): f4 is virtual and call is through pointer, so late binding; runtime target is A::f4 (object is A).
    - pA->f5(): compiler error, f5 not present in class A interface.
    - pA->f6(): compiler error, f6 not present in class A interface.

    - pB->f1(): pB type is B* and B defines non-virtual f1, so early binding to B::f1.
    - pB->f2(): B overrides virtual f2, so late binding; runtime target is B::f2.
    - pB->f3(): f3 is virtual in B, so late binding; runtime target is B::f3.
    - pB->f4(): f4 is inherited virtual, so late binding; B does not override, runtime target is A::f4.
    - pB->f5(): B-only non-virtual function, so early binding to B::f5.
    - pB->f6(): virtual function in B, so late binding; runtime target is B::f6.

    Rule reminder:
    - Pointer call is late binding only for virtual functions.
    - Pointer call to non-virtual function is still early binding.


*/

/*
    Slide example (upcasting and invalid down assignment):

    A *pA = new B;
    pA->f1(); // E, A::f1
    pA->f2(); // L, B::f2
    pA->f3(); // E, A::f3
    pA->f4(); // L, A::f4
    pA->f5(); // compiler error
    pA->f6(); // compiler error

    Reasons:
    - pA is base pointer, dynamic object is B (upcasting is valid).
    - f1 is non-virtual, so early binding by pointer type A* -> A::f1.
    - f2 is virtual, so late binding by object type B -> B::f2.
    - f3 is non-virtual in A, so early binding -> A::f3.
    - f4 is virtual in A, but B does not override it, so late binding still resolves to A::f4.
    - f5/f6 are not members of A interface, so call is not allowed through A* (compiler error).

    B *pB = new A; // compiler error

    pB->f1(); // not applicable (pB creation itself is compiler error)
    pB->f2(); // not applicable (pB creation itself is compiler error)
    pB->f3(); // not applicable (pB creation itself is compiler error)
    pB->f4(); // not applicable (pB creation itself is compiler error)
    pB->f5(); // not applicable (pB creation itself is compiler error)
    pB->f6(); // not applicable (pB creation itself is compiler error)

    Reason:
    - Derived* cannot directly point to Base object.
    - Base* can point to Base or Derived object, but Derived* requires Derived object type.
    - Since initialization fails, all subsequent pB-> calls are invalid in this example.
*/

    return 0;
}
