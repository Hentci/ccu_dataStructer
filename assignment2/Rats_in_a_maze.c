#include <stdio.h>
#include <string.h>
#define mxn 10005
int n;

// moves which sort by the description of question and the rule of stack (Down > Right > Up > Left)
const int di[4] = {0,-1,0,1}, dj[4] = {-1,0,1,0}; 

struct ele{
    int row,col;  
}stack[mxn];

/* 
maze: the maze
vis: to check that the grid of maze whether is visited or not
pre: to record the direction of the previous grid
ans: the path from start to end
*/
char maze[mxn][mxn];
int vis[mxn][mxn],pre[mxn][mxn],ans[mxn][mxn];

/* template of stack */
void push(int *top,struct ele c){
    stack[++*top] = c;
}
int empty(int *top){
    return *top < 0;
}
struct ele pop(int *top){
    return stack[(*top)--];
}

// to check next move is legal
int legal_move(int i,int j){
    return (i>= 1 && j>= 1 && i<= n && j<= n && maze[i][j] == '1' && !vis[i][j]);
}

int main(){
    // freopen("Rats_in_a_maze_input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--){
        // initialize
        memset(vis,0,sizeof vis);
        memset(ans,0,sizeof ans);

        scanf("%d", &n);
        // input the maze from (1,1) to (n,n)
        for(int i= 1;i<= n;i++){
            for(int j= 1;j<= n;j++)
                scanf(" %c",&maze[i][j]);
        }

        // connect the pointer "top" to the stack
        int top = -1;
        int *ptr = &top;
        struct ele a = {1,1};
        push(ptr,a);

        // start the dfs by using stack
        while(!empty(ptr)){
            struct ele u = pop(ptr);

            // if the rat arrive the end (n,n), backtracking the pre_move to get the path of ans 
            if(u.row == n && u.col == n){
                while(u.row != 1 || u.col != 1){
                    int pre_move = pre[u.row][u.col];
                    ans[u.row][u.col] = 1;
                    u.row -= di[pre_move],u.col -= dj[pre_move];
                }
                ans[1][1] = 1;
                for(int i= 1;i<= n;i++){
                    for(int j= 1;j<= n;j++)
                        printf("%d",ans[i][j]);
                    printf("\n");
                }
                break;
            }

            // push the four directions into stack if it is legal
            // then record the array of vis and pre
            for(int k= 0;k< 4;k++){
                int dx= u.row + di[k],dy = u.col + dj[k];
                if(legal_move(dx,dy)){
                    vis[dx][dy] = 1;
                    pre[dx][dy] = k;
                    struct ele v = {dx,dy};
                    push(ptr,v);
                }
            }
        }
    }


    return 0;
}