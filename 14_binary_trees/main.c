#include <stdio.h>
#include <stdlib.h>

// 1. Defining the Tree Node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


// 2. Creating a new node dynamically
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


// 3. Inserting cleanly using the Binary Search Tree algorithm via RECURSION
TreeNode* insert(TreeNode* root, int data) {
    // If we've reached a dead end, pop the new node here!
    if (root == NULL) {
        return createNode(data);
    }
    
    // If data is smaller, go down the LEFT path
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is larger, go down the RIGHT path
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root; 
}


// 4. Inorder Traversal (Left -> Root -> Right)
// In a Binary Search tree, this beautifully prints the nodes in perfectly sorted order!
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);     // Visit left children first
        printf("%d ", root->data);        // Print the data
        inorderTraversal(root->right);    // Visit right children last
    }
}


int main() {
    printf("--- Building a Binary Search Tree (BST) ---\n");
    TreeNode* root = NULL;
    
    /* 
    Let's build this tree:
              50
           /     \
         30       70
        /  \     /  \
      20   40   60   80 
    */
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // If we traverse it "In Order", it should automatically be completely sorted!
    printf("Sorted Output using Inorder Traversal: \n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
