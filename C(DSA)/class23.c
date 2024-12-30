// DFS and BFS traversal of graphs
#include <stdio.h>
#define maxsize 10

int graph[maxsize][maxsize] = {0}, visited[maxsize] = {0}, n;

void createGraph() {
    int edges, u, v;
    printf("Enter number of vertices (max %d): ", maxsize);
    scanf("%d", &n);
    if (n > maxsize) {
        printf("Number of vertices exceeds max size of %d\n", maxsize);
        return;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        if (u >= n || v >= n) {
            printf("Invalid edge! Vertex out of bounds.\n");
            i--; // Decrement to retry this edge
            continue;
        }
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }
}

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int startVertex) {
    int queue[maxsize], front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    queue[rear++] = startVertex;
    visited[startVertex] = 1;
    
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    createGraph();

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);

    printf("\nBFS traversal starting from vertex 0:\n");
    BFS(0);

    return 0;
}
