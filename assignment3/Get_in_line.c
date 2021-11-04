#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// datastructure of linked list
struct node{
    char individual[20];
    struct node *next;
}*head;

// the length of beginning
int length = 0;


void insertAfter(int idx,char *new_individual){
    // to judge if this operation is valid
    if(length < idx){
        printf("no result\n");
        return;
    }
    struct node *pos = head;
    struct node *new_node = (struct node*) malloc (sizeof(struct node));
    new_node -> next = NULL;
    strcpy(new_node->individual,new_individual);

    // find the position to insert
    while(idx--)
        pos = pos -> next;
    //insert the new_node
    if(pos -> next!= NULL) 
        new_node -> next = pos ->next;
    else
    // if the position is the end of list
        new_node -> next = NULL;
    pos -> next = new_node;
    length++;
}

void deleteNode(int position){
    // to judge if this operation is valid
    if(length < position || position <= 0){
        printf("no result\n");
        return;
    }
    struct node *pos = head;
    struct node *target_node = head -> next;
    
    // position need to count (position - 1) times, so I use (--position)
    while(--position){
        pos = pos -> next;
        target_node = target_node -> next;
    }
    if(target_node -> next != NULL)
        pos -> next = target_node -> next;
    // if the position is the end of list
    else
        pos -> next = NULL;
    free(target_node);
    length--;
}

void swapNode(int posa,int posb){
    // to judge if this operation is valid
    if(posa > length || posb > length || posa <= 0 || posb <= 0){
        printf("no result\n");
        return;
    }
    struct node *nd_a = head;
    struct node *nd_b = head;
    // find the position of node a
    while(posa--)
        nd_a = nd_a -> next;
    // find the position of node b
    while(posb--)
        nd_b = nd_b -> next;
    // do the swap
    char tmp[20];
    strcpy(tmp,nd_a -> individual);
    strcpy(nd_a -> individual, nd_b -> individual);
    strcpy(nd_b -> individual, tmp);
}

void printNode(int position){
    // to judge if this operation is valid
    if(length < position || position <= 0){
        printf("no result\n");
        return;
    }
    struct node* tmp = head;

    // find the target
    int i = 0;
    while(i!= position){
        tmp = tmp->next;
        i++;
    }
    printf("%s\n",tmp->individual);
}
int main(){
    // freopen("input.txt","r",stdin);
    
    // set the head of linked list
    head = NULL;
    struct node *list = (struct node*) malloc (sizeof(struct node));
    head = list;

    int q;
    scanf("%d",&q);
    while(q--){
        char op[10];
        scanf("%s",op);
        if(op[0] == 'i'){
            int pos;
            char name[20];
            scanf("%d",&pos);
            scanf("%s",name);
            insertAfter(pos,name);
        }
        else if(op[0] == 'q'){
            int pos;
            scanf("%d",&pos);
            printNode(pos);
        }
        else if(op[0] == 'd'){
            int pos;
            scanf("%d",&pos);
            deleteNode(pos);
        }
        else if(op[0] == 's'){
            int posa,posb;
            scanf("%d%d",&posa,&posb);
            swapNode(posa,posb);
        }
    }

    return 0;
}