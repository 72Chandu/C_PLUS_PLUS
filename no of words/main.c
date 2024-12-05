#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define str_size 100 //Declare the maximum size of the string
void main(){
    char str[str_size];
    int i, wrd;
	gets(str);
    i = 0;
    wrd = 1;
    while(str[i]!='\0'){
        /* check whether the current character is white space or new line or tab character*/
        if(str[i]==' ' || str[i]=='\n' || str[i]=='\t'){
            wrd++;
        }

        i++;
    }
 printf("Total number of words in the string is : %d\n", wrd-1);
}
