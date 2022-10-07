#include<stdio.h>
#include<stdlib.h>
#include<linux/string.h>
struct subjects{
char faculty1[70];
int no_of_stud1;
char faculty2[70];
int no_of_stud2;
};

struct subjects_list{
char subject_name[50];
struct subjects faculty_name;
};


struct student{
char name[30];
struct subjects_list sub[8];
int assigned_faculty[8];
};



void main(){
system("figlet WELCOME TO ENROLLEMENT");
int i,j;
struct student s[20];
struct student t;
for(j=0;j<20;j++){
for(i=0;i<8;i++){
s[j].sub[i].faculty_name.no_of_stud1=0;
s[j].sub[i].faculty_name.no_of_stud2=0;}
}
for(j=0;j<20;j++){
printf("Enter the name of student-%d:",j+1);
scanf("%s",s[j].name);
strcpy(s[j].sub[0].subject_name,"C  ");
strcpy(s[j].sub[1].subject_name,"Maths");
strcpy(s[j].sub[2].subject_name,"DBMS");
strcpy(s[j].sub[3].subject_name,"DLD");
strcpy(s[j].sub[4].subject_name,"SE");
strcpy(s[j].sub[5].subject_name,"HR");
strcpy(s[j].sub[6].subject_name,"C LAB");
strcpy(s[j].sub[7].subject_name,"DBLAB");
strcpy(s[j].sub[0].faculty_name.faculty1,"ARUL DEEPA MAM");
strcpy(s[j].sub[0].faculty_name.faculty2,"INDRAGANDHI MAM");
strcpy(s[j].sub[1].faculty_name.faculty1,"SANKAR SIR");
strcpy(s[j].sub[1].faculty_name.faculty2,"VIJAYALAKSMI MAM");
strcpy(s[j].sub[2].faculty_name.faculty1,"SIVASANKARI MAM");
strcpy(s[j].sub[2].faculty_name.faculty2,"SWAMI SIR");
strcpy(s[j].sub[3].faculty_name.faculty1,"VANI MAM");
strcpy(s[j].sub[3].faculty_name.faculty2,"SELVI MAM");
strcpy(s[j].sub[4].faculty_name.faculty1,"JASMINE MAM");
strcpy(s[j].sub[4].faculty_name.faculty2,"VIJAY SIR");
strcpy(s[j].sub[5].faculty_name.faculty1,"JAYAKUMAR SIR");
strcpy(s[j].sub[5].faculty_name.faculty2,"BASKAR SIR");
strcpy(s[j].sub[6].faculty_name.faculty1,"ARUL DEEPA MAM");
strcpy(s[j].sub[6].faculty_name.faculty2,"INDRAGANDHI MAM");
strcpy(s[j].sub[7].faculty_name.faculty1,"SIVASANKARI MAM");
strcpy(s[j].sub[7].faculty_name.faculty2,"SWAMI SIR");

for(i=0;i<8;i++){
printf("%s\n",s[j].sub[i].subject_name);
printf("The faculties are 1-%s 2-%s \n",s[j].sub[i].faculty_name.faculty1,s[j].sub[i].faculty_name.faculty2);
printf("Enter your choice 1 or 2:  ");
scanf("%d",&s[j].assigned_faculty[i]);
if(s[j].assigned_faculty[i]==1){
if(t.sub[i].faculty_name.no_of_stud1<11){
t.sub[i].faculty_name.no_of_stud1+=1;
printf("%d:\n",t.sub[i].faculty_name.no_of_stud1);
}
else{

printf("Sorry seats filled for particular faculty you are allocated to other faculty");
t.sub[i].faculty_name.no_of_stud2+=1;
s[j].assigned_faculty[i]=2;
}
}
else if(s[j].assigned_faculty[i]==2){
if(t.sub[i].faculty_name.no_of_stud2<11){
t.sub[i].faculty_name.no_of_stud2+=1;}
else{
printf("Sorry seats filled for particular faculty you are allocated to other faculty");
t.sub[i].faculty_name.no_of_stud1+=1;
s[j].assigned_faculty[i]=1;
}
}
}}
for(j=0;j<20;j++){
printf("----------------------------------------------------\n");
printf("Student Name:%s\n",s[j].name);
printf("******************************\n");
printf("SUBJECT\t|\tFACULTY\n");
printf("******************************\n");
for(i=0;i<8;i++){
if(s[j].assigned_faculty[i]==1){
printf("%s\t|\t%s\n",s[j].sub[i].subject_name,s[j].sub[i].faculty_name.faculty1);
}
else if(s[j].assigned_faculty[i]==2){
printf("%s\t|\t%s\n",s[j].sub[i].subject_name,s[j].sub[i].faculty_name.faculty2);
}
}
}


}
