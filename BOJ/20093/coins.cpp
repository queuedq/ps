#include "coins.h"

std::vector<int> coin_flips(std::vector<int> b, int c) {
    int flip = 0;
    for (int i=0; i<64; i++) {
        if (b[i]) flip ^= i;
    }
    return {flip ^ c};
}

int find_coin(std::vector<int> b) {
    int flip = 0;
    for (int i=0; i<64; i++) {
        if (b[i]) flip ^= i;
    }
    return flip;
}
