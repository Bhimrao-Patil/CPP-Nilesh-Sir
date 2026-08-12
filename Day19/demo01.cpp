/*
Exception:
- if error/problem situation occure, we mayhave following options to handle it:
   . Ignore problem if not important
   . Abort program if problem is critical
// see sirs notes for more details
*/

#include <iostream>
using namespace std;

void print_file(const char* path) {
    // if path is invalid, throw int (indicating error)
    // if path is directory, throw double (indicating error)
    // if file doesn't have appropriate permissions, throw "string" (indicating error)
    // open file
    // read contents
    // display contents
    // close file
    // read/display may have some unexpected error
}
int main() {
    try {
        print_file("D:/test");
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

            