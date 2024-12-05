#include<stdio.h>
#include<string.h>
#define str_size 100
int main(){
    char str[str_size];
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(str[i]>str[j]){
                char temp=str[j];
                str[j]=str[i];
                str[i]=temp;
            }
        }
    }
    puts(str);

}