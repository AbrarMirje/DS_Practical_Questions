#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Linked List structure
struct LinkedList
{
    struct Node *head;
};

// Function prototypes
struct Node *createNode(int data);
void createLinkedList(struct LinkedList *list, int elements[], int size);
void insertAtEnd(struct LinkedList *list, int data); // Function prototype
void insertAtBeginning(struct LinkedList *list, int data);
void deleteNode(struct LinkedList *list, int key);
void traverse(struct LinkedList *list);

// Function to create a new Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from an array of elements
void createLinkedList(struct LinkedList *list, int elements[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insertAtEnd(list, elements[i]);
    }
}

// Function to insert a new Node at the end of the linked list
void insertAtEnd(struct LinkedList *list, int data)
{
    struct Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }

    struct Node *current = list->head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

// Function to insert a new Node at the beginning of the linked list
void insertAtBeginning(struct LinkedList *list, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to delete a Node with a given key from the linked list
void deleteNode(struct LinkedList *list, int key)
{
    struct Node *current = list->head;
    struct Node *prev = NULL;

    if (current != NULL && current->data == key)
    {
        list->head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with key %d not found in the linked list.\n", key);
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to traverse and print the linked list
void traverse(struct LinkedList *list)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function for testing
int main()
{
    struct LinkedList linkedList;
    linkedList.head = NULL;

    // Creation
    int elements[] = {1, 2, 3, 4, 5};
    int size = sizeof(elements) / sizeof(elements[0]);
    createLinkedList(&linkedList, elements, size);

    // Traversal
    printf("Linked List: ");
    traverse(&linkedList);

    // Insertion at the beginning
    insertAtBeginning(&linkedList, 0);
    printf("After insertion at the beginning: ");
    traverse(&linkedList);

    // Deletion
    deleteNode(&linkedList, 3);
    printf("After deleting node with value 3: ");
    traverse(&linkedList);

    return 0;
}

/*
Output:
Linked List: 1 2 3 4 5
After insertion at the beginning: 0 1 2 3 4 5
After deleting node with value 3: 0 1 2 4 5
*/