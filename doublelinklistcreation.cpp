#include<iostream>
using namespace std;
struct  dlinklist
{
    int data;
    struct dlinklist *next;
    struct dlinklist *prev;
};
struct dlinklist *lp=NULL;
struct dlinklist *rp=NULL;
int num;
void create (struct dlinklist *);
void display(struct dlinklist *);
void insertfirst(struct dlinklist *);
void insertlast(struct dlinklist *);
void insertafter(struct dlinklist *);
int main()
{
    lp=new dlinklist;
    create(lp);
    display(lp);
    //insertfirst(lp);
    //insertlast(lp);
    insertafter(lp);
    display(lp);
}
void create(struct dlinklist *ptr)
{   
    num=0;
    int ch;
    lp->prev=NULL;
    do{
      cout<<"enter the data of node"<<num+1<<endl;
      cin>>ptr->data;
      cout<<"do you want another node? press  1"<<endl;
      cin>>ch;
      if(ch==1)
      {
          ptr->next=new dlinklist;
          ptr->next->prev=ptr;
          ptr=ptr->next;
      }
      num++;
      }while(ch==1);
ptr->next=NULL;
rp=ptr;
cout<<"total no. of nodes are:"<<num<<endl;
}
void display(struct dlinklist *ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"<-->";
        ptr=ptr->next;
    }
    ptr=rp;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"<-->";
        ptr=ptr->prev;
    }
}  
void insertfirst(struct dlinklist *ptr)
{
    struct dlinklist *new1;
    new1=new dlinklist;
    cout<<"enter value of inserting node";
    cin>>new1->data;
    if(ptr==NULL)
    {   
        new1->prev=NULL;
        new1->next=NULL;
        lp=new1;
    }
    else
    {
    new1->next=ptr;
    new1->prev=NULL;
    ptr->prev=new1;
    lp=new1;
    }

}
void insertlast(struct dlinklist *ptr)
{
    struct dlinklist *new1;
    new1=new dlinklist;
    cout<<"enter value of inserting node";
    cin>>new1->data;   
    if(ptr==NULL)
    {
        new1->next=NULL;
        new1->prev=NULL;
        lp=ptr;
    }
    else
    {   
        rp->next=new1;
        new1->next=NULL;
        new1->prev=rp;
        rp=new1;
        
    }
}
void insertafter(struct dlinklist *ptr)
{ int x;
    struct dlinklist *new1;
    new1=new dlinklist;
    cout<<"value of node";
    cin>>new1->data;
    cout<<"enter value before the place insertion ";
    cin>>x;
    while(ptr->data!=x && ptr!=NULL)
    {
        ptr=ptr->next;

    }
    if(ptr==NULL)
    {
        cout<<"element after which insertion does not exist";
    exit(0);
    }
    else if(ptr->next==NULL)
    {
    new1->next=NULL;
    new1->prev=ptr;
    ptr->next=new1;
    rp=new1;
    }
    else{
    ptr->next->prev=new1;
     new1->next=ptr->next;        
     new1->prev=ptr;
     ptr->next=new1;
    }
}
