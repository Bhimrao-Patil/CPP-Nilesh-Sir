#include <iostream>

void foo2() {
 //cout << "foo2 called" << endl; //  it will give an error because namespace is not visible in this function, so we need to use scope resolution operator to access members of namespace
}

void foo() {
    using namespace std;
    cout << "foo called" << endl;
    foo2();
}
int main() {
    using namespace std;
    foo();
    cout << "Hello, world" << endl;
}