#include <iostream>
#include <vector>
#include <chrono>
//matrix multiplcation
int main() {

    auto start = std::chrono::high_resolution_clock::now();

    const int N = 1000;
    std::vector<std::vector<int>> mat1(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> mat2(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> result(N, std::vector<int>(N, 0));

    // Serial matrix multiplication
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Print the result (for verification)
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         std::cout << result[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

     // Stop the timer and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Output the elapsed time
    std::cout << "Time taken by function: " << duration/1000000.0 << " seconds" << std::endl;

    return 0;
}
