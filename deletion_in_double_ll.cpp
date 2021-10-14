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
void deletefirst(struct dlinklist *);
void deletelast(struct dlinklist *);
void deletenode(struct dlinklist *);
int main()
{
    lp=new dlinklist;
    create(lp);
    display(lp);
    deletelast(lp);
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
void deletefirst(struct dlinklist *ptr)
{   
    cout<<"after deletion"<<endl;
    if(ptr==NULL)
    {
        cout<<"list is empty";
        exit(0);
    }
    else if(lp==rp)
    {
        rp=lp=NULL;
        free(ptr);
    }
    else{
        lp=ptr->next;
        lp->prev=NULL;
        free(ptr);
    }
}
void deletelast(struct dlinklist *ptr)
{   
    cout<<"after deletetion in list"<<endl;
    if(ptr==NULL)
    {
        cout<<"list is empty";
        exit(0);
    }
    else if(lp==rp)
    {
        lp=rp=NULL;
        free(ptr);
    }
    else{
        ptr=rp;
        rp=ptr->prev;
        rp->next=NULL;
        free(ptr);
    }
}
