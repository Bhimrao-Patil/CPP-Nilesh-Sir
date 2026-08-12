#include <iostream>
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

void myfunction() {
    myclass obj;
    obj.display();
}

int main() {
    myfunction();
    return 0;
}

            
