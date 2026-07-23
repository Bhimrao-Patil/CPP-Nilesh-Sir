# Demo02 C++ Notes

## What is a function in C++?

A function is a block of code that performs a specific task.

It helps us write reusable and organized programs.

In this example, the function `square(int n)` is used to calculate the square of a number.

## Program explanation

```cpp
#include <iostream>

using namespace std;

int square(int n) {
    return n * n;
}

int main() {
    int num = 7;
    int res = square(7);
    cout << "result: " << res << endl;
    return 0;
}
```

## Line-by-line explanation

### 1. `#include <iostream>`

This header file is used for input and output operations.

It allows us to use `cout` and `endl`.

### 2. `using namespace std;`

This tells the compiler to use the standard C++ library names directly.

So we can write `cout` instead of `std::cout`.

### 3. `int square(int n)`

This is a function declaration and definition.

- `int` means the function returns an integer value.
- `square` is the function name.
- `int n` is a parameter, which means the function receives a value from the caller.

### 4. `return n * n;`

This line calculates the square of the value passed in `n`.

If `n = 7`, then the function returns `49`.

### 5. `int main()`

This is the main function.

Every C++ program starts execution from `main()`.

### 6. `int num = 7;`

This creates a variable named `num` and stores the value `7` in it.

### 7. `int res = square(7);`

This line calls the `square()` function with `7` as the argument.

The function receives this value and returns `49`.

That returned value is stored in `res`.

### 8. `cout << "result: " << res << endl;`

This prints the result on the screen.

- `cout` is used for output.
- `res` contains the function result.
- `endl` moves the cursor to the next line.

### 9. `return 0;`

This means the program ended successfully.

## What happens when the function is called?

When `square(7)` is called, the following steps happen:

1. The main function is running.
2. The program calls `square(7)`.
3. A function activation record is created on the stack.
4. The argument `7` is passed to the parameter `n`.
5. The function executes its code.
6. The value `49` is returned to the caller.
7. The activation record is destroyed after the function finishes.

## Important concept: function call process

### Function activation record

When a function is called, memory is created for that function call on the stack.

This memory is called the activation record or stack frame.

It contains:

- the function parameters
- local variables
- return address
- temporary working data

## Simple real-life example

Think of a calculator.

You give it a number, and it returns the square of that number.

That is exactly what the function `square()` does.

You give it `7`, and it returns `49`.

## Output of the program

The program prints:

```cpp
result: 49
```

## Macros vs functions vs inline functions

### What is a macro?

A macro is defined using `#define`.

It is processed by the preprocessor before the actual compilation begins.

Example:

```cpp
#define SQUARE(x) x * x
```

If we use:

```cpp
int a = SQUARE(3);
```

then the preprocessor replaces it with:

```cpp
int a = 3 * 3;
```

### Why macros are used

Macros are used because they can make code shorter and sometimes faster.

They are replaced directly in the code before compilation.

### Important drawback of macros

Macros are not type-safe.

This means the compiler does not check the type properly because the macro is just a text replacement.

Example:

```cpp
#define ADD(a, b) a + b
```

If we write:

```cpp
int x = ADD(2, 3);
```

it works fine.

But if we write:

```cpp
std::string s = ADD("Hello", "World");
```

this may cause problems because the macro does not understand C++ data types.

### Problem with expression replacement

Macros do simple text replacement and do not understand operator priority properly.

Example:

```cpp
#define SQUARE(x) x * x
```

Now if we write:

```cpp
int result = SQUARE(3 + 4);
```

the macro expands to:

```cpp
int result = 3 + 4 * 3 + 4;
```

This is not the same as $(3 + 4) * (3 + 4)$.

So the result becomes incorrect.

### Why macros are considered bad in some cases

- They are not type-safe.
- They do not respect operator precedence.
- They can cause unexpected results.
- They are simple text replacement, not real C++ code.

### What is a normal function?

A normal function is written in C++ syntax and is called at runtime.

Example:

```cpp
int square(int n) {
    return n * n;
}
```

When this function is called, the compiler creates a function call and the program uses the function body.

This is safe and clear.

### Drawback of a normal function

A normal function call creates a function activation record on the stack.

This means:

- memory is used for the call
- time is needed for the function call
- the function is executed normally

So it is safe, but it may be a little slower than direct code expansion.

### What is an inline function?

An inline function is a function that the compiler may replace at the call site.

It gives the advantage of a function and the speed of a macro.

Example:

```cpp
inline int square(int n) {
    return n * n;
}
```

Now if we write:

```cpp
int x = square(5);
```

the compiler may replace it directly with:

```cpp
int x = 5 * 5;
```

### Why inline functions are useful

- They are faster than normal function calls.
- They avoid the creation and destruction of a function activation record.
- They are type-safe because the parameter types are known.
- They are safer than macros.

### Why inline functions are better than macros

- They are not blind text replacement.
- They respect data types.
- They are safer and easier to understand.
- They avoid many macro-related mistakes.

### Important note

Inline functions are not always used.

The compiler decides whether to actually inline them.

It usually does this only when the function is short and simple.

Inlining is usually not helpful when the function contains:

- `switch` statements
- `case` blocks
- nested `if-else`
- loops like `for`, `while`, or `do-while`
- large and complex logic

These kinds of functions are usually not good candidates for inlining because the compiler may prefer to keep them as normal functions for better code size and clarity.

Example of a good inline function:

```cpp
inline int add(int a, int b) {
    return a + b;
}
```

Example of a function that is usually not inlined:

```cpp
inline int bigFunction(int x) {
    if (x > 0) {
        for (int i = 0; i < 10; i++) {
            x += i;
        }
    }
    return x;
}
```

This function is larger and more complex, so the compiler may not inline it.

### Where to place inline

If we write the definition and declaration separately, the `inline` keyword should be written in the declaration.

Example:

```cpp
inline int add(int a, int b);

int add(int a, int b) {
    return a + b;
}
```

### Summary of the idea

- Macros are replaced by the preprocessor.
- They are fast, but unsafe and can cause mistakes.
- Normal functions are safe, but they use function call overhead.
- Inline functions are a middle ground.
- They provide speed and avoid the cost of a function call in many simple cases.
- They are safer than macros because they are type-safe.

## Final summary

- A function is a reusable block of code.
- `square(int n)` takes an input and returns a value.
- The function call sends data from the caller to the function.
- The function performs work and returns the result.
- The function call uses stack memory temporarily while it is running.
- Macros are preprocessor replacements and are not type-safe.
- Macros can cause unexpected results because of text replacement.
- Normal functions are safe but may use extra call overhead.
- Inline functions provide a better balance between speed and safety.
