# Lesson 5: Functions

As programs grow, writing all code inside `main()` becomes impossible. **Functions** allow you to break your program into smaller, reusable blocks of code.

## The Anatomy of a Function
A function consists of two parts in C: its **declaration (prototype)** and its **definition**.

### 1. Function Declaration (Prototype)
C is a top-down language. If `main()` tries to use a function before the compiler has seen it, you'll get an error! To prevent this, we declare the function *above* `main()`. A declaration tells the compiler: "Hey, there's a function with this name, it takes these inputs, and returns this type of value."

```c
// ReturnType FunctionName(InputType variableName);
int addNumbers(int a, int b);
```

### 2. Function Definition
This is the actual body of the function, which can be placed anywhere (usually below `main()`).

```c
int addNumbers(int a, int b) {
    int sum = a + b;
    return sum; // The return value MUST match the ReturnType (int)
}
```

### 3. Void Functions
If a function does not return any value back to where it was called, its return type is `void`.
```c
void printHello() {
    printf("Hello!\n");
    // No return statement necessary!
}
```

## Scope
Variables created inside a function are "local" to that function. `main()` cannot access variables created inside `addNumbers()`, and vice versa. This is known as **Variable Scope**.

Check `main.c` to see how we define, declare, and call functions!
