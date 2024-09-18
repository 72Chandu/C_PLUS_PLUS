#include<stdio.h>
int main(){
    int a[]={10,34,565,7,6,7,};
    printf("%u \n",a[0]);//10
    printf("%u\n",&a[0]);//adress of 10
    printf("%u\n",&a);//adress of 10
    printf("%u \n",a[1]);//34
    printf("%u\n",&a[1]);//adress of 34
    printf("%u\n",a+1);//adress of 34
    printf("%u\n",a+2);//adress of 565
    printf("%u\n",&a+1);//adress of 10+1*total bytes of whole array(24)
    printf("%u\n",&a+2);//adress of 10+2*total bytes of whole array(24)
    //applaying pointer 
    // printf("%u \n",*a[0]);
    printf("%u\n",*&a[0]);//10
    printf("%u\n",*&a);//adress of 10
    //printf("%u \n",*a[1]);
    printf("%u\n",*&a[1]);//34
    printf("%u\n",*(a+1));//34
    //printf("%u\n",*a+1);
    printf("%u\n",*(a+2));//565
   // printf("%u\n",*a+2);
    printf("%u\n",*(&a+1));
    printf("%u\n",*&a+1);
    printf("%u\n",*(&a+2));
    return 0;
}