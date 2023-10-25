#include <stdio.h>

void foo_simple() {
    printf("Simple\n");

    printf("\n");
}

int foo_return() {
    printf("Returned\n");

    printf("\n");

    return 1;
}

void foo_argument(int argument) {
    printf("Argument: %d\n", argument);

    printf("\n");
}

int foo_complex(int argument1, int argument2) {
    printf("Argument1: %d\n", argument1);
    printf("Argument2: %d\n", argument2);
    const int sum = argument1 + argument2;
    printf("Sum: %d\n", sum);

    printf("\n");

    return sum;
}
