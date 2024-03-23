#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert code here
	printf("head: %p\n", head);
    printf("&head: %p\n", &head);
    printf("iValue: %d\n", head->iValue);
    printf("iValue: %0.2f\n", head->fValue);
	
	return 0;
}