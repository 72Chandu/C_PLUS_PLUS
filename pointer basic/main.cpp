#include<iostream>
using namespace std;
int main(){
    int a=10;
    int *p=&a;
    int *q=p;
    int *r=q;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    cout<<q<<endl;
    cout<<&q<<endl;
    cout<<*q<<endl;
    cout<<r<<endl;
    cout<<&r<<endl;
    cout<<*r<<endl;
    cout<<(*p + *q +*r)<<endl;
    cout<<(*p)*2 +(*r)*3<<endl;
    cout<<(*p)/2 - (*r)/3<<endl;
    
    char ch[10]="chanduraj";
    char *c=ch;
    cout<<&ch<<endl;
    cout<<ch[0]<<endl;
    cout<<ch<<endl;
    
    cout<<&c<<endl;
    cout<<*c<<endl;
    cout<<c<<endl;
    
    char name[9]="sheiscdsf";
    char *s=&name[0];
    cout<<name<<endl;
    cout<<&name<<endl;
    cout<<*(name+3)<<endl;
    
    cout<<s<<endl;
    cout<<&s<<endl;
    cout<<*(s+3)<<endl;
    cout<<s+2<<endl;
    cout<<*s<<endl;
    cout<<s+8<<endl;
    
    
}