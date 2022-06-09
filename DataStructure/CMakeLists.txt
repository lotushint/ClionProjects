cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

#线性表——顺序存储
add_executable(LinearListSequentialStorage linearList/sequentialstorage/test/SequenceList.c linearList/sequentialstorage/SequenceList.h)
#线性表顺序存储——顺序栈及其应用（括号匹配，后缀表达式计算）
add_executable(LinearListSequentialStorageStack linearList/sequentialstorage/test/SequentialStack.c linearList/sequentialstorage/SequentialStack.h)
#线性表顺序存储——顺序队列
add_executable(LinearListSequentialStorageQueue linearList/sequentialstorage/test/SequentialQueue.c linearList/sequentialstorage/SequentialQueue.h)
#线性表顺序存储——顺序循环队列（解决队列空间浪费）
add_executable(LinearListSequentialStorageCircularQueue linearList/sequentialstorage/test/SequentialCircularQueue.c linearList/sequentialstorage/SequentialCircularQueue.h)

#线性表——链式存储
add_executable(LinearListChainedStorage linearList/chainstorage/test/SinglyLinkedList.c linearList/chainstorage/SinglyLinkedList.h)
#线性表链式存储——带头结点的单链表
add_executable(LinearListChainedStorageLeadingNodeSinglyLinkedList linearList/chainstorage/test/LeadingNodeSinglyLinkedList.c linearList/chainstorage/LeadingNodeSinglyLinkedList.h)
#线性表链式存储——循环单链表
add_executable(LinearListChainedStorageCircularSinglyLinkedList linearList/chainstorage/test/CircularSinglyLinkedList.c linearList/chainstorage/CircularSinglyLinkedList.h)
#线性表链式存储——双链表
add_executable(LinearListChainedStorageDoublyLinkedList linearList/chainstorage/DoublyLinkedList.h linearList/chainstorage/test/DoublyLinkedList.c)