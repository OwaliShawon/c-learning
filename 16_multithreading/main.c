#include <stdio.h>
#include <pthread.h> // POSIX Threads Library
#include <unistd.h>  // For sleep()

// A shared global variable between our threads!
int shared_counter = 0;

// Mutex lock to protect our shared variable
pthread_mutex_t lock;

// The function that our threads will execute in parallel
void* incrementCounter(void* threadID) {
    long id = (long) threadID;

    printf("[Thread %ld] Booting up and starting work...\n", id);

    for (int i = 0; i < 5; i++) {
        // --- CRITICAL SECTION START ---
        // Grab the lock! If another thread has it, wait here until they drop it.
        pthread_mutex_lock(&lock);
        
        shared_counter++; // Safely update the shared variable
        printf("[Thread %ld] Incremented counter to: %d\n", id, shared_counter);
        
        // Drop the lock so the other thread can use the variable!
        pthread_mutex_unlock(&lock);
        // --- CRITICAL SECTION END ---
        
        // Sleep for a tiny fraction so we can visually see them taking turns
        usleep(10000); 
    }

    printf("[Thread %ld] Finished work!\n", id);
    return NULL;
}

int main() {
    printf("--- Multithreading and Mutexes ---\n");

    // Initialize our Mutex Lock
    pthread_mutex_init(&lock, NULL);

    pthread_t thread1, thread2;

    // Spawn Thread 1
    pthread_create(&thread1, NULL, incrementCounter, (void*)1);
    
    // Spawn Thread 2
    pthread_create(&thread2, NULL, incrementCounter, (void*)2);

    // main() would normally just exit and kill the program instantly.
    // We MUST tell main() to wait for both threads to finish!
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the Mutex Lock since we are done
    pthread_mutex_destroy(&lock);

    printf("Final shared counter value: %d\n", shared_counter);
    return 0;
}
