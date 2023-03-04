#include<iostream>
#include<math.h>
using namespace std; 
class complex 
{ double real,img; 
 public: 
void read() 
{ 
cout<<"\nEnter the REAL PART : "; 
cin>>real; 
cout<<"\nEnter the IMAGINARY PART : "; 
cin>>img; 
}
complex operator +(complex c2) 
{ 
complex c3; 
c3.real=real+c2.real; 
c3.img=img+c2.img; 
return c3; 
}
complex operator -(complex c2) 
{ 
complex c3; 
c3.real=real-c2.real; 
c3.img=img-c2.img; 
return c3; 
}
complex operator *(complex c2) 
{ 
complex c3; 
c3.real=(real*c2.real)-(img*c2.img); 
c3.img=(real*c2.img)+(img*c2.real); 
return c3; 
}
complex operator /(complex c2) 
{ 
complex c3; 
double deno=pow(c2.real,2)+pow(c2.img,2);
c3.real=(double)((real*c2.real)+(img*c2.img))/(double)deno; 
c3.img=(double)((img*c2.real)-(real*c2.img))/(double)deno; 
return c3; 
} 
void display() 
{ cout<<real<<"+"<<img<<"i"<<endl   ; } 
}; 
int main() 
{ 
complex c1,c2,c3,c4,c5,c6; 
int choice, cont; 
cout<<"\n\nEnter the First Complex Number"; 
c1.read(); 
cout<<"\n\nEnter the Second Complex Number"; 
c2.read(); 
c3=c1+c2;
c4=c1-c2;
c5=c1*c2;
c6=c1/c2;
cout<<"The sum of two complex number is:";
c3.display(); 
cout<<"The difference of two complex number is:";
c4.display(); 
cout<<"The product of two complex number is:";
c5.display();  
cout<<"The quotient of two complex number is:";
c6.display();  
 }