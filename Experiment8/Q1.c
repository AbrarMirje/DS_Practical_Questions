#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Node structure for the adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Graph structure using adjacency list
struct Graph
{
    int numVertices;
    struct Node *adjList[MAX_VERTICES];
};

// Function prototypes
struct Node *createNode(int data);
struct Graph *createGraph(int vertices);
void addEdge(struct Graph *graph, int src, int dest);
void DFS(struct Graph *graph, int startVertex, int visited[]);
void BFS(struct Graph *graph, int startVertex);

// Function to create a new node
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

// Function to create a graph with a given number of vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (because it's an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform depth-first search (DFS) on a graph
void DFS(struct Graph *graph, int startVertex, int visited[])
{
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    struct Node *temp = graph->adjList[startVertex];
    while (temp != NULL)
    {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
        {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform breadth-first search (BFS) on a graph
void BFS(struct Graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    printf("%d ", startVertex);
    queue[++rear] = startVertex;

    while (front <= rear)
    {
        int currentVertex = queue[front++];
        struct Node *temp = graph->adjList[currentVertex];

        while (temp != NULL)
        {
            int adjVertex = temp->data;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                printf("%d ", adjVertex);
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// Main function for testing
int main()
{
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    int visited[MAX_VERTICES] = {0};
    DFS(graph, startVertex, visited);
    printf("\n");

    printf("BFS Traversal: ");
    BFS(graph, startVertex);
    printf("\n");

    return 0;
}

/*
Output:
Enter the number of vertices: 5
Enter the number of edges: 3
Enter the edges (source destination):
6
1
5
69
12
46
Enter the starting vertex for traversal: 5
DFS Traversal: 5 69
*/