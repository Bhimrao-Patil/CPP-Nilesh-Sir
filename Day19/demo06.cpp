// throwing int, double, string and catch all exception are not good practice because they are not meaningful and readable. so we need to throw a string message which is meaningful and readable.
// we can write our own exception class which is meaningful and readable. so we need to throw an object of our own exception class which is meaningful and readable. so that developer 2 can handle divide by zero error without modifying divide() fn.
#include <iostream>
using namespace std;

// standard C++ programs prefer to throw the objects of customized exception classes
//  instead of throwing primitive types - int, double, ...

class Exception {
private:
    const char* msg;
public:
    Exception(const char* msg) {
        this->msg = msg;
    }
    // ...
    const char* get_msg() {
        return this->msg;
    }
};

class Time {
private:
    int hrs, min, sec;
public:
    Time() {
        hrs = 0;
        min = 0;
        sec = 0;
    }
    void set_hrs(int h) {
        if (h < 0 || h >= 24) {
            Exception ex("invalid hrs");
            throw ex;
        }
        hrs = h;
    }
    void set_min(int m) {
        if (m < 0 || m >= 60) {
            Exception ex("invalid mins");
            throw ex;
        }
        min = m;
    }
    void set_sec(int s) {
        if (s < 0 || s >= 60) {
            Exception ex("invalid secs");
            throw ex;
        }
        sec = s;
    }
    void display() {
        cout << "time: " << hrs << ":" << min << ":" << sec << endl;
    }
};

int main()
{
    Time t1;
    try {
        t1.set_hrs(22);
        t1.set_min(-16);
        t1.set_sec(40);
        t1.display();
    }
    catch (Exception e) {
        cout << "ERROR: " << e.get_msg() << endl;
    }
    return 0;
}
