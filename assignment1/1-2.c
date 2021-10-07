#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define mxn (int)3e6

char cipherText[mxn];
char article[mxn];
char answer_dic[60][mxn];
int failure[10];
int article_indexes[mxn];
int sumofLps = 0;
int article_index_idx = 0;

/* build Failure Function */
void Failure(char *str) {
    int n = strlen(str),j= 0;
    failure[0] = 0;
    for(int i= 1;i< n;i++){
        while(j != 0 && str[i] != str[j])
            j = failure[j - 1];
        if (str[j] == str[i])
            j++;
        failure[i] = j;
    }
}

/* calculate the number of occurrences of pattern in text */
void kmpMatch(char *cipherTextfive, char *article){
    int j = 0,n = strlen(article);
    /* search the matched words with the key and find all the positions of the matched words in article */
    for(int i = 0;i< n;i++){
        while(j != 0 && cipherTextfive[j] != article[i])
            j = failure[j - 1];
        if(article[i] == cipherTextfive[j]) {
            if(j == (5 - 1)) {
                article_indexes[article_index_idx++] = i - 5 + sumofLps + 1;
                j = failure[j];
            }
            else 
                j++;
        }
    }
}

int main(){
    // freopen("1-2input.txt","r",stdin);
    scanf("%s",cipherText);
    int sz = strlen(cipherText);

    /* do ROT13 -> deal uppercase and lowercase respectively */ 
    for(int i= 0;i< sz;i++){
        if(isupper(cipherText[i])){
            int tmp = cipherText[i] - 'A';
            tmp = (tmp + 13) % 26;
            cipherText[i] = tmp + 'A';
        }
        else{
            int tmp = cipherText[i] - 'a';
            tmp = (tmp + 13) % 26;
            cipherText[i] = tmp + 'a';
        }
    }
    printf("%s\n", cipherText);

    char cipherText_five[10]; 

    /* get the five characters compose the key */
    for(int i= 0;i< 5;i++)
        cipherText_five[i] = cipherText[i];
    cipherText_five[5] = '\0';
    printf("%s\n", cipherText_five);

    getchar();
    fgets(article,mxn,stdin);


    Failure(cipherText_five);
    /* get sum of lps */
    for(int i= 0;i< 5;i++)
        sumofLps+= failure[i];
        
    printf("%d\n", sumofLps);

    kmpMatch(cipherText_five, article);

    for(int i= 0;i< article_index_idx;i++)
        printf("%d\n", article_indexes[i]);

    /* input answer_dic */
    for(int i= 0;i< 52;i++){
        char s[mxn];
        fgets(s,mxn,stdin);
        int idx = 0;
        /* deal end-of-line*/
        if(i < 51){
            for(int j= 2;j< (int)strlen(s) - 1;j++)
                answer_dic[i][idx++] = s[j];
        }
        else{
            for(int j= 2;j< (int)strlen(s);j++)
                answer_dic[i][idx++] = s[j];
        }
    }


    for(int i= 0;i< article_index_idx;i++){
        /* deal uppercase and lowercase respectively */
        article_indexes[i] = (article_indexes[i] >= 'a' ? article_indexes[i] - 6 : article_indexes[i]);
        printf("%s ", answer_dic[article_indexes[i] - 'A']);
    }
    printf("\n");


    return 0;
}