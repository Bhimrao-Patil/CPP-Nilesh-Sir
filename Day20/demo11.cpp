

/*
so in last demo instead of 
    Vector vec1(1, 2, 3), vec2(4, 5, 6);
    cout << "vec1 = "; vec1.display(); // [2, 3, 4 ]
that is not loking good. So, we can use pre-increment and post-increment operator overloading to make it look good.

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

    // pre-increment
    // why we aded & in return type? because we want to return current object. So, we need to return reference of current object.
    // if its variable, then we can return value of variable. But if its object, then we need to return reference of object.
    // because if any varaible is created inside the function, then it will be destroyed after the function ends. So, we need to return reference of current object.
    Vector& operator++() {
        for (int i = 0; i < 3; i++)
            this->arr[i] += 1;
        return *this; // return current object (value at "this")
    }
    // post-incrment
    Vector operator++(int dummy) {
        // dummy is not used. But we need to add it to differentiate between pre-increment and post-increment.
        // if we don't add dummy, then it will be considered as pre-increment. So, we need to add dummy to differentiate between pre-increment and post-increment.
        // because we have same fun in line no 61. So, we need to differentiate between pre-increment and post-increment.
        // here return by reference is not possible because we are returning temp object. So, we need to return by value.
        Vector temp = *this; // store current object in temp object. So, we need to return temp object.
        for (int i = 0; i < 3; i++)
            this->arr[i] += 1; // increment current object
        return temp;
    }
    
    friend Vector operator-(Vector vec1, Vector vec2); // friend function declaration. So, we can access private members of class Vector in this function.
    friend Vector operator+(int num, Vector v); // friend function declaration. So, we can access private members of class Vector in this function.
    friend ostream& operator<<(ostream& out, const Vector& v);

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
/*
void operator<<(ostream& out, Vector& v) {
    out << "[" << v.arr[0] << ", " << v.arr[1] << ", " << v.arr[2] << "]";


}
*/
// why return type is ostream&? because we want to return cout object. So, we need to return reference of cout object.
// operator< can be called on ostream onlly.
// so operator<< must return ostream&. So, we can use it in chain.
ostream& operator<<(ostream& out, const Vector& v) {
    out << "[" << v.arr[0] << ", " << v.arr[1] << ", " << v.arr[2] << "]";
    return out;
}
int main() {
    Vector vec1(1, 2, 3), vec2(4, 5, 6);
    //cout << vec1; // operator<<(cout, vec1); // for such simple call return type can be void too
    cout << vec1 << vec2;
        // step1: cout << vec1 -> operator<<(cout, vec1) --> returns cout
        // step2: returned cout << vec2 -> operator<<(cout, vec2) --> returns cout
        // full call --> operator<<( operator<<(cout, vec1), vec2 )
    // in this case compiler will tr to resolve the call as cout.operator<<(vect2);
    // cout is object of ostream class. 
    //ostream class has built in ops<<() function which takes string as argument for int, float, double
    // howver osteram doesnt havse ops<<() function which takes object of user defined class as argument. So, compiler will tr to resolve the call as operator<<(cout, vec2);
    // we cann not implement such fn in predefined osstearm class.
    // moral : we can not ocerload op<< for display as member dunction
    // so that is not allowed to overload op<< as member function. So, we need to overload it as global function.

    cout << "\nvec1 = " << vec1 << endl;
    return 0;
}

/*
int main() {
    Vector vec1(1, 2, 3), vec2(4, 5, 6);
    // requirement: check whether two vectors are same or not
    if (vec1 == vec2) // vec1.op==(vec2) -> bool
        cout << "vec1 is same as vec2" << endl;
    else
        cout << "vec1 is different than vec2" << endl;

    Vector vec3 = ++vec1;   // vec3 = vec1.op++();
    cout << "vec3 = ++vec1;" << endl;
    cout << "vec1 = "; vec1.display(); // [2, 3, 4]
    cout << "vec3 = "; vec3.display(); // [2, 3, 4]

    Vector vec4 = vec2++; // vec4 = vec2.op++(0);
    cout << "vec4 = vec2++;" << endl;
    cout << "vec2 = "; vec2.display(); // [5, 6, 7]
    cout << "vec4 = "; vec4.display(); // [4, 5, 6]
    return 0;
}
*/

/*
Operator overloading good practice:
1. Whererever possible, use pass by reference to avoid unnecessary memory waste.(not pass by value or pass by pointer/address)
2. if the obj is not getting modified in overloaded operator, then use const reference to avoid unnecessary memory waste.(not pass by value or pass by pointer/address)
3. relational operator overloading should be done in pairs. (== and !=, < and >, <= and >=)
*/
