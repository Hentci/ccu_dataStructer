#include <stdio.h>
#include <string.h>
#define mxn (int)1e6
char s[mxn];
int arr[mxn],arrSize;
/**********
* s: to store the input which is ready to be process into integer
* arr: after the string process, all integers are stored into this array
* arrSize: the size of arr
***********/
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[],int sz){
    for(int i = 0;i< sz;i++){
        printf("%d", arr[i]);
        // to prevent the wrong output format
        if(i != sz - 1)
            printf(", ");
    }
    printf("\n");
}

int partition(int arr[], int left, int right){
    int pivot = arr[left], i = left, j = right + 1;
    // if the left and right boundary meet or cross, this loop stop
    do{
        // partition
        do i++; while (arr[i] < pivot);
        do j--; while (arr[j] > pivot);
        // find the target to swap
        if(i < j) swap(&arr[i], &arr[j]);
    } while(i < j);
    // put the pivot to the right position
    swap(&arr[left], &arr[j]);
    // print process
    printArray(arr, arrSize);
    // return the pivot position
    return j;
}

void quickSort(int arr[],int left, int right){
    // if the left and right boundary meet or cross, the recursion stop
    if(left < right){
        int idx = partition(arr, left, right);
        // idx : the index of pivot after partition
        quickSort(arr, left, idx - 1);
        quickSort(arr, idx + 1, right);
    }
}
int main(){
    // freopen("input.txt","r",stdin);

    // process the string into integer array by using string token cut them down
    fgets(s, mxn, stdin);
    char *token, comma[3] = ", ";
    token = strtok(s, comma);
    while(token != NULL){
        int element = 0, mul = 1;
        for(int i = (int)strlen(token) - 1; ~i ;i--){
            element = element + (token[i] - '0') * mul;
            mul*= 10; 
        }
        arr[arrSize++] = element;
        token = strtok(NULL, comma);
    }
    // quick sort
    quickSort(arr, 0, arrSize - 1);

    return 0;
}
