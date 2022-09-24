#include<stdio.h>
struct student
{
    int r_no;
    char n[20];
    int phy;
    int che;
    int mat;
    float ec;
};
int main(){
    struct student s1,s2;
    float a,b;
    printf("\nEnter the reg_no,name,marks of physics,chemistry and maths for student 1: ");
    scanf("%d %s %d %d %d",&s1.r_no,s1.n,&s1.phy,&s1.che,&s1.mat);
    printf("\nEnter the reg_no,name,marks of physics,chemistry and maths for student 2: ");
    scanf("%d %s %d %d %d",&s2.r_no,s2.n,&s2.phy,&s2.che,&s2.mat);
    s1.ec=((s1.phy + s1.che)/2.0)+s1.mat;
    s2.ec=((s2.phy + s2.che)/2.0)+s2.mat;
    printf("\nReg_no: %d\nName: %s\nPhysics: %d\nChemistry: %d\nMaths: %d\nCut_off: %0.2f\n",s1.r_no,s1.n,s1.phy,s1.che,s1.mat,s1.ec);
    printf("\nReg_no: %d\nName: %s\nPhysics: %d\nChemistry: %d\nMaths: %d\nCut_off: %0.2f",s2.r_no,s2.n,s2.phy,s2.che,s2.mat,s2.ec);
    return 0;
}
