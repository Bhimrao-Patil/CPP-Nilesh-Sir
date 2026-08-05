/*
Today’s Agenda:
- Virtual destructor
- ⁠Abstract class
- ⁠Interface

*/

#include <iostream>
using namespace std;

class A {
public:
    int* pa;
    A() {
        cout << "A constructor called" << endl;
        pa = new int[3];
        for (int i = 0; i < 3; i++)
            pa[i] = 1;
    }
    void display() {
        for (int i = 0; i < 3; i++)
            cout << "pa - " << i << " ele = " << pa[i] << endl;
    }
    ~A() {
        delete[] pa;
        pa = NULL;
        cout << "A destructor called" << endl;
    }
};

class B : public A {
public:
    int* pb;
    B() {
        cout << "B constructor called" << endl;
        pb = new int[3];
        for (int i = 0; i < 3; i++)
            pb[i] = 2;
    }
    void display() {
        A::display();
        for (int i = 0; i < 3; i++)
            cout << "pb - " << i << " ele = " << pb[i] << endl;
    }
    ~B() {
        delete[] pb;
        pb = NULL;
        cout << "B destructor called" << endl;
    }
};

int main() {
    B objB;
    objB.display();
    return 0;
}

/*
diagram for the above code:

          +------------------+
          |        A         |
          +------------------+
          | int* pa          |
          +------------------+
          | A()              |
          | display()        |
          | ~A()             |
          +------------------+
                  ^
                  |
                  |
          +------------------+
          |        B         |
          +------------------+
          | int* pb          |
          +------------------+
          | B()              |
          | display()        |
          | ~B()             |
          +------------------+  
what will be the exact flow of execution for the above code?
The flow of execution for the provided code can be described step-by-step as follows:
1. The constructor of class B is called, which in turn calls the constructor of class A.
2. The constructor of class A allocates memory for the array `pa` and initializes its elements to 1.
3. Control returns to the constructor of class B, which allocates memory for the array `pb` and initializes its elements to 2.
4. The `display` method of class B is called, which first calls the `display` method of class A to print the elements of `pa`.
5. The `display` method of class B then prints the elements of `pb`.
6. When the object `objB` goes out of scope, the destructor of class B is called, which deallocates the memory for `pb`.
7. The destructor of class A is then called, which deallocates the memory for `pa`.

B obj;
  |
on stack
  |
  v
+------------------+        A::A() called
|        B         |        |1 | 1 | 1 | <-- 1000
|        pa (1000) | 100
|------------------|
|        pb (2000) | 200.  B::B() called        
|------------------|.       | 2 | 2 | 2 | <-- 2000

what will happen if B goes out of scope?
When the object `objB` of class B goes out of scope, the following sequence of events occurs:
1. The destructor of class B is called first. This destructor deallocates the memory allocated for the array `pb` using `delete[] pb;` and sets the pointer `pb` to `NULL`.
2. After the destructor of class B completes, the destructor of class A is called. This destructor deallocates the memory allocated for the array `pa` using `delete[] pa;` and sets the pointer `pa` to `NULL`.
3. After both destructors have completed, the memory for the object `objB` itself is released, and it is removed from the stack.
This ensures that all dynamically allocated memory is properly freed, preventing memory leaks.

But program begines not over here
everything is going good as obj is created on stack.

*/