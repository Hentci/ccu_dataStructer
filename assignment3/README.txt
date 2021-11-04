# Assignment III - — Linked list

============================================================================================================

## Problem 1. Get in line 

This is a C program, compile this program and run.

### Input format

First, input the integer q to know that how many query after that.
Second, according the type of query, do the operation.
Since the head alphabet of every operation is different, I readily categorize them by the first alphabet.
i -> insert
d -> delete
s -> swap
q -> query

And finally, according to the description of problem, input the variables.

### Output format

Only when we encounter the operation of "query", we need to output.
The detailed of output format is writen in the function "printNode" which output the name on the current position.

### Function explaination

#### insertAfter : insert the node after the position which we input before.

#### deleteNode : delete the node on the current position which we input before.

#### swapNode : swap the nodes a and b which we input before.

#### printNode : print the node on the current position which we input before.

Detailed explanation are writen in source code.

### How the program works

The program will a serie of operation by using linked list.

============================================================================================================

## Problem 2. Elimination game 

This is a C program, compile this program and run.

### Input format

First, input a string by using fget, so we can ignore the space.
And then, input the two integers "k" and "d" to determine the number of players to be skipped in the elimination game
and the direction to begin.

### Output format

The output is respectively in the function clockwise and counter-clockwise that determined by the input of d.
It will output the individuals which are killed and the last one which is survived.

### Function explaination

#### clockwise : a function to eliminate the people in the direction of clockwise. It will print the process of elimination.

#### counter-clockwise : a function to eliminate the people in the direction of counter-clockwise. It will print the process of elimination.

Detailed explaination are writen in source code.

### How the program works

It will eliminate a group of people by using the circular double linked list.

============================================================================================================
