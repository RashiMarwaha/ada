# **ADA - Algorithm Design and Analysis**

This repository contains implementations of various fundamental algorithms, categorized into sorting, searching, similarity measures, matrix operations, optimization problems, and graph algorithms. Each algorithm is implemented in C++ and analyzed for time complexity, space complexity, and performance.

---

## **1. Sorting Algorithms**
Sorting algorithms are used to arrange data in a specific order. The efficiency of sorting is crucial in data structures, databases, and many real-world applications.

- **Selection Sort Time Complexity** – Iteratively selects the minimum element and places it in the correct position. Time Complexity: O(n²).
- **Merge Sort Time Complexity** – A divide-and-conquer algorithm that recursively splits arrays and merges them efficiently. Time Complexity: O(n log n).
- **Quick Sort Time Complexity** – Uses partitioning to sort elements recursively. Best/Average Time Complexity: O(n log n), Worst: O(n²).
- **Bubble Sort Time Complexity** – Repeatedly swaps adjacent elements if they are in the wrong order. Best Case: O(n), Worst/Average: O(n²).
- **Quick Sort Iterative** – Implements Quick Sort using an iterative approach instead of recursion to avoid stack overflows.
- **Quick Sort Stack Calls** – Analyzes the number of stack calls required in Quick Sort.

---

## **2. Searching Algorithms**
Searching algorithms efficiently retrieve elements from datasets.

- **Linear Search** – Scans each element sequentially. Best Case: O(1), Worst: O(n).
- **Binary Search** – Recursively divides the array to locate the target element. Time Complexity: O(log n).
- **1D Peak Finding** – Finds a peak in a 1D array where an element is greater than its neighbors. Time Complexity: O(log n).
- **2D Peak Finding** – Finds a peak element in a 2D matrix using column-wise searching. Time Complexity: O(n log m).

---

## **3. Similarity Measures**
Similarity measures are used in data analysis, clustering, and recommendation systems.

- **Cosine Similarity** – Measures the cosine of the angle between two non-zero vectors. Used in NLP and text similarity.
- **Jaccard Similarity** – Measures the similarity between two sets as the intersection over union. Used in text classification.

---

## **4. Matrix Operations**
Matrix operations are critical in linear algebra, graphics, AI, and scientific computing.

- **Magic Square** – Generates a square matrix where the sum of each row, column, and diagonal is the same.
- **Matrix Multiplication - Brute Force** – Implements standard matrix multiplication using three nested loops.
- **Matrix Multiplication - Divide and Conquer** – Recursively divides matrices and combines the results for multiplication.
- **Matrix Multiplication - Strassen Algorithm** – Optimized approach that reduces multiplication operations. Time Complexity: O(n^2.81).
- **Determinant and Side Checking** – Calculates the determinant of a matrix and determines the relative position of points.

---

## **5. Optimization Problems**
Optimization problems find the best solution among feasible alternatives.

- **Max Min** – Uses divide and conquer to find the maximum and minimum elements in an array.
- **Knapsack Problem** – Implements the fractional knapsack problem using a greedy algorithm to maximize profit.
- **Activity Selection** – Selects the maximum number of activities that don't overlap using a greedy approach.

---

## **6. Graph Algorithms**
Graph algorithms are used in networking, AI, and operations research.

- **Dijkstra’s Algorithm** – Finds the shortest path from a single source vertex to all other vertices.
- **Prim’s Algorithm** – Constructs the Minimum Spanning Tree (MST) by adding the smallest edge at each step.
- **Kruskal’s Algorithm** – Constructs the MST by selecting the smallest edges while avoiding cycles.
- **Multi-Stage Graphs** – Finds the shortest path in a multi-stage weighted graph.
- **All Pairs Shortest Paths** – Computes shortest paths between all pairs of vertices in a weighted graph.

---
