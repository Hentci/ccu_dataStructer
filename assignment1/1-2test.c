#include<stdio.h>
#include<string.h>
char cipher[(int)1e6];
char article[(int)1e6];
char ans[60][(int)1e6];
int main(){
    // getchar();
    freopen("1-2test.txt","r",stdin);
    scanf("%s", cipher);
    getchar();
    fgets(article, (int)1e6,stdin);
    printf("===========\n");
    printf("%s",article);
    printf("==========\n");

    for(int i= 0;i< 52;i++){
        char c[(int)1e6];
        fgets(c,(int)1e6,stdin);
        // printf("%s",c);

        // printf("%d\n", (int)strlen(c));
        int idx = 0;
        if(i < 51){
            for(int j = 2;j< (int)strlen(c) - 1;j++)
                ans[i][idx++] = c[j];
            printf("%s\n", ans[i]);
        }
        else{
            for(int j = 2;j< (int)strlen(c);j++)
                ans[i][idx++] = c[j];
            printf("%s\n", ans[i]);
        }
    }

    return 0;
}