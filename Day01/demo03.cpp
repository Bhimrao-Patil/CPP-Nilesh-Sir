
#include <stdio.h>

//struct in C++ : 
//colection of logically related data menbberrs 
// struct in C++ is similar to class in C++, but struct members are public by default, while class members are private by defaultz
struct time
{
private:
    // data members : variables defined inside the struct
    int hour;
    int minute;
    int second;

public:
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
    // data security : hour, minute and second are private members of struct time, so they cannot be accessed directly outside the struct
    // so we cannot access them directly outside the struct, we can access them using member function of struct
    // its secure way to access the data members of struct, because we can control the access to the data members using member function of struct
    // so data security is achieved by making the data members private and providing public member functions to access them
    // so in below line we are getting error because hour, minute and second are private members of struct time, so they cannot be accessed directly outside the struct
    // our data menmbers can not wrongly utilized by the user of struct, so we can control the access to the data members using member function of struct

    t2.hour = 37; // hour can be greater than 23, but it is not valid time
    t2.minute = 20; // minute can be greater than 59, but it is not valid time
    t2.second = 40; // second can be greater than 59, but it is not valid time
    t1.display();// display() function can be called using struct variable
    t2.display();// display() function can be called using struct variable
    p2->display(); // pointer variable can also be used to access the member function of struct

}