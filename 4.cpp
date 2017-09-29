#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
 
 
int main(int argc, char *argv[])
{
   double x=0,y=1,j=0;
   double d,n,r=0,z=0,w=n;
   cout<<"Vvedite N"; cout<<"\n";
   cin>>n;
  
    d=floor(sqrt(n));
   cout<<"d="<<d;
   cout<<"\n";
   while(j<=((d*d)-1)) 
   {
               
   j++;             
   x++;
   
   if (x>d) {y++; x=1;}
   if (z>d){ z=1; }
   z=floor(sqrt(d+x*x+y*y));
   r=pow(x,2)+pow(y,2)+pow(z,2);
   cout<<"\n";
   cout<<"// "; cout<<" r= "<<r;  cout<<" x= " <<x; cout<<"  y= "<<y; cout<<"  z= "<<z; cout<<"\n"; 
 
//почему при выполнение этого условия программа считает не правельно ???? 
//if (r=n) {cout<<"// "; cout<<" r= "<<r;  cout<<" x= " <<x; cout<<"  y= "<<y; cout<<"  z= "<<z; cout<<"\n"; }
 
  cout<<"\n";
       }
             
    system("PAUSE");
    return EXIT_SUCCESS;
}