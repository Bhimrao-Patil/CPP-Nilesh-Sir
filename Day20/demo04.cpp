// But if you see
// vec3 = vec1 + vec2;  and vec4 = vec2 - vec1; is more readable than vec3 = vec2.add(vec1); and vec4 = subtract(vec2, vec1);. 
// but that is not possible in C++ by default. So, we can overload + and - operators for Vector class. 
// And we will see how to overload + and - operators for Vector class in below program
//C/C++ operator(arithmatic, relational, logical, bitwise, assignment, increment/decrement, conditional)
// are designed to work with premitive data types(int, float, double, char, etc.)
// Not for objects of user defined data types(class/struct). 
// So, we can overload operators to provide custom implementation for operators for user defined data types(class/struct).
// so we want to consider object as primitive data type. So, we can overload operators to provide custom implementation for operators for user defined data types(class/struct).
// C++ feature: operator overloading:
// - Extending the meaning of operators.
// - Now operator will be able to work with objects of user defined data types(class/struct).
// - syntax: Write functions with special names like operator+(), operator-(), operator*(), etc.
// - So instead of add we can use Vector operator+(Vector that) and i
// - Instead of subtract we can use Vector operator-(Vector that) in class Vector. 
// -And we will see how to overload + and - operators for Vector class in below program.
// In C++ operator can be overloaded as member function or as friend function.
// operator+ and operator- can be overloaded as member function or as friend function.
// And both are keywords in C++. So, we can overload + and - operators for Vector class as member function or as friend function.
// whenever we call vec3 = vec1 + vec2; // vec3 = vec1.operator+(vec2); // here vec1 is calling object of operator+ and vec2 is passed as argument to operator+.
// then vec1 is calling object of operator+ and vec2 is passed as argument to operator+. 
// So, vec1 is copied to this and vec2 is copied to that. And Vector is returned by value from operator+. 
// So, vec3 is copied to res and res is copied to vec3.
// And whenever we call vec4 = vec2 - vec1; // vec4 = operator-(vec2, vec1); 
// here vec2 and vec1 are passed as arguments to subtract function.
// its takenn care by compiler


#include <iostream>
using namespace std;

// [v0, v1, v2]
class Vector {
private:
    double arr[3];
public:
    Vector() {
        for (int i = 0; i < 3; i++)
            arr[i] = 0.0;
    }
    Vector(double v0, double v1, double v2) {
        arr[0] = v0;
        arr[1] = v1;
        arr[2] = v2;
    }
    ~Vector() {
    }
    void display() {
        cout << "[" << arr[0] << ", " << arr[1] << ", " << arr[2] << "]" << endl;
    }
    // ...
    // 1 method : member function to add two vectors (objects)
    Vector operator+(Vector that) {
        Vector res;
        for (int i = 0; i < 3; i++)
            res.arr[i] = this->arr[i] + that.arr[i];
        return res;
    }

    friend Vector operator-(Vector vec1, Vector vec2); // friend function declaration. So, we can access private members of class Vector in this function.

};
// 2 Method : global function to subtract two vectors (objects). And we know in global function we don't have this pointer.
//             So, we need to pass both objects as arguments to the function.
Vector operator-(Vector vec1, Vector vec2) {
    Vector res;
    for (int i = 0; i < 3; i++)
        // res.arr[i] = vec1.arr[i] - vec2.arr[i]; // global function can't access private members of class. So, we need to make this function as friend function of class Vector.
        res.arr[i] = vec1.arr[i] - vec2.arr[i]; 
    return res;
}

int main() {
    Vector vec1(1, 2, 3), vec2(4, 5, 6), vec3, vec4;
    //Req1:
    vec3 = vec1 + vec2; // [1, 2, 3] + [4, 5, 6] = [5, 7, 9] // vec3 = vec1.operator+(vec2);
    //vec3 = vec2.add(vec1); // [4, 5, 6] + [1, 2, 3] = [5, 7, 9] // here vect2 is this and vect1 is that
    // vect1 passed as argument to add fn and vect2 is calling object of add fn. And vec1 is passed by value to add fn. So, vec1 is copied to that and vec2 is copied to this.
    // vec2 is passed by this* so that is passed by address. 
    // Vector is returned by value from add fn. So, vec3 is copied to res and res is copied to vec3.
    cout << "vec1 + vec2 = vec3 => ";
    vec3.display();
    //Req2:
    vec3 = vec2 - vec1; // [4, 5, 6] - [1, 2, 3] = [3, 3, 3] // vec3 = operator-(vec2, vec1);
    //vec4 = subtract(vec2, vec1); // [4, 5, 6] - [1, 2, 3] = [3, 3, 3]
    // vec2 and vec1 are passed by value to subtract fn. So, vec2 is copied to vec1 and vec1 is copied to vec2.
    // Vector is returned by value from subtract fn. So, vec4 is copied to res and res is copied to vec4.
    cout << "vec2 - vec1 = vec3 => ";
    vec3.display();

    return 0;
}
// if this is clear, then we can move to operator overloading. We will overload + and - operators for Vector class.
