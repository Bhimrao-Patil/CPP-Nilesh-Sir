
#include <stdio.h>
#include <assert.h>

// class in C++ :
// collection of logically related data members and member functions
// class in C++ is similar to struct in C++, but class members are private by default, while struct members are public by default
// class in C++ is used to achieve data security, data abstraction and encapsulation
// class in C++ is used to achieve object oriented programming concepts like inheritance, polymorphism and encapsulation

class time
{
private:
    // data members : variables defined inside the struct
    int hour;
    int minute;
    int second;

public:
    void set_hrs(int h)
    {
        assert(h >= 0 && h <= 23); // hour should be between 0 and 23 
        hour = h;
    }
    void set_mins(int m)
    {
        assert(m >= 0 && m <= 59); // minute should be between 0 and 59 
        minute = m;
    }
    void set_secs(int s)
    {
        assert(s >= 0 && s <= 59); // second should be between 0 and 59
        second = s;
    }

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
    struct time t2; // decalration of class variable
    t2.set_hrs(30);

}