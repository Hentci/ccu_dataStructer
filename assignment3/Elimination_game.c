#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define mxn (int)2e5
// datastructure of (circular) double linked list
struct node{
    char individual[50];
    struct node *next,*prev;
}*head;

/****************************************************************************
 * name of variable *

s -> to input the names of string
the array of name -> to store every name
cnt -> to count the number of person
k -> representing the number of players to be skipped in the elimination game
d -> the type of direction

*****************************************************************************/
char s[mxn + 5],name[mxn + 5][50];
int cnt = 0,k,d;

void clockwise(){
    struct node *ptr = head,*target_after = NULL;
    // since we only need to count (cnt - 1) times
    while(--cnt){
        // since we need to use k (cnt - 1) times, we set a new variable "sub_k" to reset the value
        int sub_k = k;
        while(sub_k--)
            ptr = ptr -> next;
        printf("%s is killed.\n",ptr -> individual);
        // adjust the double link
        ptr -> prev -> next = ptr -> next;
        ptr -> next -> prev = ptr -> prev;
        target_after = ptr -> next;
        // free the pointer, and then go to the next start point (target_after)
        free(ptr);
        ptr = target_after;
    }
    printf("%s is survived.\n",ptr -> individual);
}

void counter_clockwise(){
    struct node *ptr = head,*target_after = NULL;
    // since we only need to count (cnt - 1) times
    while(--cnt){
        // since we need to use k (cnt - 1) times, we set a new variable "sub_k" to reset the value
        int sub_k = k;
        while(sub_k--)
            ptr = ptr -> prev;
        printf("%s is killed.\n",ptr -> individual);
        // adjust the double link
        ptr -> prev -> next = ptr -> next;
        ptr -> next -> prev = ptr -> prev;
        target_after = ptr -> prev;
        // free the pointer, and then go to the next start point (target_after)
        free(ptr);
        ptr = target_after;
    }
    printf("%s is survived.\n",ptr -> individual);
}
int main(){
    // freopen("input.txt","r",stdin);
    fgets(s,mxn,stdin);
    // separate the string of name by using string token
    char cut[5] = ", ",*tkn = strtok(s,cut);
    while(tkn !=  NULL){
        strcpy(name[cnt++],tkn);
        tkn = strtok(NULL,cut);
    }
    // end the last string
    name[cnt-1][strlen(name[cnt-1])-1]='\0';
    
    // initialize the head of list
    head = NULL;
    struct node *init = (struct node*) malloc (sizeof (struct node));
    strcpy(init -> individual, name[0]);
    head = init;
    struct node *ptr = head;

    // store every individual into the list
    for(int i= 1;i< cnt;i++){
        struct node *tmp = (struct node*) malloc (sizeof(struct node));
        strcpy(tmp -> individual, name[i]);
        ptr -> next = tmp;
        tmp -> prev = ptr;
        if(i == cnt - 1){
            tmp -> next = head;
            head -> prev = tmp; 
        }
        else
            ptr = ptr -> next;
    }

    scanf("%d%d",&k,&d);
    // 1 -> clockwise , 2 -> counter-clockwise
    d == 1 ? clockwise() : counter_clockwise();    

    return 0;
}