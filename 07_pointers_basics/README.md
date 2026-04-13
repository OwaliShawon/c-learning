# Lesson 7: Pointers (The Core of C)

Welcome to Pointers. Pointers are considered the most difficult concept for C beginners, but they give C its unmatched performance and power.

## What is a Pointer?
When you create a variable like `int age = 25;`, your computer assigns it a specific physical location in your RAM (memory). Let's pretend that memory location has the physical address `0x7FFE`. 

A **Pointer** is simply a variable that stores a **memory address** instead of a regular value!

## The Two Important Operators
To use pointers, you must understand two new operators:

1. **`&` (Address-Of Operator)**: Gives you the physical memory address of a variable.
   ```c
   int age = 25;
   // Retrieves the memory location where 'age' lives
   printf("%p", &age); // E.g., prints 0x7FFA2B
   ```

2. **`*` (Dereference / Pointer Operator)**: 
   - **When declaring**, `*` tells C "this variable is a pointer".
   - **When using**, `*` means "go to the physical address this pointer is holding, and give me the actual value sitting there".

## Example Syntax
```c
int score = 100;
int* ptrScore = &score; // ptrScore now holds the ADDRESS of score

// Changing the value at the address!
*ptrScore = 200; // This actually changes 'score' to 200!
```

## Why do we need this?
1. **Pass-by-Reference**: In Lesson 5, if you passed a variable to a function, the function created a *copy* of it. If you change the copy, the original remains unchanged. By passing a pointer (an address) to a function, the function can actually modify the original variable directly!
2. **Dynamic Memory**: Required for arrays whose sizes change during runtime (Lesson 8).
3. **Hardware Manipulation**: Essential in embedded systems when you need to change data at specific hardware registries.

Explore `main.c` carefully. Understanding the code there is the rite of passage for every C programmer!
