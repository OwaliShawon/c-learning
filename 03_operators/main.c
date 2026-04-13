#include <stdio.h>

int main() {
    // --- 1. Arithmetic Operators ---
    int a = 10;
    int b = 3;
    
    printf("--- Arithmetic ---\n");
    printf("Addition (a + b): %d\n", a + b);
    printf("Subtraction (a - b): %d\n", a - b);
    printf("Multiplication (a * b): %d\n", a * b);
    
    // Integer division drops decimals!
    printf("Division (a / b): %d\n", a / b); 
    
    // Modulo gives you the remainder of division
    printf("Modulus (a %% b): %d\n", a % b); // We use %% to print a literal %
    
    // Increment
    a++; // Now a is 11
    printf("After a++, a is: %d\n", a);

    // --- 2. Relational Operators ---
    printf("\n--- Relational (1 is True, 0 is False) ---\n");
    printf("Is a equal to b? (a == b): %d\n", a == b);
    printf("Is a greater than b? (a > b): %d\n", a > b);
    printf("Is a not equal to b? (a != b): %d\n", a != b);

    // --- 3. Logical Operators ---
    printf("\n--- Logical ---\n");
    int haveTicket = 1; // 1 means true
    int haveID = 0;     // 0 means false
    
    // AND (requires BOTH to be true)
    printf("Can I fly? (haveTicket && haveID): %d\n", haveTicket && haveID);
    
    // OR (requires ONLY ONE to be true)
    printf("Do I have SOMETHING? (haveTicket || haveID): %d\n", haveTicket || haveID);
    
    // NOT (reverses the truth value)
    printf("Do I NOT have an ID? (!haveID): %d\n", !haveID);
    
    // --- 4. Assignment Operators ---
    int score = 50;
    score += 10; // score = score + 10
    printf("\nAfter score += 10, bonus score is: %d\n", score);

    return 0;
}
