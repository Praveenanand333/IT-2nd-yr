#include<iostream>
using namespace std;
class Books{
int id;
string authorname;
string publishername;
int price;
int year;

public:
void set_id(int id1){id=id1;}
void set_authorname(string authorname1){authorname=authorname1;}
void set_publishername(string publishername1){
publishername=publishername1;}
void set_price(int price1){price=price1;}
void set_year(int year1){year=year1;}

int get_id(){return id;}
string get_authorname(){return authorname;}
string get_publishername(){return publishername;}
int get_price(){return price;}
int get_year(){return year;}
};

int main(){
Books b[5];
int choice,count=0,am;
int id[5]={1,2,3,4,5};
int price[5]={100,150,100,200,200};
int year[5]={2022,2021,2009,2018,2015};
string authorname[5]={"anand","bala","kumar","abi","Ravi"};
string publishername[5]={"a","b","c","d","e"};
for(int i=0;i<5;i++){
b[i].set_id(id[i]);
b[i].set_price(price[i]);
b[i].set_year(year[i]);
b[i].set_authorname(authorname[i]);
b[i].set_publishername(publishername[i]);
}
cout<<"Enter the id of the book to get the details:";
cin>>choice;
for(int i=0;i<5;i++){
if(id[i]==choice){
cout<<"Id:"<<b[i].get_id()<<endl;
cout<<"Price:"<<b[i].get_price()<<endl;
cout<<"Year:"<<b[i].get_year()<<endl;
cout<<"Author name:"<<b[i].get_authorname()<<endl;
cout<<"Publisher name:"<<b[i].get_publishername()<<endl;
}
}
cout<<"Enter the amount to get the number of books in that amount:";
cin>>am;
for(int i=0;i<5;i++){
if(price[i]==am){
count++;
}
}
cout<<"The number of books are:"<<count;
}
