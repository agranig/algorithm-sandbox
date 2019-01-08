#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int main() {

    uint64_t bitfield[4];
    memset(bitfield, 0, sizeof(bitfield));

    unsigned char x = 'a';
    uint8_t idx = x >> 6; // take first 2 bits as index
    uint8_t bit = (x << 2) >> 2; // clear first 2 bits, use remaining 6

    bitfield[idx] |= 1 << bit;
    if(bitfield[idx] & (1 << bit)) {
        // bit is set
        printf("bit is set\n");
    }
    bitfield[idx] &= ~(1 << bit); // clear bit

    // uint64_t allset = (uint64_t) -1LL; // all bits set;

    uint64_t allset2 = ~(0LL);
    printf("allset2=%llx\n", (unsigned long long)allset2);
    printf("allset2=%" PRIx64 "\n", allset2);

    uint8_t minus = -1;
    printf("minus=%" PRIx8 "\n", minus);


    return 0;
}
