#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascendingComparison(const void* left, const void* right) {
    const int numberOne = *(int*)left;
    const int numberTwo = *(int*)right;

    return numberOne >= numberTwo;
}

int descendingComparison(const void* left, const void* right) {
    const int numberOne = *(int*)left;
    const int numberTwo = *(int*)right;

    return numberOne <= numberTwo;
}

int main() {
    enum {
        S_NUMBERS = 3
    };

    int numbers[S_NUMBERS];
    memset(numbers, 0, S_NUMBERS);

    printf("Please input number one: ");
    scanf("%d", &numbers[0]);

    printf("Please input number two: ");
    scanf("%d", &numbers[1]);

    printf("Please input number three: ");
    scanf("%d", &numbers[2]);

    int directionSelection = 0;
    printf("Please input '0' to sort in descending order, ascending otherwise: ");
    scanf("%d", &directionSelection);
    const bool isAscending = directionSelection;

    if (isAscending) {
        qsort(numbers, S_NUMBERS, sizeof(numbers[0]), ascendingComparison);
    } else {
        qsort(numbers, S_NUMBERS, sizeof(numbers[0]), descendingComparison);
    }

    printf("Result\n");
    for (int i = 0; i < S_NUMBERS; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
