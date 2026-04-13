# Lesson 18: Advanced Systems - Building a Custom Shell

Welcome to **Part 6**. 
Everything we've learned—Pointers, Arrays, Strings, Loops, and Processes—comes together here safely to build a **Custom Shell**!

## What is a Terminal Shell?
When you type `ls -l` or `mkdir folder` into your Mac/Linux terminal, you are interacting with a Shell program (like Bash or Zsh). 
A Shell is just a very simple infinite `while` loop written in C!

The loop does four things:
1. **Prompt**: Print a prompt like `MyShell> `.
2. **Read**: Use `fgets()` to get text input from the user.
3. **Parse**: Split the string input by spaces into an Array of arguments (using `strtok()`).
4. **Execute**: Use `fork()` to spawn a child process. The child process uses `execvp()` to magically transform itself into the command the user typed (like the `ls` program), while the Parent uses `wait()` until the command is done running!

## The `execvp()` family
The `exec` system call replaces the current running process with a brand new program located on the hard drive.
For example, if you call `execvp("ls", args)`, your running C program instantly vaporizes from memory, and the physical OS `ls` program completely replaces it.
This is why we MUST `fork()` a child first! If the Parent called `execvp`, our Shell would instantly delete itself and become the `ls` program. We want the child to mutate into `ls`, while the Parent waits comfortably for the child to finish!

Explore `main.c` to see how we build our own terminal!
