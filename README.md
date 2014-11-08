TSP
===

Traveling salesman problem solutions

n or V - num of vertices

E - num of edges, E=n^2 for this problem

Brute force (brute_force_all_permutations) - checks all permutations - complexity O(n! * n)

DP (dynamic_programming_tsp_solution ) - O(N^2 * 2^N) time and O(N * 2^N) space

Both work for symmetric and asymmetric (directed and undirected) graphs.
Both brute force and DP have been checked by submitting the solutions to the uva online judge, problem: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1437

Given condition that you can visit each city multiple times simply compute distances between all vertices using floyd-warshall in O(n^3). Done in brute_force_multiple_visits. Overall complexity doesn't change. Same could be easily done for dynamic programming solution.

Nearest neighbour - O(n^2logn)

Repetitive nearest neighbour O(Nearest neigbour) * O(n) = O(n^3logn)

Both work for directed and undirected graphs.

Double MST - creates minimum spanning tree, then does n (each vertex as the starting point) times dfs (preorder traversal of the tree). Algorithm constructs for every dfs a tour, and finally it chooses the best tour. The output tour is guaranteed to be max not more than twice as long as optimal solution (only when triangle-inequality holds). MST complexity O(V^2), MST could be done in O(E * logV) but there is no point in doing that here, since we are considering only complete graphs. It works ofc only for undirected graphs. DFS is O(V) but we use dfs V number of times, to find the best tour constructed by MST. Overall complexity O(V^2). Algorithm should work easily for instances up to 10^4 num of vertices.


Important fact: "Without the triangle inequality, a polynomial time approximate algorithm with constant approximation ratio not exist unless P=NP."
We leave the proof as an exercise for the reader.

12cities_symetric.txt 
optimal found by both dp and all permutations: 1733
MST 2488
Nearest neighbour 2110
repetitive nearest neighbour 1733 (optimal) but other vertices order than dp or all permutations algorithm

