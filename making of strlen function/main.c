#include<stdio.h>
#include<stdio.h>
#include<string.h>
int strln(char *str){
int len=0;
int k=0;
while(str[k]!='\0'){
    len++;
    k++;
}
return len;
}
int main(){
    char str[100];
    gets(str);
int len=strln(str);
printf("size of string=%d",len);
}