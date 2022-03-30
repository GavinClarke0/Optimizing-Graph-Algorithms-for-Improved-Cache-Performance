#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

#define BASECASE 10

float* Matrix2DRandom(int x, int y) {
    float *matrix = new float[x * y];
    std::srand(std::time(nullptr));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            matrix[(i * x) + j] = (float)(rand());
        }
    }
    return matrix;
}

void FloydMarshallRecursive(float *A, float *B, float *C, int n , int vertexCount) {

    if (n > 64){
        float *A11 = A;
        float *A12 = A+(n/2);
        float *A21 = A+(n*vertexCount/2);
        float *A22 = A+(n*vertexCount/2+n/2);
        float *B11 = B;
        float *B12 = B+(n/2);
        float *B21 = B+(n*vertexCount/2);
        float *B22 = B+(n*vertexCount/2+n/2);
        float *C11 = C;
        float *C12 = C+(n/2);
        float *C21 = C+(n*vertexCount/2);
        float *C22 = C+(n*vertexCount/2+n/2);

        FloydMarshallRecursive(A11, B11, C11, n/2, vertexCount);
        FloydMarshallRecursive(A12, B11, C12, n/2, vertexCount);
        FloydMarshallRecursive(A21, B21, C11, n/2, vertexCount);
        FloydMarshallRecursive(A22, B21, C12, n/2, vertexCount);
        FloydMarshallRecursive(A22, B22, C22, n/2, vertexCount);
        FloydMarshallRecursive(A21, B22, C21, n/2, vertexCount);
        FloydMarshallRecursive(A12, B12, C22, n/2, vertexCount);
        FloydMarshallRecursive(A11, B12, C21, n/2, vertexCount);
        return;
    }

    for  (int k = 0; k < n; k++ ) {
        for (int i = 0; i < n; i++ ){
            for (int j = 0; j < n; j++ ){
                A[(vertexCount * i) + j] = min(A[(vertexCount * i) + j],   B[(vertexCount * i) + k] +  C[(vertexCount * k) + j]);
            }
        }
    }
}

int main() {

    int size = 100;

    float *adjacencyDenseMatrix = Matrix2DRandom(size, size);
    FloydMarshallRecursive(adjacencyDenseMatrix, adjacencyDenseMatrix, adjacencyDenseMatrix, size, size );
    return 0;
}
