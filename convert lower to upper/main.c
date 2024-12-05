#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main(){
  char str[100];
  char ch;
  printf("enter the string");
  gets(str);
  int len=strlen(str);
  printf("After Case changed the string  is: ");
  for(int i=0; i < len; i++){
    ch = islower(str[i]) ? toupper(str[i]) : tolower(str[i]);
    putchar(ch);
   }
} 
