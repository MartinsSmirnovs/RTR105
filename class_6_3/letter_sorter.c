#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ascendingComparison(const void* left, const void* right) {
    const char characterOne = *(char*)left;
    const char characterTwo = *(char*)right;

    return toupper(characterOne) >= toupper(characterTwo);
}

int descendingComparison(const void* left, const void* right) {
    const char characterOne = *(char*)left;
    const char characterTwo = *(char*)right;

    return toupper(characterOne) <= toupper(characterTwo);
}

int main() {
    enum {
        S_CHARACTERS = 3
    };

    char characters[S_CHARACTERS];
    memset(characters, 0, S_CHARACTERS);

    printf("Please input character one: ");
    scanf(" %c", &characters[0]);

    printf("Please input character two: ");
    scanf(" %c", &characters[1]);

    printf("Please input character three: ");
    scanf(" %c", &characters[2]);

    int directionSelection = 0;
    printf("Please input '0' to sort in descending order, ascending otherwise: ");
    scanf("%d", &directionSelection);
    const bool isAscending = directionSelection;

    if (isAscending) {
        qsort(characters, S_CHARACTERS, sizeof(characters[0]), ascendingComparison);
    } else {
        qsort(characters, S_CHARACTERS, sizeof(characters[0]), descendingComparison);
    }

    printf("Result\n");
    for (int i = 0; i < S_CHARACTERS; i++) {
        printf("%c\n", characters[i]);
    }

    return 0;
}
