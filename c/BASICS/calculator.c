#include<stdio.h>
void main(){
int num1,num2;
char sign;
printf("Enter the number1 and number2:");
scanf("%d %d",&num1,&num2);
printf("\n enter the operation + - * /");
scanf("%s",&sign);
switch(sign){
case '+':
printf("\n the sum of two numers are %d",num1+num2);
break;
case '-':
printf("\n the difference between the two numbers are %d",num1-num2);
break;
case '*':
printf("\n the product of two numbers are %d",num1*num2);
break;
case '/':
printf("\n the quotient is %d",num1/num2);
break;
default:
printf("\n invalid operator");
break;

}
}
