#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int l=0;
    gets(str);
    printf("seprate charcter=");
    while(str[l]!='\0'){
        printf("%c ",str[l]);
        l++;
    }

}