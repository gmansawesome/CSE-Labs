#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int size;
    cin >> size;
    int* array = new int[size];
    
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    for (int i = 1; i < size; i++) {
        for (int j = i; j >= 0; j--) {
            if (array[j] < array[j-1]) {
                int temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
            else {
                break;
            }
        }
        
        /*
        int x = i;
        while (array[x] < array[x-1]) {
            int temp = array[x-1];
            array[x-1] = array[x];
            array[x] = temp;
            x--;
        }
        */

        for (int j = 0; j <= i; j++) {
            cout << array[j] << ";";
        }
        cout << endl;
    }

    return 0;
}