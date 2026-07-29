#include <iostream>
#include <cstring>
using namespace std;

class backend_dev {
    char db[20];
public:
    backend_dev() {
        strcpy(db, "default db");
        cout << "backend_dev()" << endl;
    }
    backend_dev(const char* db) {
        strcpy(this->db, db);
        cout << "backend_dev(db)" << endl;
    }
    void develop() {
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
    frontend_dev(const char* ui) {
        strcpy(this->ui, ui);
        cout << "frontend_dev(ui)" << endl;
    }
    void develop() {
        cout << "frontend dev" << endl;
    }
};
class fullstack_dev : public backend_dev, public frontend_dev {
public:
    fullstack_dev() {
        cout << "fullstack_dev()" << endl;
    }
    fullstack_dev(const char* db, const char* ui)
        : frontend_dev(ui), backend_dev(db)
    {
        cout << "fullstack_dev(db,ui)" << endl;
    }
    void display() {
        //this->develop(); // ambiguous which develop to call?
        backend_dev::develop();
        frontend_dev::develop();
    }
};
int main()
{
    fullstack_dev dev1;
    //dev1.display(); // okay - works as expected
    //dev1.develop(); // error: develop() is ambiguous
    // how can we resolve this ambiguity? we can use scope resolution operator to specify which develop() method to call.
    dev1.backend_dev::develop();
    dev1.frontend_dev::develop();
    // so why the issue arose? because both backend_dev and frontend_dev classes have develop() method, so when we call develop() method on fullstack_dev object, compiler doesn't know which develop() method to call, so it gives error. so we can use scope resolution operator to specify which develop() method to call.
   // so its foundation of diamond problem, so we can use virtual inheritance to resolve this issue. we will see in next demo.
   // so the current exaple of multiple inheritance is not a diamond problem, but it can lead to ambiguity and complexity, so it should be used with caution.
    cout << endl;
    return 0;
}

            
    