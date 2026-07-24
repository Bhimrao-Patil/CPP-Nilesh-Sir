#include <iostream>
using namespace std;

// pass by address
void swap_nums(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// pass by reference
void swap_nums(int& ref1, int& ref2) {
    int temp = ref1;       // temp = num1;
    ref1 = ref2;           // num1 = num2;
    ref2 = temp;           // num2 = temp;
}

int main()
{
    int num1 = 10, num2 = 20;
    cout << "before swap: " << "num1 = " << num1 << ", num2 = " << num2 << endl;
    //swap_nums(&num1, &num2);
    swap_nums(num1, num2);
    cout << " after swap: " << "num1 = " << num1 << ", num2 = " << num2 << endl;
    
    int num = 0;
    int& ref = num;
    cout << "enter a number: ";
    cin >> ref; // input value of num
    cout << "you entered: " << num << endl;
    cout << "&num = " << &num << endl;
    cout << "&ref = " << &ref << endl;

    // reference is anator name to the variable here its provved
    
    return 0;
}

            
