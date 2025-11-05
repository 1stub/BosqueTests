#include <iostream>
#include <stdint.h>
#include <cassert>

struct foo {
    uint64_t bar;
};

foo f { 2 };


template<uint64_t NBits>
struct PackedBits {
    static constexpr uint64_t WORDS_NEEDED = (NBits + 63) / 64;
    uint64_t data[WORDS_NEEDED] = { 0 };
    
    void set(uint64_t index) noexcept {
        uint64_t word = index / 64;
        uint64_t bit = index % 64;
        this->data[word] |= (1ULL << bit);
     }
    
    bool get(uint64_t index) const noexcept {
        uint64_t word = index / 64;
        uint64_t bit = index % 64;
        return (this->data[word] >> bit) & 1;
    }
};

template<uint64_t NTypes>
class SupertypeTable {
private:
    PackedBits<NTypes * NTypes> bits;
    
    static inline uint64_t getTypeOffset(uint64_t sub, uint64_t super) noexcept {
        return sub * NTypes + super;
    }

public:
    template<uint64_t sub, uint64_t... supers>
    constexpr void set() noexcept {
        assert(sub <= NTypes);
        ((assert(supers <= NTypes)), ...);
        
        (this->bits.set(getTypeOffset(sub, supers)), ...);
    }
    
    inline bool get(uint64_t sub, uint64_t super) const noexcept {
        assert(sub < NTypes);
        assert(super < NTypes);
        return this->bits.get(getTypeOffset(sub, super));
    }
};

int main()
{
    SupertypeTable<12> supertypes;
    supertypes.set<1, 12, 2, 0>();

    std::cout << supertypes.get(f.bar,f.bar) << std::endl;

    return 0;
}