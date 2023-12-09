#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value);
int dequeue();
int getFront();
int getRear();
bool isEmpty();
bool isFull();
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
            if (value != -1)
            {
                printf("Dequeued %d from the queue\n", value);
            }
            break;
        case 3:
            value = getFront();
            if (value != -1)
            {
                printf("Front element is %d\n", value);
            }
            break;
        case 4:
            value = getRear();
            if (value != -1)
            {
                printf("Rear element is %d\n", value);
            }
            break;
        case 5:
            printf("Queue is %s\n", isEmpty() ? "empty" : "not empty");
            break;
        case 6:
            printf("Queue is %s\n", isFull() ? "full" : "not full");
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

void enqueue(int value)
{
    if (isFull())
    {
        printf("Error: Queue overflow!\n");
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
    if (front == -1)
    {
        front = 0;
    }
    printf("Enqueued %d to the queue\n", value);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Error: Queue underflow!\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
    return value;
}

int getFront()
{
    if (isEmpty())
    {
        printf("Error: Queue underflow!\n");
        return -1;
    }
    return queue[front];
}

int getRear()
{
    if (isEmpty())
    {
        printf("Error: Queue underflow!\n");
        return -1;
    }
    return queue[rear];
}

bool isEmpty()
{
    return front == -1 && rear == -1;
}

bool isFull()
{
    return (front == 0 && rear == MAX_SIZE - 1) || (rear + 1) % MAX_SIZE == front;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
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
Enter the value to be enqueued: 52
Enqueued 52 to the queue
1. Enqueue
2. Dequeue
3. Front
4. Rear
5. IsEmpty
6. IsFull
7. Display
8. Exit
Enter your choice: 7
Queue: 52
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