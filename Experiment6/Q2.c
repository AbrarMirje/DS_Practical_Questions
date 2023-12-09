#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Doubly Linked List structure
struct DoublyLinkedList
{
    struct Node *head;
    struct Node *tail;
};

// Function prototypes
struct Node *createNode(int data);
void createDoublyLinkedList(struct DoublyLinkedList *list, int elements[], int size);
void insertAtEnd(struct DoublyLinkedList *list, int data);
void insertAtBeginning(struct DoublyLinkedList *list, int data);
void deleteNode(struct DoublyLinkedList *list, int key);
void traverseForward(struct DoublyLinkedList *list);
void traverseBackward(struct DoublyLinkedList *list);

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
    newNode->prev = NULL;
    return newNode;
}

// Function to create a doubly linked list from an array of elements
void createDoublyLinkedList(struct DoublyLinkedList *list, int elements[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insertAtEnd(list, elements[i]);
    }
}

// Function to insert a new Node at the end of the doubly linked list
void insertAtEnd(struct DoublyLinkedList *list, int data)
{
    struct Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
}

// Function to insert a new Node at the beginning of the doubly linked list
void insertAtBeginning(struct DoublyLinkedList *list, int data)
{
    struct Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
}

// Function to delete a Node with a given key from the doubly linked list
void deleteNode(struct DoublyLinkedList *list, int key)
{
    struct Node *current = list->head;

    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with key %d not found in the doubly linked list.\n", key);
        return;
    }

    if (current->prev)
    {
        current->prev->next = current->next;
    }
    else
    {
        list->head = current->next;
    }

    if (current->next)
    {
        current->next->prev = current->prev;
    }
    else
    {
        list->tail = current->prev;
    }

    free(current);
}

// Function to traverse and print the doubly linked list forward
void traverseForward(struct DoublyLinkedList *list)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse and print the doubly linked list backward
void traverseBackward(struct DoublyLinkedList *list)
{
    struct Node *current = list->tail;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Main function for testing
int main()
{
    struct DoublyLinkedList doublyLinkedList;
    doublyLinkedList.head = NULL;
    doublyLinkedList.tail = NULL;

    // Creation
    int elements[] = {1, 2, 3, 4, 5};
    int size = sizeof(elements) / sizeof(elements[0]);
    createDoublyLinkedList(&doublyLinkedList, elements, size);

    // Traversal forward
    printf("Doubly Linked List (Forward): ");
    traverseForward(&doublyLinkedList);

    // Traversal backward
    printf("Doubly Linked List (Backward): ");
    traverseBackward(&doublyLinkedList);

    // Insertion at the beginning
    insertAtBeginning(&doublyLinkedList, 0);
    printf("After insertion at the beginning: ");
    traverseForward(&doublyLinkedList);

    // Deletion
    deleteNode(&doublyLinkedList, 3);
    printf("After deleting node with value 3: ");
    traverseForward(&doublyLinkedList);

    return 0;
}

/*
Output:
Doubly Linked List (Forward): 1 2 3 4 5
Doubly Linked List (Backward): 5 4 3 2 1
After insertion at the beginning: 0 1 2 3 4 5
After deleting node with value 3: 0 1 2 4 5
*/
