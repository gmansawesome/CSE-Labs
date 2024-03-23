#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;

    int* px = &x;
    int* py = &y;

    int arr[10] = {0};

    printf("x: %d y: %d arr[0]: %d\n", x, y, arr[0]);
    printf("&x: %p &y: %p\n", &x, &y);
    printf("px: %p &px: %p py: %p &py: %p\n", px, &px, py, &py);

    int i = 0;
    for (i; i < 10; i++) {
        *(arr+1);
        printf("%d;", *arr);
    }
    printf("\n");

    printf("arr = %p &arr[0] = %p\n", arr, &arr[0]);

    printf("&arr = %p\n", &arr);
    
    return 0;
}