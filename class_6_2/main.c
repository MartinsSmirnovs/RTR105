#include <stdio.h>

int main() {
    unsigned char number = 0;

    printf("Please input 8 bit number: ");
    scanf("%hhu", &number);

    printf("Result: ");

    printf("%d", (unsigned char)(number << 0) >> 7);
    printf("%d", (unsigned char)(number << 1) >> 7);
    printf("%d", (unsigned char)(number << 2) >> 7);
    printf("%d", (unsigned char)(number << 3) >> 7);
    printf("%d", (unsigned char)(number << 4) >> 7);
    printf("%d", (unsigned char)(number << 5) >> 7);
    printf("%d", (unsigned char)(number << 6) >> 7);
    printf("%d", (unsigned char)(number << 7) >> 7);

    printf("\n");

    return 0;
}
