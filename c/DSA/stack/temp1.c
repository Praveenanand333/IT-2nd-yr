#include<stdio.h>
#include<string.h>
int main(){
char string[52]="welcome";
printf("%c",string[0]);
int i=0;
for(i=0;i<=strlen(string);i++){
    printf("%c",string[i]);
}
}
