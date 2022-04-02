//
// Created by Gavin Clarke on 2022-04-01.
//
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

struct Vertex {
    int id;
    Vertex *next;
    float weight;
};

class AdjacencyList {
public:
    vector<Vertex *> edgesStart;
    vector<Vertex *> edgesEnd;
    AdjacencyList(int verticeCount){
        edgesStart = vector<Vertex *>(verticeCount);
        edgesEnd = vector<Vertex *>(verticeCount);
    };
};


void addEdge(AdjacencyList *list, int vertex1, int vertex2, float weight ){

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

    if (list->edgesStart[vertex1] == nullptr ){
        list->edgesStart[vertex1] =  newV1;
        list->edgesEnd[vertex1] =  newV1;
    } else {
        list->edgesEnd[vertex1]->next = newV1;
        list->edgesEnd[vertex1] = newV1;
    }

    if (list->edgesStart[vertex2] == nullptr ){
        list->edgesStart[vertex2] =  newV2;
        list->edgesEnd[vertex2] =  newV2;
    } else {
        list->edgesEnd[vertex2]->next = newV2;
        list->edgesEnd[vertex2] = newV2;
    }
}

typedef pair<int, float> Pair;


vector<int> dijkstra(AdjacencyList list, int sourceVertex){
    int TotalVertices = list.edgesStart.size();
    vector<bool> F = vector<bool>(TotalVertices, false);
    float INF = numeric_limits<float>::infinity();

    priority_queue< Pair, vector <Pair> , greater<Pair> > pQueue;
    vector<int> dist(TotalVertices, INF);
    pQueue.push(make_pair(0, sourceVertex));
    dist[sourceVertex] = 0;

    while (!pQueue.empty())
    {
        int leastCostVertex = pQueue.top().second;
        pQueue.pop();

        if (F[leastCostVertex]) continue;
        // 'i' is used to get all adjacent edgesStart of a vertex
        Vertex * currentVertex = list.edgesStart[leastCostVertex];
        while(currentVertex != nullptr) {
            if (dist[currentVertex->id] > dist[leastCostVertex] + currentVertex->weight)
            {
                dist[currentVertex->id] = dist[leastCostVertex] + currentVertex->weight;
                pQueue.push(make_pair(dist[currentVertex->id], currentVertex->id));
            }
            currentVertex = currentVertex->next;
        }
        F[leastCostVertex] = true;
    }

    return dist;
}




int main(){

    int size = 1000;

    AdjacencyList list= AdjacencyList(size);


    std::srand(1999);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            addEdge(&list, i, j, (float)(rand()));
        }
    }

    auto result = dijkstra(list, 0);
}