# Class implementations of Algorithms and Data Structures

# [Data Structures](https://github.com/yvesemmanuel/datastructures_algorithms/tree/main/data_structures)
## [Array-Based List](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20list.cpp)
* ± Predefined maximum size (alternative: dynamic arrays)
* *+* No extra space with pointers (links)
* − Space consumed by unused positions
* **Time complexity** (worst and average case): **Access - θ(*1*)**; **Search - θ(*n*)**; **Insertion - θ(*n*)**; **Deletion - θ(*n*)**.

## [Linked List](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/singly%20linked%20list.cpp)
* *+* With no predefined maximum size
* *+* No extra space for no longer accessible elements
* − Space consumed by pointers (links)
* **Time complexity** (worst and average case): **Access - θ(*n*)**; **Search - θ(*n*)**; **Insertion - θ(*1*)**; **Deletion - θ(*1*)**.

## [Array-Based Queue](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20queue.cpp)
* Policy: FIFO = first-in, first-out;
* The first element added to the queue will be the first one to be removed.

## [Array-Based Stack](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20stack.cpp) and [Linked Stack](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/linked%20stack.cpp)
* Policy: LIFO = last-in, first-out;
* The last element added to the stack will be the first to be removed.

## [Graph](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/adjacency-matrix%20based%20graph.cpp)
* A graph is a collection of nodes (vertices), some of them connected by edges, where |V| != 0.
* A graph implemented as an **adjacency matrix** is recommended for a dense graph, and a graph implemented as an **adjacency list** is recommended for a sparse graph.
* As an **adjacency matrix**, its time efficiency (graph traversal) belongs to **Θ(|V|²)**, and as an **adjacency list**, its time efficiency belongs to **Θ(|V|+|E|)**.

#### Graph Traversals


* DFS: depth-first search
  * It starts at a selected arbitrary node as the root node in the graph and explores as far as possible along each branch before backtracking.


* BFS: breadth-first search
  * It starts at a selected arbitrary node as the root node in the graph and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.

## [Binary Search Tree](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/BST%20based%20dictionary.cpp)
* **Tree**: Connected acyclic graph.
* **m-ary tree**: every internal vertex has no more than m children
* m-ary tree, where m = 2: **binary tree**
* Ordered binary tree: **binary search tree** (BST)
* **Time complexity** (average case): **Access - θ(*log n*)**; **Search - θ(*log n*)**; **Insertion - θ(*log n*)**; **Deletion - θ(*log n*)**.
* **Time complexity** (worst case): **Access - θ(*n*)**; **Search - θ(*n*)**; **Insertion - θ(*n*)**; **Deletion - θ(*n*)**.
