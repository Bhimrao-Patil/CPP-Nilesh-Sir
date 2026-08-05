/*
Today’s Agenda:
1. Interfaces
2. ⁠OOP concepts - Helpful for interviews
3. ⁠Modularity - namespaces **

Interface:
- A class which contains only one pure virtual functions (no data members & other functions), then its is called interface.
- They force (all) pure virtual functions to be overridden in derived class, otherwise derived class also becomes abstract class and can not be used to create object of derived class.
- Typically, these fn are called on base class pointer (or reference) which is pointing to derived class object to achieve runtime polymorphism.
-  Interface are used to design specification/standards
- Interface are immutable & handles fragile base class problem (once published, it can not be changed)
- means if we added one more pure virtual fn in interface, then all the derived class must implement that pure virtual fn, otherwise they will also become abstract class and can not be used to create object of derived class.
- called as fragile base class problem, because if we want to add new pure virtual fn in interface, then we have to modify all the derived class, which is not desirable. So we should not modify interface once it is published
- Interface can also be used to group different/non related object together

diagram:
        shape (interface)
        /      |       \
       /       |        \
    rectangle  circle   square


real time example:
Tubelight
- surya
- philips
- bajaj
- all these are different brands of tubelight, but they have same interface (specification)
- all these brands of tubelight have same interface (specification) - they have same size
- all these brands of tubelight have same interface (specification) - they have same voltage
- all these brands of tubelight have same interface (specification) - they have same watt
- all these brands of tubelight have same interface (specification) - they have same color
- all these brands of tubelight have same interface (specification) - they have same shape
- Its all because of ISI rule, which is implemented by government of India.
- That rules are onlu declalation by ISI not an implementation, so that all these brands of tubelight can be used interchangeably.
- So tubelight venders are implementation classes of tubelight interface (specification) which is declared by ISI.

- example
pritable method --> print
   ^
   |
    Book
   |
    Employee
    |
    Account
- Interfaces is one of the most important concept in OOP, which is used to achieve runtime polymorphism.
- meeans interface is nothing but a class which contains only pure virtual functions (no data members & other functions), then its is called interface.
- what is difference between abstract class and interface?
- abstract class can have data members and other member functions, but interface can not have data members
- abstract class can have constructor and destructor, but interface can not have constructor and destructor
- but interface has defauly constructor and destructor, which will be called when derived class object is created and destroyed.
- but we have not creatd it so iits fine
- but we can not write constructor and destructor in interface, because it can not have data members, so it can not initialize and cleanup the data members of interface.
- if we havent written any classs except class we can add pure virtual fn but if its implemented then we can not add pure virtual fn in interface, because it will break the existing implementation.
- 
*/
#include <iostream>
using namespace std;

#define PI 3.142

// class shape -- contains only pure virtual functions (nothing else)
//      - force derived class to implement all pure virtual fns -- contract'
//      - pure abstract class a.k.a. interface
class shape {
public:
    virtual double calc_area() = 0;
    virtual double calc_peri() = 0;
};

class rectangle : public shape {
public:
    rectangle(double l = 0.0, double b = 0.0) {
        length = l;
        breadth = b;
    }
    virtual double calc_area() {
        return length * breadth;
    }
    virtual double calc_peri() {
        return 2 * (length + breadth);
    }
    // ...
private:
    double length;
    double breadth;
};

class circle : public shape {
public:
    circle(double r = 0.0) {
        radius = r;
    }
    virtual double calc_area() {
        return PI * radius * radius;
    }
    virtual double calc_peri() {
        return 2 * PI * radius;
    }
private:
    double radius;
};

class square : public shape {
public:
    square(double s = 0.0) {
        side = s;
    }
    virtual double calc_area() {
        return side * side;
    }
    virtual double calc_peri() {
        return 4 * side;
    }
private:
    double side;
};

int main()
{
    shape* s = NULL;
    int choice;
    double len, br, side, rad;
    cout << "\n1. rectangle\n2. circle\n3. square\nenter choice: ";
    cin >> choice;
    switch (choice) {
    case 1: // rectangle
        cout << "enter length & breadth: ";
        cin >> len >> br;
        s = new rectangle(len, br);
        break;
    case 2: // circle
        cout << "enter radius: ";
        cin >> rad;
        s = new circle(rad);
        break;
    case 3: // square
        cout << "enter side: ";
        cin >> side;
        s = new square(side);
        break;
    default:
        cout << "invalid choice." << endl;
    }
    if (s != NULL) {
        cout << "shape area: " << s->calc_area() << endl;
        cout << "shape peri: " << s->calc_peri() << endl;
        delete s;
        s = NULL;
    }
    return 0;
}

/*
if we added one more pure virtual fn in shape interface, then all the derived class must implement that pure virtual fn, otherwise they will also become abstract class and can not be used to create object of derived class.
- If we want to add new pure virtual fn in shape interface, then we have to modify all the derived class, which is not desirable. So we should not modify interface once it is published
- So it will force to dervied class to add tha pure virtual fn in derived class, which is not desirable. So we should not modify interface once it is published
- So we should not modify interface once it is published, because it will break the existing implementation
*/
