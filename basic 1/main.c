#include<stdio.h>
#include<string.h>//built in function
int main(){//null charecter='\0'.it is used to run the whole array without knowing the size of array
//its value is 0. insted of '\0'we can use any char but we do not do becaue all of them are use in writing
//char arr[]={'h','a','p','p','y',' ','b','i','r','t','h','d','a','y','\0'};
    char arr[]="happy birthday\0";//arry can also written in this way
 //char arr[]="happy birthday";//computer automatically put '\0'at end.same reprasentation of above
//char arr[30]="happy birthday";//no error due to writing more than actual sring size
    int i=0;                     //size of sting=15 extra count of '\0'
    while(arr[i]!='\0'){
        printf("%c",arr[i]);
        
        i++;
    }
    printf("\n");
    printf("%s\n",arr);//due to inbuilt function string.we can print string by using as 'puts'
    puts(arr);//puts automatically gives \n
    char str[40];
    puts("enter the string");
    scanf("%s",str);//only the first word will be considered while using scanf for entire use 'gets'
    //not use'&' while taking whole array
    printf("%s\n",str);
    
   

}