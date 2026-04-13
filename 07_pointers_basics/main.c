#include <stdio.h>

// A function that attempts to modify a variable but fails!
void tryToChangeValue(int x) {
    x = 999; 
}

// A function that modifies a variable directly using pointers!
void actuallyChangeValue(int* ptrX) {
    *ptrX = 999; // Dereference pointer to change original value
}

int main() {
    printf("--- 1. Pointer Basics ---\n");
    int number = 42;
    
    // Declare a pointer to hold the ADDRESS of 'number'
    int* ptrNumber = &number; 

    // %p is the format specifier for a memory pointer (prints in hex)
    printf("Value of number: %d\n", number);
    printf("Memory address of number: %p\n", &number);
    printf("Value inside ptrNumber (should be address): %p\n", ptrNumber);
    
    // Using * to grab the value AT the address
    printf("Value AT the address stored in ptrNumber: %d\n", *ptrNumber);

    
    printf("\n--- 2. Modifying Values via Pointers ---\n");
    // Change the value by dereferencing the pointer
    *ptrNumber = 100;
    
    // Look! 'number' changed even though we only touched the pointer!
    printf("New value of number: %d\n", number);

    
    printf("\n--- 3. Pass by Value vs. Reference ---\n");
    int score = 50;
    
    printf("Original score: %d\n", score);
    
    // Pass by Value: The function just gets a copy of 50. Original stays 50.
    tryToChangeValue(score);
    printf("After tryToChangeValue: %d\n", score);
    
    // Pass by Reference (using pointer): We give the function the ADDRESS of score.
    // The function uses that address to overwrite the physical memory block!
    actuallyChangeValue(&score);
    printf("After actuallyChangeValue: %d\n", score);

    return 0;
}
