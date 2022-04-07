//
// Created by Gavin Clarke on 2022-04-01.
//
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Vertex {
    int id;
    float weight;
};

class AdjacencyArray {
public:
    vector<int> *vertex;
    vector<float> *weight;

    AdjacencyArray(int vertexCount) {
        vertex = new vector<int>[vertexCount];
        weight = new vector<float>[vertexCount];
    };

    void addEdge(int vertex1, int vertex2, float edgeWeight) {
        vertex[vertex1].push_back(vertex2);
        vertex[vertex2].push_back(vertex1);
        weight[vertex1].push_back(edgeWeight);
        weight[vertex2].push_back(edgeWeight);
    }
};


typedef pair<int, float> Pair;

vector<float> dijkstra(AdjacencyArray list, int sourceVertex, int TotalVertices) {

    vector<bool> F = vector<bool>(TotalVertices, false);
    float INF = numeric_limits<float>::infinity();


    priority_queue<Pair, vector<Pair>, greater<Pair> > pQueue;
    vector<float> dist(TotalVertices, INF);
    pQueue.push(make_pair(0, sourceVertex));
    dist[sourceVertex] = 0;


    while (!pQueue.empty()) {
        int leastCostVertex = pQueue.top().second;
        pQueue.pop();

        if (F[leastCostVertex]) continue;

        for (int i = 0; i < list.vertex[leastCostVertex].size(); i++) {

            int id = list.vertex[leastCostVertex][i];
            float weight = list.weight[leastCostVertex][i];

            if (!F[id] && dist[id] > dist[leastCostVertex] + weight) {
                dist[id] = dist[leastCostVertex] + weight;
                pQueue.push(make_pair(dist[id], id));
            }
        }
        F[leastCostVertex] = true;
    }

    return dist;
}

int main(int argc, char *argv[]) {

    int size = atoi(argv[1]);;

    //int size = 1024;
    AdjacencyArray list = AdjacencyArray(size);
    std::srand(1999);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            list.addEdge(i, j, (float) (rand()));
        }
    }

    auto result = dijkstra(list, 0, size);
}