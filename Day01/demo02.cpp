
#include <stdio.h>

//struct in C++ : 
//colection of logically related data menbberrs 
struct time
{
    // data members : variables defined inside the struct
    int hour;
    int minute;
    int second;

    //member function : function defined inside the struct
    void display()
    {
        printf("Time is %d:%d:%d\n", hour, minute, second);
    }

    void increment(){
        // increment sec, increment min, increment hour(0-23)

    }
};


int main()
{
    struct time t1={ 21, 02, 15}; // decalration and initialization of struct variable
    struct time t2; // decalration of struct variable
    struct time* p2 = &t2; // decalration of struct pointer variable
    //t2.hour = 10;
    t2.hour = 37; // hour can be greater than 23, but it is not valid time
    t2.minute = 20;
    t2.second = 40;
    t1.display();
    t2.display();
    p2->display(); // pointer variable can also be used to access the member function of struct

}