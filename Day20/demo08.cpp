

/*

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

    Vector operator+(int num) {
        Vector res;
        for (int i = 0; i < 3; i++)
            res.arr[i] = this->arr[i] + num;
        return res;
    }

    bool operator==(Vector that) {
        for (int i = 0; i < 3; i++)
            if (this->arr[i] != that.arr[i])
                return false;
        return true;
    }
    // or
    bool operator!=(Vector that) {
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
int main() {
    Vector vec1(2, 3, 4), vec2;
    // requirement: add a vector and a scalar (single number)
    // vector [2,3,4] + scalar [10]  = [12,13,14] 
    vec2 = vec1 + 10;   // vector [2,3,4] + scalar [10] => member fn vec1.op+(10) = [12,13,14] 
    // single number ko scalar kahte hai
    // here always operand1 is passed as this pointer make a note of it
    cout << "vector [2,3,4] + scalar [10] = ";
    vec2.display();
    // req2: 
    vec2 = 100 + vec1;  // 100.op+(vec1) -- not possible -- 1st arg obj -- dot operator
                        // 1st arg object hoga tabhi kr skte hai
                        // only option: friend fn -- Vector operator+(int num, Vector v);
                        
    cout << "scalar [100]  + vector [2,3,4]= ";
    vec2.display();     // [102, 103, 104]

    return 0;
}

*/
