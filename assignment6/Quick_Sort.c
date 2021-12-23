#include <stdio.h>
#include <string.h>
#define mxn (int)1e6
char s[mxn];
int arr[mxn],arrSize;
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int arr[],int sz){
    for(int i = 0;i< sz;i++){
        printf("%d", arr[i]);
        if(i != sz - 1)
            printf(", ");
    }
    printf("\n");
}
int partition(int arr[], int left, int right){
    int pivot = arr[left], i = left, j = right + 1;
    do{
        do i++; while (arr[i] < pivot);
        do j--; while (arr[j] > pivot);
        if(i < j) swap(&arr[i], &arr[j]);
    } while(i < j);
    swap(&arr[left], &arr[j]);
    printArray(arr, arrSize);
    return j;
}

void quickSort(int arr[],int left, int right){
    if(left < right){
        int idx = partition(arr, left, right);
        quickSort(arr, left, idx - 1);
        quickSort(arr, idx + 1, right);
    }
}
int main(){
    // freopen("input.txt","r",stdin);
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
    quickSort(arr, 0, arrSize - 1);

    return 0;
}
