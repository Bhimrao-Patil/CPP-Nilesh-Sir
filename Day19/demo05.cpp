// anathor way to handle error gracefully
#include <iostream>
#include <cstdlib>
using namespace std;

class myclass {
private:
    int a;
    int *p;
public:
    myclass() {
        a = 1;
        p = new int;
        cout << "myclass() called" << endl;
    }
    // ...
    void display() {
        cout << "display() - a = " << a << endl;
    }
    ~myclass() {
        delete p;
        cout << "~myclass() called" << endl;
    }
};

int divide(int num1, int num2) {
    if (num2 == 0)
        throw "divide by zero";
    return num1 / num2;
}
void myfunction() {
    myclass obj;
    obj.display();
    int* ptr = new int[4]; // dynamic memory allocation
    // ...
    int num, den;
    cout << "enter two numbers: ";
    cin >> num >> den;
    int res = divide(num, den);
    cout << "division result: " << res << endl;
    delete[] ptr; // dynamic memory de-allocation
}
void my_terminate_fn() {
    cout << "some error occurred. exitting..." << endl;
    exit(1); // graceful exit
}
int main() {
    set_terminate(my_terminate_fn); // set terminate handler at the program startup.
    //try {
        myfunction();
    //}
    //catch(const char *err) {
    //    cout << "ERROR: " << err << endl;
    //}
    return 0;
}

/*
if exception not handled in appn then c++ runtime handles it by calling terminate() fn which will terminate the program abnormally. so it is better to handle exception in appn and not let c++ runtime handle it.

*/            
