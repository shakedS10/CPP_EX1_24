//214695108 shakedshvartz2004@gmail.com

This program implements what algorithms we've learned in algo 1 using cpp
there are 5 algorithms:

isConnected - Checks if the graph is a strong connected graph i.e from every vertex there exists a path to every vertex, uses dfs to check.

shortestPath - Runs Bellman-Ford on the graph which relaxes the edges n-1 times and updates using the relax the prev vertex in the shortest path.

isContainsCycle - uses dfs in a recursive way to find a backedge and prints the cycle if found. the recursive part works differently for directed or undirected as if the graph is undirected there is no need for 3 colors only checking if it's not a direct egde to the parent.

isBipartite - uses dfs to color the graph in 2 colors in such way that a vertex can't have the same color as his parent, if it found a vertex with the same color as his parent return false. else consturct the string output as 2 groups.

negativeCycle - uses the idea of Bellman-Ford relaxes n-1 times amd if another relax has impact then there is a negative cycle (proven in algo 1).

To use this program type in the teminal make and use ./(test/demo) to run what you want. demo is mainly for examples some of the comments in the demo are incorrect, the tests are more precise and check if the program run as expected.
