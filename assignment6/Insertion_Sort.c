#include <stdio.h>
#include <string.h>
#define mxn (int)1e6
char s[mxn];
int arr[mxn], arrSize;

void printArray(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d", arr[i]);
        if (i != sz - 1)
            printf(", ");
    }
    printf("\n");
}

void insertionSort(int arr[], int sz){
    int key, j;
    for(int i = 1;i< sz;i++){
        printArray(arr, arrSize);
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    fgets(s, mxn, stdin);
    char *token, comma[3] = ", ";
    token = strtok(s, comma);
    while (token != NULL)
    {
        int element = 0, mul = 1;
        for (int i = (int)strlen(token) - 1; ~i; i--)
        {
            element = element + (token[i] - '0') * mul;
            mul *= 10;
        }
        arr[arrSize++] = element;
        token = strtok(NULL, comma);
    }
    insertionSort(arr, arrSize + 1);

    return 0;
}