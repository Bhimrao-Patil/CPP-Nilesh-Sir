#include <iostream>
using namespace std;

//data types in c++
// -c++ supports al data types in c -- int, float, char, double
// - c++ has two nw data types
//    - bool : boolean value true or false
            // true is const values -1 ad false is const value - 0
//     - wchar_t : wide char -- 2 or 4 bytes depnding on machin in linux its 4 bte and on windows ts 2

        // char is ASCII (-128 to +128) English leter, digit
        // only usefull for english language

        // its designed for unicode support - bigger range(2 bytes 65536 chars like eg emoji has also that 65536 f char)
// usefull for eng and other language    
// In c all vars must be declared at teh start of the block
// In c++ yu can decale vars in between the statements
int main() {
    bool flag = true; // or false
    cout << "flag :" << flag << endl;

    wchar_t ch = 'A';
    cout << "ch :" << ch << endl;

    // const int x; // valid in c -- unintialized cont variable
    const int x = 123; // in c++ cont var must be initialized at point of initialzation this is mnandate
    cout << "x :" << x << endl;

    return 0;
}