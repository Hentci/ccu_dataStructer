#include <stdio.h>
#include <stdlib.h>
#define mxsize (int)1e5 + 5
int root,n,id = 1,articu_idx;
int adj[1005][1005];
int dfn[mxsize],low[mxsize],articulate[mxsize];
/*****
* root: tree root which be zero
* id: the id of each node
* articu_idx: index to manipulate the articulate array
* dfn: store the dfn 
* low: store the low 
* articulate: store the articulate point
*****/

void dfs(int v, int par){
    // set the dfn number and initialize the low to the dfn
    dfn[v] = low[v] = id++;

    int is_articu = 0,child = 0;
    /*****
     * is_articu: check if it can be the articulation point
     * child: to count the node have how many childs
     *****/
    for(int i = 1;i<= n;i++){
        // skip the node if it is parent node or isn's adjacent 
        if(!adj[v][i] || i == par) continue;
        
        // update the low 
        if(dfn[i])
            low[v] = low[v] < dfn[i] ? low[v] : dfn[i];
        else{
            child++;
            // if it haven't been, recursive this node 
            dfs(i,v);
            low[v] = low[v] < low[i] ? low[v] : low[i];
            // check whether it can be a articulation point or not
            if(dfn[v] <= low[i])
                is_articu = 1;
        } 
    }
    // if the vertex can satisfy one of condition, then it is the articulation point
    if((dfn[v] == 1 && child >= 2) || (is_articu && dfn[v] != 1))
        articulate[articu_idx++] = v;
}

// for qsort
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d%d",&root,&n);
    for(int i = 1;i<= n;i++){
        for(int j = 1;j<= n;j++)
            scanf("%d", &adj[i][j]);
    }

    // dfs from the tree root
    dfs(root, 0);

    for(int i = 1;i<= n;i++)
        printf("%d ",dfn[i] - 1);
    printf("\n");

    for(int i = 1;i<= n;i++)
        printf("%d ",low[i] - 1);
    printf("\n");

    // sort the articulation point into ascending order before print them
    qsort(articulate, articu_idx, sizeof(articulate[0]),cmp);
    for(int i = 0;i< articu_idx;i++)
        printf("%d ",articulate[i]);
    printf("\n");

    return 0;
}