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
    float weight;
};

class AdjacencyArray {
public:
    vector<Vertex> *vertices;

    AdjacencyArray(int verticeCount){
        vertices = new vector<Vertex>[verticeCount] ;
    };

    void addEdge( int vertex1, int vertex2, float weight){

        vertices[vertex1].push_back(Vertex{
                id: vertex2,
                weight: weight,
        });

        vertices[vertex2].push_back(Vertex{
                id: vertex1,
                weight: weight,
        });
    }
};


typedef pair<int, float> Pair;

vector<float> dijkstra(AdjacencyArray list, int sourceVertex,  int TotalVertices) {

    vector<bool> F = vector<bool>(TotalVertices, false);
    float INF = numeric_limits<float>::infinity();


    priority_queue< Pair, vector <Pair> , greater<Pair> > pQueue;
    vector<float> dist(TotalVertices, INF);
    pQueue.push(make_pair(0, sourceVertex));
    dist[sourceVertex] = 0;


    while (!pQueue.empty())
    {
        int leastCostVertex = pQueue.top().second;
        pQueue.pop();

        if (F[leastCostVertex]) continue;

        for (auto& currentVertex : list.vertices[leastCostVertex]) {
            if (!F[currentVertex.id] && dist[currentVertex.id] > dist[leastCostVertex] + currentVertex.weight) {
                dist[currentVertex.id] = dist[leastCostVertex] + currentVertex.weight;
                pQueue.push(make_pair(dist[currentVertex.id], currentVertex.id));
            }
        }
        F[leastCostVertex] = true;
    }

    return dist;
}

int main(){

    int size = 1000;

    AdjacencyArray list= AdjacencyArray(size);

    std::srand(1999);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            list.addEdge(i, j, (float)(rand()));
        }
    }

    auto result = dijkstra(list, 0, 1000);
}