/* Write a program to represent the given graph using adjacency matrix and implement Depth First Search Traversal for a given graph */
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];

/* DFS recursive */
void dfs(int v, int n) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i, n);
}

int main() {
    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &start);

    dfs(start, n);
    return 0;
}
