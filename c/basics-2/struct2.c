#include<stdio.h>
struct complex{
int real;
int img;
};


struct complex add(struct complex c1,struct complex c2,struct complex c3){
struct complex c5;
c5.real=c1.real+c2.real+c3.real;
c5.img=c1.img+c2.img+c3.img;
printf("Real number part is:%d",c5.real);
printf("\n Imaginary number part is:%d",c5.img);


}


struct complex input(){
int a,i;
struct complex c[3],c4;
printf("Enter your choice 1-add 2-sub");
scanf("%d",&a);
if(a==1){
for(i=0;i<3;i++){
printf("Enter the real part of number %d",i+1);
scanf("%d",&c[i].real);
printf("Enter the imaginary part of number%d",i+1);
scanf("%d",&c[i].img);
}
add(c[0],c[1],c[2]);
}
if(a==2){
}

}
void main(){
input();

}
