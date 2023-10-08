#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>
using namespace std;

// Serial matrix multiplication
// This function performs matrix transposition in a serial manner.
// It takes as input two matrices (mat1 and mat2) and the size of the matrices (N).
// The function transposes mat1 and stores the result in mat2.
// It also measures and prints the time taken to perform the transposition.
void serial(vector<vector<int>> mat1, vector<vector<int>> mat2, int N){
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat2[j][i] = mat1[i][j];
        }
    }
    // Stop the timer and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Output the elapsed time
    cout << "Time taken by serial function: " << duration/1000000.0 << " seconds" << endl;
}

// Parallel matrix multiplication 
// This function performs matrix transposition in a parallel manner using OpenMP.
// It takes as input two matrices (mat1 and mat2) and the size of the matrices (N).
// The function transposes mat1 and stores the result in mat2.
// It also measures and prints the time taken to perform the transposition.
// The critical section ensures that only one thread writes to the output matrix at a time, preventing race conditions.
void parallel(vector<vector<int>> mat1, vector<vector<int>> mat2, int N){
    auto start = chrono::high_resolution_clock::now();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            #pragma omp critical
            {
                mat2[j][i] = mat1[i][j];
            }
        }
    }

    // Stop the timer and calculate the elapsed time
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Output the elapsed time
    cout << "Time taken by parallel function: " << duration/1000000.0 << " seconds" << endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }
}

// The main function initializes two matrices (mat1 and mat2) of size N.
// It then calls the serial and parallel functions to perform matrix transposition and measure the time taken.
// The results of the transposition are printed for verification.
int main() {
    const int N = 10;

    vector<vector<int>> mat1(N, vector<int>(N, 1));
    vector<vector<int>> mat2(N, vector<int>(N, 2));

    // Serial function call
    serial(mat1, mat2, N);

    // Parallel function call
    parallel(mat1, mat2, N);

    // Print the result (for verification)
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         cout << mat1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         cout << mat2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
