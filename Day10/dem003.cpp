#include <iostream>
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
    void display() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
    int get_age() {
        return this->age;
    }
};

class employee : public person {
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
    void display() {
        person::display();
        cout << "id: " << id << endl;
        cout << "salary: " << salary << endl;
    }
    int get_id() {
        return this->id;
    }
};

int main()
{
    employee e("Sameer", 42, 3, 90000);
    person* pp = &e; // we are seeing employe outside company means he is person, so we are seeing him as person, so we are seeing him as base class object. So this is called object slicing in c++.
    cout << "using person* : age = " << pp->age << endl; // 42
    //cout << "using person* : id = " << pp->id << endl; // because he is outside company so we can not see his id, so we can not access id of employee from person pointer, because person pointer is base class pointer and employee is derived class object. So this is called object slicing in c++.
    employee* pe = &e; // we are seeing employee in comapany means he is employee of company
    cout << "using employee* : id = " << pe->id << endl; // 3 
    cout << "using employee* : age = " << pe->age << endl; // 42

    // apply object slicing to display funcion which is same in both class
    // using base*, we can access only base members (data/fns)
    // using derived*, we can access derived as well as base members (data/fns)
    pp->display(); // this will call person class display function, because pp is person class pointer, so it will call person class display function. So this is called object slicing in c++.
    pe->display(); // this will call employee class display function, because pe is employee class pointer, so it will call employee class display function. So this is called object slicing in c++
    //  here we see name is same to same but accoring to pointer type it will call respective class display function, so this is called object slicing in c++.
    cout << "id = " << pe->get_id() << endl;
    cout << "age = " << pe->get_age() << endl;
    return 0;
}


            
