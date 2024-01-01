#include<iostream>
using namespace std;
const int n=6;
int deque[n];
int f=-1;
int r=-1;


void enqueuefront(int x)
{
    if(f==(r+1)%n)
    {
        cout<<"The queue is full. No further elements can be inserted"<<endl;
        return;
    }
   else if(f==0)
    {
        cout<<"No empty spaces at front."<<endl;
        return;
    }
    else{
        f--;
        deque[f]=x;
        cout<<"The inserted element from front is"<<x<<endl;

    }
}


void enqueuerear(int x)
{
    if(r==n-1)
    {
        cout<<"The queue is full"<<endl;
        return;
    }

    else  if (r==-1 &&f==-1)
    {
        f=r=0;
        deque[r]=x;
        cout<<"The dequeued element from rear is "<<x;
    }else{
        deque[++r]=x;
        cout<<"The dequeued element from rear is "<<x;

    }
    
}


void dequeuerear()
{
    if(f==(r+1)%n)
    {
        cout<<"The queue is empty. No elements avvailable to be deleteed";
    }else if(f==r)
    {
        cout<<"Only one elements left in the queue to be deleted which is "<<deque[r];
        f=-1;
        r=-1;
    }else{
        cout<<"The dequeued element is "<<deque[r]<<endl;
        r--;
    }
    
}

void dequeuefront()
{
    if(f==-1&&r==-1)
    {
        cout<<"The queue is empty"<<endl;
        return;
    }else if(f==r){
    
      cout<<"Only one element is present in the queue to be deleted"<<deque[f]<<endl;
      f=-1;
      r=-1;
    }
    else{
        int d=deque[f];
        cout<<"The dequeued element from the front is "<<d<<endl;
        f++;
    }
}

int main()
{
    enqueuefront(1);
    dequeuefront();
    enqueuerear(23);
    enqueuerear(4);
    dequeuerear();
    return 0;
}