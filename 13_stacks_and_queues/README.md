# Lesson 13: Stacks and Queues

Using the basic Linked List structure from the last lesson, we can create strictly governed Data Structures by artificially limiting how data is added or removed.

## 1. Stacks (LIFO)
A Stack follows **LIFO** (Last In, First Out). Think of a stack of plates in a cafeteria:
- **Push**: You put a new plate on top of the pile.
- **Pop**: To get a plate, you must take the one right off the very top.
- **Peek**: You just look at the top plate without removing it.

In computer science, algorithms like "Undo" (Ctrl+Z) and your web browser's "Back" button use Stacks!

## 2. Queues (FIFO)
A Queue follows **FIFO** (First In, First Out). Think of a line at a grocery store:
- **Enqueue**: You join the back of the line.
- **Dequeue**: The cashier serves the person at the very front of the line.

In computer systems, network packet handling, printer jobs, and background tasks are all handled using Queues!

## Implementation
Both can be built perfectly using Linked Lists. 
- For a **Stack**, you just write logic that forces all new Nodes to be injected at the `head`, and removed from the `head`.
- For a **Queue**, you keep two pointers: one pointing to the `head` (for removal), and one to the `tail` (for adding new Nodes to the back).

Let's investigate how to build a basic Stack in `main.c`!
