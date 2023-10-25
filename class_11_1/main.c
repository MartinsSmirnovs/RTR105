#include "foo.h"
#include <stdio.h>

int main() {
    foo_simple();
    foo_argument(3);
    const int value  = foo_return();
    const int value2 = foo_complex(1, 2);

    return 0;
}
