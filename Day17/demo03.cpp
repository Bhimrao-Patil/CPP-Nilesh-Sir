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
/*
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
*/

/*
int main() {
    using namespace treespace; // this will access all members of treespace namespace
    
    tree t1; // this creates object of tree class from treespace::tree
    node n1; // this creates object of node class from treespace::node
    display(); // this will call display function from treespace::display()
    cout << "counter: " << counter << endl;

    using namespace litspace; // this will access all members of litspace namespace
    list l1; // this creates object of list class from litspace::list
    //node n2; // this gives error because node class is already defined in treespace namespace, so we need to use scope resolution operator to access node class from litspace namespace
    // for compiler it is ambigious which node class to use, so we need to use scope resolution operator to access node class from litspace namespace
    // because it is available in both namespace, so we need to use scope resolution operator to access node class from litspace namespace
    litspace::node n3; // this creates object of node class from litspace::

    litspace::display(); // to remove abmiguity using scope resolution is mandotory
    cout << "counter: " << litspace::counter << endl; 

    // so we have choice which we want to select
    // using namespace -> advantage is direct access, less code typing -> sometimes makes code cleaner to read
    // using namespace -> disadvantage is ambiguty, if same name is there in both namespace, so we need to use scope resolution operator to access members of namespace 
    // common practice -> is to use :: for every access e.g. listspace::list , treespace::node
    
    // standard namespace --- "std" --> containes all predifined ns/classess/objects
    // std::cout << "hello , world" << std::endl;

    return 0;
}
*/
//namespace may written spilited in multiple parts in same flile or acorss multiple files
// compiler will consider all parts of namespace as one namespace

// may be in file1.cpp
namespace myspace {
    int count = 30;
}

// may be in file2.cpp
namespace myspace {
    void display() {
        cout << "myspace::count: " << myspace::count << endl;
    }
}

int main() {
    myspace::display();
    return 0;
}

/*
namespace is a logical container :
 - does not occupy any memory at runtime
 - no memory consumed by namespace {...} or using namespace
 - namespace member access is solely manages by the compiler at compile time
*/
