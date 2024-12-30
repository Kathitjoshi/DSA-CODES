//Graph code to check weakly,strongly connected etc using BFS..

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

// Function to add an edge to a directed graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Graph* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

     newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX];
    int front = 0;
    int rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];

        struct Graph* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// Function to check if the graph is strongly connected
int isStronglyConnected(struct Graph* graph) {
    int visited[MAX];

    // Perform BFS from each vertex
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            visited[j] = 0;
        }
        BFS(graph, i);

        // Check if all vertices are visited
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->visited[j] == 0) {
                return 0; // Graph is not strongly connected
            }
        }

        // Reset visited array
        for (int j = 0; j < graph->numVertices; j++) {
            graph->visited[j] = 0;
        }
    }

    return 1; // Graph is strongly connected
}

// Function to check if the graph is weakly connected
int isWeaklyConnected(struct Graph* graph) {
    struct Graph* undirectedGraph = createGraph(graph->numVertices);

    // Create an undirected version of the graph
    for (int v = 0; v < graph->numVertices; v++) {
        struct Graph* temp = graph->adjLists[v];
        while (temp) {
            addEdge(undirectedGraph, v, temp->vertex);
            addEdge(undirectedGraph, temp->vertex, v);
            temp = temp->next;
        }
    }

    int visited[MAX];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    // Perform BFS from the first vertex
    BFS(undirectedGraph, 0);

    // Check if all vertices are visited
    for (int i = 0; i < graph->numVertices; i++) {
        if (undirectedGraph->visited[i] == 0) {
            return 0; // Graph is not weakly connected
        }
    }

    return 1; // Graph is weakly connected
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    if (isStronglyConnected(graph)) {
        printf("The graph is strongly connected.\n");
    } else if (isWeaklyConnected(graph)) {
        printf("The graph is weakly connected.\n");
    } else {
        printf("The graph is neither strongly nor weakly connected.\n");
    }

    return 0;
}