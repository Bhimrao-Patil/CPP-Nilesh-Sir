Program purpose

This example shows dynamic memory allocation in C++ using `new[]` and `delete[]`, explains where memory is allocated (stack vs heap), and provides diagnostics and interview-focused notes.

Code (source: `Day04/demo05.cpp`)

```cpp
// dynamic memory allocation
#include <iostream>
using namespace std;

int main()
{
    int num; // local variable on the stack

    // read n at runtime and allocate an array on the heap
    int i, n, sum = 0;
    cout << "how many students? ";
    cin >> n;

    int* scores = new int[n]; // allocate n * sizeof(int) bytes on the heap

    cout << "enter marks of " << n << " students: ";
    for (i = 0; i < n; i++)
        cin >> scores[i];
    for (i = 0; i < n; i++)
        sum = sum + scores[i];
    cout << "sum of marks = " << sum << endl;

    // diagnostics: pointer size and user payload
    cout << "pointer variable size: " << sizeof(scores) << " bytes\n";
    cout << "allocated (user payload): " << (n * sizeof(*scores)) << " bytes\n";

    delete[] scores; // free the heap block
    scores = nullptr;

    return 0;
}
```

Key points

- Stack allocation (automatic storage): local variables such as `num`, `i`, `n`, `sum`, and the pointer variable `scores` are stored on the stack. Their lifetime is the scope of the function.
- Heap allocation (dynamic / free store): `new int[n]` allocates a contiguous block of memory on the heap to hold `n` `int` objects. The program receives a pointer to the first element.
- User-visible payload: the memory requested for elements is `n * sizeof(int)` bytes. Example: with `n == 3` and `sizeof(int) == 4`, payload = 12 bytes.
- Pointer size vs payload: the pointer variable `scores` itself is typically 8 bytes on a 64-bit system (`sizeof(scores) == 8`), while the block it points to is `n * sizeof(int)` (plus allocator overhead).
- Allocator bookkeeping: implementations store metadata (headers/footers) around heap blocks; this adds extra bytes but varies by runtime/allocator and is not directly visible to your program.
- `new` semantics:
  - `new int[n]` allocates memory and default-initializes / value-initializes elements depending on type and context. For built-in types, memory contains indeterminate values unless you use value initialization `new int[n]()`.
  - On allocation failure, regular `new` throws `std::bad_alloc`. Use `new (std::nothrow) int[n]` to get `nullptr` instead of an exception.
- Correct cleanup: use `delete[] scores` to free memory obtained from `new[]`. Omitting `delete[]` causes a memory leak; using `delete` (without `[]`) is undefined behavior for arrays.

- Memory leak definition: if dynamically allocated memory is not released (for example by forgetting `delete[]`), that memory is wasted for the lifetime of the process — this is called a memory leak and is especially harmful for long-running programs and services.
- OS cleanup on process exit: when a process terminates, the operating system reclaims its resources (including memory pages). Leaked memory is returned to the OS after process exit, but leaks still matter during the process lifetime.

Memory layout summary (example for n == 3 on a 64-bit system)

- Stack (frame for `main`):
  - `num`           : 4 bytes (typical for `int`)
  - `i`, `n`, `sum` : each 4 bytes
  - `scores` (pointer): 8 bytes
  - total stack-local footprint: sum of locals (depends on alignment/padding)

- Heap (allocated by `new int[n]`):
  - user payload: `n * sizeof(int)` = 3 * 4 = 12 bytes
  - allocator header: implementation-specific (e.g., 8-16 bytes)
  - total reserved by allocator: payload + overhead

Diagnostics snippet you can add to `main()` (already included above):

```cpp
cout << "pointer variable size: " << sizeof(scores) << " bytes\n";
cout << "allocated (user payload): " << (n * sizeof(*scores)) << " bytes\n";
```

Diagram (logical view)

```mermaid
flowchart TB
  subgraph Stack[Stack (call frame)]
    num["num: int (4B)"]
    i["i: int (4B)"]
    n["n: int (4B)"]
    sum["sum: int (4B)"]
    scores_ptr["scores: int* (8B)"]
  end

  subgraph Heap[Heap / Free store]
    block["allocated block: n * sizeof(int) (user payload)\n+ allocator metadata"]
  end

  scores_ptr -->|points to| block
```

Interview-focused points and questions

- Why use dynamic allocation here instead of a fixed-size array?
  - Because `n` is known only at runtime. A static `int marks[5];` requires a compile-time constant size.
- What does `new int[n]` actually return?
  - It returns a pointer to the first `int` of the allocated block (type `int*`).
- How much memory is allocated and who is responsible for freeing it?
  - The user payload is `n * sizeof(int)`; the programmer must call `delete[]` to free it.
- What happens if you forget `delete[]`?
  - Memory leak: the program's heap usage grows; in long-running programs this can exhaust memory.
- How does `new` signal failure?
  - By throwing `std::bad_alloc` (or returning `nullptr` with `std::nothrow`).
- How to avoid uninitialized elements?
  - Use `new int[n]()` to value-initialize all elements to zero.
- What does `sizeof(scores)` measure?
  - The size of the pointer variable (e.g., 8 bytes on 64-bit), not the heap block.

new vs malloc

- Language level & constructors: `new` is a C++ operator that allocates memory and (for objects) calls constructors. `malloc` is a C library function that only allocates raw memory and does not run constructors.
- Return type and casting: `new` returns a typed pointer (e.g., `int*`). `malloc` returns `void*` which in C++ requires an explicit cast (`(int*)malloc(...)`).
- Initialization: `new int[n]` default-initializes (indeterminate for built-ins) or value-initializes when written `new int[n]()`. `malloc` leaves memory uninitialized; use `calloc` for zeroed memory.
- Failure behavior: `new` throws `std::bad_alloc` on failure (or returns `nullptr` with `std::nothrow`), while `malloc` returns `NULL` on failure.
- Deallocation: memory allocated with `new[]` must be freed with `delete[]`. Memory from `malloc` must be freed with `free()`. Mixing them is undefined behavior.
- Object safety: `new` is safe for C++ objects (constructors/destructors will run). `malloc` should not be used for objects with non-trivial constructors/destructors.
- Realloc semantics: `realloc` can resize `malloc`'d blocks (C API). There is no direct equivalent for `new[]`/`delete[]` — resizing requires manual allocation, copy, and delete or use `std::vector`.

Example: `new` vs `malloc`

```cpp
// using new
int* a = new int[5];
// ... use a ...
delete[] a;

// using malloc
#include <cstdlib>
int* b = (int*)malloc(5 * sizeof(int));
// ... use b ...
free(b);
```

Interview notes

- Prefer `new` (or better, `std::vector`/RAII) in C++ code for correctness and constructor semantics.
- Mention that mixing allocation/deallocation APIs is undefined behavior and a common bug to watch for in interviews.
- Be ready to explain `std::nothrow`, placement `new`, and why RAII containers simplify memory management.

Small variations and safety notes

- Prefer RAII containers like `std::vector<int>` instead of raw `new[]`/`delete[]` in production code. `std::vector` manages memory and avoids leaks:

```cpp
#include <vector>
vector<int> scores(n);
// use scores[i]
```

- If you must use `new[]`, set the pointer to `nullptr` after `delete[]` to avoid dangling pointers.

Commands to compile and run the example

```bash
g++ -std=c++17 -g Day04/demo05.cpp -o Day04/demo05
./Day04/demo05
```

Quick practice interview answer (short)

- Q: "Explain where memory is allocated for the array created by `new int[n]`." 
- A: "The `new` operator allocates the array on the heap (free store). The pointer variable that stores the return value is on the stack. The requested user payload is `n * sizeof(int)`; the allocator may add implementation-specific metadata around it." 

If you want, I can: 
- add this diagnostics code directly into `Day04/demo05.cpp` and run it here to show live output, or
- produce a short `Day04/demo05-vec.md` showing the `std::vector` refactor and benefits.

Which of those would you like next?