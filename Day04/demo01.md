# Demo01: Default Arguments and Function Declaration in C++

## Program purpose

This program demonstrates:
- how to declare and call functions in C++
- how to use default arguments in function declarations
- how default values behave when the caller passes fewer arguments than the function accepts
- the rule that default arguments must appear from right to left only

## Included header and namespace

```cpp
#include <iostream>
using namespace std;
```

- `#include <iostream>` adds the standard input/output library.
- `using namespace std;` allows direct use of `cout`, `endl`, and other standard library names without `std::` prefix.

## Latest code overview

The file `demo01.cpp` contains:

- a function `sum(...)` with no default arguments
- a function `add(...)` with default values for the last three parameters
- a function `multiply(...)` with default values for the last three parameters
- a `main()` function that tests these functions and prints results

The exact implementation in the file is:

```cpp
#include <iostream>

using namespace std;

int sum(int a, int b, int c, int d, int e)
{
    return a + b + c + d + e;
}

int add(int a, int b, int c=0, int d=0, int e=0)
{
    return a + b + c + d + e;
}

int multiply(int a, int b, int c=1, int d=1, int e=1)
{
    return a * b * c * d * e;
}

int main()
{
    cout << "Sum 2 nums : " << sum(10, 20, 0, 0, 0) << endl;
    cout << "Sum 3 nums : " << sum(10, 20, 30, 0, 0) << endl;

    int result = add(10, 20);
    cout << "result :" << result << endl;

    result = add(10, 20, 30);
    cout << "result :" << result << endl;

    result = add(10, 20, 20, 40);
    cout << "result :" << result << endl;

    result = multiply(1, 2, 3, 4);
    cout << "result : " << multiply << endl;
}
```

### Detailed behavior

- `sum(...)` is used as a fixed-parameter function. It needs all five arguments explicitly.
- `add(...)` provides optional behavior for the last three parameters, so the caller can pass 2, 3, 4, or 5 arguments.
- `multiply(...)` uses defaults of `1` for optional parameters because `1` is the identity element for multiplication.
- In `main()`, the first two `cout` lines use `sum(...)` to demonstrate how explicit zero values replace missing inputs.
- The `add(...)` calls show how default values are filled in automatically when arguments are omitted.

## Why the current code is not fully correct

The last line in `main()` is currently:

```cpp
cout << "result : " << multiply << endl;
```

This is not correct because `multiply` is the name of the function, not the computed result.
The line should print the `result` variable that holds the return value of the `multiply(...)` call.

Correct version:

```cpp
cout << "result : " << result << endl;
```

After fixing this, the code prints the actual multiplication result.

## Function definitions

### 1. `sum(...)`

```cpp
int sum(int a, int b, int c, int d, int e)
{
    return a + b + c + d + e;
}
```

- This function takes exactly 5 integers.
- All values must be passed by the caller.
- It returns the total sum of all five values.

### 2. `add(...)` with default arguments

```cpp
int add(int a, int b, int c = 0, int d = 0, int e = 0)
{
    return a + b + c + d + e;
}
```

- `a` and `b` are required arguments.
- `c`, `d`, and `e` are optional because they have default values.
- If the caller does not send values for `c`, `d`, or `e`, the function uses `0` for those parameters.

Example calls:
- `add(10, 20)` uses `c = 0, d = 0, e = 0` and returns `30`.
- `add(10, 20, 30)` uses `d = 0, e = 0` and returns `60`.
- `add(10, 20, 20, 40)` uses `e = 0` and returns `90`.

### 3. `multiply(...)` with default arguments

```cpp
int multiply(int a, int b, int c = 1, int d = 1, int e = 1)
{
    return a * b * c * d * e;
}
```

- `a` and `b` are required.
- `c`, `d`, and `e` default to `1` because multiplying by `1` does not change the result.
- This makes the function usable with fewer than 5 arguments while preserving multiplication semantics.

Example calls:
- `multiply(2, 3)` returns `6`.
- `multiply(2, 3, 4)` returns `24`.
- `multiply(1, 2, 3, 4)` returns `24`.

## Example: `print_info(...)` with default values

The program also includes a function with a default argument in the third parameter:

```cpp
void print_info(char *name, int age, const char* addr = "unknown")
{
    cout << "name " << name << endl;
    cout << "age " << age << endl;
    cout << "addr " << addr << endl;
}
```

### Why `const char* addr` is used for the default value

- The default value is a string literal: `"unknown"`.
- In C++, string literals are stored in read-only memory.
- The type of string literals is effectively `const char[N]`.
- Using `const char*` here tells the compiler that `addr` should not be modified inside the function.
- This is safer than using `char*`, because modifying a string literal through `char*` is undefined behavior.
- `const` improves data safety and prevents accidental writes to read-only memory.

### What this function does

- `name` is a required argument.
- `age` is a required argument.
- `addr` is optional and defaults to `"unknown"`.

Example calls:
- `print_info("Superman", 768, "Krypton");`
- `print_info("James Bond", 65);` uses the default address `"unknown"`.

### Important note on the actual code

The selected code has a bug in the function body:

```cpp
cout << "name" << name << endl;
cout << "age" << name << endl;
cout << "addrr" << name << endl;
```

- All three lines print `name` instead of printing the separate values.
- The second line should print `age`.
- The third line should print `addr`.

Corrected version:

```cpp
cout << "name " << name << endl;
cout << "age " << age << endl;
cout << "addr " << addr << endl;
```

## Declaration vs definition with default arguments

When a function is declared and defined separately, the default argument value should appear only in the declaration.

Example:

```cpp
void print_details(char *name, int age, const char* addr = "unknown");

void print_details(char *name, int age, const char* addr)
{
    cout << "name " << name << endl;
    cout << "age " << age << endl;
    cout << "addr " << addr << endl;
}
```

- The declaration tells the compiler what default value to use when the caller omits the argument.
- The definition must not repeat the default value, or the compiler may emit a warning or error.
- The declaration should appear before any calls to the function.
- This separation is common when the declaration is in a header file and the definition is in a source file.

## Technical interview points about default arguments

- Default arguments are substituted at the call site by the compiler, not inside the function body.
- The function signature does not include default values; default values are part of the function declaration only.
- Because they are not part of the signature, default arguments do not create new overloads.
- You may provide default values in a function declaration (for example in a header file) and omit them in the definition.
- If a function has both a declaration and a definition, only one of them should specify default values to avoid ambiguity.
- Default arguments must be trailing parameters; you cannot skip a non-defaulted parameter before a defaulted one.
- Default values can be any compile-time or usable expression, such as constants, enum values, or other variables in scope.
- When multiple translation units use the function, the default values must be visible to the caller through the included declaration.
- Default arguments work well for optional parameters, but for complex cases consider function overloading or `std::optional` for clearer semantics.

## Important rule for default arguments

- Default arguments must appear at the end of the parameter list.
- You cannot skip a parameter in the middle and give a default for the next one.

Valid:
```cpp
int add(int a, int b, int c = 0, int d = 0);
```

Invalid:
```cpp
int wrong(int a, int b = 1, int c);
```

This means the rightmost parameters can be optional, while the leftmost parameters must be provided.

## `main()` function explanation

```cpp
int main()
{
    cout << "Sum 2 nums : " << sum(10, 20, 0, 0, 0) << endl;
    cout << "Sum 3 nums : " << sum(10, 20, 30, 0, 0) << endl;

    int result = add(10, 20);
    cout << "result :" << result << endl;

    result = add(10, 20, 30);
    cout << "result :" << result << endl;

    result = add(10, 20, 20, 40);
    cout << "result :" << result << endl;

    result = multiply(1, 2, 3, 4);
    cout << "result : " << multiply << endl;
}
```

### What happens here

- `sum(10, 20, 0, 0, 0)` calculates `10 + 20 + 0 + 0 + 0 = 30`.
- `sum(10, 20, 30, 0, 0)` calculates `10 + 20 + 30 + 0 + 0 = 60`.
- `add(10, 20)` calculates `10 + 20 + 0 + 0 + 0 = 30` using default values.
- `add(10, 20, 30)` calculates `10 + 20 + 30 + 0 + 0 = 60`.
- `add(10, 20, 20, 40)` calculates `10 + 20 + 20 + 40 + 0 = 90`.

### Bug note

The last output line in the program is incorrect:

```cpp
cout << "result : " << multiply << endl;
```

- This prints a function pointer or invalid output.
- It should instead print the computed value, for example:

```cpp
cout << "result : " << result << endl;
```

## Summary of concepts

- Functions let you put reusable code into named blocks.
- Default arguments let a function accept fewer parameters than its full signature.
- Required parameters must come first, and optional parameters must come last.
- For addition, default arguments are usually `0`.
- For multiplication, default arguments are usually `1`.
- Always print actual values, not the function name.

## Example output (corrected)

If the final `cout` is corrected, the expected output would be:

```text
Sum 2 nums : 30
Sum 3 nums : 60
result :30
result :60
result :90
result : 24
```
