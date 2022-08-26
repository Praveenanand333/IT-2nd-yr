#include<stdio.h>
int main(){
int days,weeks,years,remdays;
printf("enter the number of days");
scanf("%d",&days);
years=days/365;
weeks=(days%365)/7;
remdays=(days%365)%7;
printf("%d",years);
printf(" \n %d",weeks);
printf(" \n %d",remdays);

getch();
return 0;
}