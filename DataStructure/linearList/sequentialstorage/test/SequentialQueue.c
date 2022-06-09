//
// Created by hefan on 2022/5/31.
//
#include "../SequentialQueue.h"

int main() {
    sequence_queue sq;
    init(&sq);
    printf("队列是否为空：%d\n", empty(sq));

    printf("队尾插入1：");
    insert(&sq, 1);
    display(sq);
    printf("\n队尾插入3：");
    insert(&sq, 3);
    display(sq);
    printf("\n队尾插入8：");
    insert(&sq, 8);
    display(sq);
    printf("\n队首：%d", get(sq));

    delete(&sq);
    printf("\n删除队首：");
    display(sq);

    return 0;
}