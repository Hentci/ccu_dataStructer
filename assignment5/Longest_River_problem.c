#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mxsize (int)5e6 + 5
int n,m,o;

/*data of river*/
struct river{
    char name[20];
    int len;
    int confluence;
    int rank;
}rv[mxsize];

/*a struct for record the parent node*/
struct parent{
    int label;
    int distance;
}par[mxsize];

/*Just for the output format, so it store the origin river order*/
char ans[mxsize][20];

/*a compare function that compare the distance for qsort*/
int cmp(const void *a, const void *b){
    return (*(struct river*)b).len - (*(struct river*)a).len;
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<= n;i++){
        scanf("%s%d%d",rv[i].name, &rv[i].confluence, &rv[i].len);
        // copy the original order
        strcpy(ans[i], rv[i].name);
    }
    scanf("%d", &o);
    for(int i = 0,a,b,dis;i< o;i++){
        scanf("%d%d%d",&a ,&b, &dis);
        // build the relation, where a -> parent, b -> child
        par[b].label = a;
        par[b].distance = dis;
    }
    for(int i = 1;i<= n;i++){
        // using the parent to update the river length
        while(rv[i].confluence != 0){
            int nd = rv[i].confluence;
            rv[i].len += par[nd].distance;
            rv[i].confluence = par[nd].label;
        }
    }
    // sort
    qsort(rv + 1, n, sizeof rv[1], cmp);

    // fill the rank data of rivers
    int rk = 0;
    for(int i = 1;i<= n;i++)
        rv[i].rank = rv[i].len == rv[i - 1].len ? rk : ++rk;

    for(int i = 1;i<= n;i++){
        printf("%s ",ans[i]);
        for(int j = 1;j<= n;j++){
            // Since the original format of river is upset by the qsort, 
            // I use the string compare to find the other data whether it match the river name or not.
            if(!strcmp(rv[j].name, ans[i]))
                printf("%d \n",rv[j].rank);
        }
    }

    return 0;
}