#include <stdio.h>
#include <string.h>
#include <ctype.h>

int top=0;

typedef struct node{
    char c;
}element;

element stack[128000];
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand} precedence;

precedence gettok(char *res)
{
    switch(*res)
    {
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divide;
        case '*' : return times;
        case '%' : return mod;
        case '\0': return eos;
        default : return operand;
    }
}

void push(char oprt)
{
    stack[++top].c=oprt;
}

char pop(element *stack)
{
    top--;
    if(stack[top+1].c == '(')
        return '\0';  
    return stack[top+1].c;
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int state=1;
        int pstate=0;
        int opnum=0;
        int optnum=0;
        char output[102400];
        char line[102400];
        memset(line,'\0',102400);
        memset(output,'\0',102400);
        scanf("%s",line);
        // TODO
        int parentheses = 0,ok = 1,digit_and_symbol = 0,is_one_to_nine = 0;
        for(int i= 0;i< (int)strlen(line);i++){
            if(line[i] == '(') parentheses++;
            if(line[i] == ')') parentheses--;
            if(isdigit(line[i])) digit_and_symbol++,is_one_to_nine++;
            if(line[i] == '+' || line[i] == '-' || line[i] =='*' || line[i] == '/')
                digit_and_symbol--,is_one_to_nine = 0;
            if(parentheses < 0 || digit_and_symbol < 0 || is_one_to_nine > 1 || strlen(line) < 2) ok = 0;
        }
        if(parentheses || !ok || !digit_and_symbol){
            printf("0\n");
            continue;
        }
        //
        fflush(stdin);
        char *ptr=line;
        char *qtr=output;
        stack[top].c='\0';
        int isp[]={0,19,12,12,13,13,13,0};
        int icp[]={20,19,12,12,13,13,13,0};
        precedence token;
        for(token = gettok(ptr);token != eos;token = gettok(ptr))
        {
            if(token == operand)
            {
                *qtr++=*ptr;
                opnum++;
            }         
            else if(token == rparen)
            {
                pstate+=1;
                while(stack[top].c!='(')
                {
                    *qtr++=pop(stack);
                    if(top==-1)
                    {
                        state=0;
                        break;
                    }   
                }
                if(state==1)
                    *qtr=pop(stack);
                else
                    break;
            }
            else
            {
                optnum++;
                while(isp[gettok(&stack[top].c)] >= icp[token])
                    *qtr++=pop(stack);
                if(*ptr=='(')
                {
                    pstate-=1;
                    optnum--;
                }
                push(*ptr);
            }
            ptr++;
        }
        while(top!=-1)
        {
            *qtr++=pop(stack);
        }
        if(state!=1 || pstate!=0 || optnum != opnum-1 || strlen(output)<3)
        {
            puts("0");
        }
        else
        {
            printf("1 %s\n",output);
        }
        
    }
    return 0;
}
