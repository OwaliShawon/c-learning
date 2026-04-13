# Lesson 6: Arrays and Strings

So far, every variable we've declared has only held a single value. But what if we need to store 100 integer scores or an entire paragraph of text? This is where **Arrays** and **Strings** come in!

## 1. Arrays
An array is a collection of variables of the **same type** stored in contiguous memory locations.

```c
// Declaring an array that holds 5 integers
int scores[5];

// Initializing the array with values
int numbers[5] = {10, 20, 30, 40, 50};
```

**Key rules of arrays in C:**
1. **Zero-Indexed**: The first element is at index `0`. The last element is at index `n-1`. For an array of size 5, the valid indices are `0, 1, 2, 3, 4`.
2. **Fixed Size**: Once an array is declared with a specific size, you cannot change its size in standard C.
3. **No Bounds Checking**: If you try to access `scores[100]`, C won't stop you! It will just access garbage data in memory or crash your program. **Be careful!**

## 2. Strings (Character Arrays)
In many programming languages, `String` is a built-in data type. **In C, there is no String data type!** 
A string in C is just an **array of characters** that ends with a special "null terminator" character `\0`.

```c
// A string is just a char array!
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

// A much easier shorthand:
char name[] = "John"; // The null terminator '\0' is added automatically!
```

### The Null Terminator `\0`
The compiler needs to know where the text ends in memory, because arrays don't actually track their own length! The `\0` character acts as a stop sign. If you create a char array but forget the `\0`, printing it as a string (`%s`) will print garbage characters until it accidentally hits a zero in memory.

Check out `main.c` to see how we traverse arrays and print strings!
