#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
using namespace std;


void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int* arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


void mergeStrands(int* arr, int& arr_size, int* strand, int strand_size) {
    int* temp = new int[arr_size + strand_size];

    int i = 0, j = 0, k = 0;

    while (i < arr_size && j < strand_size) {
        if (arr[i] <= strand[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = strand[j++];
        }
    }

    while (i < arr_size) temp[k++] = arr[i++];
    while (j < strand_size) temp[k++] = strand[j++];

    for (int x = 0; x < k; x++) {
        arr[x] = temp[x];
    }

    arr_size = k;

    delete[] temp;
}

void strandSort(int* arr, int n) {
    if (n <= 1) return;

    int* sorted_arr = new int[n];
    int sorted_size = 0;

    int* strand = new int[n];
    int current_n = n;

    while (current_n > 0) {
        int strand_size = 0;

        strand[strand_size++] = arr[0];

        for (int x = 0; x < current_n - 1; x++) {
            arr[x] = arr[x + 1];
        }
        current_n--;

        int i = 0;
        while (i < current_n) {
            if (arr[i] >= strand[strand_size - 1]) {
                strand[strand_size++] = arr[i];

                for (int x = i; x < current_n - 1; x++) {
                    arr[x] = arr[x + 1];
                }
                current_n--;
            }
            else {
                i++;
            }
        }

        mergeStrands(sorted_arr, sorted_size, strand, strand_size);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }
}

int main() {
    srand(time(NULL));

    int n = 10;
    int* arr1 = new int[n];
    int* arr2 = new int[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = arr1[i];
    }

    for (int i = 0; i < n; i++) std::cout << arr1[i] << " ";
    cout << endl;


    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr1, 0, n - 1);
    auto time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();

    for (int i = 0; i < n; i++) std::cout << arr1[i] << " ";
    cout << endl << time << endl;

    start = chrono::high_resolution_clock::now();
    strandSort(arr2, n);
    time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();

    for (int i = 0; i < n; i++) std::cout << arr2[i] << " ";
    cout << endl << time << endl;


    return 0;
}