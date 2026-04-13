# Lesson 8: Dynamic Memory Allocation

In previous lessons, variables and arrays had **fixed sizes determined before compile time**. For example, `int scores[5]` means this array can only ever hold exactly 5 integers. But what if you don't know how many scores the user will type until the program is already running? 

Enter **Dynamic Memory** from the `<stdlib.h>` library!

## The Heap vs. The Stack
- **The Stack**: Where static variables (like `int x = 5;`) live. Fast, but limited size and automated lifecycle.
- **The Heap**: A massive pool of free memory managed by the OS. You must manually request chunks of this memory, and crucially, **you must manually give it back**!

## Core Functions in `<stdlib.h>`

### 1. `malloc` (Memory Allocation)
Asks the operating system for a raw contiguous block of bytes on the Heap. It returns a `void` pointer to the start of that memory block, which you cast into whatever pointer type you need.
```c
// Calculate size needed: 5 elements * 4 bytes/int = 20 bytes
int* myDynamicArray = (int*) malloc(5 * sizeof(int));
```

### 2. `calloc` (Contiguous Allocation)
Like `malloc`, but inherently zeros-out the memory instead of leaving random garbage data.
```c
int* zeroes = (int*) calloc(5, sizeof(int));
```

### 3. `realloc` (Re-Allocation)
Used to resize an already-allocated block of memory larger or smaller without losing the old data.
```c
myDynamicArray = (int*) realloc(myDynamicArray, 10 * sizeof(int));
```

### 4. `free` (Free Memory)
> [!CAUTION] 
> **MEMORY LEAKS!** Whenever you use `malloc` or `calloc`, you MUST use `free()` when you are done. Otherwise, the program will hold onto that memory until your entire computer restarts or kills it!
```c
free(myDynamicArray); 
myDynamicArray = NULL; // Good practice to prevent accessing dead memory
```

Let's look at `main.c` to see how we build an array whose size we decide while the program is running!
