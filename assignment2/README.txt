# Assignment II - Stacks and Queues

============================================================================================================

## Problem 1. Rats in a maze

This is a C program, compile this program and run.

### Input format 

First, input the integer t to know how many tests after that.
Second, input the integer n to know the size of square maze.
Third, input the maze from (1,1) to (n,n).

### output format

I use the array "pre" to record every direction of the previous grids that have arrived.
and then, I backtracking the "pre" and record the ans.
Finally, print ans from (1,1) to (n,n).

### Funtion explaination

#### push: to push the element to the stack

#### empty: to check the stack whether is empty or not

#### pop: get and pop the element simultaneously

Detailed explanation are writen in source code.

### How the program works

The program will find and print the path of rat from start to end.

============================================================================================================

## Problem 2. Infix to Postfix

This is a C program, compile this program and run.

### Input format

First, input the integer t to know how many test cases after that.
And then, input the t test cases of "infix" string which the program need to process.

### Output format

when the program determine that the infix expression is invalid or don't satisfy the condition of the problem,
then it print "0" and continue to process the next test case.

if it is valid, then the "infix" string goto the toPostfix function,
and print "1 " and the processed "postfix" string.

### Function explaination

#### push: to push the element to the stack

#### empty: to check the stack whether is empty or not

#### get_top: get the top element of stack

#### pop: pop the top element of stack

#### precedence: to get the precedence of symbol

#### toPostfix: change the infix expression into the postfix expression

Detailed explanation are writen in source code.

### How the program works 

First, it will check whether the expression is valid or not.
Second, it follow the precedence of every symbols and push every element into the stack.
Third, by using the stack we can get a answer string which have become postfix.

============================================================================================================

## Problem 3. Push and pop

This is a C program, compile this program and run.

### Input format

First, input the integer t to know how many test cases after that.
And then, input the initial string "a" and target string "b". 

### Output format

First, print the symbol "[" to begin.
Second, print every answer one by one after the recursive function.
And then, print the "]" to end this test case.

### Function explaination

#### rec: A recursive function.
First, I set a stop-loss point, if the index reach the end, the function will print one of answers.
Second, it have two judge to determine the next operation will be push or pop.
if the a_idx don't reach n - 1 then the operation is push, it push the character to the stack,
and recursive next character, and restore the character to the original, so it can check if it have other outcome.
if the stack is not empty and the res_stack is not full and b[res_top + 1] == stack[stack_top](which mean the next top element of res and the top element of stack are the same),
then the operation is pop, it will get the top of stack and store it into the result, and recursive the next character to yield every outcome. 
and restore the character to the original, so it can check if it have other outcome.

Detailed explanation are writen in source code.

### How the program works

It will yield the operations subset that can change the original string into the target string.

============================================================================================================

