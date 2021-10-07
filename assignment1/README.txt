# Assignment I — Structs and Arrays

============================================================================================================

## Problem 1. Arrays of Structures

This is a C program, compile this program and run.

### Input format

First, input the integer n to know how many datas after
Second, using the struct to bind every element, and according to the problem, input every element in order.
Then input the target vaccine.

### output format

According to the problem print every element that correspond the condiction.

### explaination

Detailed explanation of functions are writen in source code.

### How the program works

The program will try to find the individual that correspond the target vaccine.

============================================================================================================

## Problem 2. ROT13 and KMP

This is a C program, compile this program and run.

### Input format

First, input the cipherText.
Second, using fgets to input the article and using getchar() to deal with the EOL.
Finally, using the 2-D array to store all values of answer_dic, and using the for-loop to cut every string.
And I use if-else to deal with the EOL problem of last string.

### Output format

Just print every value and string by the description of problem.

### Function explaination 

#### Failure function

First, initialize the failure[0] = 0.
Second, using the for-loop to scan the key-string (cipherText_five)
In the for-loop, using while, if-else and the j(index of failure array and the key) to determine every value in the failure array.
Finally, get the failure array.

#### kmpMatch function

First, using the for-loop to scan the article
Second, in the for-loop, we use the failure array that get by using failure function to match the key.
If we match the key, we reset the index j, because the article may contain many string that match the key.
And if we match the key, we store the index to the article_indexes.

Other detailed explanation of functions are writen in source code.

### How the program works 

First, it using ROT13 to decrypt the secret string for finding the key.
Second, it using KMP to search the pattern and find the secret message.
Finally, by matching answer_dic we can get the last message.

============================================================================================================





