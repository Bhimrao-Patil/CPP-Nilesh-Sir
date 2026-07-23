//what is class in c++?
//class is a user defined data type which has data members and member functions. 
// Buildinng blocks that binds data members and member functions together.
// Class has
// variable members (data members) and function members (member functions)
// By defauult class members are private, but we can make them public or protected using access specifiers.
// As its private, it cannot be accessed directly from outside the class. We can access them using public member functions (getters and setters).
//it is a blueprint for creating objects. it is a way to encapsulate data and functions together. 
//it is a way to achieve data abstraction and encapsulation.
// 
// for example if we build a house we need a blueprint to build it. similarly we need a class to create objects.
// what is object in c++?
// object is an instance of a class. it is a real world entity that has state and behavior. 
//it is created from a class. it has its own copy of data members and can access member functions of the class.
// Entity has a physical existence which can store data, send data, receive messgaes, to communcate with  other objects. it is a real world entity that has state and behavior.
// object has
    // data members (state object) and member functions (behavior of object), unique address (identtiy of object)
// what is state of object?
// state of object is the value of data members of the object at a given time. it is the current condition of the object. it can change over time. it is represented by the values of the data members of the object. it is the current condition of the object. it can change over time. it is represented by the values of the data members of the object. it is the current condition of the object. it can change over time. it is represented by the values of the data members of the object. it is the current condition of the object. it can change over time          
// what is behavior of object?
// behavior of object is the actions that the object can perform. it is represented by the member functions of the class. it is the actions that the object can perform. it is represented by the member functions of the class. it is the actions that the object can perform. it is represented by the member functions of the class. it is the actions that the object can perform. it is represented by the member functions of the class. it is the actions that the object can perform. it is represented by the member functions of the class. it is the actions that the object can perform. it is represented by the member functions of the class. it is the actions that the object can perform.
// what is identity of object?
// identity of object is the unique address of the object in memory. it is the unique address of the object in memory. it is the unique address of the object in memory. it is the unique address of the object in memory. it is the unique address of the object in memory. it is the unique address of the object in memory. it is the unique address of the object in memory     
// interview questions size of empty class in c++?
// size of empty class in c++ is 1 byte. it is because of the fact that every object in c++ must have a unique address. so even if the class is empty, it must have a size of at least 1 byte to ensure that each object has a unique address
// exaple of empty class in c++
//  In c++ writing empty class is allowed. it is a class that has no data members and no member functions
// when object is created it must have a unique address in memory. so even if the class is empty, it must have a size of at least 1 byte to ensure that each object has a unique address. so the size of empty class in c++ is 1 byte.
// So in c++ size of empty class is 1 byte. it is because of the fact that every object in c++ must have a unique address. so even if the class is empty, it must have a size of at least 1 byte to ensure that each object has a unique address. so the size of empty class in c++ is 1 byte.
// the value stored in data members of the object called state of object
// behaviour is how objects acts and reacts when its state is changed and operatiion is done
// behaviour is decided by the member function object vehaves diferretly upon the state of object
// Data security-- oop
// how do we handle it 
// we wil keep our data members private
// member functions will be public
// time class
// data: hrs, min, sec
// time t1(...);
// why getter/setters?
// getter/setters are used to access private data members of a class. they are public member functions that allow us to get and set the values of private data members. they provide a way to control access to the data members and ensure that the data is valid before it is set. they also provide a way to encapsulate the data and hide the implementation details from the user.

#include <iostream>
// In C++, console input/output  is done using objects of some classes. 
// The iostream library provides the necessary classes and functions for console input/output.
// class osteram -- output steram (printing
// class istream - inpu stream (scanning)
// The two main classes used for console input/output are std::cin and std::cout.
// std::cin is used for input from the console. it is an object of the istream class. it is used to read data from the standard input stream (keyboard).
// std::cout is used for output to the console. it is an object of the ostream class. it is used to write data to the standard output stream (console).
// std::endl is used to insert a newline character and flush the output buffer. it is equivalent to '\n' but also flushes the output buffer. it is used to ensure that the output is displayed immediately.
// std::cerr is used for error output to the console. it is an object of the ostream class. it is used to write error messages to the standard error stream (console).
// std::clog is used for logging output to the console. it is an object of the ostream class. it is used to write log messages to the standard log stream (console).
// std::flush is used to flush the output buffer. it is used to ensure that the output is displayed immediately without waiting for the buffer to fill
// C++ headers do not have .h extension
// c++ oragnisize all classess, methds, objects/variables into logicl containers called as namespaces 
// All stanadred libarray classed, functions and obects are in "std" namespaces
using namespace  std;
int main() {
    int num1, num2, result;
    cout << "Enter two numbers :";
    cin >> num1;
    cin >> num2;
    // cin >> num1 >> num2;
    result = num1 + num2;
    cout << "results: " << result << endl;
    
    char name[80];
    cout << "Enter Name";
    cin >> name; // to input full string including spaces - use seperate fn cin.getlin()
    return 0;
}