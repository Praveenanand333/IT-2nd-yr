#include<iostream>
using namespace std;
class LinkedList{
public:
	struct Node
	{
		int data;
		struct Node* next;
		
	}*head;
	
	LinkedList(){
	head=NULL;}


void InsertAtBeginning(int x){
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
}


void InsertAtEnd(int x){
struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
 struct Node* temp1 = head;
    temp->data=x;
    temp->next=NULL;
    if(head==NULL){
		head=temp;
		return;
 }
    while (temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
}


void Print(){
    struct Node* temp = head;
    cout<<"the list is :\n";
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}


void Insertatpos(int data,int n){
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));//temp1 is the new node to be inserted
    temp1->data=data;
    temp1->next=NULL;
    if(n==1){
        temp1->next=head;
        head=temp1;
        return;

    }
    struct Node* temp2=head;
    for(int i =0;i<n-2;i++){
		temp2=temp2->next;//temp2 is the node at the (n-1)th position
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}


void Delete(int n){
    struct Node* temp1=head;
    if(n==1){
        head=temp1->next;
        free(temp1);
        return;
    }
    for(int i=0;i<n-2;i++){
        temp1=temp1->next;
    }
    //temp1 points to the n-1 th node
	struct Node* temp2=temp1->next;//temp2 points to the n th node which is to be deleted
	temp1->next=temp2->next;//n+1 th node
	free(temp2);
}
};


int main(){
LinkedList ll;
int choice,val,pos;

do{
cout<<"1-Insert at beginiing\n2-Insert at end\n3-Insert at pos\n4-Delete\n5-Display\n6-Exit\n";
cin>>choice;
switch(choice){
case 1:
	cout<<"\nEnter the value to be inserted:";
	cin>>val;
	ll.InsertAtBeginning(val);
	cout<<"\nThe linked list after insertion is:";
	ll.Print();
	break;
case 2:
	cout<<"\nEnter the value to be inserted:";
	cin>>val;
	ll.InsertAtEnd(val);
	cout<<"\nThe linked list after insertion is:";
	ll.Print();
	break;
case 3:
	cout<<"\nEnter the value to be inserted:";
	cin>>val;
	cout<<"\nEnter the position:";
	cin>>pos;
	ll.Insertatpos(val,pos);
	cout<<"\nThe linked list after insertion is:";
	ll.Print();
	break;
case 4:
	cout<<"\nEnter the position to be deleted:";
	cin>>val;
	ll.Delete(val);
	cout<<"\nThe linked list after deletion is:";
	ll.Print();
	break;
case 5:
	ll.Print();
	break;
case 6:
	break;
default:
	cout<<"\nInvalid choice:";
	break;

}
}while(choice!=6);
}
