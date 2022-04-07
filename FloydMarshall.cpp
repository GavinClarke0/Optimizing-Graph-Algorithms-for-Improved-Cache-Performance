#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

float* Matrix2DRandom(int x, int y) {
    float *matrix = new float[x * y];
    std::srand(1999);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            matrix[(i * x) + j] = (float)(rand());
        }
    }
    return matrix;
}

// linear array 
void FloydMarshall(float *A, float *B, float *C, int vertexCount) {
    for  (int k = 0; k < vertexCount; k++ ) {
        for (int i = 0; i < vertexCount; i++ ){
            for (int j = 0; j < vertexCount; j++ ){
                cout << "(" << i << " " << j << ") ";
                cout << "(" << i << " " << k << ") ";
                cout << "(" << k << " " << j << ")" << endl;
                //A[(vertexCount * i) + j] = min(A[(vertexCount * i) + j], B[(vertexCount * i) + k] + C[(vertexCount * k) + j]);
            }
        }
    }
}

void FloydMarshall(float *A, int vertexCount) {
    for  (int k = 0; k < vertexCount; k++ ) {
        for (int i = 0; i < vertexCount; i++ ){
            for (int j = 0; j < vertexCount; j++ ){
                A[(vertexCount * i) + j] = min(A[(vertexCount * i) + j], A[(vertexCount * i) + k] + A[(vertexCount * k) + j]);
            }
        }
    }
}

void PrintMatrix(float *T, int TRowSize){
    for(int i = 0; i < TRowSize; i++){
        for (int j = 0; j < TRowSize; j++){
            cout << T[(i * TRowSize) + j] << " ";
        }
        cout << ""<< endl;
    }
}

int main(int argc, char *argv[]) {

    int size = atoi(argv[1]);

    //int size = 2;
    float *adjacencyDenseMatrix = Matrix2DRandom(size, size);
    FloydMarshall(adjacencyDenseMatrix, adjacencyDenseMatrix, adjacencyDenseMatrix, size );

    //PrintMatrix(adjacencyDenseMatrix,size);

    return 0;
}
