#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#include <chrono>

//parallel version of bubblesort
void oddEvenTranspositionSort(std::vector<int>& arr) {
    int n = arr.size();
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        #pragma omp parallel for
        for (int i = 1; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
        #pragma omp parallel for
        for (int i = 0; i < n - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

int main() {
    const int arr_size = 120000;
    std::vector<int> arr(arr_size);

    std::srand(std::time(0));
    for (int& num : arr) {
        num = std::rand() % arr_size;
    }
    auto start = std::chrono::high_resolution_clock::now();
    oddEvenTranspositionSort(arr);

    // Optional: Print the sorted array
    // for (auto& num : arr)
    //     std::cout << num << " ";
    // std::cout << "\n";

    // Stop the timer and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Output the elapsed time
    std::cout << "Time taken by function: " << duration/1000000.0 << " seconds" << std::endl;

    return 0;
}
