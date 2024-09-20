#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// #include <stdint.h> // already included in <inttypes.h>
#include <inttypes.h>

int main()
{
    int i;
    int32_t i32;            // 32 bit integer
    int_least8_t i8;        // smallest 8 bit
    int_fast16_t f8;        // fastest minimun
    intmax_t imax;          // biggest signed integers
    uintmax_t uimax;        // biggest unsigned integers

    i32 = 1004;

    printf("me32 = %d\n", i32);
    printf("me32 = %" "%d" "\n", i32);
    printf("me32 = %d" PRId32 "\n", i32);
    // PRI는 printf의 약자, d32이는 32비트의 decimal

    return 0;
}
