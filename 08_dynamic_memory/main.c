#include <stdio.h>
#include <stdlib.h> // IMPORTANT: Required for malloc, calloc, realloc, and free

int main() {
    printf("--- 1. Malloc (Dynamic Array Allocation) ---\n");
    
    int size = 3; 
    
    // We are asking for memory to hold 3 integers (12 bytes usually)
    // malloc returns a void pointer, so we cast it to (int*)
    int* ptr = (int*) malloc(size * sizeof(int));
    
    // ALWAYS check if malloc worked. If your PC is out of RAM, it returns NULL!
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit program with error code
    }

    // Now 'ptr' acts EXACTLY like a standard array
    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;

    printf("Dynamically stored values:\n");
    for (int i = 0; i < size; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }

    
    printf("\n--- 2. Realloc (Resizing the array dynamically!) ---\n");
    // What if 3 integers wasn't enough? Let's grow it to 5!
    size = 5;
    ptr = (int*) realloc(ptr, size * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // The old values are intact! Let's fill the new spaces.
    ptr[3] = 400;
    ptr[4] = 500;

    printf("After reallocating to 5 elements:\n");
    for (int i = 0; i < size; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }


    printf("\n--- 3. Free (Preventing Memory Leaks) ---\n");
    // We are done with this dynamic memory. We MUST return it to the OS.
    free(ptr);
    
    // Good practice: nullify the pointer so we don't accidentally use it later
    ptr = NULL; 
    printf("Memory successfully freed and handed back to the OS!\n");

    return 0;
}
