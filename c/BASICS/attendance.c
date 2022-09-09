#include<stdio.h>
void attendancecal(int totclass,int attendedclass){
float percentage;
percentage=(attendedclass/(float)totclass)*100;
printf("Your attendance percentage is :%f",percentage);
}



void main(){
int totclass,attendedclass;
printf("Enter the total number of classes:");
scanf("%d",&totclass);
printf("Enter the no of classes you attended:");
scanf("%d",&attendedclass);
attendancecal(totclass,attendedclass);
}
