#include <stdio.h>

// --- 1. Function Declarations (Prototypes) ---
// We tell the compiler these functions exist, so we can use them in main()
void greetUser();
int square(int number);
int findMax(int a, int b);

int main() {
    printf("--- Welcome to Lesson 5 ---\n");

    // Calling a void function
    greetUser();

    // Calling a function that returns an int
    int result = square(5);
    printf("The square of 5 is: %d\n", result);

    // Calling a function with multiple parameters
    int max = findMax(10, 20);
    printf("The larger number between 10 and 20 is: %d\n", max);

    return 0;
}

// --- 2. Function Definitions ---

// A void function doesn't return anything
void greetUser() {
    printf("Hello there, programmer!\n");
}

// A function that takes one argument and returns an int
int square(int number) {
    return number * number;
}

// A function that takes two arguments and uses control flow!
int findMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
