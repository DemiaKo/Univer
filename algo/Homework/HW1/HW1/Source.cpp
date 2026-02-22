#include <random>
#include <chrono>
#include "Algorithms.h"

int main() {
    srand(time(NULL));

    int n = 5; cin >> n;
    int* arr1 = new int[n] {38, 27, 43, 3, 9};
    int* arr2 = new int[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = arr1[i];
    }

    cout << "Array: { ";
    for (int i = 0; i < n - 1; i++) cout << arr1[i] << ", ";
    cout << arr1[n-1] << " }" << endl;

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr1, 0, n - 1);
    auto time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "Sorted array: { ";
    for (int i = 0; i < n - 1; i++) cout << arr1[i] << ", ";
    cout << arr1[n - 1] << " }" << endl;
    cout << "Time: " << time << endl;

    cout << "\n\n";

    cout << "Array: { ";
    for (int i = 0; i < n - 1; i++) cout << arr2[i] << ", ";
    cout << arr2[n - 1] << " }" << endl;

    start = chrono::high_resolution_clock::now();
    strandSort(arr2, n);
    time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << "Sorted array: { ";
    for (int i = 0; i < n - 1; i++) cout << arr2[i] << ", ";
    cout << arr2[n - 1] << " }" << endl;
    cout << "Time: " << time << endl;


    return 0;
}
