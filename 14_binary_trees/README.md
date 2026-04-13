# Lesson 14: Binary Trees

Until now, our data structures (Arrays, Linked Lists, Stacks, Queues) have been **Linear**, meaning you traverse them in a straight line from start to finish.

**Trees** are **Hierarchical** data structures. They branch out!

## The Binary Tree Node
A Linked List node holds `Data` and a pointer to the `Next` node.
A Binary Tree node holds `Data`, and TWO pointers: one to the `Left` child, and one to the `Right` child.

```c
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
```

## Binary Search Tree (BST)
To make trees powerful, we use rules. A **Binary Search Tree** ensures that:
- Every node placed in the **left** subtree is strictly *smaller* than the parent.
- Every node placed in the **right** subtree is strictly *larger* than the parent.

**Why is this amazing?**
If you have a perfectly balanced Tree with 1,000,000 numbers in it, and you are searching for the number `42,000`:
- In an Array or Linked List, you might have to check all 1,000,000 numbers sequentially.
- In a Binary Search Tree, every single time you navigate left or right, you eliminate *half* of the remaining numbers! It only takes maximum **20** steps to find any number in a 1,000,000 element Tree. This is known as `O(log n)` time complexity!

## Recursion
Because Trees branch exponentially, we cannot easily use a standard `while` loop to navigate them. 
Instead, we use **Recursion**—functions that call themselves entirely anew for the left branch, and again for the right branch.

Look at `main.c` to see recursion in action!
