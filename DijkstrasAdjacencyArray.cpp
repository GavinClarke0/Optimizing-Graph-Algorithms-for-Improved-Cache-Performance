//
// Created by Gavin Clarke on 2022-04-01.
//
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Vertex {
    int id;
    float weight;
};

class AdjacencyArray {
public:
    Vertex **vertices;
    int *edgeCount;
};


typedef pair<int, float> Pair;

void dijkstra(AdjacencyArray list, int sourceVertex){
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
        for (int i =0; i < list.edgeCount[leastCostVertex]; i++){
            Vertex currentVertex = list.vertices[leastCostVertex][i];
            dist[currentVertex.id] = dist[leastCostVertex] + currentVertex.weight;
            pQueue.push(make_pair(dist[currentVertex.id], currentVertex.id));
        }
    }
}

int main(){

}