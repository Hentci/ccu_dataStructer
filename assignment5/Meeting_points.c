#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mxsize (int)1e4 + 5
int n,m,case_cnt;
char name[mxsize][30];
int d[mxsize][mxsize];
int sum[mxsize];
/**********
 * case_cnt: to count the case
 * name: store the names
 * d: to build the distance graph
 * sum: to find the sum of meeting cost of each node
 **********/

int main(){
    // freopen("input.txt","r",stdin);

    // EOF
    while(scanf("%d%d",&n,&m) && (n && m)){
        case_cnt++;
        for(int i = 0;i< n;i++)
            scanf("%s", name[i]);
        // initialize the graph d to INF and sum to zero
        memset(d, 0x3f, sizeof d);
        memset(sum, 0, sizeof sum);

        // input the distance which have been known
        for(int i = 0;i< m;i++){
            int a,b,dis;
            scanf("%d%d%d",&a ,&b ,&dis);
            --a,--b;
            d[a][b] = dis;
            d[b][a] = dis;
        }

        // set the distance to zero to itself
        for(int i = 0;i< n;i++)
            d[i][i] = 0;

        // implement the Floyd Warshall Algorithm in O(n^3)
        for(int k = 0;k< n;k++){
            for(int i = 0;i< n;i++){
                for(int j = 0;j< n;j++)
                    d[i][j] = d[i][j] < d[i][k] + d[k][j] ? d[i][j] : d[i][k] + d[k][j];
            }
        }

        // initialize the minimum to INF
        int mn_sum = __INT_MAX__;
        int ans_idx = 0;
        // store all the sum of meeting cost and find the minimum
        for(int i = 0;i< n;i++){
            for(int j = 0;j< n;j++)
                sum[i] += d[i][j];
            if(mn_sum > sum[i]){
                ans_idx = i;
                mn_sum = sum[i];
            }
        }
        printf("Case #%d %s\n",case_cnt, name[ans_idx]);
    }


    return 0;
}