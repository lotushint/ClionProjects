//
// Created by hefan on 2022/5/29.
//
#include "../SequenceList.h"

int main() {
    sequence_list slt;
    init(&slt);
    append(&slt, 5);
    insert(&slt, 6, 0);
    insert(&slt, 1, 0);
    display(slt);
    printf("\n");
    delete(&slt, 0);
    display(slt);
    return 0;
}