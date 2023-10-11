#include <stdio.h>

union REG {
    unsigned char data;
    struct {
        char BIT0 : 1;
        char BIT1 : 1;
        char BIT2 : 1;
        char BIT3 : 1;
        char BIT4 : 1;
        char BIT5 : 1;
        char BIT6 : 1;
        char BIT7 : 1;
    };
};

int main() {
    union REG reg;

    reg.data = 0;

    reg.BIT0 = 1;
    reg.BIT1 = 1;

    printf("%d\n", reg.data);
    return 0;
}
