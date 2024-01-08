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

        void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void insertAfterANode(int value, int sData)
    {
        // find that specific node after which new node is to be inserted
        Node *ptr = head;
        while (ptr->data != sData)
        {
            ptr = ptr->next;
        }

        Node *newNode = new Node(value);
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void insertBeforeANode(int value, int sData)
    {
        // find the specific node before which the new node is to be inserted
        Node *ptr = head;
        while (ptr->next->data != sData)
        {
            ptr = ptr->next;
        }

        Node *newNode = new Node(value);
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void printList() const
    {
        const Node *ptr;
        ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

        cout << "\n";
    }
};

int main()
{
    LinkedList l;
    l.insertBeginning(3);
    l.insertBeginning(2);
    l.printList();
    l.insertAtEnd(1);
    l.insertAfterANode(4, 3);
    l.printList();
    l.insertBeforeANode(7, 8);
    l.printList();

    return 0;
}
