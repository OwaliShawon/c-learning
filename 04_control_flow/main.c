#include <stdio.h>

int main() {
    // --- 1. If / Else ---
    int age = 20;
    
    printf("--- If / Else ---\n");
    if (age >= 18) {
        printf("You are an adult.\n");
    } else if (age >= 13) {
        printf("You are a teenager.\n");
    } else {
        printf("You are a child.\n");
    }

    // --- 2. Switch Statement ---
    char grade = 'B';
    
    printf("\n--- Switch Statement ---\n");
    switch (grade) {
        case 'A':
            printf("Excellent!\n");
            break;
        case 'B':
            printf("Well done!\n");
            break;
        case 'C':
            printf("You passed.\n");
            break;
        case 'F':
            printf("Better luck next time.\n");
            break;
        default:
            printf("Invalid grade.\n");
    }

    // --- 3. For Loop ---
    printf("\n--- For Loop ---\n");
    for (int i = 1; i <= 3; i++) {
        printf("Loop count: %d\n", i);
    }

    // --- 4. While Loop ---
    printf("\n--- While Loop ---\n");
    int count = 3;
    while (count > 0) {
        printf("Countdown: %d\n", count);
        count--;
    }

    // --- 5. Do-While Loop ---
    printf("\n--- Do-While Loop ---\n");
    int secret = 0;
    do {
        // This runs at least once, even though secret isn't < 0!
        printf("Executing do-while once!\n");
    } while (secret < 0);

    return 0;
}
