//Write a program to find out DFS

#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = -1;
int rear = -1;

// BFS function
void BFS(int start, int vertices)
{
    int i;
    int current;

    // Insert starting vertex into queue
    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear)
    {
        current = queue[++front];

        printf("%d ", current);

        // Check all adjacent vertices
        for (i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 &&
                visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int vertices, i, j;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    for (i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");

    BFS(start, vertices);

    return 0;
}
