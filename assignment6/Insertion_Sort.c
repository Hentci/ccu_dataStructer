#include <stdio.h>
#include <string.h>
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

void insertionSort(int arr[], int sz){
    int key, j;
    /*****
    * key: the key which is ready to inserted
    * j: the position where key is inserted
    ******/
    for(int i = 1;i< sz;i++){
        // print the process
        printArray(arr, arrSize);
        key = arr[i];
        j = i - 1;
        // back to the start of array and find the position to insert key
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        // insert the key
        arr[j + 1] = key;
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
    // insertion sort
    insertionSort(arr, arrSize + 1);

    return 0;
}