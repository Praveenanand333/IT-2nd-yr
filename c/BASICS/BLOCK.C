#include<stdio.h>
int main(){
int i,j,k,l;
for(i=0;i<=6;i++){
if(i==1 || i==4){
printf("##### \n");
}
else{
printf("# \n");
}
}

printf("\n \n");
for(j=0;j<=6;j++){
if(j<=4){
for(i=0;i<=j;i++){
printf("\t");
}
printf("#");
}
else{
printf("\t\t\t\t\t#\n");
}
for(i=j;i<4;i++){
printf("\t");
}
if(j<4){
printf("#\n\n");}
}
getch();
return 0;

}