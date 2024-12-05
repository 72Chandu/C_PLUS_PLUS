#include<stdio.h>
int main(){
    char str[100], substr[100];
    int pos,len;
    printf("enter the string: ");
    gets(str);
    printf("enter the starting position of string");
    scanf("%d",&pos);
    printf("enter the length of substring");
    scanf("%d",&len);
    int c=0;
    while(c<len){
        substr[c]=str[pos+c-1];//copy into another array string
        c++;
        substr[len]='\n';
   }
  puts(substr);
   return 0;
}