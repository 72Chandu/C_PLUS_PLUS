#include<stdio.h>
#include<string.h>
int main(){
    char s1[]= "physics wallah";
    char*s2=s1;//puri string s1 me s2 ko point kar do.s2 is shallow copy
    s1[0]='m';
    printf("%s",s2);
    printf("deep copy");
    char s2[]="physics wallah";
    printf("%s\n",s1);
    printf("%s",s2);
}