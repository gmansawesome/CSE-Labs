#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getOrdinal(int count){
    char* ordinal = (char *) malloc(3 * sizeof(char));

    int j = count % 10, k = count % 100;
    if (j == 1 && k != 11){
        strcpy(ordinal, "st");
    }
    else if (j == 2 && k != 12){
        strcpy(ordinal, "nd");
    }
    else if (j == 3 && k != 13){
        strcpy(ordinal, "rd");
    }
    else {
        strcpy(ordinal, "th");
    }

    return ordinal;
}

int digitSum(int num) {
    int tempSum = 0;

    while (num != 0) {
        tempSum += num % 10;
        num = num/10;

        if (num < 0) {
            tempSum *= -1;
            num *= -1;
        }
    }
    return tempSum;
}

int main() {
    int evenSum = 0;
    int evenCount = 0;
    int oddSum = 0;
    int oddCount = 0;

    int currentVal = 1;
    int count = 0;
    while (currentVal != 0) {
        count++;

        char* ordinal = getOrdinal(count);

        printf("Enter the %d%s value: ", count, ordinal);
        scanf("%d", &currentVal);

        if (currentVal == 0) {
            break;
        }

        if (digitSum(currentVal) % 2 == 0) {
            evenSum += currentVal;
            evenCount++;
            // printf("adding to even");
        }
        else {
            oddSum += currentVal;
            oddCount++;
            // printf("adding to odd");
        }
    }

    printf("\n");

    if (evenCount == 0 && oddCount == 0) {
        printf("There is no average to compute.\n");
    }
    else {
        if (evenCount != 0) {
            // printf("evenSum/evenCount = %d/%d\n", evenSum, evenCount);
            float evenAvg = (float)evenSum/evenCount;
            printf("Average of input values whose digits sum up to an even number: %0.2f\n", evenAvg);
        }
        if (oddCount != 0) {
            // printf("oddSum/oddCount = %d/%d\n", oddSum, oddCount);
            float oddAvg = (float)oddSum/oddCount;
            printf("Average of input values whose digits sum up to an odd number: %0.2f\n", oddAvg);
        }
    }
}