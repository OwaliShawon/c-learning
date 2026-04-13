# Lesson 16: Multithreading and Concurrency

In the last lesson, `fork()` created a fully isolated clone of our program, meaning the parent and child couldn't easily share variables because their memory was physically separated.

What if we want multiple tasks running at the exact same time, but we want them to *share* the same memory, arrays, and variables? We use **Threads**!

## `pthread.h` (POSIX Threads)
Threads are significantly lighter and faster to create than full Processes. 

```c
#include <pthread.h>

// 1. You define a function that the Thread will run. It must return void* and accept void*.
void* myThreadTask(void* args) {
    // Thread does work here...
    return NULL;
}

// 2. You spawn the thread
pthread_t threadID;
pthread_create(&threadID, NULL, myThreadTask, NULL);

// 3. You tell main() to wait for it to finish!
pthread_join(threadID, NULL);
```

## The Danger: Race Conditions
Because Threads run perfectly in parallel and share variables, what happens if Thread A and Thread B try to update `score += 10;` at the absolute exact millisecond?
They might both read the score as `50`, both add `10`, and both write `60`. The score should be `70`, but because they crashed into each other, we lost data! This is called a **Race Condition**.

## The Solution: Mutexes (Mutual Exclusion)
A Mutex is a lock. 
1. `pthread_mutex_lock()`: A thread reaches out and grabs the lock. If another thread already has the lock, this thread simply pauses entirely and waits!
2. `pthread_mutex_unlock()`: The thread finishes the safe math, and drops the lock for the next thread to grab.

Let's see threading in action in `main.c`!
