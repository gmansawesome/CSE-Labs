#include <iostream>

using namespace std;

class record{
  public:
    int key[11];

  record(){
    for(int i=0;i<=10;i++) {
        key[i] = 0;
    }
  }
};

// Global variables that can be accessed anywhere. Not recommend for serious programming. 
record* A;
int* C; 
record* B;
int k = 4;
int arraySize;

void CountSort(int r) { // r will be used to refer to key[r]
    // Initialize C and B arrays
    C = new int[k];
    B = new record[arraySize+1];

    for (int i = 0; i < k; i++) {
      C[i] = 0;
    }

    // Count occurrences of each digit
    for (int i = 1; i <= arraySize; i++) {
        C[A[i].key[r]]++;
    }

    // Adjust count array to hold actual positions
    for (int i = 1; i < k; i++) {
        C[i] += C[i - 1];
    }

    // Build the sorted array by positions calculated in C
    for (int i = arraySize; i >= 1; i--) {
        B[C[A[i].key[r]]] = A[i];
        C[A[i].key[r]]--;
    }

    // Copy the sorted array back to A
    for (int i = 1; i <= arraySize; i++) {
        A[i] = B[i];
    }

    delete[] C;
    delete[] B;
}


int main(int argc,char **argv) {
  // Get the size of the sequence
  cin >> arraySize;

  A = new record[arraySize+1];

  // Continue reading sequences until there is no more
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
    {
       cin >> A[i].key[j];
    }
  }
  
  // Radix Sort: TBD
  for (int i = 10; i >= 0; i--) {
    CountSort(i);
  }
 
  //output 
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
       cout << A[i].key[j] << ";";
    cout << endl;
  } 

   // Free allocated space
  delete[] A;

  return 0;
}