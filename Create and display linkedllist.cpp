#include<iostream>
using namespace std;
struct node
{
int data;
struct node *next;
};
void printlinkedlist(struct node *ptr)
{
while(ptr!=NULL)
{
    cout<<ptr->data<<endl;
    ptr=ptr->next;

}
}
int main()
{
struct node *first,*second,*third,*fourth,*fifth;
first= new node;
second=new node;
third= new node;
fourth= new node;
fifth=new node;

first->data=10;
first->next=second;

second->data=20;
second->next=third;
third->data=30;
third->next=fourth;
fourth->data=40;
fourth->next=fifth;
fifth->data=50;
fifth->next=NULL;
cout<<"FIRST==>";
//to print the elements of linked list
printlinkedlist(first);
cout<<"NULL";
return 0;
}




