#include<stdio.h>
#include<string.h>
int main(){
    char str[]="collage wallh ";
   printf("%p\n",&str[0]);
    printf("%p\n",str);
    char *ptr=str;//ptr know points to str[0];
    int i=0;
    while(*ptr!='\0'){
        printf("%c",*ptr);
        ptr++;//ptr will move for next adress
        i++;
    }
}