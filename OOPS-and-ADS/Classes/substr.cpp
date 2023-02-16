#include<iostream>
using namespace std;
int main(){
string str="ABCD";
int n=str.length();
for(int i=0;i<n;i++){
for(int j=i;j<=n;j++){
	cout<<str.substr(i,j)<<endl;
}
}
}
