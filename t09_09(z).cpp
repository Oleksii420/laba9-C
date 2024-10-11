#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int** createMatrix(int N, int M) {
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[M];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int N) {
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fillMatrix(int** matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int** matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    int N, M, k;
    cin >> N;
    cin >> M;
    cin >> k;

    int** matrix = createMatrix(N, M);
    fillMatrix(matrix, N, M);

    int** newMatrix = createMatrix(N + k, M);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++) {
            newMatrix[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            newMatrix[i + k][j] = matrix[i][j];
        }
    }

    printMatrix(newMatrix, N + k, M);

    deleteMatrix(matrix, N);
    deleteMatrix(newMatrix, N + k);

    return 0;
}
