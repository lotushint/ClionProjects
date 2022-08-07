//
// Created by lotushint on 2022/8/5.
// 丰满树
// 构建的丰满树：
//             4
//     1               7
//  0     2         5     8
//          3     6         9
//

#include "PlumpTree.h"

int main() {
    BinaryTree tree;
    int node[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    tree = createPlumpTree(node, 0, 9);
    return 0;
}