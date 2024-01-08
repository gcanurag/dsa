#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node *next;

        Node(int value):data(value),next(nullptr){}
};


class LinkedList{
    private:
        Node *start;

    public:
        LinkedList():start(nullptr){}

        void insertFromBeginnig(int value){
            Node *newNode = new Node(value);
            newNode->next = start;
            start = newNode;
        }

        void insertAtEnd(int value){
            Node *newNode = new Node(value);
            if(start==nullptr){
                start = newNode;
            }else{
                Node *ptr = start;
                while(ptr->next!=nullptr){
                    ptr = ptr->next;
                }
                ptr->next = newNode;
            }
        }


        void deleteFromBeginnig(){
            if(start==nullptr){
                cout << "The list is empty::underflow condition" << endl;
                return;
            }else{
                Node *ptr = start;
                start = start->next;
                delete ptr;
            }
            
        }

        void deleteAfterANode(int sData){
            if (start == nullptr)
            {
                cout << "The list is empty::underflow condition" << endl;
                return;
            }else{
                Node *ptr = start;
                while(ptr->data!=sData){
                    ptr = ptr->next;
                }
                Node *temp = ptr->next;
                ptr -> next = temp -> next;
                delete temp;
            }
        }

        void deleteBeforeANode(int sData){
            if(start==nullptr){
                cout << "The list is empty::underflow condition" << endl;
                return;
            }
            Node *ptr = start;
            while(ptr->next->data!=sData){
                ptr = ptr->next;
            }
            if(ptr==nullptr){
                cout << "The node with data" << sData << "is not found" << endl;
                return;
            }
            if(ptr->next==nullptr){
                cout << "The node with data " << sData << " is at the end of the list." << endl;
            }
            Node *temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }

        void printList(){
            if(start==nullptr){
                cout << "The list is empty" << endl;
                return;
            }else{
                Node *ptr = start;
                while(ptr!=nullptr){
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
            }

        }
};


int main(){
    LinkedList l;
    l.insertFromBeginnig(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.printList();
    l.deleteAfterANode(3);
    l.printList();
    l.deleteBeforeANode(3);
    l.printList();
    return 0;
}