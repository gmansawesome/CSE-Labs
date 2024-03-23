#include <stdio.h>
int main() {
	int input = 0;
	int typo = 0;

	//acquires repetition count
	printf("Enter the repetition count for the punishment phrase: ");
	scanf("%d", &input);
	while (input <= 0) {
		printf("You entered an invalid value for the repetition count!\nEnter the number of repetitions for the punishment phrase again: ");
		scanf("%d", &input);
	}

	//acquires typo placement
	printf("Enter the line where you want to insert the typo: ");
	scanf("%d", &typo);
	while (typo <= 0 || typo > input) {
		printf("You entered an invalid value for the typo placement!\nEnter the number of repetitions for the typo again: ");
		scanf("%d", &typo);
	}

	//performs the repetitions
	int i = 1;
	printf("\n");
	for (i; i <= input; i++) {
		if (i == typo) {
			printf("Cading wiht is C avesone!");
		}
		else {
			printf("Coding with C is awesome!");
		}
		printf("\n");
	}

	//for testing
	//printf("\n%d lines with a typo on line %d\n", input, typo);

	return 0;
}
