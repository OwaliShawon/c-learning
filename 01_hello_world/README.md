# Lesson 1: Hello World in C

Welcome to the first lesson in C programming! In this lesson, we will write our first program and understand its structure.

## The Anatomy of a C Program
In the `main.c` file, you will observe the fundamental structure of every C program:

1. **`#include <stdio.h>`** 
   - This is an **include directive**. 
   - `#include` tells the compiler to grab extra code from a header file library.
   - `<stdio.h>` stands for **St**andard **I**nput **O**utput. It contains the instructions that let you take input from the keyboard and output content (like text) to the terminal screen.

2. **`int main()`**
   - This is the **main function**. 
   - The execution of any C program always begins at `main()`. Every C program must have one!
   - `int` means that the function will return an integer value back to the operating system once it finishes.

3. **`{ ... }`**
   - The curly braces mark the beginning and end of a unit of code (a "block"). Everything inside these braces belongs to `main()`.

4. **`printf("Hello, World!\n");`**
   - `printf` is a built-in function to print text to the screen (defined in `<stdio.h>`).
   - The `\n` at the end makes the cursor jump to the **next line**, so the output looks clean.
   - Notice the **semicolon (`;`)** at the end. Every statement in C must end with a semicolon!

5. **`return 0;`**
   - We end our `main` function with `return 0`. By convention, returning `0` tells the operating system that your program executed successfully without any errors.

## How to run it:
Open your terminal, navigate to this folder (`01_hello_world`) and run the following commands:
```bash
# 1. Compile the code 
gcc main.c -o hello

# 2. Run the compiled executable
./hello
```
