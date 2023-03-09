#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int i=0;
int size=3;
int frju(int n,int heights[]){
if(n==0){
return 0;
}
int l=frju(n-1,heights)+abs(heights[n]-heights[n-1]);
int r=INT_MAX;
if(n-2>=0){
r=frju(n-2,heights)+abs(heights[n]-heights[n-2]);}
return min(l,r);
}

int main(){

int arr[5]={10,30,20,10};
int res=frju(3,arr);
cout<<res;
}
