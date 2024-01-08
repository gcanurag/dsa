#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insertBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void printList()const {
        const Node *ptr;
        ptr = head;
        while(ptr!=nullptr){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

        cout << "\n";
    }
};

int main(){
    LinkedList l;
    l.insertBeginning(3);
    l.insertBeginning(2);
    l.insertBeginning(5);

    cout << "The linked list is";
    l.printList();

    
    return 0;
}
