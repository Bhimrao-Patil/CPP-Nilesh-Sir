/*

Access specifiers for class members in inheritance
- public inheritance: public members of base class become public members of derived class, protected members of base class become protected members of derived class, private members of base class are not accessible in derived class
- protected inheritance: public members of base class become protected members of derived class, protected members of base class become protected members of derived class, private members of base class are not accessible in derived class
- private inheritance: public members of base class become private members of derived class, protected members of base class become private members of derived class, private members of base class are not accessible in derived class

class employee {
    int empid;
    //int salary;
protected:
    int salary;
public:
    employee() {
        empid = 0;
        salary = 0;
    }
    int cal_gross_salary() {
        return salary;;
    }
    
};
class manager : public employee {
    int bonus;
public:
    manager() {
        bonus = 0;
    }
    int cal_gross_salary() {
        // return this->salary + bonus; // error: 'salary' is a private member of 'employee'
        // so we can make salary as protected member of employee class, so that it can be accessed in derived class manager
        //instead of adding getter and setter methods for salary, we can make salary as protected member of employee class, so that it can be accessed in derived class manager
        return this->salary + bonus; // now it is accessible in derived class manager
    }
};

// in derived class we can access via 3 ways
// 1. using getter and setter methods of base class
// 2. making base class members as protected
// 3. making base class members as public
*/
class Employee {
    int empid;
    //int salary;
protected:
    int salary;
public:
    Employee() {
        empid = 0;
        salary = 0;
    }
    int cal_gross_salary() {
        return salary;;
    }
};
class Manager : public Employee {
    int bonus;
public:
    Manager() {    
        bonus = 0;
    }
    int cal_gross_salary() {
        // return this->salary + bonus; // error: 'salary' is a private member of 'Employee'
        // so we can make salary as protected member of Employee class, so that it can be accessed in derived class Manager
        //instead of adding getter and setter methods for salary, we can make salary as protected member of Employee class, so that it can be accessed in derived class Manager
        return this->salary + bonus; // now it is accessible in derived class Manager
    }
}; 

#include <iostream>
using namespace std;

int main() {
    Manager m1;
    cout << "Gross salary of manager: " << m1.cal_gross_salary() << endl;
    return 0;
}