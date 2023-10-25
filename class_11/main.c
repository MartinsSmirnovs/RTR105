#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// By convention 0! is 1
// This function returns true if the passed number is 0 and we
// should use the convention
// This function returns false if the passed number is not 0 and we
// should NOT use the convention
bool checkForConvention(int number) {
    return number == 0;
}

// All factorial functions return 0 on failure, and
// non-zero number as factorial on success
#define FACTORIAL(Type)                                                                                                                              \
    Type factorial_##Type(int number) {                                                                                                              \
        if (checkForConvention(number)) {                                                                                                            \
            return 1;                                                                                                                                \
        }                                                                                                                                            \
                                                                                                                                                     \
        Type factorial = 1;                                                                                                                          \
        int i          = 1;                                                                                                                          \
        while (i <= number) {                                                                                                                        \
            /* Perform check for overflow before actually calculating and storing */                                                                 \
            /* next factorial value */                                                                                                               \
            /* By dividing each factorial value with it's last multiplier we should get the previous factorial value */                              \
            const Type factorialCheck = factorial * i;                                                                                               \
            if (factorialCheck / i != factorial) {                                                                                                   \
                return 0;                                                                                                                            \
            }                                                                                                                                        \
                                                                                                                                                     \
            factorial = factorialCheck;                                                                                                              \
            i++;                                                                                                                                     \
        }                                                                                                                                            \
                                                                                                                                                     \
        return factorial;                                                                                                                            \
    }

FACTORIAL(int);
FACTORIAL(char);
FACTORIAL(int64_t);

int main() {
    int number = 0;
    printf("Please input the decimal number: ");
    scanf("%d", &number);

    enum Decision {
        UseChar = 0,
        UseInt,
        UseLongLong
    };

    enum Decision decision = 0;
    printf("Please input:\n"
           "0 - for char data type\n"
           "1 - for int data type\n"
           "2 (or anything else) - for long long data type\n");
    scanf("%d", (int*)&decision);

    long long result = 0;
    switch (decision) {
        case UseInt: {
            result = factorial_int(number);
        } break;
        case UseChar: {
            result = factorial_char(number);
        } break;
        case UseLongLong:
        default: {
            result = factorial_int64_t(number);
        } break;
    }

    if (result == 0) {
        printf("The factorial cannot be calcualted! Please use different data type!\n");
    } else {
        printf("The factorial value for %d is %lld\n", number, result);
    }

    return 0;
}
