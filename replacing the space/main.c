#include<stdio.h>
#include<ctype.h>
int main(){
	char t;
	char str[100]; 
    printf(" Input a string : ");
    gets(str);
    printf(" Input replace character : ");
	scanf("%c",&t);
	printf(" After replacing the space with  %c the new string is :\n",t);
    int ctr=0;
	while (str[ctr]){
		int new_char=str[ctr];//storing string in new variable
		if (isspace(new_char)) 
		new_char=t;
		putchar (new_char);
		ctr++;
	}
	return 0;
}
