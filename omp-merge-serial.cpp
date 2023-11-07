#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
//serial merge
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    const int arr_size = 500000;
    std::vector<int> arr(arr_size);

    // Seed the random number generator and populate the array with random integers
    std::srand(std::time(0));
    for (int& num : arr) {
        num = std::rand() % arr_size;
    }
    auto start = std::chrono::high_resolution_clock::now();

    mergeSort(arr, 0, arr_size - 1);

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
