# Lesson 15: Processes and `fork()`

Welcome to **Part 5: System Level C**. We are now stepping outside the C language itself and interacting directly with the Unix/Linux Operating System using POSIX libraries (`<unistd.h>`).

## What is a Process?
When you compile and run a C program, it becomes a **Process** inside your Operating System. A Process is an instance of a running program. It has its own isolated memory space.

## Spawning Processes with `fork()`
In C, you can tell the Operating System to literally split your running program into TWO identical processes that run simultaneously! This is done using the `fork()` system call.

When you call `fork()`:
1. The OS pauses your program.
2. It makes an exact 1:1 clone of the entire program in memory.
3. Both programs resume executing from that exact line simultaneously!

### How do we tell them apart?
Because they are identical clones, we need a way to tell which one is the "Parent" (the original) and which one is the "Child" (the clone). 
`fork()` returns a **Process ID (PID)** integer:
- If `PID == 0`: "I am the Child process."
- If `PID > 0`: "I am the Parent process, and this number is my child's ID."
- If `PID < 0`: "The OS failed to create a clone."

## The `wait()` system call
Because the OS schedules processes independently, the Parent could finish executing before the Child does, creating a "Zombie" process. To prevent this, the Parent process often calls `wait(NULL)`, which tells it to pause and wait until all its children have finished executing before it continues.

Check out `main.c` to see two processes running at the exact same time!
