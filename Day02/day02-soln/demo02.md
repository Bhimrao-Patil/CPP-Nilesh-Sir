# Demo02 C++ Notes

This markdown file explains the code in [demo02.cpp](demo02.cpp).

## 1. Class and encapsulation

The class `time` keeps its data private and exposes behavior through public methods.

```cpp
class time {
    private:
        int hrs, mins, secs;

    public:
        time();
        time(int h, int m, int s);
        ~time();

        void set_hrs(int h);
        void set_mins(int m);
        void set_secs(int s);

        int get_hrs();
        int get_mins();
        int get_secs();

        void display();
};
```

- `hrs`, `mins`, and `secs` are private members.
- They can be changed only through public functions such as setters.
- This protects the object's data from direct outside modification.

## 2. Why direct access fails

The following line would cause an error:

```cpp
t1.hrs = 10;
```

Because `hrs` is private, it cannot be accessed directly from `main()`.

The correct way is:

```cpp
t1.set_hrs(10);
```

## 3. Constructors and destructor

### Default constructor

```cpp
time() {
    this->hrs = 0;
    this->mins = 0;
    this->secs = 0;
}
```

- This initializes the object to `00:00:00`.
- It is called automatically when an object is created.

### Parameterized constructor

```cpp
time(int h, int m, int s) {
    assert(h >= 0 && h < 24);
    assert(m >= 0 && m < 60);
    assert(s >= 0 && s < 60);

    this->hrs = h;
    this->mins = m;
    this->secs = s;
}
```

- This allows creating an object with initial values.
- Example: `time t4(10, 20, 30);`

### Destructor

```cpp
~time() {
    printf("bye from destructor\n");
}
```

- The destructor is called automatically when an object goes out of scope.
- It is useful for cleanup when an object owns resources.

## 4. Setters and getters

### Setters

```cpp
void set_hrs(int h) {
    assert(h >= 0 && h < 24);
    this->hrs = h;
}
```

These functions safely update private data and validate values.

### Getters

```cpp
int get_hrs() {
    return this->hrs;
}
```

Getters let us read private values without allowing direct modification.

## 5. The `this` pointer

Inside member functions, `this` points to the current object.

```cpp
void display() {
    printf("time is %02d:%02d:%02d\n", this->hrs, this->mins, this->secs);
}
```

- `this->hrs` means “the `hrs` of the current object”.
- This is useful when member names and parameter names are similar.

## 6. Object memory concept

In this program, the objects are created on the stack:

```cpp
time t1;
time t2;
time t3;
time t4(10, 20, 30);
```

- Stack memory is used for local objects.
- Each object has its own copy of `hrs`, `mins`, and `secs`.
- If we used `new`, the object would be created on the heap instead.

## 7. Main program flow

The `main()` function demonstrates the class behavior step by step:

1. Create `t1` and set time using setters.
2. Create `t2` and set values again.
3. Call `display()` to print the object values.
4. Use getters to show the values.
5. Create `t3` and `t4` to show more examples.
6. Use the parameterized constructor for `t4`.

## 8. Summary

This example teaches important C++ concepts:

- Encapsulation
- Private and public members
- Constructors and destructors
- Setters and getters
- The `this` pointer
- Object creation and memory location
