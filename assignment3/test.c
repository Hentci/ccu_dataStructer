#include <stdio.h>
#include <string.h>
char s[10000],name[10000][10000];
int main(){
    fgets(s,10000,stdin);
    printf("%d",(int)strlen(s));
    int cnt = 0;
    // printf("%s\n",s);
   char cut[3] = ", ",*tkn = strtok(s,cut);
    while(tkn){
        strcpy(name[cnt++],tkn);
        tkn = strtok(NULL,cut);
    }
    name[cnt-1][strlen(name[cnt-1])-1]='\0';
    for(int i= 0;i< cnt;i++)
        printf("%s\n",name[i]);

    return 0;
}