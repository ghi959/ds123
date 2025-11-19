/* Write a program to represent the given graph using adjacency linked list and implement Breadth-First Search Traversal for a given Graph. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node { int v; struct Node *next; };
struct Node *adj[MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;

/* enqueue */
void enqueue(int x) { queue[++rear] = x; }
/* dequeue */
int dequeue() { return queue[front++]; }

/* add edge */
void addEdge(int u, int v) {
    struct Node *n = malloc(sizeof *n);
    n->v = v; n->next = adj[u]; adj[u] = n;
}

void bfs(int start) {
    visited[start] = 1;
    enqueue(start);

    while (front <= rear) {
        int x = dequeue();
        printf("%d ", x);
        struct Node *p = adj[x];
        while (p) {
            if (!visited[p->v]) {
                visited[p->v] = 1;
                enqueue(p->v);
            }
            p = p->next;
        }
    }
}

int main() {
    int n, e;
    printf("Number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Start vertex: ");
    scanf("%d", &start);

    bfs(start);
    return 0;
}
