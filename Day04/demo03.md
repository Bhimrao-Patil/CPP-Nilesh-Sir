# Demo03: Swap by Address and Swap by Reference in C++

## Program purpose

This program demonstrates two ways to swap integer values:
- swap using pointers (pass by address)
- swap using references (pass by reference)

It also shows how C++ overloaded functions can provide two versions of the same operation with different parameter types.

## Latest code listing from `Day04/demo03.cpp`

```cpp
#include <iostream>
using namespace std;

// pass by address
void swap_nums(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// pass by reference
void swap_nums(int& ref1, int& ref2) {
    int temp = ref1;       // temp = num1;
    ref1 = ref2;           // num1 = num2;
    ref2 = temp;           // num2 = temp;
}

int main()
{
    int num1 = 10, num2 = 20;
    cout << "before swap: " << "num1 = " << num1 << ", num2 = " << num2 << endl;
    //swap_nums(&num1, &num2);
    swap_nums(num1, num2);
    cout << " after swap: " << "num1 = " << num1 << ", num2 = " << num2 << endl;
    
    int num = 0;
    int& ref = num;
    cout << "enter a number: ";
    cin >> ref; // input value of num
    cout << "you entered: " << num << endl;
    cout << "&num = " << &num << endl;
    cout << "&ref = " << &ref << endl;

    // reference is another name for the variable here it is proved

    return 0;
}
```

## Latest code details

- The current source file defines both the pointer-based and reference-based swap functions.
- In `main()`, the code is using the reference overload by calling `swap_nums(num1, num2);`.
- The pointer-based call is still present in comments: `//swap_nums(&num1, &num2);`.
- After the swap example, the code demonstrates a reference bound to a new integer variable `num`.
- Input is read through the reference `ref`, and the program prints both `num` and `ref` to show they are the same object.
- The code prints the addresses `&num` and `&ref` to prove that a reference has the same address as the original variable.

## What the code does

## What the code does

1. Declares two integer variables: `num1 = 10` and `num2 = 20`.
2. Prints their values before swapping.
3. Calls `swap_nums(num1, num2)` to swap the two values using the reference overload.
4. Prints the values after swapping.
5. Declares `num = 0` and a reference `ref` bound to `num`.
6. Reads input from the user into `ref`.
7. Prints the value of `num` and the value of `ref` to show they are identical.
8. Prints the addresses of `num` and `ref` to prove they share the same memory location.

## Detailed explanation

### Function overloading

The code defines two functions with the same name, `swap_nums`:
- `void swap_nums(int* ptr1, int* ptr2)` accepts pointers to integers.
- `void swap_nums(int& ref1, int& ref2)` accepts integer references.

This is called function overloading. The compiler chooses the correct version based on the argument types used at the call site.

### Pass by address (pointer version)

```cpp
void swap_nums(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```

- `ptr1` and `ptr2` are pointers that store addresses of integers.
- `*ptr1` and `*ptr2` dereference the pointers to access the actual integer values.
- Swapping is done by reading and writing through the pointer addresses.
- A call would look like: `swap_nums(&num1, &num2);`
- The caller passes the addresses using the address-of operator `&`.

### Pass by reference (reference version)

```cpp
void swap_nums(int& ref1, int& ref2) {
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}
```

- `ref1` and `ref2` are references, which are aliases for the original variables.
- References behave like the original variables, so there is no explicit dereference operator.
- The call is simply: `swap_nums(num1, num2);`
- The compiler binds `ref1` to `num1` and `ref2` to `num2`.

### Why the program uses the reference version

- The active call in `main()` is `swap_nums(num1, num2);`.
- Because the arguments are plain integers, the compiler selects the reference overload.
- The pointer overload would require addresses, not values.
- The commented-out line `//swap_nums(&num1, &num2);` is how the pointer version would be called.

### Reference input example

The latest code also shows reference input:

```cpp
int num = 0;
int& ref = num;
cout << "enter a number: ";
cin >> ref;
cout << "you entered: " << num << endl;
cout << "&num = " << &num << endl;
cout << "&ref = " << &ref << endl;
```

- `ref` is a reference alias to `num`.
- Reading into `ref` updates `num` because they share the same object.
- Printing `num` and `ref` shows the same value.
- Printing `&num` and `&ref` shows the same address.
- This proves that references are not separate storage; they are alternative names for the same variable.

## Pointer vs reference for swap

### Pointer version

- More explicit about addresses.
- Syntax uses `&` to pass addresses and `*` to dereference.
- Safe when you need to represent optional or nullable references.
- Example call: `swap_nums(&num1, &num2);`

### Reference version

- Cleaner syntax, because it looks like ordinary variables.
- The function directly manipulates the caller's variables.
- Cannot be null and must be initialized.
- Example call: `swap_nums(num1, num2);`

## Interview perspective

### Why use references over pointers?

- References are safer and easier to read.
- They cannot be null and cannot be left uninitialized.
- They are the preferred choice for most swap and pass-by-reference use cases.
- Use pointers when you need explicit address handling or nullability.

### What does function overloading teach?

- C++ allows multiple functions with the same name but different parameter types.
- Overloads are resolved at compile time.
- This makes the same operation available for different styles of use.

### What is actually swapped?

- The functions swap the values stored in `num1` and `num2`.
- The `swap_nums` function does not return a value.
- The swap happens by modifying the caller's variables through address or alias.

## Example output

The program prints:

```text
before swap: num1 = 10, num2 = 20
 after swap: num1 = 20, num2 = 10
```

## Summary

- `demo03.cpp` teaches both pass-by-address and pass-by-reference techniques.
- References are usually the cleaner, safer solution in C++.
- Function overloading lets the same function name work with both pointers and references.
- The code also serves as a good interview example for explaining how values move between caller and callee.
