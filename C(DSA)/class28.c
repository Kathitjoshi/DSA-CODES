//To check if path exists using DFS and adjacency list

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the structure for the adjacency list node and the graph
struct Graph {
    int vertex;
    struct Graph* next;
    int numVertices;
    struct Graph** adjLists;
    int* visited;
};

// Function to create a new adjacency list node
struct Graph* createNode(int v) {
    struct Graph* newNode = (struct Graph*)malloc(sizeof(struct Graph));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with numVertices vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Graph**)malloc(vertices * sizeof(struct Graph*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Graph* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform DFS traversal
int DFS(struct Graph* graph, int vertex, int endVertex) {
    struct Graph* adjList = graph->adjLists[vertex];
    struct Graph* temp = adjList;

    graph->visited[vertex] = 1;
    if (vertex == endVertex) {
        return 1; // Path exists
    }

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            if (DFS(graph, connectedVertex, endVertex)) {
                return 1; // Path exists
            }
        }
        temp = temp->next;
    }
    return 0; // No path exists
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    int startVertex = 0;
    int endVertex = 4;

    if (DFS(graph, startVertex, endVertex)) {
        printf("Path exists between %d and %d\n", startVertex, endVertex);
    } else {
        printf("No path exists between %d and %d\n", startVertex, endVertex);
    }

    return 0;
}


//To check if path exists using BFS and adjacency list

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// // Define the structure for the adjacency list node and the graph
// struct Graph {
//     int vertex;
//     struct Graph* next;
//     int numVertices;
//     struct Graph** adjLists;
//     int* visited;
// };

// // Function to create a new adjacency list node
// struct Graph* createNode(int v) {
//     struct Graph* newNode = (struct Graph*)malloc(sizeof(struct Graph));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to create a graph with numVertices vertices
// struct Graph* createGraph(int vertices) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->numVertices = vertices;

//     graph->adjLists = (struct Graph**)malloc(vertices * sizeof(struct Graph*));
//     graph->visited = (int*)malloc(vertices * sizeof(int));

//     for (int i = 0; i < vertices; i++) {
//         graph->adjLists[i] = NULL;
//         graph->visited[i] = 0;
//     }

//     return graph;
// }

// // Function to add an edge to an undirected graph
// void addEdge(struct Graph* graph, int src, int dest) {
//     // Add an edge from src to dest
//     struct Graph* newNode = createNode(dest);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;

//     // Since the graph is undirected, add an edge from dest to src
//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode;
// }

// // Function to perform BFS traversal
// int BFS(struct Graph* graph, int startVertex, int endVertex) {
//     int queue[MAX];
//     int front = 0;
//     int rear = 0;

//     graph->visited[startVertex] = 1;
//     queue[rear++] = startVertex;

//     while (front < rear) {
//         int currentVertex = queue[front++];

//         struct Graph* temp = graph->adjLists[currentVertex];

//         while (temp) {
//             int adjVertex = temp->vertex;

//             if (adjVertex == endVertex) {
//                 return 1; // Path exists
//             }

//             if (graph->visited[adjVertex] == 0) {
//                 graph->visited[adjVertex] = 1;
//                 queue[rear++] = adjVertex;
//             }
//             temp = temp->next;
//         }
//     }

//     return 0; // No path exists
// }

// int main() {
//     int vertices = 5;
//     struct Graph* graph = createGraph(vertices);

//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 1, 3);
//     addEdge(graph, 2, 4);

//     int startVertex = 0;
//     int endVertex = 4;

//     if (BFS(graph, startVertex, endVertex)) {
//         printf("Path exists between %d and %d\n", startVertex, endVertex);
//     } else {
//         printf("No path exists between %d and %d\n", startVertex, endVertex);
//     }

//     return 0;
// }