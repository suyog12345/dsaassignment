#include<iostream>
using namespace std;
struct link
{
int data;
struct link *next;    
}*start;
struct link *push(struct link *);
struct link *pop(struct link *);
void display(struct link *);
int main()
{
    int choice,f;
do{
    cout<<"enter you choice 1->push  2->pop  3->exit"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        start=push(start);
        display(start);
        break;
        case 2:
        start=pop(start);
        display(start);
        break;
        case 3:
        f=1;
        break;
    }
    }while(f!=1);
}
struct link *push(struct link *rec)
{
    struct link *newrec;
    newrec =new link;
    cout<<"enter element"<<endl;
    cin>>newrec->data;
    newrec->next=rec;
    rec=newrec;
    return rec;

}
struct link *pop(struct link *rec)
{
struct link *temp;
    if(rec==NULL)
    {
    cout<<"list is empty";
    }
    else
    {
temp=rec->next;
free(rec);
rec=temp;
    }
return rec;
}
void display(struct link *rec)
{
    while(rec!=NULL)
    {
        cout<<rec->data<<endl;
        rec=rec->next;
    }
}
