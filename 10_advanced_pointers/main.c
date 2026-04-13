#include <stdio.h>

// A struct to be used with pointer
struct Player {
    int hp;
};

// Two simple math functions for our function pointer callback
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }


int main() {
    printf("--- 1. Pointers to Structs ---\n");
    struct Player p1;
    p1.hp = 100;
    
    struct Player* ptrStruct = &p1;
    
    // We modify hp using the "->" operator because ptrStruct is a pointer!
    ptrStruct->hp = 250;
    
    printf("Player HP is now: %d\n", p1.hp);


    printf("\n--- 2. Pointer Arithmetic ---\n");
    int arr[] = {10, 20, 30};
    
    // 'arr' actually holds the physical memory address of the first element!
    int* ptrArr = arr; 
    
    printf("First element: %d\n", *ptrArr);
    
    // Move the pointer one memory block forward! 
    ptrArr++; 
    printf("Second element via pointer addition: %d\n", *ptrArr);


    printf("\n--- 3. Double Pointers ---\n");
    int value = 42;
    int* ptrPrimary = &value;         // Pointer 1
    int** ptrSecondary = &ptrPrimary; // Pointer 2 storing Pointer 1's Address

    printf("Value directly: %d\n", value);
    printf("Value via *ptrPrimary: %d\n", *ptrPrimary);
    printf("Value via **ptrSecondary: %d\n", **ptrSecondary); // Dereferenced TWICE!


    printf("\n--- 4. Function Pointers ---\n");
    // We declare a function pointer that expects two ints and returns an int
    int (*mathPointer)(int, int);

    // Assign the memory address of our 'add' function to the pointer
    mathPointer = add; 
    printf("Addition Callback Output: %d\n", mathPointer(5, 5));

    // Swap the pointer to point to the 'multiply' function memory location!
    mathPointer = multiply;
    printf("Multiplication Callback Output: %d\n", mathPointer(5, 5));

    return 0;
}
