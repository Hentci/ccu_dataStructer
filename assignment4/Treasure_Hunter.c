#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
}*root = NULL;
struct node* search(struct node *pos,int target){
    struct node *tmp = pos;
    if(!tmp)
        return NULL;

    // find the target
    if(tmp -> data == target)
        return tmp;
    if(target > tmp -> data){
        if(tmp -> right)
            return search(tmp->right, target);
        else
        // return parent to insert
            return tmp;
    }
    else {
        if(tmp -> left)
            return search(tmp ->left, target);
        else
        // return parent to insert
            return tmp;
    }
}
void insert(int target){
    struct node * tmp = search(root, target);
    if(tmp || !root){
        // build a new node
        struct node *new_node = (struct node *) malloc (sizeof(struct node));
        new_node -> data = target;
        new_node -> left = NULL;
        new_node -> right = NULL;

        // find the position to insert
        if(root) {
            if(target > tmp -> data)
                tmp -> right = new_node;
            else
                tmp -> left = new_node;
        }
        else
        // let the new node be the root
            root = new_node;
    }
}
/**************************
 * n : the number of nodes
 * key_path : to record the path of finding key
 * key_treasure : to record the path of finding treasure
 * step_key : to count the step of finding key
 * step_treasure : to count the step of finding treasure
 * step_same : to count the same step of key and treasure
***************************/
int n,key,treasure,key_path[1000],treasure_path[1000];
int step_key = 0,step_treasure = 0,step_same = 0;

void find_path(int target, int path[],int *cnt){
    struct node *tmp = root;
    // implement the BST
    while(tmp){
        path[(*cnt)++] = tmp -> data;
        if(tmp -> data == target)
            return;
        if(tmp -> data > target)
            tmp = tmp -> left;
        else
            tmp = tmp -> right;
    }
}
int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d", &n);
    int nd;
    while(n--){
        scanf("%d", &nd);
        insert(nd);
    }
    scanf("%d%d", &key, &treasure);
    find_path(key, key_path, &step_key);
    find_path(treasure, treasure_path, &step_treasure);

    // step_same can check whether we need to go back to the root to find treasure or not
    for(int i= 0;i< step_key && i< step_treasure;i++){
        if(key_path[i] != treasure_path[i])
            break;
        step_same = i;
    }
    // print key_path
    for(int i= 0;i< step_key;i++){
        if(i) printf("->");
        printf("%d", key_path[i]);
    }

    // print the path back to the start to find treasure 
    for(int i = step_key - 2;i > step_same;i--)
        printf("->%d", key_path[i]);

    // print the treasure_path
    for(int i= step_same;i< step_treasure;i++)
        printf("->%d", treasure_path[i]);

    printf("\n");

    return 0;
}