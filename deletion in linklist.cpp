#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *start;
void create(struct node *);
void display(struct node *);
void deletee(struct node *);
void deleteend(struct node *);
void deleteindex(struct node *);
int main()
{
    start = new node;
    create(start);
    display(start);
    // deletee(start);
    //display(start);
    //deleteend(start);
    deleteindex(start);
    cout<<"after deleting node"<<endl;
    display(start);
}
void create( struct node *ptr)
{
    int num=0;
    int ch;
    do{
        cout<<"enter the value of node"<<num+1<<endl;
        cin>>ptr->data;
        cout<<"do you want to enter another node? press 1"<<endl;
        cin>>ch;
        if(ch==1)
        {
            ptr->next=new node;
            ptr=ptr->next;
        }
        num++;
    }while(ch==1);
        ptr->next=NULL;
}
      void display(struct node *ptr)
      {
      while(ptr!=NULL)
      {
      cout<<ptr->data<<endl;
      ptr=ptr->next;
      }
      }
void deletee(struct node *ptr)
{
    cout<<"first node deleted successfully";
    if(ptr==NULL)
    {
        cout<<"list is empty";
    }
    else if(ptr->next==NULL)
    {
        start=NULL;
        free(ptr);
    }
    else{
        start=ptr->next;
        free(ptr);
    }
}
void deleteend(struct node *ptr)
{
struct node *prev = ptr;

if(ptr==NULL)
{
    cout<<"list is empty";
}
else if(ptr->next==NULL)
{
    start = NULL;
    free(ptr);
}
else{
    
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=NULL;
    free(ptr);
}
}
void deleteindex(struct node *ptr)
{
    int index;
    cout<<"enter index no for deletion";
    cin>>index;
    struct node *prev = ptr;
    for(int i =1;i<index;i++)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=ptr->next;
    free(ptr);
}
