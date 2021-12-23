#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define mxn (int)1e6
char s[mxn];
int arr[mxn], arrSize;
void printArray(int arr[], int sz){
    for (int i = 0; i < sz; i++){
        printf("%d", arr[i]);
        if (i != sz - 1)
            printf(", ");
    }
    printf("\n");
}
void merge(int left, int right, int n){
    int Lsize = n, Rsize = right - left - n + 1;
    int L[Lsize], R[Rsize];
    for(int i = 0;i< Lsize;i++)
        L[i] = arr[left + i];
    for(int i = 0;i< Rsize;i++)
        R[i] = arr[left + n + i];
    int idxL = 0, idxR = 0, idxArr = left;
    while(idxL < Lsize && idxR < Rsize){
        if(L[idxL] <= R[idxR])
            arr[idxArr++] = L[idxL++];
        else
            arr[idxArr++] = R[idxR++];
    }
    while(idxL < Lsize) arr[idxArr++] = L[idxL++];
    while(idxR < Rsize) arr[idxArr++] = R[idxR++];
}

void mergeSort(int n){
    int segSize = 1, left, right;
    while(segSize < n){
        segSize <<= 1;
        for(int i = 0;i< n;i+= segSize){
            left = i, right = (n - 1) < (i + segSize - 1) ? n - 1 : i + segSize - 1;
            merge(left, right, segSize >> 1);
        }
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

    mergeSort(arrSize);
    printf("\n");
    int minGap = __INT32_MAX__;
    for(int i = 1;i< arrSize;i++)
        minGap = minGap < (arr[i] - arr[i - 1]) ? minGap : arr[i] - arr[i - 1];

    printf("Minimum gap: %d\n", minGap);

    return 0;
}