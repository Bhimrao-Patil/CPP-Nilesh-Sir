#include <iostream>
using namespace std;

/*
void print_file(const char* path, int arg) {
    // if path is invalid, throw int (indicating error)
    if (arg == 1) throw -1;
    // if path is directory, throw double (indicating error)
    if (arg == 2) throw -3.14;
    // if file doesn't have appropriate permissions, throw "string" (indicating error)
    if (arg == 3) throw "error";
    // open file
    // read contents
    // display contents
    // close file
    // read/display may have some unexpected error
    if (arg > 5) {
        exception ex;
        throw ex;
    }
}

int main() {
    try {
        print_file("D:/test", 7);// change the argument to 1, 2, 3, 4, 5, 6, 7 and see the output
        cout << "okay" << endl;
    }
    catch (int x) {
        cout << "invalid path" << endl;
    }
    catch (double y) {
        cout << "path is of directory" << endl;
    }
    catch (const char* z) {
        cout << "file perm error: " << z << endl;
    }
    catch (...) {
       cout << "some error occurred" << endl;
    }
    return 0;
}
/*

/* but sometimes what happen main is written by developer 1 and fun is written by developer 2 and developer 2 is not aware of the exception types that main is handling. So, in such cases, we can use throw(...) in function declaration to indicate that this function can throw any type of exception. This way, developer 1 can handle any type of exception thrown by developer 2's function. */

// pata hi kounsa exception throw hoga isliye function declaration me throw(...) likha hai.
// in older c++ we can use throw(...) in function declaration to indicate that this function can throw any type of exception. This way, developer 1 can handle any type of exception thrown by developer 2's function. But in C++11 and later, this is deprecated and we should not use it. Instead, we can use noexcept specifier to indicate that a function does not throw any exceptions. If a function is declared as noexcept, the compiler will generate an error if the function throws an exception. This way, we can ensure that the function does not throw any exceptions and we can handle any exceptions thrown by other functions in our code.
void print_file(const char* path, int arg) throw(int, double, const char*) {
    // if path is invalid, throw int (indicating error)
    if (arg == 1) throw -1;
    // if path is directory, throw double (indicating error)
    if (arg == 2) throw -3.14;
    // if file doesn't have appropriate permissions, throw "string" (indicating error)
    if (arg == 3) throw "error";
    // open file
    // read contents
    // display contents
    // close file
    // read/display may have some unexpected error
    if (arg > 5) {
        exception ex;
        throw ex;
    }
}
// if we pass 7 then becaause in our code throws unexpected exception which is not handled in main so it will terminate the program and display terminate called after throwing an instance of 'std::exception' what(): std::exception Aborted (core dumped) in linux. In windows it will display unhandled exception has occurred in your application. If you click on continue then it will terminate the program. If you click on debug then it will open visual studio and show you the line where exception is thrown. If you click on close then it will terminate the program.
// see notes terminate() and exception handling in C++ for more details.
int main() {
    try {
        print_file("D:/test", 7);// change the argument to 1, 2, 3, 4, 5, 6, 7 and see the output
        cout << "okay" << endl;
    }
    catch (int x) {
        cout << "invalid path" << endl;
    }
    catch (double y) {
        cout << "path is of directory" << endl;
    }
    catch (const char* z) {
        cout << "file perm error: " << z << endl;
    }
    // catch (...) {
    //    cout << "some error occurred" << endl;
    // }
    return 0;
}


