#include<iostream>
#include<stack>
using namespace std;
int n=5;
int *queue=new int[n];
int f=-1, r=-1;
void enqueue(int x)
{
    if(r==n-1)
    {
        cout<<"Queue is full"<<endl;
        return;

    }
    if(f==-1&&r==-1){
        r=0;
        f=0;
        queue[r]=x;
         cout<<"The inserted element is "<<x<<endl;
    }
    else{
        queue[++r]=x;
        cout<<"The inserted element is "<<x<<endl;
    }

}

void dequeue()
{
    if(f==-1&&r==-1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    if(f==r)
    {
        cout<<"Only one element is present"<<endl;
        f=-1;
        r=-1;

    }else{
        int d=queue[f];
        f++;
        cout<<"The dequeued element is "<<d<<endl;
        

    }
    
}


int main()
{
    enqueue(2);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(1);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;

}

