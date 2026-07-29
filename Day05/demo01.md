# Demo01: Constructor, Destructor, Default Arguments, and Dynamic Memory in C++

## 1. Program objective

This program teaches an important Object-Oriented Programming concept in C++:

- how to create a class
- how to define a constructor
- how to define a destructor
- how to use default arguments in constructors
- how to allocate memory dynamically using `new` and `delete`
- how objects are stored in memory

The file [demo01.cpp](demo01.cpp) demonstrates both static and dynamic object creation.

---

## 2. What this code is doing in simple words

The program creates a class named `dist` that represents a distance value with two parts:

- `feet`
- `inches`

Whenever an object of this class is created, the constructor runs automatically and initializes the values.

When the object is destroyed, the destructor runs automatically and performs cleanup work.

This is a very common pattern in C++ programming and is asked frequently in interviews.

---

## 3. Code overview

```cpp
#include <iostream>

using namespace std;

class dist {
private:
    int feet, inches;
public:
    dist(int f = 0, int i = 0) // default args
    {
        this->feet = f;
        this->inches = i;
        cout << "dist() called" << endl;
    }

    ~dist()
    {
        cout << "~dist() called" << endl;
    }

    void display()
    {
        cout << "distance : " << feet << "\" " << inches << " " << endl;
    }
};
```

### Explanation

- `feet` and `inches` are private data members.
- The constructor `dist(int f = 0, int i = 0)` initializes them.
- The destructor `~dist()` is called automatically when the object is removed from memory.
- `display()` prints the stored distance.

---

## 4. Important concepts used in this program

### 4.1 Class

A class is a blueprint for creating objects.

It groups together:

- data members (variables)
- member functions (methods)

In this program, `dist` is the class.

### 4.2 Object

An object is an instance of a class.

For example:

```cpp
dist d1(5, 8);
```

Here, `d1` is an object of class `dist`.

### 4.3 Constructor

A constructor is a special member function that is automatically called when an object is created.

Its job is to initialize the object.

In this code:

```cpp
dist(int f = 0, int i = 0)
```

is the constructor.

#### Why is it important?

- It initializes values.
- It ensures the object starts in a valid state.
- It is called automatically.

### 4.4 Destructor

A destructor is a special member function that is automatically called when an object is destroyed.

Its job is to release resources, if needed.

In this code:

```cpp
~dist()
```

is the destructor.

#### Why is it important?

- It cleans up resources.
- It is called automatically when the object goes out of scope or is deleted.

### 4.5 Default arguments

The constructor uses default values:

```cpp
dist(int f = 0, int i = 0)
```

This means:

- if the user passes no values, the object gets `0` and `0`
- if the user passes one value, the second one still defaults to `0`
- if the user passes both, those values are used

#### Example

```cpp
dist d1;        // feet = 0, inches = 0
dist d2(5);    // feet = 5, inches = 0
dist d3(5, 8); // feet = 5, inches = 8
```

### 4.6 `this` pointer

The line:

```cpp
this->feet = f;
this->inches = i;
```

uses the `this` pointer.

`this` points to the current object.

It is useful when the parameter name and data member name are the same.

For example, if we had parameter names `feet` and `inches`, then `this->feet` helps distinguish between the member and the parameter.

---

## 5. Explanation of the `main()` function

```cpp
int main() 
{
    dist d1(5, 8);
    d1.display();

    dist* p2 = new dist();
    p2->display();
    delete p2;

    dist* p3 = new dist(4, 9);
    p3->display();
    delete p3;

    dist* ptr = new dist[3];
    for(int i=0; i < 3; i++)
        ptr[i].display();

    delete[] ptr;

    return 0;
}
```

---

## 6. Step-by-step explanation

### Step 1: Static object creation

```cpp
dist d1(5, 8);
```

This creates an object `d1` in the stack memory.

- constructor runs immediately
- values are initialized as `feet = 5`, `inches = 8`
- `display()` prints the distance

#### Interview point

This is an example of static memory allocation.

### Step 2: Dynamic object creation with `new`

```cpp
dist* p2 = new dist();
```

This creates an object dynamically in the heap memory.

- `new` allocates memory at runtime
- constructor runs
- pointer `p2` stores the address of that object

Because the object is created using `new`, it must be deleted manually using `delete`.

### Step 3: Deleting a dynamically created object

```cpp
delete p2;
```

This destroys the object pointed by `p2`.

- destructor runs
- memory is released

### Step 4: Another dynamic object with parameterized constructor

```cpp
dist* p3 = new dist(4, 9);
```

This creates another object in heap memory using the constructor with values `4` and `9`.

### Step 5: Creating an array of objects dynamically

```cpp
dist* ptr = new dist[3];
```

This line creates an array of 3 objects of type `dist` in the heap memory.

This is very important:

- `new dist[3]` means: create 3 separate objects of class `dist`
- each object needs its own constructor call
- the constructor is called automatically for every object in the array
- because the constructor has default arguments, each object is initialized with the default values `0` and `0`

So in this line:

```cpp
dist* ptr = new dist[3];
```

the constructor `dist(int f = 0, int i = 0)` will be called 3 times.

#### Why 3 times?

Because the expression `new dist[3]` means:

- create object 1
- create object 2
- create object 3

Each one is created using the constructor.

#### What happens internally?

The compiler creates memory for 3 objects one after another:

```text
+------------------+   +------------------+   +------------------+
| object 0         |   | object 1         |   | object 2         |
| feet = 0        |   | feet = 0        |   | feet = 0        |
| inches = 0      |   | inches = 0      |   | inches = 0      |
+------------------+   +------------------+   +------------------+
```

And `ptr` stores the address of the first object.

So `ptr` is not the object itself. It is only a pointer to the first element of the array.

### Step 6: Accessing array elements

```cpp
for(int i=0; i < 3; i++)
    ptr[i].display();
```

Here, `ptr[i]` means the `i`th object in the array.

This is an important point for interviews:

- `ptr` is a pointer variable of type `dist*`
- `ptr` points to the beginning of an array of `dist` objects
- `ptr[i]` means “go to the object at index `i`”
- `ptr[i]` gives us an actual object, not a pointer to that object

So we use the dot operator `.` because the result of `ptr[i]` is an object.

#### Visual idea

```text
ptr points to the first object in memory

memory layout of 3 objects:

+----------------+   +----------------+   +----------------+
| object 0 (dist)|   | object 1 (dist)|   | object 2 (dist)|
+----------------+   +----------------+   +----------------+
^                                              
|                                              
ptr                                            
```

Now:

- `ptr[0]` = first object
- `ptr[1]` = second object
- `ptr[2]` = third object

So `ptr[1].display()` means: “take the second object and call its `display()` function.”

#### Why not `ptr->display()` here?

Because `ptr->display()` means:

- take the object pointed by `ptr`
- access its member using the arrow operator `->`

That works only for the first object, because `ptr` points to the first object.

So:

- `ptr[i].display()` works because `ptr[i]` is an object
- `ptr->display()` works for the first object only, because `ptr` is a pointer
- `ptr[i]->display()` would be incorrect here, because `ptr[i]` is not a pointer

#### Very short memory rule

- Use `.` when you have an object
- Use `->` when you have a pointer to an object

That is why `ptr[i].display()` is correct here.

---

## 7. Stack vs Heap memory

This program is a great example of understanding memory allocation.

### Stack memory

Used for:

- local variables
- normal objects like `d1`

Advantages:

- faster
- automatically managed

### Heap memory

Used for:

- objects created with `new`
- dynamic memory allocation

Advantages:

- flexible
- can be allocated at runtime

Disadvantages:

- must be manually deleted
- can cause memory leaks if not deleted

---

## 8. Memory diagram

Here is a simple diagram of how memory is organized:

```text
Stack Memory
-------------------------------------------------
| d1 object                                      |
| feet = 5, inches = 8                           |
-------------------------------------------------

Heap Memory
-------------------------------------------------
| p2 -> object (created by new dist())          |
| feet = 0, inches = 0                          |
-------------------------------------------------
| p3 -> object (created by new dist(4, 9))      |
| feet = 4, inches = 9                          |
-------------------------------------------------
| ptr -> array of 3 dist objects                |
| obj[0] = (0,0)                                 |
| obj[1] = (0,0)                                 |
| obj[2] = (0,0)                                 |
-------------------------------------------------
```

### After `delete p2;`

```text
Heap Memory
-------------------------------------------------
| p2 points to freed memory                     |
| object destroyed, destructor executed         |
-------------------------------------------------
```

### After `delete[] ptr;`

```text
Heap Memory
-------------------------------------------------
| array of objects destroyed                    |
| destructor called for each object            |
-------------------------------------------------
```

---

## 9. Interview-style explanation

### Q1. What is a constructor?

A constructor is a special member function that is automatically called when an object is created. Its job is to initialize the object.

### Q2. What is a destructor?

A destructor is a special member function that is called when an object is destroyed. It is used for cleanup and releasing resources.

### Q3. What is the difference between `new` and `delete`?

- `new` allocates memory dynamically in the heap.
- `delete` frees that memory and calls the destructor.

### Q4. Why do we use `delete[]` for an array of objects?

Because `new[]` allocates memory for multiple objects. To free all of them correctly, we must use `delete[]`.

### Q5. What is the difference between stack and heap memory?

- Stack memory is used for local and normal objects and is automatically managed.
- Heap memory is used for dynamic memory and must be managed manually.

### Q6. Why is `this->feet = f;` used?

Because it clearly shows that `feet` belongs to the current object and helps avoid confusion when parameter names are same as member names.

### Q7. What is the role of default arguments in this program?

Default arguments allow the constructor to be called with fewer arguments. If values are not passed, the constructor uses the default values `0` and `0`.

---

## 10. Memory leak and why it matters

A memory leak happens when memory is allocated using `new` but is never released using `delete` or `delete[]`.

In this program, if we forget to write:

```cpp
delete p2;
delete p3;
delete[] ptr;
```

then the allocated memory will remain unused in the heap.

### Why is this a problem?

- the program uses more memory than necessary
- memory keeps growing over time
- the program may become slow or crash in larger applications

### Simple example

```cpp
int main() {
    int* p = new int(10);  // memory allocated
    // forgot to delete p
    return 0;
}
```

Here, the memory allocated for `p` is leaked.

### Important note about size shown by Valgrind

When Valgrind runs your program, it may show memory usage in its own log output that is different from the simple size you expected from the class definition.

In your case, the class `dist` has two integer members:

```cpp
int feet, inches;
```

So from the class design, you may expect the object size to be around 8 bytes, and for 3 objects you may think about 24 bytes.

But Valgrind's log can show a larger number because it reports memory as seen by the runtime allocator and the debugger tool itself.

This can happen because Valgrind also tracks:

- allocator metadata
- alignment padding
- internal bookkeeping structures
- additional runtime overhead for memory management

So if you see something like 24 bytes in your understanding but 32 bytes in Valgrind's output, it does not always mean your code is wrong.

It usually means:

- the logical object size is one thing
- the memory footprint seen by Valgrind during execution is another thing
- Valgrind is reporting the full memory activity and overhead, not only the raw data size

### Interview explanation

When you are asked about this in an interview, say:

> Valgrind shows the memory footprint as observed during execution, which may include allocator overhead and bookkeeping. So the number in Valgrind logs can be larger than the simple size of the class members.

This is why you should not compare the raw class size directly with the exact number shown in Valgrind logs without understanding the tool's reporting details.

---

## 11. What is Valgrind?

Valgrind is a powerful debugging and profiling tool used mainly on Linux systems.

It helps detect:

- memory leaks
- invalid memory access
- use of uninitialized memory
- improper deletion of memory

### Why is Valgrind useful?

Valgrind helps a programmer find memory-related bugs that are often hard to notice during normal execution.

It is especially useful when working with:

- `new` and `delete`
- dynamic arrays
- object allocation in classes
- large C++ programs

### In simple words

If your program has a memory leak, Valgrind tells you:

- where memory was allocated
- whether it was freed or not
- how much memory was lost

---

## 12. Double delete and null pointer best practice

If you call `delete` on the same pointer more than once, the program may behave unexpectedly.

### Example

```cpp
int* p = new int(10);
delete p;
delete p;   // dangerous
```

The first `delete` frees the memory.

The second `delete` tries to free the same memory again.

This can cause undefined behavior, crashes, or memory corruption.

### Best practice

After deleting a pointer, assign it to `nullptr`:

```cpp
int* p = new int(10);
delete p;
p = nullptr;
```

### Why is this useful?

- prevents accidental double deletion
- makes the pointer safe to check later
- avoids using a dangling pointer

### Interview answer

> After deleting a pointer, set it to `nullptr` so that it does not point to invalid memory anymore and we avoid accidentally deleting it again.

---

## 13. Difference between `nullptr` and `NULL`

Both `nullptr` and `NULL` are used to represent a null pointer, but they are not the same in modern C++.

### `NULL`

- `NULL` is a macro defined in C header files
- it is usually defined as `0` or `(void*)0`
- it is not type-safe

Example:

```cpp
int* p = NULL;
```

### `nullptr`

- `nullptr` is a keyword introduced in C++11
- it is a dedicated null pointer literal
- it is type-safe and recommended in modern C++

Example:

```cpp
int* p = nullptr;
```

### Key difference

- `NULL` is old-style and less safe
- `nullptr` is the preferred modern choice

### Interview point

Use `nullptr` in C++ because it clearly means “this pointer has no valid address” and avoids confusion with integer `0`.

---

## 14. `malloc` vs `new` and why `malloc` is not used in C++

In C++, `malloc()` and `free()` are from the C language memory management functions.

They are not the preferred way to allocate memory in C++ because they do not call constructors and destructors.

### Example

```cpp
dist* p4 = (dist*)malloc(sizeof(dist));
cout << "p4 allocated using malloc()" << endl;
p4->display();
free(p4);
```

### What happens here?

- `malloc()` allocates raw memory only
- it does not call the constructor of `dist`
- the object inside that memory is not properly initialized
- `free()` releases the memory, but it does not call the destructor

So this is unsafe and incorrect for objects with constructors and destructors.

### Why `new` is better

```cpp
dist* p5 = new dist();
p5->display();
delete p5;
```

`new`:

- allocates memory
- calls the constructor
- creates a proper object

`delete`:

- calls the destructor
- frees the memory

### Difference between `malloc` and `new`

| Feature | `malloc()` | `new` |
| --- | --- | --- |
| Comes from | C | C++ |
| Allocates raw memory | Yes | Yes |
| Calls constructor | No | Yes |
| Calls destructor | No | Yes |
| Used for built-in types | Yes | Yes |
| Used for objects | Not recommended | Recommended |
| Pair with `free()` | Yes | No, use `delete` |

### Interview point

> In C++, never use `malloc()` and `free()` for objects. Always use `new` and `delete` because `new`/`delete` handle constructors and destructors properly.

### Extra important points about `new` and `delete`

#### 1. No type casting is needed with `new`

In C, you often write:

```c
int* p = (int*)malloc(sizeof(int));
```

But in C++ you do not need to cast the result of `new`:

```cpp
int* p = new int;
```

This is cleaner and safer.

#### 2. Deallocate with `delete`, not `free()`

For memory allocated with `new`, always use `delete`:

```cpp
int* p = new int;
delete p;
```

For arrays, use `delete[]`:

```cpp
int* arr = new int[5];
delete[] arr;
```

#### 3. On failure, `new` throws `std::bad_alloc`

If memory allocation fails, `new` throws an exception of type `std::bad_alloc`.

Example:

```cpp
try {
    int* p = new int[100000000000000];
} catch (std::bad_alloc& e) {
    cout << "Memory allocation failed: " << e.what() << endl;
}
```

This is different from `malloc()`, which usually returns `nullptr` on failure.

### Interview answer

> `new` does not require a cast, it must be paired with `delete` or `delete[]`, and on failure it throws `std::bad_alloc` rather than returning `NULL`.

---

## 15. How to use Valgrind on Linux

### Step 1: Compile the program with debug information

```bash
g++ -g demo01.cpp -o demo01
```

The `-g` flag is important because it adds debugging information.

### Step 2: Run the program with Valgrind

```bash
valgrind ./demo01
```

### Step 3: Check the output

If there is any memory leak, Valgrind will show details like:

- `definitely lost`
- `possibly lost`
- `still reachable`

### Example command

```bash
valgrind --leak-check=full ./demo01
```

This gives more detailed information about memory leaks.

### Interview point

Valgrind is used to check whether the program is managing memory correctly.

It is very helpful in C++ because manual memory management can lead to leaks and dangling pointers.

---

## 16. Valgrind installation on different operating systems

### Linux

On Ubuntu or Debian-based systems:

```bash
sudo apt update
sudo apt install valgrind
```

On Fedora:

```bash
sudo dnf install valgrind
```

On Arch Linux:

```bash
sudo pacman -S valgrind
```

### Windows

Valgrind is not officially supported on Windows in the same way as Linux.

Common alternatives are:

- Dr. Memory
- Visual Studio Debugger
- AddressSanitizer (with clang or gcc on Windows)

If you are using Windows and want a similar memory-checking tool, Microsoft Visual Studio's debugger is a good option.

### macOS

Valgrind is not commonly used on modern macOS systems because it may have limited support.

You can install it using Homebrew if available:

```bash
brew install valgrind
```

However, on newer macOS versions, some users may face compatibility issues.

For macOS, alternatives include:

- Xcode Instruments
- AddressSanitizer
- clang's memory sanitizers

### Important note

For learning and interviews, Linux is the most common environment for Valgrind because it is widely used and well-supported.

---

## 17. Important points to remember

- Constructor initializes an object.
- Destructor destroys an object and cleans up resources.
- `new` creates objects dynamically in heap memory.
- `delete` removes a single dynamically created object.
- `delete[]` removes an array of dynamically created objects.
- Objects created on the stack are automatically destroyed when they go out of scope.
- Objects created with `new` need manual deletion.
- Forgetting to delete allocated memory causes a memory leak.
- Valgrind helps detect memory leaks and other memory errors in C++ programs.

---

## 11. Short summary

This program demonstrates:

- class and object creation
- constructor and destructor behavior
- default arguments
- dynamic allocation using `new`
- memory release using `delete`
- creation and access of an array of objects

It is an excellent example for understanding object-oriented programming and memory management in C++.
