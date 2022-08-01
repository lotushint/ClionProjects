cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

#2
#线性表——顺序存储
add_executable(LinearListSequentialStorage linearlist/sequentialstorage/test/SequenceList.c linearlist/sequentialstorage/SequenceList.h)
#线性表——顺序存储——顺序栈及其应用（括号匹配，后缀表达式计算）
add_executable(LinearListSequentialStorageStack linearlist/sequentialstorage/test/SequentialStack.c linearlist/sequentialstorage/SequentialStack.h)
#线性表——顺序存储——顺序队列
add_executable(LinearListSequentialStorageQueue linearlist/sequentialstorage/test/SequentialQueue.c linearlist/sequentialstorage/SequentialQueue.h)
#线性表——顺序存储——顺序循环队列（解决队列空间浪费）
add_executable(LinearListSequentialStorageCircularQueue linearlist/sequentialstorage/test/SequentialCircularQueue.c linearlist/sequentialstorage/SequentialCircularQueue.h)

#3
#线性表——链式存储
add_executable(LinearListLinkedStorage linearlist/linkedstorage/test/SinglyLinkedList.c linearlist/linkedstorage/SinglyLinkedList.h)
#线性表——链式存储——带头结点的单链表
add_executable(LinearListLinkedStorageLeadingNodeSinglyLinkedList linearlist/linkedstorage/test/LeadingNodeSinglyLinkedList.c linearlist/linkedstorage/LeadingNodeSinglyLinkedList.h)
#线性表——链式存储——循环单链表
add_executable(LinearListLinkedStorageCircularSinglyLinkedList linearlist/linkedstorage/test/CircularSinglyLinkedList.c linearlist/linkedstorage/CircularSinglyLinkedList.h)
#线性表——链式存储——双链表
add_executable(LinearListLinkedStorageDoublyLinkedList linearlist/linkedstorage/DoublyLinkedList.h linearlist/linkedstorage/test/DoublyLinkedList.c)
#线性表——链式存储——链式栈
add_executable(LinearListLinkedStorageChainStack linearlist/linkedstorage/LinkedStack.h linearlist/linkedstorage/test/LinkedStack.c)
#线性表——链式存储——链式栈
add_executable(LinearListLinkedStorageLinkedQueue linearlist/linkedstorage/LinkedQueue.h linearlist/linkedstorage/test/LinkedQueue.c)

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
#树型结构——树的线性表示——树的括号表示（将树的括号表示转换成树的孩子表示（数组方式））
add_executable(BracketToChildRepresentation tree/brackettochild/BracketToChildRepresentation.h tree/test/BracketToChildRepresentation.c)
#树型结构——树的线性表示——树的层号表示（将树的层号表示转换成树的扩充孩子表示（增加一个域指向结点双亲的下标））
add_executable(LevelToChildRepresentation tree/leveltochild/LevelToChildRepresentation.h tree/test/LevelToChildRepresentation.c)

#7
#二叉树——二叉树的存储结构——顺序存储（完全二叉树的顺序存储，一般二叉树的顺序存储，一般二叉树的顺序存储扩展（增加一个存放双亲下标的域））
add_executable(SequentialStorageOfBinaryTree binarytree/binarytreestorage/sequentialstorage/CompleteBinaryTreeStructure.h binarytree/binarytreestorage/sequentialstorage/GeneralBinaryTreeStructure.h binarytree/binarytreestorage/sequentialstorage/GeneralBinaryTreeStructure2.h binarytree/test/Seq.c)
#二叉树——二叉树的存储结构——链式存储（链式存储，链式存储扩展（增加了一个指针域指向结点的双亲）,二叉树的遍历（递归方式），二叉树的遍历（非递归方式），二叉树的创建（前序遍历））
add_executable(LinkedStorageOfBinaryTree binarytree/binarytreestorage/linkedstorage/BinaryTreeStructure.h binarytree/binarytreestorage/linkedstorage/BinaryTreeStructure2.h binarytree/traverse/BinaryTraverse.h binarytree/traverse/BinaryTraversalNon_Recursive.h binarytree/binarytreecreation/BinaryTreeCreation.h binarytree/test/BinaryTraverseRecursionAndNon_Recursion.c binarytree/binarytreeotheroperations/BinaryTreeOtherOperations.h)
#二叉树——穿线二叉树（中序穿线二叉树）
add_executable(InorderThreadingBinaryTree binarytree/inorderthreadingbinarytree/storage/InorderThreadingBinaryTreeStorage.h binarytree/inorderthreadingbinarytree/test/InorderThreadingBinaryTree.c binarytree/inorderthreadingbinarytree/creation/InorderThreadingBinaryTreeCreation.h binarytree/inorderthreadingbinarytree/traverse/InorderThreadingBinaryTreeTraverse.h)

#8
#图——图的基本存储结构——邻接矩阵
add_executable(AdjacencyMatrix graph/adjacency/adjacencymatrix/AdjacencyMatrix.h graph/test/AdjacencyMatrix.c)
#图——图的基本存储结构——邻接表
add_executable(AdjacencyList graph/adjacency/adjacencylist/AdjacencyListStorageStructure.h graph/adjacency/adjacencylist/AdjacencyListCreation.h graph/test/AdjacencyList.c)
#图——图的基本存储结构——邻接多重表
add_executable(AdjacencyMultiList graph/test/AdjacencyMultiList.c)
#图——图的遍历——深度优先遍历
add_executable(Depth-firstTraversal graph/traverse/Depth-firstTraversal.h graph/test/Depth-firstTraversal.c)
#图——图的遍历——广度优先遍历
add_executable(Breadth-firstTraversal graph/traverse/Breadth-firstTraversal.h graph/test/Breadth-firstTraversal.c)
#图——生成树与最小生成树——Prim最小生成树算法
add_executable(PrimMinimumSpanningTree graph/minimumspanningtree/primminimumspanningtree/PrimMinimumSpanningTree.h graph/test/PrimMinimumSpanningTree.c)
#图——生成树与最小生成树——Kruskal最小生成树算法
add_executable(KruskalMinimumSpanningTree graph/minimumspanningtree/kruskalminimumspanningtree/KruskalMinimumSpanningTree.h graph/test/KruskalMinimumSpanningTree.c)
#图——最短路径——单源最短路径
add_executable(SingleSourceShortestPath graph/test/SingleSourceShortestPath.c graph/shortestpath/singlesourceshortestpath/SingleSourceShortestPath.h)
#图——所有顶点对的最短路径（单源最短路径，floyd算法）
add_executable(ShortestPathForAllVertexPairs graph/test/ShortestPathForAllVertexPairs.c graph/shortestpath/shortestpathforallvertexpairs/ShortestPathForAllVertexPairs.h)
#图——拓扑排序
add_executable(TopologicalSort graph/test/TopologicalSort.c graph/topologicalsort/TopologicalSort.h)
#图——关键路径
add_executable(CriticalPath graph/test/CriticalPath.c graph/criticalpath/CriticalPath.h)

#9
#检索——线性表的检索——检索顺序表
add_executable(RetrieveSequentialList retrieve/test/RetrieveSequentialList.c retrieve/sequentialsearch/sequentiallist/RetrieveSequentialList.h)
#检索——线性表的检索——检索链式表
add_executable(RetrieveLinkedList retrieve/test/RetrieveLinkedList.c retrieve/sequentialsearch/linkedlist/RetrieveLinkedList.h)