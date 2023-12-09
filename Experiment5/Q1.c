#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int *front = NULL;
int *rear = NULL;

bool isFull();
bool isEmpty();
void enqueue(int value);
int dequeue();
int getFront();
int getRear();
void display();

int main()
{
    int choice, value;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. IsEmpty\n");
        printf("6. IsFull\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != INT_MIN)
            {
                printf("Dequeued %d from the queue\n", value);
            }
            break;
        case 3:
            value = getFront();
            if (value != INT_MIN)
            {
                printf("Front element is %d\n", value);
            }
            break;
        case 4:
            value = getRear();
            if (value != INT_MIN)
            {
                printf("Rear element is %d\n", value);
            }
            break;
        case 5:
            if (isEmpty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 6:
            if (isFull())
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting the program\n");
            exit(0);
        default:
            printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}

bool isFull()
{
    return rear == &queue[MAX_SIZE - 1];
}

bool isEmpty()
{
    return front == NULL && rear == NULL;
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Error: Queue overflow!\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = &queue[0];
    }
    else
    {
        rear++;
    }
    *rear = value;
    printf("Enqueued %d to the queue\n", value);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Error: Queue underflow!\n");
        return INT_MIN;
    }
    int value = *front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front++;
    }
    return value;
}

int getFront()
{
    if (isEmpty())
    {
        printf("Error: Queue underflow!\n");
        return INT_MIN;
    }
    return *front;
}

int getRear()
{
    if (isEmpty())
    {
        printf("Error: Queue underflow!\n");
        return INT_MIN;
    }
    return *rear;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int *i = front; i <= rear; i++)
    {
        printf("%d ", *i);
    }
    printf("\n");
}

/*
Output:
1. Enqueue
2. Dequeue
3. Front
4. Rear
5. IsEmpty
6. IsFull
7. Display
8. Exit
Enter your choice: 1
Enter the value to be enqueued: 25
Enqueued 25 to the queue
1. Enqueue
2. Dequeue
3. Front
4. Rear
5. IsEmpty
6. IsFull
7. Display
8. Exit
Enter your choice: 7
Queue: 25
1. Enqueue
2. Dequeue
3. Front
4. Rear
5. IsEmpty
6. IsFull
7. Display
8. Exit
Enter your choice: 8
Exiting the program
*/