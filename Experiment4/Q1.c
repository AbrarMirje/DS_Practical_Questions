#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct node
{
    int data;
    struct node *next; // To store the pointer to the next node
};

// Declare a global pointer to the top of the stack
struct node *top = NULL;

// A function to create a new node and return its pointer
struct node *createNode(int data)
{
    // Allocate memory for the new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // Check if memory allocation was successful
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // Assign the data and the next pointer to the new node
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// A function to push a new node to the top of the stack
void push(int data)
{
    // Create a new node with the given data
    struct node *newNode = createNode(data);
    // Check if the stack is empty
    if (top == NULL)
    {
        top = newNode;
    }
    else
    {
        // Make the new node point to the current top of the stack
        newNode->next = top;
        top = newNode;
    }
    printf("Pushed %d to the stack\n", data);
}

// A function to pop a node from the top of the stack and return its data
int pop()
{
    int data;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        // Store the data of the top node
        data = top->data;
        // Store the pointer to the top node
        struct node *temp = top;
        // Make the next node the new top of the stack
        top = top->next;
        // Free the memory of the popped node
        free(temp);
        return data;
    }
}

// A function to return the data of the top node without popping it
int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        // Return the data of the top node
        return top->data;
    }
}

// A function to check if the stack is empty or not
int isEmpty()
{
    // Return 1 if the top pointer is NULL, 0 otherwise
    return top == NULL;
}

// A function to display the data of all the nodes in the stack
void display()
{
    // Declare a pointer to traverse the stack
    struct node *temp = top;
    // Check if the stack is empty
    if (temp == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");
        // Loop until the end of the stack
        while (temp != NULL)
        {
            // Print the data of the current node
            printf("%d ", temp->data);
            // Move to the next node
            temp = temp->next;
        }
        // Print a new line
        printf("\n");
    }
}

// A function to free the memory of the stack
void destroy()
{
    // Declare a pointer to store the top node
    struct node *temp;
    // Loop until the stack is empty
    while (top != NULL)
    {
        // Store the top node
        temp = top;
        // Move the top pointer to the next node
        top = top->next;
        // Free the memory of the node
        free(temp);
    }
    printf("Stack destroyed\n");
}

// A function to display the menu and return the user's choice
int menu()
{
    int choice;
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. IsEmpty\n");
    printf("5. Display\n");
    printf("6. Destroy\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// The main function
int main()
{
    int choice;
    int data;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1: // Push
            printf("Enter the data to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2: // Pop
            data = pop();
            if (data != -1)
            {
                printf("Popped %d from the stack\n", data);
            }
            break;
        case 3: // Peek
            data = peek();
            if (data != -1)
            {
                printf("Peeked %d from the stack\n", data);
            }
            break;
        case 4: // IsEmpty
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 5: // Display
            display();
            break;
        case 6: // Destroy
            destroy();
            break;
        case 7: // Exit
            printf("Exiting the program\n");
            break;
        default: // Invalid choice
            printf("Invalid choice, please try again\n");
            break;
        }
    } while (choice != 7); // Repeat until the user chooses to exit
    return 0;
}

/*
Output:
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Destroy
7. Exit
Enter your choice: 1
Enter the data to be pushed: 50
Pushed 50 to the stack
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Destroy
7. Exit
Enter your choice: 5
Stack: 50
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Destroy
7. Exit
Enter your choice: 6
Stack destroyed
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Destroy
7. Exit
Enter your choice: 5
Stack is empty
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Destroy
7. Exit
Enter your choice: 7
Exiting the program
*/