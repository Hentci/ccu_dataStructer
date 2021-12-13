# Assignment V - — Graph

============================================================================================================

## Problem 1. Longest River problem

This is a C program, compile this program and run.

### Input format

First, input two integers n and m which imply the number of river sources and the confluence.
Second, input the data about the name, confluence, and length of the river.
Since we need to compare the data with the previous index, I start the input from the array of index 1.
Third, input an integer o which imply the number of relationships.
Finally, input the o datas, which respectively are two confluences and their distance.

### Output format

print the data with their rank.

### Function explaination

cmp: a compare function ,which is use for qsort.

Detailed explanation are writen in source code.

### How the program works

The program will rank all the rivers in the system problem gives.

============================================================================================================

## Problem 2. Articulation point detection

This is a C program, compile this program and run.

### Input format

First, input two integers, which are root and the number of vertex respectively.
Second, input and build the adjacent graph simultaneously.

### Output format

First, it output the dfn of all the vertexs that according to the adjacent list.
Second, it output the low of all the vertexs that according to the adjacent list.
Finally, it output the Articulation point of all the vertexs in ascending order that according to the adjacent list.

### Function explaination

cmp: a compare function ,which is use for qsort.

dfs: it do the depth-first search according to the adjacent graph.
     And it find and update the dfn, low, Articulation point simultaneously.

Detailed explanation are writen in source code.

### How the program works

The program will find the dfn, low and Articulation points according to the graph.

============================================================================================================

## Problem 3. Meeting points

This is a C program, compile this program and run.

### Input format

First, it input two integers n and m, and check whether it is end of file or not.
Second, input the n names(vertexs).
Third, input three integer which are two vertexs and their weight, and build the distance graph simultaneously.

### Output format

Output the minimum cost name and follow the format problem gives.

### Function explaination

None.

Detailed explanation are writen in source code.

### How the program works

The program will implement the Floyd Warshall algorithm to build the distance graph.
And find the group member which have the minimum sum.

============================================================================================================