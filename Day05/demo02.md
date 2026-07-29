# Demo02: Dynamic Array Inside a Class

## 1. Program objective

This program demonstrates:

- how to create a class with a dynamic array
- how to allocate memory inside the constructor using `new`
- how to release memory inside the destructor using `delete[]`
- how object-oriented programming is used to manage student marks

---

## 2. Program idea

The program takes the number of students, stores their marks in a dynamic array, accepts the marks from the user, and then displays all marks along with the average.

This is a good example of:

- encapsulation
- constructor and destructor
- dynamic memory allocation
- array handling inside a class

---

## 3. Code overview

```cpp
#include <iostream>

using namespace std;

class school {
private:
    int n;
    int* marks;

public:
    school(int n) {
        this->n = n;
        this->marks = new int[n];
        cout << "Inside school() ctor " << endl;
    }

    ~school() {
        delete[] this->marks;
        this->marks = NULL;
        cout << "Inside ~school() dtor " << endl;
    }

    void accept() {
        cout << "enter marks of " << this->n << " students: ";
        for (int i = 0; i < this->n; i++)
            cin >> this->marks[i];
    }

    void display() {
        int sum = 0;
        cout << "marks: ";
        for (int i = 0; i < this->n; i++) {
            sum += this->marks[i];
            cout << this->marks[i] << ", ";
        }
        double avg = (double)sum / this->n;
        cout << "\naverage = " << avg << endl;
    }
};
```

---

## 4. Important concepts used

### 4.1 Class and object

The class `school` contains:

- `n` → number of students
- `marks` → pointer to a dynamic array of marks

The object `s1` is created in `main()`.

### 4.2 Constructor

The constructor:

```cpp
school(int n) {
    this->n = n;
    this->marks = new int[n];
}
```

This is used to:

- initialize the number of students
- allocate memory for the marks array dynamically

So when an object is created, memory is allocated automatically for the marks.

### 4.3 Destructor

The destructor:

```cpp
~school() {
    delete[] this->marks;
    this->marks = NULL;
}
```

This is used to:

- free the dynamically allocated memory
- prevent memory leak

### 4.4 Dynamic array

```cpp
int* marks;
```

This pointer will point to an array of integers allocated at runtime.

The line:

```cpp
this->marks = new int[n];
```

creates an array of `n` integers in heap memory.

---

## 5. Step-by-step explanation

### Step 1: Taking input from user

```cpp
int num;
cout << "enter num of students in school: ";
cin >> num;
```

The user enters the number of students.

### Step 2: Creating object

```cpp
school s1(num);
```

This calls the constructor and allocates memory for the marks array.

### Step 3: Accepting marks

```cpp
s1.accept();
```

The user enters marks for each student.

### Step 4: Displaying marks and average

```cpp
s1.display();
```

The program prints all marks and calculates the average.

### Step 5: Object destruction

When `s1` goes out of scope, the destructor is called automatically.

It frees the memory using:

```cpp
delete[] this->marks;
```

---

## 6. Why dynamic memory is used here

Static arrays need size at compile time, but here the number of students is entered by the user at runtime.

So we use dynamic memory allocation:

```cpp
new int[n]
```

This makes the program flexible.

---

## 7. Why `delete[]` is used

Because `new int[n]` allocates an array of integers, we must free it using:

```cpp
delete[] marks;
```

If we used `delete` instead of `delete[]`, it would be incorrect for arrays.

---

## 8. Why `marks = NULL;` is written

After deleting the array, the pointer is set to `NULL`.

This is a safety practice.

It means:

- the pointer no longer points to invalid memory
- accidental use of the pointer is avoided

---

## 9. Memory diagram

```text
Object s1
-------------------------------------------------
| n = number of students                        |
| marks -> dynamically allocated int array      |
| marks[0], marks[1], marks[2], ...              |
-------------------------------------------------
```

The array is stored in heap memory.

When the object is destroyed, that heap memory is released.

---

## 10. Interview-style questions

### Q1. What is the role of the constructor in this program?

The constructor initializes the object and allocates memory for the marks array using `new`.

### Q2. Why is the destructor important?

The destructor releases memory allocated dynamically so there is no memory leak.

### Q3. Why is `delete[]` used instead of `delete`?

Because `new int[n]` allocates an array, so `delete[]` must be used to free the complete array.

### Q4. What is the use of `marks` pointer?

It points to the dynamically allocated array where student marks are stored.

### Q5. Why is `NULL` assigned after deletion?

To avoid dangling pointer issues and make the pointer safe.

---

## 11. Important points to remember

- A class can contain a pointer to a dynamic array.
- `new` is used to allocate memory at runtime.
- `delete[]` is used to free an array allocated with `new[]`.
- The constructor is used for initialization and dynamic allocation.
- The destructor is used for cleanup and memory release.
- Always free dynamic memory to avoid memory leaks.

---

## 12. Short summary

This program shows how to store marks of students using a dynamic array inside a class.

It explains:

- object-oriented design
- constructor and destructor
- dynamic memory allocation
- array management
- memory cleanup
