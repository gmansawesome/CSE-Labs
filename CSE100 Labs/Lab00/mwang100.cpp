#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int* Sequence;
    int size = 1;

    cin >> size;
    Sequence = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> Sequence[i];
    }

    int max = Sequence[0];
    int min = Sequence[0];

    for (int i = 0; i < size; i++) {
        if (Sequence[i] > max) {
            max = Sequence[i];
        }
        if (Sequence[i] < min) {
            min = Sequence[i];
        }
    }

    cout << max << ';' << min;
    
    delete[] Sequence;

    return 0;
}