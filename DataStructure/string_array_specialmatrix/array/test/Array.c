//
// Created by lotushint on 2022/6/20.
//

#include "../Array.h"

int main() {
    array a;
    datatype value;
    initArray(&a, 2, 3, 4);
    assign(&a, 3, 1, 2, 3);
    getValue(a, 1, 2, 3, &value);
    printf("%d", value);
    return 0;
}