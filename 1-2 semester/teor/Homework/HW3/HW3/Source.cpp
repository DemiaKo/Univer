#include <iostream>
#include <chrono>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long fib(int n) {
    double s = sqrt(5);
    return((1 / s) * (pow((1 + s) / 2, n) - pow((1 - s) / 2, n)));
}

int main() {
    /*int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/


    auto start = chrono::high_resolution_clock::now();
    int count; cin >> count;
    for (int i = 0; i <= count; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    auto end = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();
    cout << end << endl;

    start = chrono::high_resolution_clock::now();
    cout << fibonacci(count) << " ";
    end = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << end << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i <= count; i++) {
        cout << fib(i) << " ";
    }
    cout << endl;  
    end = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();

    cout << end << endl;

    start = chrono::high_resolution_clock::now();
    cout << fib(count) << " ";
    end = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start).count();
    cout << end << endl;


    return 0;
}