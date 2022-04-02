//
// Created by Gavin Clarke on 2022-04-01.
//
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Vertex {
    int id;
    Vertex *next;
    float weight;
};

class AdjacencyList {
public:
    Vertex **vertices;
};


void AddEdge(AdjacencyList list, int vertex1, int vertex2, float weight ){

    Vertex * newV1 = new Vertex{
            id: vertex2,
            next: nullptr,
            weight: weight,
    };

    Vertex * newV2 = new Vertex{
            id: vertex1,
            next: nullptr,
            weight: weight,
    };

    Vertex *currentVertex = list.vertices[vertex1];
    if (currentVertex != nullptr){
        while (currentVertex->next != nullptr){
            currentVertex = currentVertex->next;
        }
        currentVertex->next = newV1;
    } else {
        list.vertices[vertex1] =  newV1;
    }
    currentVertex = list.vertices[vertex2];
    if (currentVertex != nullptr){
        while (currentVertex->next != nullptr){
            currentVertex = currentVertex->next;
        }
        currentVertex->next = newV2;
    } else {
        list.vertices[vertex2] =  newV2;
    }
}

typedef pair<int, float> Pair;


void dijkstra(AdjacencyList list, int sourceVertex){
    int TotalVertices;
    float INF = numeric_limits<float>::infinity();

    priority_queue< Pair, vector <Pair> , greater<Pair> > pQueue;
    vector<int> dist(TotalVertices, INF);
    pQueue.push(make_pair(0, sourceVertex));
    dist[sourceVertex] = 0;

    while (!pQueue.empty())
    {
        int leastCostVertex = pQueue.top().second;
        pQueue.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        Vertex * currentVertex = list.vertices[leastCostVertex];
        while(currentVertex != nullptr) {
            if (dist[currentVertex->id] > dist[leastCostVertex] + currentVertex->weight)
            {
                dist[currentVertex->id] = dist[leastCostVertex] + currentVertex->weight;
                pQueue.push(make_pair(dist[currentVertex->id], currentVertex->id));
            }
        }
    }
}




int main(){



}