#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    cout<<"Enter number of process:";
    cin>>n;
  
    cout<<"\nEnter Burst Time:\n";
    for(int i=0;i<n;i++)
    {
       
        cin>>bt[i];
        p[i]=i+1;         
    }
  
   //sorting of burst times
    sort(bt,bt+n);
    wt[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
  
    avg_wt=(float)total/n;      
    total=0;
  
    cout<<"\nProcesst    Burst Time    \tWaiting Time    Turnaround Time\n";
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        cout<<p[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
    }
  
    avg_tat=(float)total/n;    
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
} 	
