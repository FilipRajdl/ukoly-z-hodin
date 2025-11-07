#include <iostream>
#include <cstdint>

int main() {
    uint64_t a = 65;      // můžeš změnit podle svého vstupu
    uint64_t b = 8921;    // můžeš změnit podle svého vstupu
    const uint64_t factorA = 1092455;
    const uint64_t factorB = 430625591;
    const uint64_t divisor = 2147483647;

    int matches = 0;

    for (int i = 0; i < 40000000; ++i) {
        a = (a * factorA) % divisor;
        b = (b * factorB) % divisor;

        if ( (a & 0xFFFF) == (b & 0xFFFF) ) {
            ++matches;
        }
    }

    std::cout << "Po 40 000 000 parech: " << matches << " shod." << std::endl;
    return 0;
}
