/*
Type of Inheritance in C++:
- Single inheritance: In single inheritance, a derived class inherits from a single base class.
    - B  is derived class and A is base class
    - Nano car is derived class and Car is base class
- Multilevel inheritance: In multilevel inheritance, a derived class inherits from another derived class.
    - C is derived class, B is derived class, and A is base class
    - Means c is derived from A and B
    - Nano car is derived from Car and Vehicle
    - Fullstack developer is derived from Frontend developer and Backend developer
- Herarchical inheritance: In hierarchical inheritance, multiple derived classes inherit from a single base class.
    - B and C are derived classes and A is base class
    - Nano car and Swift car are derived from Car
    - Employee class and manager is employee, cleark is employee, salesman is employee
    - here it means multiple derived classes are inheriting from a single base class.
- Multilevel inheritance: In multilevel inheritance, a derived class inherits from another derived class.
    - C is derived class, B is derived class, and A is base class
    - Means c is derived from A and B
    - Nano car is derived from Car and Vehicle
    - Person -> Student -> Engineering student
    - here it means a derived class is inheriting from another derived class.
- Hybrid inheritance: In hybrid inheritance, a derived class inherits from multiple base classes.
    - D is derived class, B and C are base classes, and A is base class
    - Means D is derived from B and C, and B and C are derived from A
    - Nano car is derived from Car and Vehicle, and Car is derived from Vehicle
    - here it means a derived class is inheriting from multiple base classes.
-Multiple inheritance: In multiple inheritance, a derived class inherits from multiple base classes.
    - D is derived class, B and C are base classes
    - Means D is derived from B and C
    - Nano car is derived from Car and Vehicle
    - here it means a derived class is inheriting from multiple base classes.
    - C++ supports multiple inheritance, but it can lead to ambiguity and complexity, so it should be used with caution.

*/

#include <iostream>
using namespace std;

class backend_dev {
    char db[20];
public:
    backend_dev() {
        strcpy(db, "default db");
        cout << "backend_dev()" << endl;
    }

    backend_dev(const char* db_name) {
        strcpy(this->db, db_name);
        cout << "backend_dev(const char*)" << endl;
    }
    
    void develop_backend() {
        cout << "backend dev" << endl;
    }
};
class frontend_dev {
    char ui[20];
public:
    frontend_dev() {
        strcpy(ui, "default ui");
        cout << "frontend_dev()" << endl;
    }
    frontend_dev(const char *ui) {
        strcpy(this->ui, ui);
        cout << "frontend_dev()" << endl;
    }
    void develop_frontend() {
        cout << "frontend dev" << endl;
    }
};
class fullstack_dev : public backend_dev, public frontend_dev {
public:
    fullstack_dev() {
        cout << "fullstack_dev()" << endl;
    }
    fullstack_dev(const char *db, const char *ui) 
        : frontend_dev(ui), backend_dev(db)
    {
        cout << "fullstack_dev(db,ui)" << endl;
    }
    void display() {
        develop_backend();
        develop_frontend();
    }
};
int main()
{
    fullstack_dev dev1;
    dev1.develop_backend();
    dev1.develop_frontend();
    cout << endl;
    dev1.display();
    // here fullstack_dev class is inheriting from backend_dev and frontend_dev classes, so it can access the methods of both classes.
    // so output will be:
    /*
    backend dev
    frontend dev
    backend dev
    frontend dev
    */
   // when derived class obj is created, first base class constructor is called and then derived class constructor is called, so output will be:
   /*
    backend_dev()
    frontend_dev()
   */ 
    // the order of constructor calling is opposite of destructor calling, so when derived class obj is destroyed, first derived class destructor is called and then base class destructor is called.   
    fullstack_dev dev2("MySQL", "React");
    dev2.display();
    // here fullstack_dev class is inheriting from backend_dev and frontend_dev classes, so it can access the methods of both classes.
    // so output will be:
    /*
    backend_dev(const char*)
    frontend_dev()
    fullstack_dev(db,ui)
    backend dev
    frontend dev
    */
    return 0;
}
