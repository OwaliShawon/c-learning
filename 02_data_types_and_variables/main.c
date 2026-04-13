#include <stdio.h>

int main() {
    // 1. Integer (Whole numbers)
    int age = 28;
    int year = 2026;

    // 2. Floating-point (Decimals)
    float pi = 3.14f; // 'f' indicates it's a single-precision float
    
    // 3. Double (More precise decimals)
    double speedOfLight = 299792458.0;

    // 4. Character (Single character in single quotes)
    char grade = 'A';

    // Printing variables using Format Specifiers:
    // %d prints integers
    printf("My age is %d and the current year is %d.\n", age, year);

    // %f prints floats. You can restrict decimal places like %.2f
    printf("Value of pi is approx %.2f.\n", pi);

    // %lf prints doubles. 
    printf("Speed of light is exactly %.1lf m/s.\n", speedOfLight);

    // %c prints a single character
    printf("My final grade was %c.\n", grade);

    // Let's change a variable's value and print it again
    age = 29;
    printf("Next year, I will be %d.\n", age);

    return 0;
}
