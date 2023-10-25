# Algorithms and Data Structures Description

## [Data Structures](https://github.com/yvesemmanuel/datastructures_algorithms/tree/main/data_structures)
### [Array-Based List](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20list.cpp)
- ± Predefined maximum size (alternative: dynamic arrays)
- *+* No extra space with pointers (links)
- − Space is consumed by unused positions
- **Time Complexity** (worst and average case): **Access - θ(*1*)** | **Search - θ(*n*)** | **Insertion - θ(*n*)** | **Deletion - θ(*n*)**.

### [Singly Linked List](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/singly%20linked%20list.cpp)
- *+* No predefined maximum size
- *+* No extra space for inaccessible elements
- − Space is consumed by pointers (links)
- **Time Complexity** (worst and average case): **Access - θ(*n*)** | **Search - θ(*n*)** | **Insertion - θ(*1*)** | **Deletion - θ(*1*)**.

### [Array-Based Queue](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20queue.cpp)
- Policy: FIFO = first-in, first-out
- The first element added to the queue will be the first to be removed.

### [Array-Based Stack](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20stack.cpp) and [Linked Stack](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/linked%20stack.cpp)
- Policy: LIFO = last-in, first-out
- The last element added to the stack will be the first to be removed.

### [Graph](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/adjacency-matrix%20based%20graph.cpp)
- A graph is a collection of nodes (vertices) connected by edges where |V| != 0.
- An adjacency matrix is recommended for a dense graph, and an adjacency list is recommended for a sparse graph.
- As an adjacency matrix, its time efficiency (graph traversal) is **Θ(|V|²)**, and as an adjacency list, its time efficiency is **Θ(|V|+|E|)**.

#### Graph Traversals
- DFS: Depth-first search starts at a selected arbitrary node as the root node in the graph and explores as far as possible along each branch before backtracking.
- BFS: Breadth-first search starts at a selected arbitrary node as the root node in the graph and explores all neighboring nodes at the present depth before moving to nodes at the next depth level.
- Topological Sorting: For a directed acyclic graph (DAG), topological sorting is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.

### [Binary Search Tree (BST)](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/BST%20based%20dictionary.cpp)
- A binary search tree (BST) is an ordered binary tree where each internal vertex has no more than two children.
- **Time Complexity** (average case): **Access - θ(*log n*)** | **Search - θ(*log n*)** | **Insertion - θ(*log n*)** | **Deletion - θ(*log n*)**.
- **Time Complexity** (worst case): **Access - θ(*n*)** | **Search - θ(*n*)** | **Insertion - θ(*n*)** | **Deletion - θ(*n*)**.

### [AVL Tree](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/AVL%20tree.cpp)
- The balance factor of every node is either -1, 0, or 1.
- The difference between the heights of the left and right subtrees.
- The height of an empty tree is -1.
- An AVL tree is a self-balancing binary search tree.
- **Rotation** is a local transformation to rebalance the tree.
- **Time Complexity** (average and worst case): **Access - θ(*log n*)** | **Search - θ(*log n*)** | **Insertion - θ(*log n*)** | **Deletion - θ(*log n*)**.

## [Algorithms](https://github.com/yvesemmanuel/datastructures_algorithms/tree/main/algorithms)
Consider the worst case for all time and space complexities.

### [Sorting](https://github.com/yvesemmanuel/datastructures_algorithms/tree/main/algorithms/sorting)
#### [Selection Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/selection%20sort%20(brute%20force).cpp)
- An in-place comparison sorting algorithm.
- **Time Complexity**: **O(*n²*)**.
- **Space Complexity**: **O(*1*)**.
- **Design Strategy**: Brute force.

#### [Bubble Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/bubble%20sort.cpp)
- A simple sorting algorithm that repeatedly steps through the list, comparing and swapping adjacent elements if they are in the wrong order.
- **Time Complexity**: **O(*n²*)**.
- **Space Complexity**: **O(*1*)**.
- Stable.

#### [Insertion Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/insertion%20sort%20(decrease-and-conquer).cpp)
- A simple sorting algorithm that builds the final sorted array (or list) one item at a time.
- **Time Complexity**: **O(*n²*)** in the worst case but more efficient in practice than other quadratic algorithms.
- **Space Complexity**: **O(*1*)**.
- Stable.
- **Design Strategy**: Decrease-and-conquer.

#### [Merge Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/merge%20sort.cpp)
- A divide-and-conquer algorithm that divides the unsorted list into n sublists, repeatedly merging them to produce sorted sublists until there is only one sublist remaining.
- **Time Complexity**: **O(*nlog n*)**.
- **Space Complexity**: **O(*n*)**.
- Not in-place.
- Stable.
- **Design Strategy**: Divide-and-conquer.

#### [Quick Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/quick%20sort.cpp)
- A divide-and-conquer algorithm that selects a pivot element from the array and partitions the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.
- **Time Complexity**: **O(*n²*)** in the worst case but **Ω(*nlog n*)** in the best
