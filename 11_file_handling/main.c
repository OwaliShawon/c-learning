#include <stdio.h>

int main() {
    printf("--- 1. Writing to a File ---\n");
    
    // Open a file in "w" (write) mode. It will create it if it doesn't exist.
    FILE* filePointer = fopen("test.txt", "w");
    
    // Always check if the OS actually let us open it!
    if (filePointer == NULL) {
        printf("Failed to open file!\n");
        return 1;
    }

    // Write text into the file
    fprintf(filePointer, "Hello, Hard Drive!\n");
    fprintf(filePointer, "This is persistent data.\n");
    
    // We MUST close it to save changes and unlock it!
    fclose(filePointer);
    printf("Successfully wrote to test.txt and closed it.\n");


    printf("\n--- 2. Appending to a File ---\n");
    // Open in "a" (append) mode so we don't delete what we just wrote!
    filePointer = fopen("test.txt", "a");
    fprintf(filePointer, "This line is appended to the bottom!\n");
    fclose(filePointer);
    printf("Successfully appended text!\n");


    printf("\n--- 3. Reading from a File ---\n");
    // Open in "r" (read) mode.
    filePointer = fopen("test.txt", "r");
    if (filePointer == NULL) {
        printf("Could not find the file to read!\n");
        return 1;
    }

    char buffer[255]; // Temporary storage to hold the strings we read
    
    printf("Reading contents of test.txt:\n");
    printf("-----------------------------\n");
    
    // fgets reads one line at a time until the End of File (EOF)
    while (fgets(buffer, 255, filePointer) != NULL) {
        // Print the string we just read
        printf("%s", buffer);
    }
    
    printf("-----------------------------\n");
    
    // Don't forget to close!
    fclose(filePointer);

    return 0;
}
