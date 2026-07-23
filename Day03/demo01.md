# Demo01 C++ Notes

## What is a class in C++?

A class is a user-defined data type that has data members and member functions.

It is a building block that binds data members and member functions together.

A class has:

- variable members (data members)
- function members (member functions)

## Access control and data security

By default, class members are private, but we can make them public or protected using access specifiers.

Since the members are private, they cannot be accessed directly from outside the class. We can access them using public member functions such as getters and setters.

This improves data security because private data is protected inside the class.

It also helps us write clean, organized, and secure code.

## Class as a blueprint for objects

If we build a house, we need a blueprint. Similarly, we need a class to create objects.

A class is a blueprint for creating objects.

It is a way to encapsulate data and functions together.

It is also a way to achieve data abstraction and encapsulation.

## What is an object in C++?

An object is an instance of a class.

It is a real-world entity that has state and behavior.

It is created from a class and has its own copy of data members.

It can access the member functions of the class.

An object can also store data, send data, receive messages, and communicate with other objects.

## Object composition

An object has:

- data members for its state
- member functions for its behavior
- a unique address for its identity

## State of an object

The state of an object is the value of its data members at a given time.

It is the current condition of the object.

It can change over time.

Real-life example: a car can have a state such as speed = 60 and fuel = 20.

## Behavior of an object

The behavior of an object is the actions it can perform.

It is represented by the member functions of the class.

Real-life example: a car can accelerate, brake, or turn.

## Identity of an object

The identity of an object is its unique address in memory.

Even if two objects have the same values, they are still different objects because they have different identities.

Real-life example: two people can have the same name, but they are still different persons.

## Example of a class and object

```cpp
class Student {
private:
    int rollNo;

public:
    void setRollNo(int r) {
        rollNo = r;
    }

    int getRollNo() {
        return rollNo;
    }
};

int main() {
    Student s1;      // object of class Student
    s1.setRollNo(101);
    return 0;
}
```

Here, `s1` is an object of the class `Student`.

## Getter and setter concept

Getter and setter functions are used to access and update private data safely.

### Setter
A setter is a public member function that assigns a value to a private data member.

Example:

```cpp
void setRollNo(int r) {
    rollNo = r;
}
```

### Getter
A getter is a public member function that returns the value of a private data member.

Example:

```cpp
int getRollNo() {
    return rollNo;
}
```

### Why are getters and setters used?

- They protect private data from direct access.
- They allow controlled modification of data.
- They help keep the class safe and organized.
- They make it easier to validate values before storing them.

### Real-life example

Think of a bank account:

- The balance is private.
- A setter can be used to deposit or withdraw money.
- A getter can be used to check the current balance.
- This prevents unauthorized direct changes.

## Empty class

An empty class is a class that has no data members and no member functions.

Example:

```cpp
class Empty {
};
```

In C++, writing an empty class is allowed. Even if the class is empty, it must have a size of at least 1 byte because every object in C++ must have a unique address in memory.

### Important points

- It contains no data members.
- It contains no member functions.
- It is still a valid class.
- It can be used as a marker or placeholder.
- The size of an empty class in C++ is 1 byte.
- This is because every object must have a unique address.

## Final summary

- A class is a user-defined data type that contains data members and member functions.
- It binds data and behavior together.
- It helps in encapsulation and data abstraction.
- Private data is protected for better data security.
- A class acts as a blueprint for creating objects.
- An object is an instance of a class and a real-world entity with state and behavior.
- An object has state, behavior, and identity.
- Objects can store data, send data, receive messages, and communicate with other objects.
- The value stored in data members is called the state of the object.
- Behavior is how an object acts or reacts when its state changes or a function is called.
- In object-oriented programming, data security is handled by keeping data members private and member functions public.
- Getter and setter functions are used to access and update private data safely.
- An empty class is valid in C++ and has a size of 1 byte because every object needs a unique address in memory.

## Input and output in C++

In C++, console input and output are done using the iostream library.

The library provides stream classes for handling input and output.

## Namespaces and using namespace std

C++ headers do not have a `.h` extension.

C++ organizes classes, methods, objects, and variables into logical containers called namespaces.

All standard library classes, functions, and objects are placed in the `std` namespace.

Example:

```cpp
using namespace std;
```

This line tells the compiler that we want to use the names from the `std` namespace directly.

### Why is this used?

- It makes standard library names easier to use.
- It avoids writing `std::` before every standard object or function.
- It is commonly used in beginner programs.

### Real-life analogy

Think of a company with different departments:

- Developer department
- Tester department
- Each department has its own manager

In the same way, C++ uses namespaces to group related things together.

- The developer team can have its own names.
- The testing team can have its own names.
- The compiler can separate them properly.

So, a namespace is like a department or a separate room where related items are kept together.

### Important note

Using `using namespace std;` is simple, but in larger programs it can sometimes cause naming conflicts. In such cases, writing `std::cout` and `std::cin` explicitly is better.

- `std::ostream` is the output stream class used for printing data.
- `std::istream` is the input stream class used for reading data.
- `std::cout` is an object of `std::ostream` and is used for output to the console.
- `std::cin` is an object of `std::istream` and is used for input from the keyboard.
- `std::endl` inserts a newline character and flushes the output buffer.
- `std::cerr` is used for error output to the console.
- `std::clog` is used for logging output.
- `std::flush` is used to flush the output buffer immediately.

### Important points

- `iostream` provides classes and functions for console input/output.
- `std::cin` reads data from the standard input stream.
- `std::cout` writes data to the standard output stream.
- `std::cerr` is meant for error messages.
- `std::clog` is used for log messages.
- `std::endl` is similar to `\n`, but it also flushes the buffer.

Example:

```cpp
#include <iostream>

int main() {
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age >= 18) {
        std::cout << "You are an adult." << std::endl;
    } else {
        std::cerr << "You are under 18." << std::endl;
    }

    return 0;
}
```

### Explanation

The program below is the same type of example that you just ran in the C++ file:

```cpp
#include <iostream>
using namespace std;

int main() {
    int num1, num2, result;

    cout << "Enter two numbers :";
    cin >> num1;
    cin >> num2;

    result = num1 + num2;
    cout << "results: " << result << endl;

    return 0;
}
```

### What this program does

- It takes two numbers from the user.
- It adds them.
- It prints the result on the screen.

If someone is more comfortable with `printf` and `scanf`, that is also fine in C++. They are still valid for basic input and output.

### Why we use `cin` and `cout`

- `cin` is used to take input from the user.
- `cout` is used to display output on the screen.
- They are part of the C++ iostream library.
- They are easier and more modern to use than `printf` and `scanf` for many beginner programs.

### How `cout` works

`cout` is used to send output to the console, but it does not always write directly to the screen immediately.

Instead, it usually sends the data to an output buffer first. A buffer is a temporary memory area where data is stored before it is finally transferred to the destination.

### Step-by-step idea

1. You write a statement such as `cout << "Hello";`
2. The text `Hello` is placed into the output buffer.
3. The program does not immediately force the screen to show it.
4. Later, when the buffer is full or when the program flushes it, the data is sent to the console.

### Why this is useful

Using a buffer makes input and output faster and more efficient.

- It reduces the number of direct writes to the screen.
- It groups several output operations together.
- It improves performance in many programs.

### Simple real-life example

Think of a teacher writing marks on a board.

Instead of writing each mark one by one immediately, the teacher may first collect a few marks on a small notepad and then write them all together on the board.

That is similar to how a buffer works.

### Important point

The buffer is temporary memory, not the final display itself.

So, `cout` is not just "printing directly" in the same moment. It is first storing data in a buffer, and then that buffer is sent to the console.

### Buffering summary

Yes, this is a good beginner-level idea, but the more accurate explanation is this:

- `std::cin` is usually buffered input.
- `std::cout` is usually buffered output.
- `std::cerr` is normally unbuffered or line-buffered, so error messages appear quickly.
- `std::clog` is usually buffered, so it is used for logs.

### About `\n`, `printf`, Python, and Java

A newline such as `\n` often makes output appear sooner because many terminals use line-buffering.

But the main idea is this:

- If we write `\n`, the output is often shown sooner.
- If we do not write `\n`, the data may stay in the buffer for some time.
- When the buffer becomes full, or when the program ends, or when we flush it, the data goes to the console.

So in simple words:

- `\n` is helpful because it can make the output appear earlier.
- If we do not use `\n`, the output may still appear later when the buffer is full or flushed.

### In different languages

- In C/C++, `std::endl` or `std::flush` can be used.
- In Python, `print(..., flush=True)` forces immediate output.
- In Java, `System.out.flush()` can be used.

### `<<` and `>>` in input and output

In C++, when we use `<<` and `>>` with streams, they are called insertion and extraction operators.

- `<<` is the insertion operator.
- `>>` is the extraction operator.
- `cout << value;` inserts data into the output stream.
- `cin >> value;` extracts data from the input stream.

Example:

```cpp
int age;
cout << "Enter your age: ";
cin >> age;
cout << "Your age is " << age;
```

### Extra note

The same symbols are also used as shift operators when working with integer values.

- `a << b` means left shift.
- `a >> b` means right shift.

Example:

```cpp
int a = 8;
int b = a << 1; // 8 becomes 16
int c = a >> 1; // 8 becomes 4
```

### Important point

The meaning of `<<` and `>>` depends on the context.

- With `cin` and `cout`, they are used for insertion and extraction.
- With integers, they are used as shift operators.

## Real-life example

Think of a car:

- Class = car design or blueprint
- Object = a real car created from that design
- State = current speed, fuel, and engine status
- Behavior = start, stop, accelerate, brake
- Identity = each car is a different physical object
