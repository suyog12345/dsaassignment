#include<iostream>
using namespace std;
struct node 
{
int data;
struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void insert();
void deletee();
void display();
void insert()
{
    struct node *ptr;
    ptr=new node;

    if(ptr==NULL)
    {
        cout<<"queue is empty";
    }
    else
    {
    cout<<"enter value"<<endl;
    cin>>ptr->data;
    if(front==NULL)
    {
        front=ptr;
        rear=ptr;
        front->next=NULL;
        rear->next=NULL;
    }
    else
    {
    rear->next=ptr;
    rear=ptr;
    rear->next=NULL;
    }

  }

}
void deletee()
{
    struct node *ptr;
    if(front==NULL)
    {
        cout<<"underflow";
    }

    else
    {
        ptr=front;
        front=front->next;
        free(ptr);
    }
}

void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}  
int main()
{
     insert(); 
      insert(); 
       insert(); 
        insert(); 
         insert(); 
         display();
         deletee();
         display();
}
