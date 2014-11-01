TSP
===

Traveling salesman problem solutions
n or V - num of vertices
E=num of edges, E=n^2
Brute force (brute_force_all_permutations) - checks all permutations - complexity O(n! * n)
DP (dynamic_programming_tsp_solution ) - O(N^2 * 2^N) time and O(N * 2^N) space
Both work for symetric and asymetric (directed and undirected) graphs.

Both brute force and DP have been checked by submitting the solutions to the uva online judge, problem: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1437

Given condition that you can visit each city multiple times simply compute distances between all vertices using floyd-warshall in O(n^3). Done in brute_force_multiple_visits. Overall complexity doesn't hange. Same could be easly done for dynamic aproach solution.

Nearest neighbour - O(n^2)
Repetitive nearest neighbour O(Nearest neigbour) * O(n) = O(n^3)



