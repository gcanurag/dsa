#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int value):data(value),next(nullptr){}
};

class LinkedStack{
    private:
        Node *top;

    public:
        LinkedStack():top(nullptr){}

        void push(int value){
            Node *newNode = new Node(value);
            if(top==nullptr){
                newNode->next = nullptr;
                top = newNode;
            }else{
                newNode->next = top;
                top = newNode;
            }
        }

        void pop(){
            if(top==nullptr){
                cout << "The stack is full" << endl;
                return;
            }else{
                Node *ptr = top;
                top = top->next;
                delete ptr;
            }
        }

        void printStack(){
            const Node *ptr = top;
            do{
                cout << ptr->data << " ";
                ptr = ptr->next;
            } while (ptr!= nullptr);
            cout << "\n";
        }
};

int main(){
    LinkedStack l;
    l.push(1);
    l.push(2);
    l.push(0);
    
    l.printStack();
    l.pop();
    l.printStack();
    return 0;
}
