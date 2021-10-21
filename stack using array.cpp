#include<iostream>
#define size 100
using namespace std;
int top=-1;
int flag=0;
int stack[size];
void push(int *,int);
void display(int *);
int pop(int *);
int peep(int *);
int main()
{
    int data;
    char choice;
    int q=0;
    do{
      cout<<"push-i     pop->p      z->peep     quit->q "<<endl;
      cout<<"input choice";
      cin>>choice;
   
      switch(choice)
      {
          case 'i' :
          cout<<"element you want to enter";
          cin>>data;
          push(stack,data);
          if (flag!=0)
          {
              cout<<"after inserting";
              display(stack);
              if(top==(size-1))
              cout<<"stack is full";
          }
          else
              cout<<"stack overflow after pushing";
              break;
          case 'p':
         data=pop(stack);
         if(flag)
         {
             cout<<"data is popped"<<data<<endl;
             cout<<"the rest data is as follows"<<endl;
             display(stack); 
         }
         else{
        cout<<"stack underflow";
        break;            
             }
      case 'z':
      //peep(stack);
      cout<<peep(stack);
      break;

     case 'q':
       q=1;         
 
      }     
      }while(!q);

}
void push(int s[],int d)
{
    if(top==(size-1))
    {
    flag=0;
    }
    else
    {
        flag=1;
        ++top;
        s[top]=d;       
    }
}
int pop(int s[])
{
    int popped_element;
    if(top==-1)
    {
    flag=0;
    popped_element = 0;
    }
    else{
        flag=1;
        popped_element=s[top];
        --top;
    }
    return(popped_element);
}
void display(int s[])
{
    int i;
    if(top==-1)
    cout<<"stack is empty";

    else{
        for(i=top;i>=0;i--)
        {
            cout<<s[i]<<endl;
        }
    }
}
int peep(int s[])
{
    int i;
    int peeped_element;
    cout<<"enter the info number to which you want to access";
    cin>>i;
    if(top-i+1<0)
    {
        peeped_element=0;
        flag=0;
    }   
    else
    {
        flag=1;
        peeped_element=s[top-i+1];
    }
    return peeped_element;
}
