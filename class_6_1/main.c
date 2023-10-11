#include <stdio.h>

int main() {
    long numberOne = 0;
    long numberTwo = 0;

    printf("Please input the first number: ");
    scanf("%ld", &numberOne);
    printf("Please input the second number: ");
    scanf("%ld", &numberTwo);

    const unsigned long result = numberOne * numberTwo;

    printf("Result: %ld\n", result);

    return 0;
}
