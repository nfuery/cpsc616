#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>
using namespace std;

// Parallel matrix multiplication 
void parallel(vector<vector<int>> mat1, vector<vector<int>> mat2, vector<vector<int>> result, int N){
    auto start = chrono::high_resolution_clock::now();
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    // Stop the timer and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Output the elapsed time
    cout << "Time taken by parallel function: " << duration/1000000.0 << " seconds" << endl;
}

// Serial matrix multiplication
void serial(vector<vector<int>> mat1, vector<vector<int>> mat2, vector<vector<int>> result, int N){
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
     // Stop the timer and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Output the elapsed time
    cout << "Time taken by serial function: " << duration/1000000.0 << " seconds" << endl;
}

int main() {
    const int N = 1000;
    vector<vector<int>> mat1(N, vector<int>(N, 1));
    vector<vector<int>> mat2(N, vector<int>(N, 2));
    vector<vector<int>> result(N, vector<int>(N, 0));

    // Serial function call
    serial(mat1, mat2, result, N);

    // Parallel function call
    parallel(mat1, mat2, result, N);
    
    return 0;
}
