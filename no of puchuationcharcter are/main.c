#include<stdio.h>//punctuation characters are= , .
#include<ctype.h>
int main(){
    char str[100];
    int count=0;
    int chart=0;
    gets(str);
    while(str[chart]){
        if(ispunct(str[chart]))
            count++;
        chart++;
    }
    printf(" no of punctuation characters are =%d ",count);
}