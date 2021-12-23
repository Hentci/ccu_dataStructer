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

void selectionSort(int arr[],int sz){
    int mn;
    for(int i = 0;i<= sz - 2;i++){
        mn = i;
        for(int j = i + 1;j<= sz - 1;j++)
            mn = arr[j] < arr[mn] ? j : mn;
        swap(&arr[i], &arr[mn]);
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
    selectionSort(arr, arrSize);


    return 0;
}