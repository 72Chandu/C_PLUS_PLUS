#include<stdio.h>
#include<stdio.h>
int main(){
    char str[]="collage wallah";
    char*ptr=str;// ptr pointing to "c" of collage wallah
    ptr="physics wallah";//now the ptr change adress to "p" of physics wallah
    printf("%s\n",str);
    //indiviual charecter modiefies
    char*p=str;
    *p='p';//'*p(pointing the string (collage wallah))' pe jo charecter hai use chage kar do 'p'
     printf("%s",str);

}