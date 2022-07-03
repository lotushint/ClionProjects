//
// Created by lotushint on 2022/6/19.
//
#include "../KMP.h"

int main() {
    sequenceString p;
    p.string[0] = 'a';
    p.string[1] = 'b';
    p.string[2] = 'c';
    p.string[3] = 'a';
    p.string[4] = 'b';
    p.string[5] = 'a';
    p.string[6] = 'c';
    p.string[7] = '\0';
    p.length = 7;

    int next[8];
    Next(p.string, next);
    for (int i = 0; i < 8; ++i) {
        printf("%5d ",next[i]);
    }
    return 0;
}