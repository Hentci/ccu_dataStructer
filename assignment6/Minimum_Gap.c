#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define mxn (int)1e6
char s[mxn];
int arr[mxn], arrSize;
/**********
* s: to store the input which is ready to be process into integer
* arr: after the string process, all integers are stored into this array
* arrSize: the size of arr
***********/
void printArray(int arr[], int sz){
    for (int i = 0; i < sz; i++){
        printf("%d", arr[i]);
        if (i != sz - 1)
            printf(", ");
    }
    printf("\n");
}

void merge(int left, int right, int n){
    // initialize the left and right segment and their size
    int Lsize = n, Rsize = right - left - n + 1;
    int L[Lsize], R[Rsize];

    // assign the values of the original array to the segment L and R
    for(int i = 0;i< Lsize;i++)
        L[i] = arr[left + i];
    for(int i = 0;i< Rsize;i++)
        R[i] = arr[left + n + i];
    // initialize the index of segment L ,R and original array
    int idxL = 0, idxR = 0, idxArr = left;

    // if the index is meet or cross the size of any segment, the loop stop
    while(idxL < Lsize && idxR < Rsize){
        if(L[idxL] <= R[idxR])
            arr[idxArr++] = L[idxL++];
        else
            arr[idxArr++] = R[idxR++];
    }

    // process the remain elements
    while(idxL < Lsize) arr[idxArr++] = L[idxL++];
    while(idxR < Rsize) arr[idxArr++] = R[idxR++];
}

void mergeSort(int n){
    // initialize the size of each segment to 1
    int segSize = 1, left, right;

    // if the segment size equal or bigger than the orginal array size, this loop stop
    while(segSize < n){
        // multiple the size of each segment into 2 times, since we merge two of them
        segSize <<= 1;
        // merge each segment 
        for(int i = 0;i< n;i+= segSize){
            // set the left boundary to i, and the right boundary to min(n - 1, i + segSize - 1)
            left = i, right = (n - 1) < (i + segSize - 1) ? n - 1 : i + segSize - 1;
            // merge two segments into one
            merge(left, right, segSize >> 1);
        }
        // print the process
        printArray(arr, arrSize);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    fgets(s, mxn, stdin);
    char *token, comma[3] = ", ";
    token = strtok(s, comma);
    while (token != NULL){
        int element = 0, mul = 1;
        for (int i = (int)strlen(token) - 1; ~i; i--){
            element = element + (token[i] - '0') * mul;
            mul *= 10;
        }
        arr[arrSize++] = element;
        token = strtok(NULL, comma);
    }
    // merge sort
    mergeSort(arrSize);
    printf("\n");

    // set the minimum to INF
    int minGap = __INT32_MAX__;
    // find the minimum gap
    for(int i = 1;i< arrSize;i++)
        minGap = minGap < (arr[i] - arr[i - 1]) ? minGap : arr[i] - arr[i - 1];

    printf("Minimum gap: %d\n", minGap);

    return 0;
}