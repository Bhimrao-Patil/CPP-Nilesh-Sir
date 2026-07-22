/*
C++ Compilation, Linking, and Cross-platform Theory for Day02/demo01.cpp

A. C++ build pipeline
---------------------
1. Preprocessing
   - Input: demo01.cpp
   - Preprocessor handles directives such as:
       #include, #define, #ifdef, #pragma
   - It expands header contents and macros.
   - Output: a single translation unit ready for parsing.

2. Compilation
   - The compiler parses the preprocessed source into tokens and builds an AST.
   - It performs semantic analysis: type checking, name lookup, overload resolution.
   - It converts the AST to intermediate representation (IR).
   - It may optimize the IR: constant folding, dead code elimination, inlining.
   - Output: assembly code for the target architecture.

3. Assembly
   - The assembler converts assembly into an object file (.o).
   - Object files contain machine code, data, symbol tables, and relocation entries.
   - External references remain unresolved until linking.

4. Linking
   - The linker combines object files and libraries into an executable.
   - It resolves symbols such as main() and printf().
   - It assigns final addresses to code and global/static data.
   - It produces a platform-specific executable format.

   Common sections in executables:
     .text  - program instructions
     .data  - initialized global/static variables
     .bss   - zero-initialized global/static variables
     relocation and metadata for the loader

5. Loading into RAM
   - When executing the binary, the OS loader reads the file from disk.
   - It creates a virtual address space for the process.
   - It maps executable files into memory pages.
   - It sets up the stack, heap, arguments, and environment variables.
   - It starts execution at the program entry point.

6. Runtime memory layout
   - Code segment (.text): executable instructions
   - Read-only data: constants and string literals
   - Initialized data (.data): globals/statics with values
   - Uninitialized data (.bss): zeroed globals/statics
   - Heap: dynamic allocations by malloc/new
   - Stack: function frames and local variables
   - OS/kernel space: protected and not part of user program

B. Why executables are OS-specific
----------------------------------
- Windows uses PE format and Windows system calls.
- Linux uses ELF format and POSIX/Linux system calls.
- macOS uses Mach-O format and Apple system calls.
- A native binary built for one OS cannot directly run on another.

C. Running a Windows executable on Linux
----------------------------------------
- Use Wine for many Windows programs:
    wine program.exe
- Use a Windows virtual machine if Wine is insufficient.
- Rebuild from source for Linux if possible.

D. Running a Linux executable on Windows
----------------------------------------
- Use WSL (Windows Subsystem for Linux) and run it inside WSL.
- Use a Linux virtual machine.
- Rebuild from source for Windows if the source is available.

E. Cross-compilation examples
-----------------------------
- Build Windows executable on Linux/macOS using mingw-w64:
    x86_64-w64-mingw32-g++ demo01.cpp -o demo01.exe
- Build Linux executable on Windows via WSL:
    g++ demo01.cpp -o demo01

F. Can one executable work on all OSes?
---------------------------------------
- Native answer: no. One compiled binary cannot natively run on all OSes.
- Closest alternatives:
    - use a portable runtime such as Java JVM (.jar file)
    - use .NET with cross-platform assemblies
    - use Python/Ruby scripts interpreted by a runtime
    - use WebAssembly inside a supporting host
- In C++ you can write portable source code, but you still compile separately for each OS.

G. Commands for this file
-------------------------
- Compile and run on macOS/Linux:
    g++ -std=c++17 -g demo01.cpp -o demo01
    ./demo01
- Preprocess only:
    g++ -E demo01.cpp -o demo01.i
- Compile to assembly:
    g++ -S demo01.cpp -o demo01.s
- Compile to object file:
    g++ -c demo01.cpp -o demo01.o
- Link from object file:
    g++ demo01.o -o demo01
*/

#include <stdio.h>

int main() {
    printf("hello world\n");
    return 0;
}
