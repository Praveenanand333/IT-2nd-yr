#include<stdio.h>
void main(){
int marks;
char grade;
printf("Enter the marks :");
scanf("%d",&marks);
if(marks>=90){
grade='O';
}
else if(80<=marks<90){
grade='A';
}
else if(70<=marks<80)
{
grade='B';
}
else if(60<=marks<70)
{
grade='C';
}
else if(50<=marks<60)
{
grade='D';
}
printf("\n you got the grade %c",grade);

}
