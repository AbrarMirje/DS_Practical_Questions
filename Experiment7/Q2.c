#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function prototypes
struct TreeNode *insert(struct TreeNode *root, int key);
struct TreeNode *deleteNode(struct TreeNode *root, int key);
struct TreeNode *minValueNode(struct TreeNode *node);
void display(struct TreeNode *root);

// Function to create a new node
struct TreeNode *createNode(int key)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into a BST
struct TreeNode *insert(struct TreeNode *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to delete a node with a given key from a BST
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct TreeNode *temp = minValueNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to find the node with the minimum key value
struct TreeNode *minValueNode(struct TreeNode *node)
{
    struct TreeNode *current = node;

    // Find the leftmost leaf
    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Function to display the BST in-order
void display(struct TreeNode *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

// Main function for testing
int main()
{
    struct TreeNode *root = NULL;

    // Insertion
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display
    printf("Binary Search Tree (In-order): ");
    display(root);
    printf("\n");

    // Deletion
    root = deleteNode(root, 20);
    printf("After deleting 20: ");
    display(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("After deleting 30: ");
    display(root);
    printf("\n");

    return 0;
}

/*
Output:
Binary Search Tree (In-order): 20 30 40 50 60 70 80
After deleting 20: 30 40 50 60 70 80
After deleting 30: 40 50 60 70 80
*/
