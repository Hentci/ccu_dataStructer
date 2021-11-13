#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
}*queue[1000],*root,*parent;
// using queue to implement levelorder traversal
int front = -1, rear = -1;
struct node *pop_and_get_front(){
    return queue[++front];
}
int isempty(){
    return rear == front;
}
void push(struct node *nd){
    queue[++rear] = nd;
}

struct node* search(struct node *pos,int target){
    struct node *tmp = pos;
    if(!tmp)
        return NULL;

    // find the target
    if(tmp -> data == target)
        return tmp;
    if(target > tmp -> data){
        if(tmp -> right){
            // record parent to delete
            parent = tmp;
            return search(tmp->right, target);
        }
        else
        // return parent to insert
            return tmp;
    }
    else {
        if(tmp -> left){
            // record parent to delete
            parent = tmp;
            return search(tmp ->left, target);
        }
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
void _delete(int target){
    struct node *tmp = search(root, target);
    // Three case
    /***********
     * case 1. Leaf node
     * case 2. With one subtree
     * case 3. Non-leaf node
    ************/ 

    // 1.
    if(!tmp -> left && !tmp -> right){
        if(parent -> data > target)
            parent -> left = NULL;
        else
            parent -> right = NULL;
        free(tmp);
        return;
    } 
    // 2.
    // the subtree is on the right
    if(!tmp -> left){
        if(parent -> data > target)
            parent -> left = tmp -> right;
        else
            parent -> right = tmp -> right;
        free(tmp);
        return;
    }
    // the subtree is on the left
    else if(!tmp -> right){
        if(parent -> data > target)
            parent -> left = tmp -> left;
        else
            parent -> right = tmp -> left;
        free(tmp);
        return;
    }
    // 3.
    // Find the smallest node on the right subtree to replace the data of delete node
    struct node *replace_node = tmp -> right;
    while(replace_node -> left != NULL)
        replace_node = replace_node -> left;
    int replace_data = replace_node -> data;
    _delete(replace_node -> data);
    tmp -> data = replace_data;
}
void printIn_inorder(struct node *nd){
    if(nd){
        printIn_inorder(nd -> left);
        printf("%d ", nd -> data);
        printIn_inorder(nd -> right);
    }
}
void printIn_levelorder(struct node *nd){
    push(nd);
    while(!isempty()){
        struct node *front = pop_and_get_front();
        printf("%d ", front -> data);
        if(front -> left)
            push(front -> left);
        if(front -> right)
            push(front -> right);
    }
}
int main(){
    // freopen("input.txt","r",stdin);
    int n,m,nd_data;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &nd_data);
        insert(nd_data);
    }
    scanf("%d", &m);
    while(m--){
        scanf("%d", &nd_data);
        _delete(nd_data);
    }
    printf("Infixorder: ");
    printIn_inorder(root);
    printf("\n");
    printf("Levelorder: ");
    printIn_levelorder(root);
    printf("\n");   

    return 0;
}