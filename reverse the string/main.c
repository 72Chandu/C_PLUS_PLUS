#include<stdio.h>
#include<string.h>
int main(){
    char str[15];
    gets(str);
    puts("size of str");
    int size=0;
    int k=0;
    //finding size of string
    while(str[k]!='\0'){
        size++;
        k++;
    }
    printf("%d\n",size);
    //reversing the string
   for(int i=0,j=size-1;i<=j;i++,j--){
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
   }
   puts(str);

}

//m2 with recurrsion 

void reverse(string &s, int lo, int hi){
    if(lo>=hi) return;
    swap(s[lo],s[hi]);
    reverse(s,lo+1, hi-1);
}
 reverse(s,0, s.size()-1);