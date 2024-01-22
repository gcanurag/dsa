#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int value):data(value),next(nullptr){}
};


class LinkedQueue{
    private:
        Node *f;
        Node *r;

    public:
        LinkedQueue():f(nullptr),r(nullptr){}

        void enqueue(int x){
            Node *ptr = new Node(x);
            if (f == nullptr && r ==nullptr)
            {
                f = ptr;
                r = ptr;
                f->next = nullptr;
                r->next = nullptr;
            }else{
                r->next = ptr;
                r = ptr;
                r->next = nullptr;
            }
        }


        void dequeue(){
            if (f == nullptr && r == nullptr){
                cout << "The queue is empty" << endl;
                return;
            }
            if(f==r){
                cout << "Only one element is present" << endl;
                f = r = nullptr;
                cout << "Now the queue is empty";
            }else{
                Node *ptr = f;
                f = f->next;
                delete ptr;
            }
        }

        void printQueue(){
            Node *ptr = f;
            while(ptr!=nullptr){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << "\n";
        }
};

int main()
{
    LinkedQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.printQueue();
    q.dequeue();
    q.printQueue();

    return 0;
}