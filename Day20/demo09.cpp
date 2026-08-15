

/*
Are these efficient? Unnecessary memory waste occurs when using pass by value in operator overloading. Consider using pass by reference instead.
so alag sau 24 byte ka memory waste ho raha hai. So, we can use pass by reference to avoid this memory waste.
so because of pass by value, 24 byte ka memory waste ho raha hai. So, we can use pass by reference to avoid this memory waste.
there is reason jaha jaha possible hai vaha pass by reference use karna chahiye. So, we can use pass by reference to avoid this memory waste.
and pass const reference because we are not modifying the object. So, we can use pass by reference to avoid this memory waste.
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

    //bool operator==(Vector& that) {
    Vector operator+(int num) {
        Vector res;
        for (int i = 0; i < 3; i++)
            res.arr[i] = this->arr[i] + num;
        return res;
    }

    bool operator==(const Vector& that) {
        for (int i = 0; i < 3; i++)
            if (this->arr[i] != that.arr[i])
                return false;
        return true;
    }
    // or
    // bool operator!=(Vector& that) {
    bool operator!=(const Vector& that) {
        return ! this->operator==(that); // this->op==(that) -> bool
    }
    friend Vector operator-(Vector vec1, Vector vec2); // friend function declaration. So, we can access private members of class Vector in this function.
    friend Vector operator+(int num, Vector v); // friend function declaration. So, we can access private members of class Vector in this function.
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

Vector operator+(int num, Vector v) { // friend function definition. So, we can access private members of class Vector in this function.
    Vector res;
    for (int i = 0; i < 3; i++)
        res.arr[i] = num + v.arr[i];
    return res;
}


int main() {
    Vector vec1(1, 2, 3), vec2(4, 5, 6);
    // requirement: check whether two vectors are same or not
    if (vec1 == vec2) // vec1.op==(vec2) -> bool
        cout << "vec1 is same as vec2" << endl;
    else
        cout << "vec1 is different than vec2" << endl;

    return 0;
}
/*
Operator overloading good practice:
1. Whererever possible, use pass by reference to avoid unnecessary memory waste.(not pass by value or pass by pointer/address)
2. if the obj is not getting modified in overloaded operator, then use const reference to avoid unnecessary memory waste.(not pass by value or pass by pointer/address)
3. relational operator overloading should be done in pairs. (== and !=, < and >, <= and >=)
*/
