#include <iostream>
#include <cstring>
using namespace std;

class person {
private:
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
    // getters/setters
    void accept() {
        cout << "name: ";
        cin >> name;
        cout << "age: ";
        cin >> age;
    }
    void display() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
    ~person() {
        //cout << "~person() called" << endl;
    }
};

class student : public person {
private:
    int roll;
    int marks;
public:
    student() {
        roll = 0;
        marks = 0;
    }
    student(const char* nm, int a, int r, int m)
        :person(nm, a) {
        roll = r;
        marks = m;
    }
    // getters/setters
    void accept() {
        this->person::accept(); // calling base class method
        cout << "roll: ";
        cin >> roll;
        cout << "marks: ";
        cin >> marks;
    }
    void display() {
        //this->display(); // call person::display() method , here currentlly its calling student::display() method, so it will give recursion, so we need to call person::display() method using scope resolution operator like this: person::display();
        this->person::display(); // calling base class method
        // using scope resolution base:: is compulsory, as name of base fn is same as derived fn
        // not using scope resolution, fn will call itself recursive. 
        cout << "roll: " << roll << endl;
        cout << "marks: " << marks << endl;
    }
    ~student() {
        //cout << "~student() called" << endl;
    }
};

int main()
{
    person p1("James", 65);
    p1.display(); // person::display
    cout << endl;

    //student s1;
    //s1.accept_student();
    //s1.display_student();

    student s2("sakshi", 14, 5, 89);
    s2.display(); // student::display
    cout << "sizeof(s2) = " << sizeof(s2) << endl;
    
    // but here we are calling student::display() method, but it is calling person::display() method, because person::display() method is not virtual, so it is not overridden in student class, so it is called from base class person.
    // why its giving segementation fault, because we are calling person::display() method, but it is trying to access student class members roll and marks, which are not initialized, so it is giving segmentation fault.
    // to avoid this we can make person::display() method virtual, so that it can be overridden in student class, so that it can access student class members roll and marks.
    // or we can call person::display() method using scope resolution operator like this: person::display(); so that it can access person class members name and age, and not student class members roll and marks.
    // if we not make person::display() method virtual, then it will call person::display() method, which will not access student class members roll and marks, so it will not give segmentation fault.
    // otherwise its nothing but recursion, because person::display() method is calling student::display() method, which is calling person::display() method, which is calling student::display() method, and so on, so it will give segmentation fault.
    return 0;

}


            
