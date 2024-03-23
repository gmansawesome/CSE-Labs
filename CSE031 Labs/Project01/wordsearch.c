#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
void search(char** arr, char* word, int i, int j, int index, int** found, int* wordFound);
void toUpper(char* str);
int bSize;

// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            printf("%c ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void searchPuzzle(char** arr, char* word) {
    int n = bSize;

    int i, j;
    int** found = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++) {
        *(found + i) = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; ++j) {
            *(*(found + i) + j) = 0;            
        }
    }

    toUpper(word);
    // printf("Word: %s\n", word);
    
    // Flag to keep track if the word is found
    int wordFound = 0;
    int wordCount = 0;
    
    //finds all possible words using a recursive searching algo
    for (i = 0; i < n && !wordFound; i++) {
        for (j = 0; j < n && !wordFound; j++) {
            if (*(*(arr + i) + j) == *word) {
                search(arr, word, i, j, 0, found, &wordFound);
                if (wordFound == 1) {
                    wordCount++;
                    wordFound = 0;
                }
            }
        }
    }

    // printf("wordFound = %d\n", wordFound);
    // printf("wordCount = %d", wordCount);

    // Output according to whether the word was found or not
    if (wordCount > 0) {
        printf("Word found!\n");
        printf("Printing the search path:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", *(*(found + i) + j));
                if (j != n-1) {
                    printf("\t");
                }
            }
            printf("\n");
        }
    } else {
        printf("Word not found!\n");
    }
}

void search(char** arr, char* word, int i, int j, int index, int** found, int* wordFound) {
    int n = bSize;

    if (*(word+index) == '\0') {
        *wordFound = 1;
        return;
    }

    if (*(*(arr + i) + j) == *(word+index)) {
        //concatenate/finish depending on situation
        if (*(*(found + i) + j) == 0) {
            *(*(found + i) + j) = index + 1; //if zero (not traversed) concatenate index
        }
        else if (*(*(found + i) + j) != 0)  {
            int digits = 0;
            int multiple = 10;
            int temp = *(*(found + i) + j);

            while (temp != 0) {
                temp /= 10;
                digits++;
            }

            for (int x = 1; x < digits; x++) {
                multiple *= 10;
            }

            // printf("%d\n", (index + 1)*multiple);
            // printf("%d\n", *(*(found + i) + j));
            *(*(found + i) + j) = ((index + 1)*multiple) + *(*(found + i) + j); // if non-zero (traversed) concatenate in front of existing number
        }
        else {
            *wordFound = 1; //if nothing then return (finished)
            return;
        }
        
        //all possible branches
        int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

        for (int k = 0; k < 8; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            //check bounds
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && !*wordFound) {
                search(arr, word, ni, nj, index + 1, found, wordFound);

                if (*wordFound) {
                    return;
                }
            }
        }

        //if it reaches a dead end, sets to zero
        if (!*wordFound) {
            *(*(found + i) + j) = 0;
            return;
        }
    }
}

void toUpper(char* str) {
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - ('a' - 'A');
        }
        str++;
    }
}