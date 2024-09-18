/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int x=4,y=8;
    cout<<"before swaping without third variable \n"<<x<<endl;
    cout<<"before swaping without third variable \n"<<y<<endl;
    x=x+y;
    y=x-y;
    x=x-y;
    cout<<"after swapping without third variable \n"<<x<<endl;
    cout<<"after swapping without third variable \n"<<y<<endl;
    
    

    return 0;
}