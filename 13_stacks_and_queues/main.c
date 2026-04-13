#include <stdio.h>
#include <stdlib.h>

// Standard linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// --- STACK IMPLEMENTATION (LIFO) ---

// PUSH: Add to the top
void push(Node** topRef, int new_data) {
    // 1. Ask OS for memory
    Node* new_node = (Node*) malloc(sizeof(Node));
    
    // 2. Put data in
    new_node->data = new_data;
    
    // 3. Make this new node point down to the old top
    new_node->next = (*topRef);
    
    // 4. Update the official "top" pointer to point to this new node
    (*topRef) = new_node;
    
    printf("Pushed %d onto the stack.\n", new_data);
}

// POP: Remove from the top
int pop(Node** topRef) {
    if (*topRef == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1; 
    }
    
    // 1. Grab the top node
    Node* temp = *topRef;
    
    // 2. Update the official "top" to be the next one down
    *topRef = (*topRef)->next;
    
    // 3. Extract the data
    int popped_data = temp->data;
    
    // 4. FREE the memory back to OS!
    free(temp);
    
    printf("Popped %d from the stack.\n", popped_data);
    return popped_data;
}

void printStack(Node* top) {
    printf("Current Stack (Top -> Bottom): ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- LIFO Stack Demonstration ---\n");
    // Start with an empty stack
    Node* stackTop = NULL;

    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    
    printStack(stackTop); // Should print 30 -> 20 -> 10 -> NULL
    
    pop(&stackTop);       // Should remove 30
    
    printStack(stackTop); // Should print 20 -> 10 -> NULL
    
    // Clean up remaining memory before exiting
    pop(&stackTop);
    pop(&stackTop);
    pop(&stackTop); // Will trigger underflow!

    return 0;
}
