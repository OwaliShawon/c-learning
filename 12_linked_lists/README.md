# Lesson 12: Linked Lists

Welcome to Parts 4: **Data Structures**. So far, when we needed a list of items, we used an Array. But arrays suffer from critical limitations:
1. They require contiguous chunks of memory (hard to find for huge arrays).
2. Inserting an item in the middle requires shifting every single subsequent item over by one index (extremely slow).
3. They cannot easily grow or shrink without `realloc`.

**Linked Lists** solve all of this by breaking the data apart!

## The Concept of a Node
A Linked List is a chain of `Node` structs. Every Node contains two things:
1. The **Data** (e.g., an integer).
2. A **Pointer** to the *next* Node in the chain.

Because each Node physically knows where the next one lives in memory, they can be scattered anywhere in the computer's RAM!

## Defining a Node in C
```c
// We must name the struct so the pointer inside knows what to point to!
typedef struct Node {
    int data;
    struct Node* next; // Pointer to the next node in the chain
} Node;
```

## Traversing a List
Because there is no index, you cannot quickly access `List[5]`. Instead, you must start at the the very first node (the `head`) and follow the pointers down the chain until you reach your destination.
The final Node in the chain will have a `next` pointer pointing to `NULL`, telling us the list is over!

Check out `main.c` where we will dynamically spawn Nodes on the Heap and chain them together!
