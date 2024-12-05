#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int i,j,k,count=0;
    printf("Enter the string: ");
    gets(str);
    int len=strlen(str);
    for(i=0;i<len;i++){
     char ch=str[i];
        for(j=0;j<len;j++){
            if(ch==str[j]){
                count++;
                //deleting the current element those are found
                for(k=j;k<(len-1);k++){//shifted one index back all the characters of string
                    str[k]=str[k+1];//jo charcter count ho gaya hai usko delete karo
                }
                len--;//after shifting lenght of string is dec by 1
                str[len]='\0';//updation of string's last index
                j--;//after shifting j is dec by 1
            }
        }
        printf("%c = %d times\n",ch,count);
        count=0;
        i--;//afterr shifting i is dec by 1
    }
	return 0;
}