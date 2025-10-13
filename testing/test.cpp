#include <iostream>
#include <stdint.h>

int main()
{
    volatile uint64_t tmp = 7;
    *(volatile uint64_t**)alloca(sizeof(uint64_t)) = &tmp;

    return 0;
}