#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define mxn (int)2e5

/*
stack: to process the "infix" to "postfix"
s: to store the string which problem give
top and ptr to point the top of stack
*/
char stack[mxn],s[mxn];
int top;
int *ptr;

// template of stack
void push(int *top,char c){
    stack[++*top] = c;
}
int empty(int *top){
    return *top < 0;
}
char get_top(int *top){
    return stack[*top];
}
void pop(int *top){
    (*top)--;
}

// precedence of symbols
int precedence(char c){
    return c== '+'|| c=='-'? 1: c== '*'|| c== '/'? 2: 0;
}

void toPosfix(char *str){
    char res[mxn];
    memset(res,'\0',sizeof(res));
    int res_idx = 0; 
    for(int i= 0;i< (int)strlen(str);i++){
        // If the scanned character is an operand, add it to output string.
        if(isdigit(str[i]))
            res[res_idx++] = str[i];
        // If the scanned character is an ‘(‘, push it to the stack.
        else if(str[i] == '(')
            push(ptr,'(');
        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered.
        else if(str[i] == ')'){
            while(get_top(ptr) != '('){
                res[res_idx++] = get_top(ptr);
                pop(ptr);
            }
            pop(ptr);
        }
        //If an operator is scanned
        else{
            while(!empty(ptr) && precedence(str[i]) <= precedence(get_top(ptr))){
                res[res_idx++] = get_top(ptr);
                pop(ptr);
            }
            push(ptr,str[i]);
        }
    }
    // Pop all the remaining elements from the stack
    while(!empty(ptr)){
        res[res_idx++] = get_top(ptr);
        pop(ptr);
    }
    printf("1 %s\n",res);
}

int main(){
    // freopen("03input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        char stack[mxn],s[mxn];
        scanf("%s",s);
        /* 
        parentheses: to prevent the expression that have invalid parentheses ex:((1-1)
        digit_and_symbol: to prevent the expression that have invalid order of digits and symbols ex: -1+1
        is_one_to_nine: to prevent the expression that have the number that bigger than nine ex: 12/1
        ok: to prevent other situations
        */
        int parentheses = 0,ok = 1,digit_and_symbol = 0,is_one_to_nine = 0;
        for(int i= 0;i< (int)strlen(s);i++){
            if(s[i] == '(') parentheses++;
            if(s[i] == ')') parentheses--;
            if(isdigit(s[i])) digit_and_symbol++,is_one_to_nine++;
            if(s[i] == '+' || s[i] == '-' || s[i] =='*' || s[i] == '/')
                digit_and_symbol--,is_one_to_nine = 0;
            if(parentheses < 0 || digit_and_symbol < 0 || is_one_to_nine > 1 || strlen(s) < 2) ok = 0;
        }
        if(parentheses || !ok || !digit_and_symbol){
            printf("0\n");
            continue;
        }

        // to connect the top to stack
        top = -1;
        ptr = &top;
        toPosfix(s);
    }

    return 0;
}