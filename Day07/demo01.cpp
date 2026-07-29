/*
inheritance in c++
-Inheritance represents an "is-a" relationship between a base class and a derived class.
 - Mango is a fruit, so Mango(Child/derived) class can be derived from Fruit(Parent/base) class.
- Student is a person, so Student class can be derived from Person class.
- So all things include in child class which are present in parent class.
- All members of parent class are inhertited into child class except private members of parent class.
    - Parent class a.k.a base class or super class
    - Child class a.k.a derived class or sub class
- It is process of generalization to specialization.
- Subclass reprsents specialization in which field and methods from super class are added,
modified or even hidden

UML diagram for inheritance
Person
-------------------
- name: char[20]
- age: int
-------------------
+ Person()
+ Person(const char*, int)
+ accept(): void
+ display(): void
--------------------
Student
-------------------
- roll: int
- marks: int
-------------------
+ Student()
+ Student(const char*, int, int, int)
+ accept(): void
+ display(): void
--------------------  
-in C++ size of derived class = size of base class + size of derived class members
- constructor of base class is called first and then constructor of derived class is called
- we can use base intialization list to call base class constructor from derived class constructor
- destructor of derived class is called first and then destructor of base class is called
- Order of destructor is reverse of order of constructor

*/
#include <iostream>
#include <cstring>
using namespace std;

class person {
private:
    char name[20];
    int age;
public:
    person() {
        cout << "person default constructor called" << endl;
        strcpy(name, "");
        age = 0;
    }
    person(const char* nm, int a) {
        cout << "person parameterized constructor called" << endl;
        strcpy(name, nm);
        age = a;
    }
    // getters/setters
    void accept_person() {
        cout << "name: ";
        cin >> name;
        cout << "age: ";
        cin >> age;
    }
    void display_person() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
    ~person() {
        cout << "person destructor called" << endl;
    }
};

class student : public person {
private:
    int roll;
    int marks;
public:
    student() {
        cout << "student default constructor called" << endl;
        roll = 0;
        marks = 0;
    }
    student(const char* nm, int a, int r, int m) : person(nm, a) { // calling base class parameterized constructor
        cout << "student parameterized constructor called" << endl;
         //calling base class parameterized constructor
        // its is base /member initialization list, it is used to initialize base class members
        // calling base class parameterized constructor
        //callinge member obj 

        roll = r;
        marks = m;
    }
    // getters/setters
    void accept_student() {
        this->accept_person(); // calling base class method
        cout << "roll: ";
        cin >> roll;   
        cout << "marks: ";
        cin >> marks;
    }
    void display_student() {
        //cout << name << age << endl; // error: 'name' and 'age' are private members of 'person'
        // we can display pesron data using display_person() method of person class
        this->display_person(); // calling base class method

        cout << "roll: " << roll << endl;
        cout << "marks: " << marks << endl;
    }

    ~student() {
        cout << "student destructor called" << endl;
    }
};

int main()
{
    person p1("John", 20);
    p1.display_person();
    cout << endl;

    // student s1;
    // s1.accept_student();
    // s1.display_student();
    // cout << endl;

    student s2("Alice", 19, 101, 95);
    s2.display_student();
    // here it will give an issue
    /*
    person default constructor called
    student parameterized constructor called
    name: 
    age: 0
    roll: 101
    marks: 95
    */
   // because we are not calling base class parameterized constructor in derived class parameterized constructor
    // so we need to call base class parameterized constructor in derived class parameterized constructor
    // using member initialization list like this: student(const char* nm, int a, int r, int m) : person(nm, a) { ... }
    // if we nothing like this: student(const char* nm, int a, int r, int m) { ... } then it will call base class default constructor and then derived class parameterized constructor

    // constructor and destructor calling order in inheritance
    // when we create an object of derived class, first base class constructor is called and then derived class constructor is called
    // when we destroy an object of derived class, first derived class destructor is called and then base class destructor is called
    // so the order of constructor and destructor calling is opposite
    
    cout << "sizeof student: " << sizeof(student) << endl; // 32 bytes
    // why 32 bytes? because student class has 2 int members (roll and marks) and person class has 2 char array members (name[20] and age), so total size = 4 + 4 + 20 + 4 = 32 bytes
    // if the char array is of size 21 then the size will be 36 bytes because of padding, so the size of student class will be 36 bytes
    // why padding is important? because of memory alignment, so the size of student class will be 36 bytes
    // but 3 bytes of padding is wasted, so we can use char array of size 20 instead of 21 to save memory, so the size of student class will be 32 bytes
    // so if its wasted so why padding concepts comes into picture? because of memory alignment, so the size of student class will be 36 bytes
    // so how we can overcome insted of using char array we can use string class, so the size of student class will be 24 bytes because string class has 3 members (char* str, int len, int cap) and 1 int member (age), so total size = 8 + 4 + 4 + 4 = 24 bytes



    return 0;
}