/*
We learned below till now:
C++
    - oop programming

Remaining:
    - namespace
    - Casting operators
    - Exception handling
    - Operator overloading
    - friend function
    - const & mutable keywords
    - Templates
    - STL
    - File IO
*/
/*
u r data starurere expert in your new project and ur manager conisderd you for it
class node {
};

class list {
};

----
class node {
};

class tree {
};
-------
we need to do above in one project.
individually code is working but same class name is there in both projects, so it will create problem
it will be very very complicated to manage both projects in one project
so what we need to for it i.e. logical separation of code in one project
we put this in one logical container seperatelly for each project
dirctly it will not in contact
like list space and tree space.
e.g one name soham in our building but there home is different so we can identify them by their home address
so we can use namespace to logically separate the code in one project
- namespace is a logical container for code
- namespace is a logical container for code, which is used to group related classes, functions, variables, and other identifiers together. It helps to avoid naming conflicts and provides a way to organize code
Namespace:
- logical organization of code base
- avoids naming conflicts we create an namespace
- namespace is a logical container for code, which is handled by compiler level
- which is used to group related classes, functions, variables, and other identifiers together. 
- It helps to avoid naming conflicts and provides a way to organize code
- it will contains 
    - classes
    - global functions
    - global variables
    - nested namespace

- to create namespace we use keyword namespace followed by name of namespace and then open and close curly braces
- to access the members of namespace we use scope resolution operator ::
- we can create nested namespace inside namespace

namespace litspace {
    class node {
    };

    class list {
    };
}

namespace treespace {
    class node {
    };

    class tree {
    };
}
- how to access the members of namespace we use scope resolution operator ::
- to use contains inside namespace there is basic syntax
    - namespace_name::class_name
    - namespace_name::function_name
    - namespace_name::variable_name
- eg. 
    litspace::node
    treespace::node
*/
#include <iostream>
using namespace std;

namespace litspace {
    class node {
    public:
        node() {
            cout << "node constructor" << endl;
        }  
    };

    class list {
    public:
        list() {
            cout << "list constructor" << endl;
        }
    };

    int counter = 10;
     void display() {
        cout << "litspace display function" << endl;
    }
}
namespace treespace {
    class node {
    public:
        node() {
            cout << "node constructor" << endl;
        }
    };

    class tree {
    public:
        tree() {
            cout << "tree constructor" << endl;
        }
    };

    int counter = 20;
    
    void display() {
        cout << "treespace display function" << endl;
    }
}

int main() {
    // to use each member in the nmaspace we need to use scope resolution operator ::
    // this will access members from namespace readable way
    litspace::list ll;
    litspace::node l2;


    treespace::tree tt;    
    treespace::node t2;

    cout << "list count: " << litspace::counter << endl;
    cout << "tree count: " << treespace::counter << endl;

    cout << "list display: ";
    litspace::display();
    cout << "tree display: ";
    treespace::display();
    return 0;
}