#include <iostream>

using namespace std;

void max_heapify(int* arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest]) 
        largest = left; 

    if (right < n && arr[right] > arr[largest]) 
        largest = right; 

    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        max_heapify(arr, n, largest); 
    } 
} 

void build_max_heap(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) 
        max_heapify(arr, n, i); 
}

int main() {
    int n = 0;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build_max_heap(arr, n);
    for (int i = n-1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        build_max_heap(arr, i);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ';';
    }
}