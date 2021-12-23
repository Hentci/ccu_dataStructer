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
        if(i != sz - 1)
            printf(", ");
    }
    printf("\n");
}

void selectionSort(int arr[],int sz){
    int mn;
    for(int i = 0;i< sz;i++){
        // set the first element to the minimum of the subarray
        mn = i;
        // find the minimum of the subarray
        for(int j = i + 1;j< sz + 1;j++)
            mn = arr[j] < arr[mn] ? j : mn;
        // swap the minimum to the start of subarray
        swap(&arr[i], &arr[mn]);
        // print the process
        printArray(arr, arrSize);
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
    // selection sort
    selectionSort(arr, arrSize - 1);

    return 0;
}