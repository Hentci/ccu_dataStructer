#include <stdio.h>
#include <string.h>
struct individual {
    char id[20],name[50],vaccine_brand[60],city[40];
    int age;
}arr[20];
int main(){
    int n;
    scanf("%d", &n);
    for(int i= 0;i< n;i++)
        scanf("%s%s%s%d%s", arr[i].id, arr[i].name, arr[i].vaccine_brand, &arr[i].age, arr[i].city);
    char target_vaccine[30];
    scanf("%s",target_vaccine);

    for(int i= 0;i< n;i++){
        /* compare the vaccine brand by using string compare */
        if(!strcmp(target_vaccine, arr[i].vaccine_brand))
            printf("%s %s %s %d %s\n",arr[i].id, arr[i].name, arr[i].vaccine_brand, arr[i].age, arr[i].city);
    }

    return 0;
}