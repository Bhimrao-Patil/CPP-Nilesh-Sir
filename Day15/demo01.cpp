#include <iostream>
using namespace std;

#define PI 3.142

// class shape -- contains only pure virtual functions (nothing else)
//      - force derived class to implement all pure virtual fns -- contract'
//      - pure abstract class a.k.a. interface
class shape {
public:
    virtual double calc_area() = 0;
    virtual double calc_peri() = 0;
};

class rectangle : public shape {
public:
    rectangle(double l = 0.0, double b = 0.0) {
        length = l;
        breadth = b;
    }
    virtual double calc_area() {
        return length * breadth;
    }
    virtual double calc_peri() {
        return 2 * (length + breadth);
    }
    // ...
private:
    double length;
    double breadth;
};

class circle : public shape {
public:
    circle(double r = 0.0) {
        radius = r;
    }
    virtual double calc_area() {
        return PI * radius * radius;
    }
    virtual double calc_peri() {
        return 2 * PI * radius;
    }
private:
    double radius;
};

class square : public shape {
public:
    square(double s = 0.0) {
        side = s;
    }
    virtual double calc_area() {
        return side * side;
    }
    virtual double calc_peri() {
        return 4 * side;
    }
private:
    double side;
};


// implement fn that sum areas of all shapes.
double shapes_area_total(shape* arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != NULL)
            sum += arr[i]->calc_area();
    }
    return sum;
}

// implement fn that inputs shape info as per user choice
shape* input_shape() {
    shape* s = NULL;
    int choice;
    double len, br, side, rad;
    cout << "\n1. rectangle\n2. circle\n3. square\nenter choice: ";
    cin >> choice;
    switch (choice) {
    case 1: // rectangle
        cout << "enter length & breadth: ";
        cin >> len >> br;
        s = new rectangle(len, br);
        break;
    case 2: // circle
        cout << "enter radius: ";
        cin >> rad;
        s = new circle(rad);
        break;
    case 3: // square
        cout << "enter side: ";
        cin >> side;
        s = new square(side);
        break;
    default:
        cout << "invalid choice." << endl;
    }
    return s;
}

int main() {
    shape* arr[5];
    for(int i=0; i<5; i++)
        arr[i] = input_shape();
    double total_area = shapes_area_total(arr, 5);
    cout << "total shapes area: " << total_area << endl;
    for (int i = 0; i < 5; i++)
        delete arr[i];
    return 0;
}

            
