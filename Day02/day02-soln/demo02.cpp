/*
Demo02 Detailed Explanation: Classes, Access Control, and Memory Layout

A. Class and data encapsulation
   1. class time {
        private:
           int hrs, mins, secs;
        public:
           void setTime(int h, int m, int s);
           void display() const;
      };
   2. private members (hrs, mins, secs)
      - Only member functions of the class can access these directly.
      - Code outside the class cannot write or read these members.
   3. public member functions
      - setTime and display are public and can be called from main().

B. Why the original code caused a compiler error
   - In main(), the lines:
         t1.hrs = 10;
         t1.mins = 10;
         t1.secs = 10;
     try to access private members of class time.
   - C++ access control prevents this.
   - The compiler error is:
         'int time::hrs' is private within this context
   - The correct way is to use public member functions or constructors.

C. Memory allocation for objects
   1. Local objects on the stack:
      - time t1; creates t1 on the stack in main().
      - time t2; creates t2 on the stack in main().
      - Their member variables are stored inside each object.
   2. Global objects in the data segment:
      - If you write `time t1;` outside main(), it is stored in the data segment.
      - Global objects are zero-initialized by default.
   3. Heap objects with new:
      - time *tp = new time();
      - The object is allocated on the heap.

D. Initialization behavior
   - For local objects, built-in types are not automatically initialized.
   - After `time t1;`, hrs, mins, secs contain garbage until set.
   - Global objects are initialized to zero by default.

E. Runtime memory layout summary
   - Code segment (.text): compiled functions like main() and display().
   - Data segment: global/static objects and initialized data.
   - BSS segment: zero-initialized global/static objects.
   - Heap: memory allocated by new/malloc.
   - Stack: local variables and function call frames.

F. First C++ compiler: Cfront
   - The first C++ compiler implementation was Cfront.
   - Created by Bjarne Stroustrup at Bell Labs in the early 1980s.
   - Cfront translated C++ source into C source.
   - The generated C code was then compiled by an existing C compiler.
   - This made C++ practical before native C++ compilers were available.

G. Cfront vs modern C++ compilers
   - Cfront: source-to-source translator from C++ to C.
   - Modern compilers (g++, clang++, MSVC): compile C++ directly to machine code or object files.
   - Cfront depended on a separate C compiler for the final binary.
   - Modern compilers include optimizers, code generators, and linkers in one toolchain.
   - Modern compilers also support advanced C++ standards, templates, exceptions, and runtime features.

H. The implicit this pointer
   - Every non-static member function receives an implicit pointer named `this`.
   - `this` points to the object on which the member function is called.
   - For example, when `t1.display();` is called, the function effectively receives `&t1` as `this`.
   - Inside `display()`, `this->hrs`, `this->mins`, and `this->secs` refer to the current object's members.
   - `this` is only available inside member functions and is not a normal variable you declare.
   - In your current code, `display()` uses `this` implicitly to print values from the correct object.

I. Setter explanation
   - The methods `set_hrs`, `set_mins`, and `set_secs` are setter functions.
   - A setter updates a private member variable through a public interface.
   - In your code, `t1.set_hrs(10);` safely assigns a value to `hrs`.
   - The setters use `assert` to validate the values before assignment.
   - This is better than accessing private members directly from `main()`.

J. Getter explanation
   - The methods `get_hrs`, `get_mins`, and `get_secs` are getter functions.
   - A getter reads a private member variable through a public interface.
   - `get_hrs()` returns the current value of `hrs` without allowing modification.
   - Getters protect data by preventing outside code from changing private values directly.
   - In your code, `t2.get_hrs()` is used to display the stored time values.

K. Facilitator explanation
   - `display()` is a facilitator method: it helps present object data in a useful form.
   - A facilitator uses existing data and member functions without changing the object's state.
   - In your code, `display()` prints `hrs`, `mins`, and `secs` together as a formatted string.
   - Facilitators improve usability and keep the object interface simple for users.

L. Constructor and destructor explanation
   - `time()` is a default constructor that initializes `hrs`, `mins`, and `secs` to 0.
   - A constructor is a special function with the same name as the class and no return type.
   - The default constructor is called automatically when an object is created without arguments.
   - `time(int h, int m, int s)` is a parameterized constructor.
   - It allows creating an object with initial values, for example `time t4(10, 20, 30);`.
   - Constructors are useful to avoid garbage values in built-in members.
   - `~time()` is the destructor.
   - A destructor is called automatically when an object goes out of scope.
   - In this class, the destructor does not need to free resources because no dynamic memory is used.
   - The destructor is useful in general for cleanup when an object owns resources like memory, files, or network handles.

M. Explanation of the existing code
   - `time t1;` and `time t2;` create two objects on the stack.
   - `t1.set_hrs(10);`, `t1.set_mins(10);`, and `t1.set_secs(10);` initialize the object safely.
   - `time t4(10, 20, 30);` creates an object using the parameterized constructor.
   - `t1.display();` and `t2.display();` work because `display()` is public.
   - `printf("time=> %d-%d-%d\n", t2.get_hrs(), t2.get_mins(), t2.get_secs());` uses getters to read values safely.
   - This means object behavior is accessed through public methods, while private data remains protected.
*/

#include <stdio.h>
#include <assert.h>

class time {
    private:
        int hrs, mins, secs;

    public:
        // constructor - parameterless constructor- intializes the object to 00:00:00
        // constructor is a special member function that has the same name as the class and no return type
        // no explicit return type, not even void
        // automatically called by compiler when an object is created
        // if we not right it its showing us grabaje value because compiler does not provide default constructor if we write any constructor with parameters
        // if no constructor is provided, compiler provides a default constructor that does nothing (does not initialize members)
        // default construcor not provieded for intialization of built-in types, so they contain garbage values
        // means constructor is always there but if we write any constructor with parameters then compiler does not provide default constructor
        // its better to provide constructor for intialization of built-in types to avoid garbage values

        time() 
        {
            this->hrs = 0;
            this->mins = 0;
            this->secs = 0;
        } // default constructor initializes to 00:00:00
        // parameterized constructor
        // parameterized constructor is a constructor that takes parameters and initializes the object with the given values
        // constructor machine level code is kept in a seperate section of the code segment called the ctor section, and it is called by the compiler when an object is created

        time(int h, int m, int s) 
        {
            assert(h >= 0 && h < 24); // validate hours
            assert(m >= 0 && m < 60); // validate minutes
            assert(s >= 0 && s < 60); // validate seconds
            this->hrs = h;
            this->mins = m;
            this->secs = s;
        } // parameterized constructor initializes to given values

        // destructor is compliement of constructor, it is a special member function that has the same name as the class and preceded by a tilde (~) and no return type
        // destructor is automatically called by compiler when an object goes out of scope or is deleted
        ~time()
        {
            // destructor does not take any parameters and does not return anything
            // destructor is used to release resources acquired by the object during its lifetime
            // for very simple class -- writing destructor is not necessary, compiler provides a default destructor that does nothing
            // you can relay on compiler provided default destructor for simple classes, but for complex classes that acquire resources (like dynamic memory, file handles, etc.), you should provide a destructor to release those resources
            // in this case, since we are not acquiring any resources, the default destructor is sufficient
            printf("bye from destructor\n");
        }   

        // setters or mutators
        void set_hrs(int h) 
        { 
            assert(h >= 0 && h < 24); // validate hours
            this->hrs = h; 
        }

        void set_mins(int m) 
        { 
            assert(m >= 0 && m < 60); // validate minutes
            this->mins = m; 
        }

        void set_secs(int s) 
        { 
            assert(s >= 0 && s < 60); // validate seconds
            this->secs = s; 
        }
        // getters or inspectors
        int get_hrs() {
            return this->hrs;
        }
        int get_mins() {
            return this->mins;
        }
        int get_secs() {
            return this->secs;
        }
        // facilitators

        void display() // void displa(time *this)
        {
            printf("time is %02d:%02d:%02d\n", this->hrs, this->mins, this->secs);
        }
};

int main() {
    time t1; // local object stored on the stack
    //t1.hrs = 10; t1.mins = 10; t1.secs = 10; // compiler error: cannot access private members
    t1.set_hrs(10); t1.set_mins(10); t1.set_secs(10); // valid: using public member functions   
    time t2; // another local object stored on the stack
    ///t2.hrs = 20; t2.mins = 20; t2.secs = 20; // compiler error: cannot access private members
    t2.set_hrs(20); t2.set_mins(20); t2.set_secs(20); // valid: using public member functions
    // t1.hrs = 12 ; error: cannot access private member 
    
    t1.display(); // disaplay(&t1) is public, so this works
    t2.display(); // disaplay(&t2) is public, so this works

    // if someone want hiphan instead of colon, they can use printf("time is %02d-%02d-%02d\n", this->hrs, this->mins, this->secs);
    // but some pleople prefer colon, so we use colon in this example
    // so how can we achieve this requirement? we can use a setter function to set the separator character, and then use that character in the display function. for example, we can add a private member variable char sep; and a public setter function void set_sep(char s) { this->sep = s; } and then in the display function, we can use printf("time is %02d%c%02d%c%02d\n", this->hrs, this->sep, this->mins, this->sep, this->secs); and then in main(), we can call t1.set_sep('-'); to set the separator to hyphen.
    // add  getter for it
    printf("time=> %d-%d-%d\n", t2.get_hrs(), t2.get_mins(), t2.get_secs());
    if(t2.get_hrs() > 12)
        printf("time=> %d-%d-%d PM\n", t2.get_hrs()-12, t2.get_mins(), t2.get_secs());
    else
        printf("time=> %d-%d-%d AM\n", t2.get_hrs(), t2.get_mins(), t2.get_secs());

    time t3; // local object stored on the stack
    t3.set_hrs(15); t3.set_mins(30); t3.set_secs(45); // valid: using public member functions
    t3.display(); // disaplay(&t3) is public, so this works
    printf("time=> %d-%d-%d\n", t3.get_hrs(), t3.get_mins(), t3.get_secs());

    time t4(10, 20, 30); // local object stored on the stack, using parameterized constructor
    t4.display(); // disaplay(&t4) is public, so this works
    printf("time=> %d-%d-%d\n", t4.get_hrs(), t4.get_mins(), t4.get_secs());
    return 0;
}
