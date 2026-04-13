#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 100

int main() {
    char input[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS];

    printf("Welcome to C-Shell v1.0!\n");
    printf("Type 'exit' to quit.\n\n");

    // The infinite loop of a Terminal Shell
    while (1) {
        // 1. Prompt
        printf("c-shell> ");
        
        // 2. Read the user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue; // Ignore empty presses
        }

        // Remove the trailing newline character that fgets captures
        input[strcspn(input, "\n")] = 0;

        // Check if user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("Shutting down shell...\n");
            break;
        }

        // 3. Parse: Split the string by spaces into an array of pointers
        int arg_count = 0;
        char* token = strtok(input, " ");
        while (token != NULL) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL; // execvp requires the argument array to be perfectly NULL-terminated

        if (arg_count == 0) continue; // If they just hit enter randomly

        // 4. Execute: Spawn a child process to run the command!
        pid_t pid = fork();

        if (pid < 0) {
            printf("Fork failed!\n");
        } 
        else if (pid == 0) {
            // Child process block: Mutate into the new program
            // execvp parameters: (Name of program, Array of arguments)
            if (execvp(args[0], args) < 0) {
                // If execvp fails, it means the command doesn't exist!
                printf("c-shell: command not found: %s\n", args[0]);
            }
            exit(1); // Kill the child firmly if execvp failed
        } 
        else {
            // Parent process block: Wait for the child program to finish running
            wait(NULL);
        }
    }

    return 0;
}
