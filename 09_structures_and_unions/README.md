# Lesson 9: Structures and Unions

Unlike arrays that can only hold elements of the *same* type, **Structures** and **Unions** allow you to group *different* variable types under a single name. This is C's version of building custom objects!

## 1. Structs
A `struct` allocates separate memory for every single member inside of it.
For example, if you are building an RPG game, you might want a `Player` data type that holds their HP (integer), their name (string), and their score (float).

```c
struct Player {
    char name[50];
    int hp;
    float score;
};

// Declaring a player variable:
struct Player player1;
player1.hp = 100;
```

### The `typedef` Keyword
Writing `struct Player` every time you declare a variable is annoying. We use `typedef` to assign a shorter alias!
```c
typedef struct {
    int x;
    int y;
} Point;

// Now you can just use 'Point' as the type!
Point p1; 
p1.x = 10;
```

## 2. Unions
A `union` looks identical to a `struct`, but with one massive difference: **all its members share the exact SAME memory location!** 

Because memory is shared, a Union can only store a value in *one* of its members at any given time. If you update the Integer member, the Float member gets instantly overwritten.

**Why use this?**
Unions are heavily used in low-level programming to save memory. For instance, if a network packet can either contain an `int error_code` OR a `float data_value`, but never both simultaneously, a Union ensures exactly enough memory is reserved for the largest type, rather than wasting memory allocating both.

Check `main.c` to see how we assign variables inside Structs and Unions!
