#include<stdio.h>
#include<ctype.h>
int main(){
	int ctr=0;
	char str[100]; 
    gets(str);
    printf(" Here is the above string in UPPERCASE :\n ");
	while (str[ctr]){
		char str_char=str[ctr];
		putchar(toupper(str_char));
		ctr++;
	}
	return 0;
}
