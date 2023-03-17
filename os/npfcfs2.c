#include <stdio.h>
int main() {
   int proc[] = { 1, 2, 3};
   int n = sizeof proc / sizeof proc[0];
   int burst_time[] = {5, 8, 12};
   int  total_wt = 0, total_tat = 0,wt=0,tat1=burst_time[0];
   printf("Processes  Burst   Waiting Turn around ");
   for ( int i=0; i<n; i++) {
   if(i!=0){tat1+=burst_time[i];}
      printf("\n");
      printf(" %d\t  %d\t\t %d \t%d", i+1, burst_time[i], wt, tat1);
      wt+=burst_time[i];
      
   }
   return 0;
}
