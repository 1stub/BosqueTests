#include <iostream>
#include <stdint.h>
#include <cassert>

typedef uint32_t UnicodeChar;


int main() {

   
    auto abc = U"馬'bcd";

    std::cout << sizeof(abc[1]) << std::endl;

    std::cout << abc[1] << std::endl;
    std::cout << abc[0] << std::endl;

    return 0;
}