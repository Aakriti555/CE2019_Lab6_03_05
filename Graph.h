//Implementing a LINKEDLIST through STRUCT 
struct Vertex
{
    int data;
    // Pointers to show Neighbors
    Vertex *nextNeighbor;
    Vertex *prevNeighbor;
    //Pointers to show Vertices
    Vertex *upVertex;
    Vertex *downVertex;
    
    Vertex():nextNeighbor(nullptr), prevNeighbor(nullptr), upVertex(nullptr), downVertex(nullptr){}; 
    Vertex(int data):data(data), nextNeighbor(nullptr), prevNeighbor(nullptr), upVertex(nullptr), downVertex(nullptr){};
    
};

class Graph{
private:
    Vertex *HEAD;
public:
    Graph();
    bool isEmpty();
    bool isDirected();
    void addVertex(int newVertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    void numVertices();
    void numEdges();
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    int *neighbours(int vertex);
    bool neighbour(int vertex1, int vertex2);
};
