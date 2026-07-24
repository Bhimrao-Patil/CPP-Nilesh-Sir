#include <iostream>

using namespace std;
//logically, reference is anaothor name to the variable
// internall referemces are constant points that are automatically derefernced
// 1. const ptr : it can point to only one variable(intialised)
// and can not point to anatore var nor reassignment
//2. auto derefernce: no value at ("*")operator
  

char ch2 = 'X';
class test {
private:
    int num;    //8 bytes
    char& ref; // reference as a data meber, intit not allowed heher // 8 bytes
    char& ref2; // reference as data member // bytes 8 byte

public:
    // reference must be initialsed at the pont of decalation and we are initializing in ctor
/*
    test(char& r) { // it gives an error
        ref = r;
    }
*/

    // so use new concept comes in pictur ctor member intialser list
    test(char& r) 
         :num(10), // // primitive type data members can also be initialized in member initializer list 
         ref(r),
         ref2(ch2)
    {
             // must be initialised in "contructor intialser list" 
        //ref = r;
        //num = 10;

    }

    void change()
    {
        ref++; // inc char. (ASCII Value)
        ref2++;
    }
};

int main()
{
    char ch = 'A'; 
    test obj(ch);
    cout << "ch : " <<  ch << endl; // A
    obj.change();
    cout << "ch : " <<  ch << endl; // B
    cout << "ch2 = " << ch2 << endl; // Y
    cout << "sizeof(obj) = " << sizeof(obj) << endl;// 24


    return 0;

}
