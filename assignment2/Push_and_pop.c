#include <stdio.h>
#include <string.h>
#define mxn 1000
char a[mxn],b[mxn],stack[mxn],res[mxn],ans[mxn];
/*****************
a: original string 
b: target string
stack: the bridge of "a" and "res"
res: to operate "pop" 
ans: answer 
*****************/

int a_idx,stack_top,res_top;
/*********************
a_idx for a
stack_top for stack
res_top for b and res
**********************/

// the recursive function to yield all subset 
void rec(int idx,int n){
    // stop-loss point when res_top == n - 1
    if(res_top == n - 1){
        printf("%c",ans[0]);
        for(int i= 1;i< idx;i++)
            printf(" %c",ans[i]);
        printf("\n");
    }
    else{
        // push
        if(a_idx < n){
            ans[idx] = 'i';
            stack[++stack_top] = a[a_idx++];
            rec(idx+1,n);
            a[--a_idx] = stack[stack_top--];
        }
        // pop
        if(stack_top>= 0 && res_top< n - 1 && b[res_top + 1] == stack[stack_top]){
            ans[idx] = 'o';
            res[++res_top] = stack[stack_top--];
            rec(idx+1,n);
            stack[++stack_top] = res[res_top--];
        }
    }
}
int main(){
    // freopen("Push_and_pop_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        // initialize all start of array and stacks
        a_idx = 0,stack_top = -1, res_top = -1;
        scanf("%s%s",a,b);
        printf("[\n");
        // if their string length are not the same, then they don't have any answers
        if(strlen(a) == strlen(b))
            rec(0,(int)strlen(a));
        printf("]\n");
    }


    return 0;
}