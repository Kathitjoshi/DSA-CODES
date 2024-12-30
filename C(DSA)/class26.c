//BFS using adjacency list and checking if they are connected to the same graph structure as the current graph structure 

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
// void BFS(struct Graph* graph, int startVertex) {
//     int queue[MAX];
//     int front = -1;
//     int rear = -1;

//     graph->visited[startVertex] = 1;
//     queue[++rear] = startVertex;

//     while (front != rear) {
//         int currentVertex = queue[++front];
//         printf("Visited %d\n", currentVertex);

//         struct Graph* temp = graph->adjLists[currentVertex];

//         while (temp) {
//             int adjVertex = temp->vertex;

//             if (graph->visited[adjVertex] == 0) {
//                 graph->visited[adjVertex] = 1;
//                 queue[++rear] = adjVertex;
//             }
//             temp = temp->next;
//         }
//     }
// }

// // Function to check if the graph is connected
// int isConnected(struct Graph* graph) {
//     for (int i = 0; i < graph->numVertices; i++) {
//         if (graph->visited[i] == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main() {
//     int vertices = 5;
//     struct Graph* graph = createGraph(vertices);

//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 3, 4);

//     BFS(graph, 0);

//     if (isConnected(graph)) {
//         printf("The graph is connected.\n");
//     } else {
//         printf("The graph is not connected.\n");
//     }

//     return 0;
// }


//DFS using adjacency list and checking if they are connected to the same graph structure as the current graph structure 


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
void DFS(struct Graph* graph, int vertex) {
    struct Graph* adjList = graph->adjLists[vertex];
    struct Graph* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Function to check if the graph is connected
int isConnected(struct Graph* graph) {
    // Perform DFS from the first vertex
    DFS(graph, 0);

    // Check if all vertices are visited
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            return 0; // Graph is not connected
        }
    }
    return 1; // Graph is connected
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);

    if (isConnected(graph)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}