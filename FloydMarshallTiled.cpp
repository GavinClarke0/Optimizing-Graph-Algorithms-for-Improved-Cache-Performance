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

// naive floyd warshall to be preformed on each block
inline void FloydMarshall(float *A, int n , int vertexCount) {
    for  (int k = 0; k < n; k++ ) {
        for (int i = 0; i < n; i++ ){
            for (int j = 0; j < n; j++ ){
                A[(vertexCount * i) + j] = min(A[(vertexCount * i) + j],   A[(vertexCount * i) + k] +  A[(vertexCount * k) + j]);
            }
        }
    }
}



void FloydMarshallTiled(float *A,  int BlockSize , int vertexCount) {

    int blockCountRow = vertexCount/BlockSize;

    for (int b = 0; b < blockCountRow; b++){
        float *Block = A + (b * vertexCount) + (b * BlockSize);
        FloydMarshall(Block, BlockSize, vertexCount);

        // run FW on rows of CR block
        for (int col = 0; col < blockCountRow; col++){
            if (col == b) continue;
            Block = A + (b * vertexCount) + (col * BlockSize);
            FloydMarshall(Block, BlockSize, vertexCount);
        }

        // run FW on columns of CR block
        for (int row = 0; row < blockCountRow; row++){
            if (row == b) continue;
            Block = A + (row * vertexCount) + (b * BlockSize);
            FloydMarshall(Block, BlockSize, vertexCount);
        }

        // Run FW on remaining blocks
        for (int col = 0; col < blockCountRow; col++){
            for (int row = 0; row < blockCountRow; row++){

                if (row == b || col == b)
                    continue;

                Block = A + (row * vertexCount) + (col * BlockSize);
                FloydMarshall(Block, BlockSize, vertexCount);
            }
        }
    }
}

int main() {

    int size = 1024;

    float *adjacencyDenseMatrix = Matrix2DRandom(size, size);
    FloydMarshallTiled(adjacencyDenseMatrix, 64, size );
    return 0;
}
