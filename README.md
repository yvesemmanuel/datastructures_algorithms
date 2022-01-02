# Algorithms and Data Structures description

# [Data Structures](https://github.com/yvesemmanuel/datastructures_algorithms/tree/main/data_structures)
### [Array-Based List](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20list.cpp)
* ± Predefined maximum size (alternative: dynamic arrays)
* *+* No extra space with pointers (links)
* − Space consumed by unused positions
* **Time complexity** (worst and average case): **Access - θ(*1*)**; **Search - θ(*n*)**; **Insertion - θ(*n*)**; **Deletion - θ(*n*)**.

### [Singly Linked List](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/singly%20linked%20list.cpp)
* *+* With no predefined maximum size
* *+* No extra space for no longer accessible elements
* − Space consumed by pointers (links)
* **Time complexity** (worst and average case): **Access - θ(*n*)**; **Search - θ(*n*)**; **Insertion - θ(*1*)**; **Deletion - θ(*1*)**.

### [Array-Based Queue](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20queue.cpp)
* Policy: FIFO = first-in, first-out;
* The first element added to the queue will be the first one to be removed.

### [Array-Based Stack](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/array-based%20stack.cpp) and [Linked Stack](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/linked%20stack.cpp)
* Policy: LIFO = last-in, first-out;
* The last element added to the stack will be the first to be removed.

### [Graph](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/adjacency-matrix%20based%20graph.cpp)
* A graph is a collection of nodes (vertices), some of them connected by edges, where |V| != 0.
* A graph implemented as an **adjacency matrix** is recommended for a dense graph, and a graph implemented as an **adjacency list** is recommended for a sparse graph.
* As an **adjacency matrix**, its time efficiency (graph traversal) belongs to **Θ(|V|²)**, and as an **adjacency list**, its time efficiency belongs to **Θ(|V|+|E|)**.

#### Graph Traversals

* DFS: depth-first search
  * It starts at a selected arbitrary node as the root node in the graph and explores as far as possible along each branch before backtracking.


* BFS: breadth-first search
  * It starts at a selected arbitrary node as the root node in the graph and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.

* Topological Sorting
  * Let G be a **DAG** (directed acyclic graph), a topological sorting is a linear ordering of its vertices such that for every directed edge 'uv' from vertex 'u' to vertex 'v', 'u' comes before 'v' in the ordering.

### [Binary Search Tree](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/data_structures/BST%20based%20dictionary.cpp)
* **Tree**: Connected acyclic graph.
* **m-ary tree**: every internal vertex has no more than m children
* m-ary tree, where m = 2: **binary tree**
* Ordered binary tree: **binary search tree** (BST)
* **Time complexity** (average case): **Access - θ(*log n*)**; **Search - θ(*log n*)**; **Insertion - θ(*log n*)**; **Deletion - θ(*log n*)**.
* **Time complexity** (worst case): **Access - θ(*n*)**; **Search - θ(*n*)**; **Insertion - θ(*n*)**; **Deletion - θ(*n*)**.


# [Algorithms](https://github.com/yvesemmanuel/datastructures_algorithms/tree/main/algorithms)
## [Sorting](https://github.com/yvesemmanuel/datastructures_algorithms/tree/main/algorithms/sorting)
#### You should consider the worst case for all time and space complexity.

### [Seletion Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/selection%20sort%20(brute%20force).cpp)
* It's an in-place comparison sorting algorithm. It has an **O(*n²*)** time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort.
* Space complexity: **O(*1*)**
* **Design strategy: brute force**

### [Bubble Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/bubble%20sort.cpp)
* It's a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. 
* *+* Simple implementation
* Time complexity: **O(*n²*)**
* Space complexity: **O(*1*)**
* *+* Stable

### [Insertion Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/insertion%20sort%20(decrease-and-conquer).cpp)
* It's a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. 
* *+* More efficient in practice than most other simple quadratic (i.e., **O(*n²*)**) algorithms such as selection sort or bubble sort
* *+* Simple implementation
* Space complexity: **O(*1*)**
* *+* Stable
* **Design strategy: decrease-and-conquer**

### [Merge Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/merge%20sort.cpp)
* Conceptually, a merge sort works as follows:

  * Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
  * Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

* Time complexity: **O(*nlog n*)**
* Space complexity: **O(*n*)**
* *-* Not in-place
* *+* Stable
* **Design strategy: divide-and-conquer**

### [Quick Sort](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/sorting/quick%20sort.cpp)
* It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. For this reason, it is sometimes called **partition-exchange sort**.

* Time complexity: **O(*n²*)**, but **Ω(*nlog n*)** in best and average case
* Space complexity: **O(*log n*)**
* *+* In-place
* *-* Not stable
* **Design strategy: divide-and-conquer**

### [Dijkstra](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/single-source%20shortest%20paths/dijkstra.cpp)
* Let G be a weighted graph and *v* (source) a vertice that belongs to G, finds the shortest path from *v* to all other vertices in G.

* It can't be used on weighted graphs with negative weights
* Time complexity: **O(|*V²*|)**, V = number of vertices
* **Design strategy: greedy algorithms**

### [Bellman-Ford](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/single-source%20shortest%20paths/bellman-ford.cpp)
* Let G be a weighted graph and *v* (source) a vertice that belongs to G, finds the shortest path from *v* to all other vertices in G.

* It can be used on weighted graphs with negative cycles
* Time complexity: **O(|*V³*|)**, V = number of vertices
* **Design strategy: dynamic programming**

### [Floyd-Warshall](https://github.com/yvesemmanuel/datastructures_algorithms/blob/main/algorithms/all-pairs%20shortest%20paths/floyd-warshall.cpp)
* Let G be a weighted graph, finds the shortest path between all pairs of nodes in G.
* Floyd algorithm: can be used on weighted graphs with negative weights (but no negative cycles)
  * Based on the Warshall algorithm for computing transitive closures

* Time complexity: **O(|*V³*|)**, V = number of vertices
* **Design strategy: dynamic programming**
