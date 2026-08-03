/*
Yesterday we discussed about the virtual inheritance(diamond problem) in C++. Today we will discuss about the virtual functions in C++.
In C++, a virtual function is a member function in the base class that you expect to override in derived classes. When you use a virtual function, you tell the compiler to support late binding on this function. Late binding means that the function to be called is determined at runtime based on the type of the object pointed to by the base class pointer, rather than the type of the pointer itself.
c++ books
1. inside c++ object model by Stanley B. Lippman
2. keshav dattatraya by c++ programming language
where all internal of vtable are discussed in detail. You can refer these books for more details.
3. C++ Primer by Stanley B. Lippman, Josée Lajoie, and Barbara E. Moo 
4. C++ Programming: Principles and Practice Using C++ by Bjarne Stroustrup

Virtual Functions in C++ and object slicing today we will talk about

1st we see object slicing in c++ and then we will see virtual functions in c++.
for example we have 2 entities
Employee 
    - id
    - sal
Student
    - roll
    - marks

    and both are person
SO if we create a diagram like this
        Person
        /    \
   Employee  Student
Person has name [20] and age [4]

- Person p; // if we create object of person size will be 24 bytes
- Employee e; // if we create object of employee size will be 32 bytes
consider we have one employee
here what we will see name= sample and age= 20 and id= 1 and sal= 1000
and we are asking sameer what is your name , means we are consdering him like a person
p = e; // here we are assigning employee object to person object, 
so here we are slicing the employee object and only person part will be copied to person object, means name and age will be copied to person object and id and sal will be sliced off. This is called object slicing in c++.
what will be the size of person object is 24 bytes and when we asigning derved class object to base class object then only base class part will be copied to base class object and derived class part will be sliced off. This is called object slicing in c++.
Rest of elements will be sliced off. This is called object slicing in c++.
When  dervied clas object is assigned to base class object.
only base class part present in derived class object is asigned to base class object.
rest of the elements present in derived class object will be sliced off. That is id and sal will be sliced off. This is called object slicing in c++.
when we meet any one we can ask his name 
because we are seeing him as a person, but we can not ask his id and sal because we are seeing him as a person. This is called object slicing in c++.
same we are doing in programming called as object slicing in c++.
oop is all about mimicking the real world entities in programming. So we can say that object slicing is a part of oop in c++.
- Student s; // if we create object of student size will be 32 bytes



*/

#include <iostream>
#include <cstring>
using namespace std;

class person {
public:
    char name[20];
    int age;
public:
    person() {
        strcpy(name, "");
        age = 0;
    }
    person(const char* nm, int a) {
        strcpy(name, nm);
        age = a;
    }
    void display_person() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
};

class employee: public person {
public:
    int id;
    int salary;
public:
    employee() {
        id = 0;
        salary = 0;
    }
    employee(const char* nm, int a, int i, int s)
        : person(nm, a) {
        id = i;
        salary = s;
    }
    void display_employee() {
        person::display_person();
        cout << "id: " << id << endl;
        cout << "salary: " << salary << endl;
    }
};

int main() {
    // person p;
    // cout << "sizeof person = " << sizeof(p) << endl; // 24
    employee e("Sameer", 42, 3, 90000);
    cout << "sizeof employee = " << sizeof(e) << endl;  // 32
    e.display_employee();
    cout << endl;
    cout << "Assigning employee object to person object" << endl;
    person p2;
    cout << "sizeof person = " << sizeof(p2) << endl; // 24

    p2 = e; // derived class obj assigned to base class obj,
        // only base part present in derived is assigned to that base object
    p2.display_person();
        // with such base obj, now you can only access base part data/functionality
    // p2.id = 10; // error, because id is not present in person class
    // p2.salary = 1000; // error, because salary is not present in person class
    p2.age = 20; // ok, because age is present in person class
    /*
    Person *ptr = &e; // ok, because employee is a person
    if dervied class objects addreess is assigned to base class pointer, then only base part present in derived class object can be accessed using base class pointer.
    ptr->age = 20; // ok, because age is present in person class
    ptr->id = 10; // error, because id is not present in person class
    C++ only language derived class object initializes base class part.
    we can access base class part using derived class object, but we can not access derived class part using base class object.
    
    */
   person *ptr = &e; // ok, because employee is a person
   cout << "e name" << ptr->name << endl; // ok, because name is present in person class
   cout << "e age" << ptr->age << endl; // ok, because age is present in person class
   // cout << "e id" << ptr->id << endl; // error, because id is not present in person class
   // cout << "e salary" << ptr->salary << endl; // error, because salary is not present in person class
   
   return 0;


}
/*
exaple like we are pucrchasing a car and we are seeing it as a car, but we can not see it as a BMW or Audi, because we are seeing it as a car. This is called object slicing in c++.
like in fruit basket we have different fruits like apple, mango, banana, but we are seeing it as a fruit basket, but we can not see it as a apple or mango or banana, because we are seeing it as a fruit basket. This is called object slicing in c++.
HR wants bday list of all employees so we want only name and age of employees, so we can create a person object and assign employee object to person object, so only name and age will be copied to person object and id and salary will be sliced off. This is called object slicing in c++.
So in all above examples we are seeing the real world entities in programming and we are seeing them as a base class object, but we can not see them as a derived class object, because we are seeing them as a base class object. This is called object slicing in c++.
in fruit example fruit is base class and apple, mango, banana are derived classes. When we are seeing fruit basket we can not see it as a apple or mango or banana, because we are seeing it as a fruit basket. This is called object slicing in c++.

*/

            
