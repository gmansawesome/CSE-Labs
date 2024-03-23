#include <iostream>

using namespace std;

void printArr(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << ";";
    }
}

void merge(int* array,  int lower, int mid, int upper) {
    // cout << "Merge reached!" << endl;
    int n1 = (mid-lower)+1;
    int n2 = upper-mid;
    int* Larr = new int[n1+1];
    int* Rarr = new int[n2+1];

    int k = 0;
    for (int i = lower; i <= mid; i++) {
        Larr[k] = array[i];
        k++;
    }

    k = 0;
    for (int i = mid+1; i <= upper; i++) {
        Rarr[k] = array[i];
        k++;
    }

    Larr[n1] = 10000;
    Rarr[n2] = 10000;

    // printArr(Larr, n1+1);
    // printArr(Rarr, n2+1);

    int i = 0;
    int j = 0;
    for (int k = lower; k <= upper; k++) {
        if (Larr[i] < Rarr[j]) {
            array[k] = Larr[i];
            i++;
        }
        else {
            array[k] = Rarr[j];
            j++;
        }
    }

    // cout << "array:";
    // printArr(array, 3);

    delete[] Larr;
    delete[] Rarr;
}

void mergeSort(int* array, int lower, int upper) {
    if (lower < upper) {
        int mid = (upper+lower)/2;
        // cout << lower << mid << upper << endl;
        mergeSort(array, lower, mid);
        mergeSort(array, mid+1, upper);
        merge(array, lower, mid, upper);
    }
}

int main(int argc, char** argv) {
    int size = 0;
    cin >> size;
    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    mergeSort(array, 0, size-1);
    printArr(array, size);
}