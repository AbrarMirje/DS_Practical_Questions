#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// A function to push an element to the top of the stack
void push(int value)
{
    // Check if the stack is full
    if (top == SIZE - 1)
    {
        printf("Error: Stack overflow!\n");
        return;
    }

    stack[++top] = value;
    printf("Pushed %d to the stack\n", value);
}

// A function to pop an element from the top of the stack and return its value
int pop()
{
    if (top == -1)
    {
        printf("Error: Stack underflow!\n");
        return INT_MIN;
    }
    return stack[top--];
}

// A function to return the value of the top element without popping it
int peek()
{
    if (top == -1)
    {
        printf("Error: Stack underflow!\n");
        return INT_MIN;
    }
    return stack[top];
}

// A function to check if the stack is empty or not
int isEmpty()
{
    // Return 1 if the top is -1, 0 otherwise
    return top == -1;
}

// A function to display the values of all the elements in the stack
void display()
{
    // Check if the stack is empty
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    // Print a message
    printf("Stack: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// The main function
int main()
{
    int choice, value;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. IsEmpty\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Push
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2: // Pop

            value = pop();
            // Check if the stack was not empty
            if (value != INT_MIN)
            {
                // Print the popped value
                printf("Popped %d from the stack\n", value);
            }
            break;
        case 3: // Peek
            // Peek the value from the stack and store it
            value = peek();
            // Check if the stack was not empty
            if (value != INT_MIN)
            {
                // Print the peeked value
                printf("Peeked %d from the stack\n", value);
            }
            break;
        case 4: // IsEmpty
            // Check if the stack is empty or not and print the result
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
            // Display the values of the stack
            display();
            break;
        case 6: // Exit
            // Print a message and exit the loop
            printf("Exiting the program\n");
            exit(0);
        default: // Invalid choice
            // Print a message and continue the loop
            printf("Invalid choice, please try again\n");
        }
    }
    // Return 0 to indicate normal termination
    return 0;
}

/*
Output:
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Exit
Enter your choice: 1
Enter the value to be pushed: 25
Pushed 25 to the stack
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Exit
Enter your choice: 1
Enter the value to be pushed: 65
Pushed 65 to the stack
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Exit
Enter your choice: 5
Stack: 65 25
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Exit
Enter your choice: 2
Popped 65 from the stack
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Exit
Enter your choice: 5
Stack: 25
1. Push
2. Pop
3. Peek
4. IsEmpty
5. Display
6. Exit
Enter your choice: 6
Exiting the program
*/