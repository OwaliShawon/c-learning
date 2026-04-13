#include <stdio.h>
#include <unistd.h> // POSIX standard: required for fork() and getpid()
#include <sys/wait.h> // Required for wait()

int main() {
    printf("--- Spawning Processes with fork() ---\n");
    printf("Original Program Started. Process ID: %d\n", getpid());
    
    // Create a clone! Everything below this line will be executed TWICE simultaneously.
    pid_t process_id = fork();

    if (process_id < 0) {
        printf("Fork failed!\n");
        return 1;
    } 
    else if (process_id == 0) {
        // Child Process Block
        printf("[CHILD] Hello! I am the clone. My PID is: %d\n", getpid());
        printf("[CHILD] My Parent's PID is: %d\n", getppid());
        printf("[CHILD] I am doing child work now... done!\n");
    } 
    else {
        // Parent Process Block
        printf("[PARENT] I am the original. My PID is: %d\n", getpid());
        printf("[PARENT] I successfully spawned a child with PID: %d\n", process_id);
        
        // Wait for the child to finish so we don't accidentally exit early
        printf("[PARENT] Waiting for child to finish...\n");
        wait(NULL); 
        printf("[PARENT] Child finished! Parent exiting now.\n");
    }

    // Both processes will eventually reach this return statement!
    return 0;
}
