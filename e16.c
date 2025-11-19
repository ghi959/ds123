/* Write a program to represent the given graph using adjacency matrix and implement Breadth-First Search Traversal for a given Graph. */
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;

/* enqueue */
void enqueue(int x) { queue[++rear] = x; }

/* dequeue */
int dequeue() { return queue[front++]; }

/* BFS starting from given source */
void bfs(int v, int n) {
    visited[v] = 1;
    enqueue(v);

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    printf("Enter start vertex: ");
    scanf("%d", &start);

    bfs(start, n);
    return 0;
}
