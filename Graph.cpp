#include "Graph.h"
#include <iostream>
#include <array>

Graph::Graph()
{
    HEAD = nullptr;
}

bool Graph::isEmpty()
{
    if (HEAD == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Graph::isDirected()
{
    bool isDirected;
    Vertex *temp = new Vertex();
    Vertex *otherTemp = new Vertex();
    temp = HEAD;
    while (temp != nullptr)
    {
        otherTemp = temp->nextNeighbor;
        while (otherTemp != nullptr)
        {

            if (this->neighbour(temp->data, otherTemp->data) && this->neighbour(otherTemp->data, temp->data))
            {
                isDirected = false;
            }
            else
            {
                isDirected = true;
            }
            otherTemp = otherTemp->nextNeighbor;
        }
        temp = temp->downVertex;
    }
    return isDirected;
}

void Graph::addVertex(int newVertex)
{
    Vertex *vertex = new Vertex(newVertex);
    if (isEmpty())
    {
        HEAD = vertex;
        std::cout << "Vertex has been added" << std::endl;
    }
    else
    {
        Vertex *temp = new Vertex();
        temp = HEAD;

        while (temp->downVertex != nullptr && temp->data != newVertex)
        {
            temp = temp->downVertex;
        }

        if (temp->downVertex == nullptr)
        {
            temp->downVertex = vertex;
            vertex->upVertex = temp;
            std::cout << "Vertex has been added" << std::endl;
        }
        else
        {
            std::cout << "Vertex already exists" << std::endl;
        }
    }
}

void Graph::removeVertex(int vertexToRemove)
{
    Vertex *temp = new Vertex();
    temp = HEAD;
    while (temp != nullptr && temp->data != vertexToRemove)
    {
        temp = temp->downVertex;
    }
    if (temp == nullptr)
    {
        std::cout << "Vertex doesn't exist" << std::endl;
    }
    else
    {
        if (temp->downVertex == nullptr)
        {
            temp->upVertex->downVertex = nullptr;
        }
        else
        {
            temp->downVertex->upVertex = temp->upVertex;
            temp->upVertex->downVertex = temp->downVertex;
            delete temp;
        }
        // after removing the vertex we need to remove the edges from other vertices
        Vertex *remove = new Vertex();
        remove = HEAD;
        while (remove != nullptr)
        {
            if (neighbour(remove->data, vertexToRemove))
            {
                removeEdge(remove->data, vertexToRemove);
            }
            remove = remove->downVertex;
        }
    }
}

void Graph::addEdge(int vertex1, int vertex2)
{
    Vertex *temp = new Vertex();
    Vertex *newVertex = new Vertex(vertex2);
    temp = HEAD;

    while (temp != nullptr && temp->data != vertex1)
    {
        temp = temp->downVertex;
    }

    if (temp == nullptr)
    {
        std::cout << "Vertex doesn't exists." << std::endl;
    }

    else
    {
        while (temp->nextNeighbor != nullptr && temp->nextNeighbor->data != vertex2)
        {
            temp = temp->nextNeighbor;
        }
        if (temp->nextNeighbor == nullptr)
        {
            temp->nextNeighbor = newVertex;
            newVertex->prevNeighbor = temp;
            std::cout << "Edge has been added." << std::endl;
        }

        else
        {
            std::cout << "Edge already exists." << std::endl;
        }
    }
}

void Graph::removeEdge(int vertex1, int vertex2)
{
    Vertex *temp = new Vertex();
    temp = HEAD;
    while (temp != nullptr && temp->data != vertex1)
    {
        temp = temp->downVertex;
    }
    if (temp == nullptr)
    {
        std::cout << "Vertex" << vertex1 << "doesn't exists." << std::endl;
    }
    else
    {
        temp = temp->nextNeighbor;
        while (temp != nullptr && temp->data != vertex2)
        {
            temp = temp->nextNeighbor;
        }
        if (temp == nullptr)
        {
            std::cout << "Edge doesn't exists" << std::endl;
        }
        else
        {
            if (temp->nextNeighbor == nullptr)
            {
                delete temp;
                std::cout << "Edge has been deleted" << std::endl;
            }
            else
            {
                temp->prevNeighbor->nextNeighbor = temp->nextNeighbor;
                temp->nextNeighbor->prevNeighbor = temp->prevNeighbor;
                delete temp;
                std::cout << "Edge has been deleted" << std::endl;
            }
        }
    }
}

void Graph::numVertices()
{
    int v = 0;
    Vertex *temp = new Vertex();
    temp = HEAD;
    while (temp != nullptr)
    {
        v++;
        temp = temp->downVertex;
    }
    std::cout << "The number of vertices in the Graph is " << v << std::endl;
}

void Graph::numEdges()
{
    int e = 0;
    Vertex *trackVer = new Vertex();
    Vertex *trackNei = new Vertex();
    trackVer = HEAD;
    while (trackVer != nullptr)
    {
        trackNei = trackVer->nextNeighbor;
        while (trackNei != nullptr)
        {
            e++;
            trackNei = trackNei->nextNeighbor;
        }
        trackVer = trackVer->downVertex;
    }
    std::cout << "The number of edges in the Graph is " << e << std::endl;
}
