#include<iostream>
using namespace std;
const int n=5;
int cqueue[n];
int f=-1;
int r=-1;


void enqueue(int x)
{
    if(f==-1&&r==-1)
    {
        cout<<"Initially the queue was empty"<<endl;
        f=r=0;
        cqueue[r]=x;
        cout<<"The inserted element is"<<x<<endl;
    }
    else if(((r+1)%n)==f)  //checks the full condition for both cases. f=0 and r=n-1 as well as f==r+1
    {
        cout<<"The queue is full and no further elements can be inserted."<<endl;
        return;
    }
    else{
        r=(r+1)%n;
        cqueue[r]=x;
        cout<<"The inserted element is "<<x<<endl;
    }
}


void dequeue()
{
    if(f==-1&&r==-1){
        cout<<"The queue is empty and no elements to deleted"<<endl;
    }
    else if(f==r)
    {
        cout<<"There is only one element left in the queue to be dequeued "<<cqueue[r]<<endl;
        f=-1;
        r=-1;
    }
    else{
        int d=cqueue[f];
        f=(f+1)%n;
        cout<<"The deleted element is "<<d<<endl;
    }



}


int main(){

    enqueue(2);
    enqueue(5);
    enqueue(7);
    enqueue(-6);
    enqueue(4);
    enqueue(6);
    dequeue();
    enqueue(3);






    return 0;

}

