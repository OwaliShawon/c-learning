#include <stdio.h>
#include <stdlib.h>

// Define our Node structure
typedef struct Node {
    int data;
    struct Node* next; // Recursively points to the same struct type
} Node;

// Function to print the entire linked list
void printList(Node* node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next; // Move the pointer to the next node in the chain
    }
    printf("NULL\n");
}

int main() {
    // 1. Create the pointers for our new nodes
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // 2. Dynamically allocate memory for the nodes on the Heap
    head = (Node*) malloc(sizeof(Node));
    second = (Node*) malloc(sizeof(Node));
    third = (Node*) malloc(sizeof(Node));

    // Check if allocation failed
    if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 3. Populate head node and link it
    head->data = 10;
    head->next = second; // Pointing to the physical memory of 'second'

    // 4. Populate second node and link it
    second->data = 20;
    second->next = third; // Pointing to the physical memory of 'third'

    // 5. Populate third node and terminate the list
    third->data = 30;
    third->next = NULL; // NULL tells our while-loop to stop!

    // Print the chained list
    printList(head);

    // 6. Free the dynamically allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
