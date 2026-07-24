// demo02.cpp : this file contains "main" fn. Program execution begins and ends

#include<iostream> 

using namespace std;

int main()
{   
    // pointer in c also used in cpp
    int num1 = 10, num2 = 20;
    // Pointer can be garbage
    //int* ptr1; // ptr1 is pointer to int
    //*ptr =1 //proramm will fail it will be dangling ptr
    int* ptr1 = NULL;
    ptr1 = &num1; // add of nu1 is assigned to ptr1
    cout << "*ptr1= " << *ptr1 << endl; // value at ptr1 - > 10//
    // please add digram of its execution

    ptr1 = &num2;  // now we modified add of ptr1 and num2 is assigned to ptr1 (old add overwriten)
    cout << "*ptr1= " << *ptr1 << endl; // value at ptr2 - > 20//
    
    int num3 = 30;
    // ptr are powerfull but we need safe ptr not grabage and null ptr
    // so sfare alternate ptrs comes in cpp is reference
    //c+  references
    // safer alternative to ptrs
    //reference is alias (anator name) to variable
    //int& ref3; // reference req initalisation its not like  ptr we need ti intialation at the point o declaration
    int& ref3 = num3; // ref3 is alias to num3
    cout << "num3 = " << num3 << endl;
    cout << "ref3 = " << ref3 << endl;
    // if we print size of both its same everytime as per datat type
    // please if poosible add digram of it

    // no concept of reference to refernce -- all refernce will refer to same variable
    float num4 = 4.4;
	float& r4 = num4; // r4 is ref to num4 -- r4 is another name of num4
	float& r5 = r4;   // r5 is ref to num4 -- r5 is another name of num4
	num4++; // 4.4 --> 5.4
	r4++;   // 5.4 --> 6.4
	r5++;   // 6.4 --> 7.4
	cout << "num4 = " << num4 << ", " << r4 << ", " << r5 << endl;
    return 0;

}
// refernce must be initialized at pt of decalaion
// ref cannot later ref to anaother var
// in c its nothing but const pointer
// ref can not be null refer. null ptr is possible
//ref can be data member of a class 
// ref can be args to fn or retur. value fn