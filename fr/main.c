#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
    int i, count=0;
    char str[100], ch;
    printf("Enter the String: ");
    gets(str);
    int len=strlen(str);
    printf("Enter any character (present in string) to find its frequency: ");
    scanf("%c", &ch);
    for(i=0;i<len;i++) {
        if(ch==str[i]) count++;
    }
    printf("\nFrequency of %c = %d", ch, count);
    printf("\n\n%c occurs %d times in %s", ch, count, str);
    return 0;
}