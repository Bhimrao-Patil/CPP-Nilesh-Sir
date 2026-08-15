/*
if we write operator+ as global and make it friend function of class vector
then it will give an error because operator+ is already defined as member function of class vector. So, we can't define it again as global function.
so its not allowed same signature function can't be defined twice. So, we can define operator+ as member function or global function but not both. But we can define operator- as global function because it is not defined as member function of class vector. So, we can define it as global function and make it friend function of class vector so that we can access private members of class vector in this function
And c++ has not vec1 * vect2. As * has not operator overloading. So, we can't overload * operator for vector class. 
we can do int * int, double * double, int * double, double * int. But we can't do vector * vector. So, we can't overload * operator for vector class.
Advantages of operator overloading:
1. It makes code more readable and understandable.
2. It increases the readability of code.
So limitation of operator overloading:
1. cannot change num of operands.
eg. == operator is binary operator 2 args
   - member fun: this & 1 arg
   - friend fun: 2 args explictly
2. cannot change precedence of operators.
    e.g. ob1 + ob2 * ob3; // here * has higher precedence than +. So, ob2 * ob3 will be evaluated first and then ob1 + (ob2 * ob3) will be evaluated. So, we can't change precedence of operators.
3. cannot change associativity of operators.
    e.g. ob1 - ob2 + ob3; // - first and then +. So, we can't change associativity of operators.
4. certain operators cannot be overloaded. e.g. ::, ., .*, sizeof, typeid, const_cast, dynamic_cast, static_cast, reinterpret_cast, ?:, sizeof..., alignof, co_await
5. certain operators can be overloaded only as friend. e.g. =, [], ()


*/

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
    friend Vector operator+(Vector that); // friend function declaration. So, we can access private members of class Vector in this function. --- IGNORE ---

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
Vector operator+(Vector that) {
    Vector res;
    for (int i = 0; i < 3; i++)
        res.arr[i] = this->arr[i] + that.arr[i];
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
