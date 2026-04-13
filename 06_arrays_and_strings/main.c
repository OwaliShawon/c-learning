#include <stdio.h>

int main() {
    printf("--- 1. Arrays ---\n");
    // Declare and initialize an array of integers
    int numbers[5] = {10, 20, 30, 40, 50};

    // Access specific elements (zero-indexed!)
    printf("First element: %d\n", numbers[0]);
    printf("Third element: %d\n", numbers[2]);
    printf("Last element: %d\n", numbers[4]);

    // Updating an array element
    numbers[0] = 99;
    printf("Updated first element: %d\n", numbers[0]);

    // Using a for loop to iterate through the array
    printf("\nIterating through array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Index %d: %d\n", i, numbers[i]);
    }

    printf("\n--- 2. Strings ---\n");
    // Manually declaring a string with null terminator
    char manualString[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    // The easy way to declare a string
    char easyString[] = "World"; 

    // %s is used to print strings (character arrays up to \0)
    printf("Manual: %s\n", manualString);
    printf("Easy: %s\n", easyString);

    // Let's modify a character inside the string
    easyString[0] = 'w';
    printf("After modification: %s\n", easyString);

    // Iterating through a string until we hit the null terminator
    printf("\nSpelling out the word:\n");
    int index = 0;
    while (easyString[index] != '\0') {
        printf("Char %d is: %c\n", index, easyString[index]);
        index++;
    }

    return 0;
}
