# Demo03 C++ Notes

## Data types in C++

C++ supports all the basic data types of C, such as:

- `int`
- `float`
- `char`
- `double`

C++ also adds some new data types.

## New data types in C++

### 1. `bool`

`bool` is used to store boolean values.

It can hold only two values:

- `true`
- `false`

Example:

```cpp
bool flag = true;
```

### Important point about `bool`

In C++, `true` is treated as a non-zero value and `false` is treated as zero.

So:

- `true` means 1
- `false` means 0

Example:

```cpp
bool flag = true;
cout << flag;
```

This prints:

```cpp
1
```

### Why `bool` is useful

`bool` is useful when we need to make decisions.

It is commonly used in:

- conditions
- loops
- comparisons
- flags

## 2. `wchar_t`

`wchar_t` stands for wide character.

It is used to store characters that are larger than normal `char`.

### Why `wchar_t` is needed

A normal `char` is usually enough for English letters and simple symbols.

But `char` is limited for many other languages and special symbols.

So `wchar_t` was introduced for wider character support.

### Size of `wchar_t`

The size of `wchar_t` depends on the machine.

- On Linux, it is often 4 bytes.
- On Windows, it is often 2 bytes.

### Important point

`wchar_t` is useful for Unicode support.

Unicode is used to represent many languages and symbols, such as:

- emoji
- characters from other languages
- special symbols

## Difference between `char` and `wchar_t`

### `char`

- used for ordinary ASCII characters
- mostly used for English letters and basic symbols
- smaller range

Example:

```cpp
char ch = 'A';
```

### `wchar_t`

- used for wide character support
- supports a larger range of characters
- useful for international text and Unicode

Example:

```cpp
wchar_t ch = L'A';
```

## Program explanation

```cpp
#include <iostream>
using namespace std;

int main() {
    bool flag = true;
    cout << "flag :" << flag << endl;

    wchar_t ch = 'A';
    cout << "ch :" << ch << endl;

    const int x = 123;
    cout << "x :" << x << endl;

    return 0;
}
```

## Line-by-line explanation

### 1. `#include <iostream>`

This header file is used for input and output operations.

It allows us to use `cout` and `endl`.

### 2. `using namespace std;`

This tells the compiler to use the standard C++ namespace directly.

So we can write `cout` without writing `std::cout`.

### 3. `bool flag = true;`

This creates a boolean variable named `flag`.

It stores the value `true`.

### 4. `cout << "flag :" << flag << endl;`

This prints the value of `flag` on the screen.

Since `flag` is a `bool`, it is printed as:

```cpp
1
```

### 5. `wchar_t ch = 'A';`

This creates a wide character variable named `ch`.

It stores the character `A`.

### 6. `cout << "ch :" << ch << endl;`

This prints the wide character on the screen.

### 7. `const int x = 123;`

This declares a constant integer variable.

In C++, a `const` variable must be initialized at the time of declaration.

So this is valid:

```cpp
const int x = 123;
```

But this is not valid in C++:

```cpp
const int x;
```

because it is not initialized.

This is why the code comment:

```cpp
// const int x; // valid in C -- uninitialized const variable
```

is important.

In C, such a declaration may appear in some cases, but in C++ it is not allowed unless it is initialized immediately.

### 8. `cout << "x :" << x << endl;`

This prints the value of the constant variable.

## Output of the program

The program prints:

```cpp
flag :1
ch :A
x :123
```

## Extra important notes from the latest code

### Difference between C and C++ declaration rules

In C, variables must be declared at the start of a block.

In C++, variables can be declared in the middle of the code.

Example:

```cpp
int main() {
    int a = 10;
    cout << a;

    int b = 20;
    cout << b;
}
```

This is valid in C++.

### `const` in C++

In C++, a `const` variable must be initialized immediately.

Example:

```cpp
const int x = 123;
```

This is valid.

But:

```cpp
const int x;
```

is not valid in C++ because it has no initial value.

### `bool` and `true` / `false`

- `bool` stores true or false.
- `true` is treated as non-zero.
- `false` is treated as zero.

### `wchar_t`

- `wchar_t` is used for wide characters.
- It supports a larger character range.
- It is useful for Unicode and international text.

## Final summary

- C++ supports all basic C data types.
- `bool` is used for true/false values.
- `true` is treated as non-zero and `false` as zero.
- `wchar_t` is used for wide characters.
- `wchar_t` is useful for Unicode and international text support.
- `char` is mainly used for simple ASCII characters.
- `wchar_t` is better for broader character support.
- In C++, variables can be declared inside a block at any point.
- `const` variables must be initialized when declared.
