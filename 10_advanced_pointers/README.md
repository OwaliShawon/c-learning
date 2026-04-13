# Lesson 10: Advanced Pointers

We've seen pointers holding memory addresses. Now let's explore some of the most complex, yet insanely powerful uses of pointers in C.

## 1. Pointers to Structs (`->` Operator)
When you have a regular Struct, you access its members using the dot (`.`) operator (e.g., `player1.hp`).
When you have a **Pointer to a Struct**, you *must* use the arrow (`->`) operator!

```c
struct Player p1 = {"John", 100};
struct Player* ptr = &p1;

// This changes John's HP!
ptr->hp = 50; 
```
*Note: `ptr->hp` is exactly identical to writing `(*ptr).hp` behind the scenes.*

## 2. Pointer Arithmetic
Since a pointer is fundamentally just a numerical memory address (like `0x1000`), you can do math on it!
If `ptr` points to an integer, what happens if you do `ptr++`?
It doesn't add 1! Because an integer is exactly 4 bytes in size, `ptr++` literally adds 4 bytes to the physical address so it perfectly targets the *next* integer! This is how arrays work natively in C under the hood.

## 3. Pointers to Pointers (Double Pointers)
If a pointer stores the physical address of a variable, a **Double Pointer** stores the physical address of a *Pointer*!
You denote this with `**`.
```c
int num = 42;
int* ptr1 = &num;       // Points to num
int** ptr2 = &ptr1;     // Points to ptr1!

// To get the number '42' out of ptr2, you must dereference it twice!
printf("%d", **ptr2); 
```

## 4. Function Pointers
A block of code (a function) also occupies memory. That means functions have memory addresses! You can pass a Function Pointer to another function. This allows you to pass behavior as an argument (commonly called "Callbacks").

Dive into `main.c`—if you can trace the logic here, you've mastered C!
