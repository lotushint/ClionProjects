cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

#2
#线性表——顺序存储
add_executable(LinearListSequentialStorage linearList/sequentialstorage/test/SequenceList.c linearList/sequentialstorage/SequenceList.h)
#线性表顺序存储——顺序栈及其应用（括号匹配，后缀表达式计算）
add_executable(LinearListSequentialStorageStack linearList/sequentialstorage/test/SequentialStack.c linearList/sequentialstorage/SequentialStack.h)
#线性表顺序存储——顺序队列
add_executable(LinearListSequentialStorageQueue linearList/sequentialstorage/test/SequentialQueue.c linearList/sequentialstorage/SequentialQueue.h)
#线性表顺序存储——顺序循环队列（解决队列空间浪费）
add_executable(LinearListSequentialStorageCircularQueue linearList/sequentialstorage/test/SequentialCircularQueue.c linearList/sequentialstorage/SequentialCircularQueue.h)

#3
#线性表——链式存储
add_executable(LinearListLinkedStorage linearList/linkedstorage/test/SinglyLinkedList.c linearList/linkedstorage/SinglyLinkedList.h)
#线性表链式存储——带头结点的单链表
add_executable(LinearListLinkedStorageLeadingNodeSinglyLinkedList linearList/linkedstorage/test/LeadingNodeSinglyLinkedList.c linearList/linkedstorage/LeadingNodeSinglyLinkedList.h)
#线性表链式存储——循环单链表
add_executable(LinearListLinkedStorageCircularSinglyLinkedList linearList/linkedstorage/test/CircularSinglyLinkedList.c linearList/linkedstorage/CircularSinglyLinkedList.h)
#线性表链式存储——双链表
add_executable(LinearListLinkedStorageDoublyLinkedList linearList/linkedstorage/DoublyLinkedList.h linearList/linkedstorage/test/DoublyLinkedList.c)
#线性表链式存储——链式栈
add_executable(LinearListLinkedStorageChainStack linearList/linkedstorage/LinkedStack.h linearList/linkedstorage/test/LinkedStack.c)
#线性表链式存储——链式栈
add_executable(LinearListLinkedStorageLinkedQueue linearList/linkedstorage/LinkedQueue.h linearList/linkedstorage/test/LinkedQueue.c)

#4
#字符串——顺序存储
add_executable(SequenceString string_array_specialmatrix/string/sequencestring/SequenceString.h string_array_specialmatrix/string/sequencestring/test/SequenceString.c)
#字符串——链式存储
add_executable(LinkedString string_array_specialmatrix/string/linkedstring/LinkedString.h string_array_specialmatrix/string/linkedstring/test/LinkedString.c)
#字符串——朴素的模式匹配（顺序串）
add_executable(SequenceStringBruteForcePatternMatching string_array_specialmatrix/string/patternmatching/BruteForce.h string_array_specialmatrix/string/patternmatching/test/BruteForce.c)
#字符串——快速模式匹配（顺序串）
add_executable(SequenceStringKMPPatternMatching string_array_specialmatrix/string/patternmatching/KMP.h string_array_specialmatrix/string/patternmatching/test/KMP.c)
#数组——三维数组（顺序存储）
add_executable(Array string_array_specialmatrix/array/test/Array.c string_array_specialmatrix/array/Array.h)
#特殊矩阵——带状矩阵
add_executable(SpecialMatrixStripMatrix string_array_specialmatrix/specialmatrix/test/StripMatrix.c string_array_specialmatrix/specialmatrix/StripMatrix.h)

#6
#树型结构——树的存储方式（双亲表示法，孩子表示法（指针方式，数组方式，链表方式），孩子兄弟表示法），树的构造和遍历（前序遍历，后序遍历，层次遍历）
add_executable(TreeStorageStructure tree/treestoragestructure/ParentalRepresentation.h tree/treestoragestructure/ChildRepresentation1.h tree/treestoragestructure/ChildRepresentation2.h tree/treestoragestructure/ChildRepresentation3.h tree/treestoragestructure/KidBrotherRepresentation.h tree/traverse/Traverse.h tree/test/ChildRepresentation1Traverse.c)
add_executable(BracketToChildRepresentation tree/brackettochild/BracketToChildRepresentation.h tree/test/BracketToChildRepresentation.c)
add_executable(LevelToChildRepresentation tree/leveltochild/LevelToChildRepresentation.h tree/test/LevelToChildRepresentation.c)

#7
#顺序存储完全（满）二叉树
add_executable(BinaryTree binarytree/BinaryTree.h binarytree/test/BinaryTree.c)