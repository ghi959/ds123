/* Write a program to represent the given graph using adjacency linked list and implement Depth First Search Traversal for a given graph. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node { int v; struct Node *next; };
struct Node *adj[MAX];
int visited[MAX];

/* add edge u->v */
void addEdge(int u, int v) {
    struct Node *n = malloc(sizeof *n);
    n->v = v; n->next = adj[u];
    adj[u] = n;
}

/* DFS recursive */
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node *p = adj[v];
    while (p) {
        if (!visited[p->v])
            dfs(p->v);
        p = p->next;
    }
}

int main() {
    int n, e;
    printf("Vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) adj[i] = NULL;

    printf("Edges: ");
    scanf("%d", &e);

    printf("Enter edges u v:\n");
    for (int i = 0; i < e; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Start: ");
    scanf("%d", &start);

    dfs(start);
    return 0;
}
