#include<stdio.h>
void main(){
int length,breadth,area,perimeter,choice;
printf("Enter the length of the rectangle:");
scanf("%d",&length);
printf("\n Enter the breadth of the rectangle:");
scanf("%d",&breadth);
area=length*breadth;
perimeter=2*(length+breadth);
printf("\n Enter your choice 1 for area 2 for perimeter:");
scanf("%d",&choice);
if(choice==1){
printf("\n The area of the recatangle is %d",area);
}
else if(choice==2){
printf("\n The perimeter of the rectangle is %d",perimeter);
}
else{
printf("\n invalid choice");
}
}
