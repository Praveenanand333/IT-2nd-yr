#include<stdio.h>
void main(){
int items,price;
float finalprice,discount;
printf("Enter the no of items");
scanf("%d",&items);
printf("\n Enter the price of each item:");
scanf("%d",&price);
printf("\n Enter the discount");
scanf("%f",&discount);
finalprice=(items*price)-((items*price)*(discount/100));
printf("The total amount is %f",finalprice);
}
