# Demo06: Static Members in C++ (chair example)

**Source:** [Day06/demo01.cpp](Day06/demo01.cpp#L1)

## 1. Program objective

- Demonstrate how to declare and use `static` data members and `static` member functions in a C++ class.
- Explain where `static` storage is allocated and how it differs from instance members.
- Show how to correctly define and initialize a `static` member outside the class body.

This example uses a `chair` class in which each `chair` object has its own `height`, `weight`, and `color`, while all chairs share a common `price`.

## Original author's notes (cleaned and corrected)

The original comments in `demo01.cpp` explained the motivation for using `static` members. Here is a cleaned and corrected version of those notes:

```
Static members:
We have a `chair` concept with attributes:
  - height
  - weight
  - color

If all chairs in a shop share the same price (for example, every chair costs 99), it makes sense to store `price` as a class-wide value instead of an instance member.

Examples:
  - c1: height=2, weight=1, color=BLACK
  - c2: height=2.5, weight=1.5, color=RED
  - c3: height=2, weight=1.5, color=BLUE

In this program, `price` is a shared data member (declared `static`) and is defined outside the class body.
```

### Mapping the author's points to the code

- "height, weight, color": the instance members `height`, `weight`, and `color` in `chair`.
- "shared price": represented by `static int price` in the `chair` class.
- "define outside class": implemented with `int chair::price = 2000;` in the source file.

## 2. What the program does (plain English)

- Defines a class `chair` with instance attributes and a shared `price` declared as `static`.
- Demonstrates setting the shared price with a static setter, reading it with a static getter, and printing it from both instance and static functions.
- Creates three `chair` objects, displays each (including the shared price), and shows how `sizeof` reflects only instance data.

## 3. Full source (cleaned and formatted)

```cpp
// Day06/demo01.cpp
#include <iostream>

#define BLACK   0
#define RED     1
#define GREEN   2
#define BLUE    3

using namespace std;

class chair {
private:
    int height;            // per-object
    int weight;            // per-object
    int color;             // per-object
    static int price;      // shared by all chairs (class member)

public:
    chair() : height(0), weight(0), color(BLACK) {}

    chair(int h, int w, int c) : height(h), weight(w), color(c) {}

    void display() const {
        cout << "chair: height=" << height << '"'
             << ", weight=" << weight << "kg, color=" << color
             << ", price=" << price << '\n';
    }

    static int get_price() { return price; }

    static void set_price(int p) { chair::price = p; }

    static void display_price() { cout << "price = " << price << '\n'; }
};

// Definition and initialization of the static member (required once)
int chair::price = 2000;

int main() {
    chair::set_price(2500);

    chair c1(2, 1, BLACK);
    chair c2(1, 2, RED);
    chair c3(3, 2, BLUE);

    c1.display();
    c2.display();
    c3.display();

    cout << "chair price (via getter): " << chair::get_price() << '\n';
    cout << "chair object size: " << sizeof(c1) << '\n';

    return 0;
}
```

## 4. Line-by-line explanation

- `#include <iostream>`: provides I/O facilities such as `std::cout`.
- `#define BLACK 0` etc.: simple macros used here for color constants. In production code prefer `enum` or `enum class`.
- `using namespace std;`: avoids repeatedly writing `std::`. Use with care to avoid name conflicts.

- `class chair { ... }` — the type used to demonstrate static members.
  - `int height, weight, color;` — instance members: each `chair` object has its own copy.
  - `static int price;` — class member: a single `price` shared by all `chair` objects. This line declares the member but does not allocate storage.

- Constructors:
  - `chair() : height(0), weight(0), color(BLACK) {}` — default constructor initializes members using an initializer list.
  - `chair(int h, int w, int c) : height(h), weight(w), color(c) {}` — parameterized constructor.

- `void display() const { ... }` — instance method that prints instance members and the shared `price`.
  - Instance methods can access static members directly (e.g., `price`) because static members are in the class scope.

- `static int get_price()` — static member function that returns the class-wide `price`.
  - Static functions can be called using `chair::get_price()` and do not have a `this` pointer.

- `static void set_price(int p)` — static setter that assigns to `chair::price`.

- `int chair::price = 2000;` — definition and initialization of the static member. This must appear once in a translation unit to allocate storage.

- `main()`:
  - `chair::set_price(2500);` updates the shared price for all `chair` objects.
  - Three `chair` objects (`c1`, `c2`, `c3`) are created with different instance attributes.
  - Calling `display()` prints each object's attributes and the shared `price`.
  - `cout << sizeof(c1)` shows that `sizeof` reflects only instance data (static members are not part of the object's size).

## 5. Key concepts and why they matter

- Static data member vs instance data member:
  - Instance data: Each object has a separate copy. Use when values are per-object.
  - Static (class) data: Single copy shared across all objects. Use for configuration, counters, or caches.

- Declaration vs definition of static members:
  - Declaration inside the class tells the compiler the member exists and its type.
  - Definition outside the class (`int chair::price = ...;`) actually allocates storage. Without this you get an undefined reference at link time.

- Static member functions:
  - Can be called without an object (`chair::get_price()`), cannot use `this`, and can only directly access static members.

- Memory/layout reason:
  - Static members have static storage duration and are typically placed in the data segment of the executable. They do not affect object layout or `sizeof`.

## 6. Typical output (example)

```
chair: height=2" , weight=1kg, color=0, price=2500
chair: height=1" , weight=2kg, color=1, price=2500
chair: height=3" , weight=2kg, color=3, price=2500
chair price (via getter): 2500
chair object size: 12
```

Notes:
- The exact `sizeof(c1)` depends on platform and ABI. On x86_64/macOS/Linux with 4-byte `int`, `sizeof` would usually be 12 (three ints); alignment or padding may change it.

## 7. Compile and run

Compile and run using g++:

```bash
g++ -std=c++17 Day06/demo01.cpp -o demo01
./demo01
```

For debugging/analysis, add `-g`:

```bash
g++ -g -std=c++17 Day06/demo01.cpp -o demo01
```

## 8. Common interview questions (with short model answers)

- Q: What is a `static` data member?
  - A: A member shared by all objects of a class; only one copy exists and it has static storage duration.

- Q: Where do you define a `static` data member and why?
  - A: Define it in one .cpp (translation unit) using `Type Class::member = value;` so the linker can allocate storage for it.

- Q: Can `static` member functions access instance members?
  - A: No, they have no `this` pointer and can only access other static members or instance members via an explicit object reference.

- Q: Do static members contribute to `sizeof`?
  - A: No, `sizeof` describes per-object storage layout; static members live separately.

- Q: Why use `chair::price = p;` instead of `price = p;` inside a static function?
  - A: Both work inside the class, but `chair::price` is explicit and avoids shadowing if the parameter name is `price`.

- Q: How do you make static data access thread-safe?
  - A: Protect accesses with synchronization (e.g., `std::mutex`) or use `std::atomic` for simple numeric types.

- Q: How do you restrict access to static data?
  - A: Keep it `private` and expose controlled `static` getters/setters.

## 9. Suggested improvements and code-cleanups

- Replace `#define` color macros with `enum` or `enum class`:
  ```cpp
  enum Color { BLACK=0, RED=1, GREEN=2, BLUE=3 };
  ```

- Keep `price` private and provide `get_price`/`set_price` as the public API. Consider validating values in `set_price`.

- Use `constexpr` for compile-time constants where applicable.

- Mark `display()` as `const` to indicate it does not modify the object (already applied in the cleaned code).

## 10. Variations and exercises

- Exercise: Implement a per-class counter to track how many `chair` objects are alive using a `static` counter incremented in the constructor and decremented in the destructor.

- Exercise: Make `price` an `std::atomic<int>` and demonstrate concurrent updates in a multithreaded test.

- Exercise: Move color from `int` to `enum class Color` and print names instead of numeric values.

## 11. Troubleshooting / common mistakes

- Forgetting to define the static member (`int chair::price;`) causes a link-time error: `undefined reference to 'chair::price'`.

- Shadowing the `price` parameter in `set_price(int price)` and accidentally assigning the parameter to itself. Use `chair::price = price;` to disambiguate.

- Sharing mutable static state across threads without synchronization leads to data races.

## 12. Quick cheat-sheet for interviews

- Declaration: inside class `static Type name;`
- Definition: outside class `Type Class::name = init;` (one translation unit)
- Access static member: `Class::name` or from instance `obj.name` (prefer `Class::name`)
- Static function: declared `static` inside class, call as `Class::fn()`

---

If you want, I can also:
- add a line-by-line annotated version of the original source with comments beside each line, or
- create a short printable one-page cheat-sheet focusing only on interview questions and answers.
