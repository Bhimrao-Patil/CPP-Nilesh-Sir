#include <iostream>

using namespace std;

int sum (int a, int b, int c, int d, int e)
{
    return a + b + c + d + e;
}

// Functions with default arguments
// if args pasased by the calling fn ten use those values
// if args not passed by the calling fn, use default values of args
// deault values is not always 0 its user choice
int add (int a, int b, int c=0, int d=0, int e=0)
{
    return a + b + c + d + e;
}

// if here we intialize default value o it will always 0
int multiply (int a, int b, int c=1, int d=1, int e=1)
{
    return a * b * c * d * e;
}

// can it be possible if we default value to b=1 and not to c , no that is not  allowed
// basic rule is all default values must be always at end 
// we can have all default values that is possible but not in between
// default args must be right most args
// we can also have all args as deafult args

void print_info(char *name, int age, const char* addr = "unknown")
{
    // why const char <please add about i thins ro data sec>
    cout << "name" << name << endl;
    cout << "age" << name << endl;
    cout << "addrr" << name << endl;
}

// if we have writing declaration and defination of fun seprately
// tehen default argument value should be written indeclarion
// and write declation on top  and defination on his top <please add about it corectly>
void print_details(char *name, int age, const char* addr = "unknown");
int main()
{
    cout << "Sum 2 nums : " << sum(10, 20, 0, 0, 0) << endl;
    cout << "Sum 3 nums : " << sum(10, 20, 30, 0, 0) << endl;

    int result = add(10, 20);
    cout << "result :" << result << endl;

    result = add(10, 20, 30);
    cout << "result :" << result << endl;

    result = add(10, 20, 20, 40);
    cout << "result :" << result << endl;

    result = multiply(1, 2, 3, 4);
    cout << "result : " << multiply << endl;

    print_info("Superman", 768, "Crpton");
    print_info("James bond", 65);

    
}