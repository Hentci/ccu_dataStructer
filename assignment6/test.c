#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int number[100005],size,tmp,min_gap=1e9;
char string[200005];
int min(int a,int b){
    return a<b?a:b;
}
void print(){
    for(int k=0;k<size;k++){
        if(k)printf(", ");
        printf("%d",number[k]);
    }
    printf("\n");
}
void merge(int left,int right,int s){
    int size_A=s,size_B=right-left-s+1;
    int arr_A[size_A],arr_B[size_B];
    for(int i=0;i<size_A;i++)arr_A[i]=number[left+i];
    for(int i=0;i<size_B;i++)arr_B[i]=number[left+s+i];
  
    int idx_A=0,idx_B=0; 
    int idx_num=left; 
    while(idx_A<size_A&&idx_B<size_B){
        if(arr_A[idx_A]<=arr_B[idx_B]){
            number[idx_num++]=arr_A[idx_A++];
        }
        else number[idx_num++]=arr_B[idx_B++];
    }
    while(idx_A<size_A)number[idx_num++]=arr_A[idx_A++];
    while(idx_B<size_B)number[idx_num++]=arr_B[idx_B++];
}
void merge_sort(int size){
    int s=1;
    do{
        s*=2;
        for(int i=0;i<size;i+=s){
            int left=i,right=min(size-1,i+s-1);
            merge(left,right,s/2);
        }
        print();
    }while(s<size);
}
int main(){
    freopen("input.txt", "r", stdin);
    fgets(string,200005,stdin);
    for(int i=0;i<strlen(string);i++){
        if(isalnum(string[i]))tmp=tmp*10+string[i]-'0';
        if(string[i]==','){
            number[size++]=tmp;
            tmp=0;
        }
    }
    number[size++]=tmp;
    merge_sort(size);
    for(int i=1;i<size;i++){
        if(min_gap>number[i]-number[i-1])
            min_gap=number[i]-number[i-1];
    }
    printf("Minimum gap: %d",min_gap);
}
