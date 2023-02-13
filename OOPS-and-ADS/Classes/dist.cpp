#include<iostream>
using namespace std;
class Distance{
int feet;
int inches;


public:
void set_feet(int feet1){feet=feet1;}
void set_inches(int inches1){inches=inches1;}

void sum(Distance d1){
cout<<"Sum of feet is:"<<feet+d1.feet<<"\n";
cout<<"Sum of inches is:"<<inches+d1.inches<<"\n";
}
};

int main(){
Distance a,b;
a.set_feet(5);
b.set_feet(6);
a.set_inches(30);	
b.set_inches(35);
a.sum(b);
}
