#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
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

    bubbleSort(arr);

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
