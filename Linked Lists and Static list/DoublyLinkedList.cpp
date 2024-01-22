#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
private:
    Node *start;

public:
    LinkedList() : start(nullptr) {}

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
        }
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        Node *ptr = start;
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
        }
    }

    void insertAfterANode(int value, int sData)
    {
        Node *newNode = new Node(value);
        Node *ptr = start;
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            while (ptr->data != sData)
            {
                ptr = ptr->next;
            }
            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next->prev = newNode;
            ptr->next = newNode;
        }
    }

    void insertBeforeANode(int value, int sData)
    {
        Node *newNode = new Node(value);
        Node *ptr = start;
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            while (ptr->next->data != sData)
            {
                ptr = ptr->next;
            }
            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next->prev = newNode;
            ptr->next = newNode;
        }
    }

    void deleteFromBeginnig()
    {

        if (start == nullptr)
        {
            cout << "Underflow" << endl;
            return;
        }
        else
        {
            Node *ptr = start;
            start = start->next;
            delete ptr;
        }
    }

    void deleteFromEnd()
    {
        if (start == nullptr)
        {
            cout << "Underflow" << endl;
            return;
        }
        else
        {
            Node *ptr = start;
            while (ptr->next->next != nullptr)
            {
                ptr = ptr->next;
            }
            Node *temp = ptr->next;
            ptr->next = nullptr;
            delete temp;
        }
    }

    void deleteAfterANode(int sData)
    {

        if (start == nullptr)
        {
            cout << "Underflow" << endl;
            return;
        }
        else
        {
            Node *ptr = start;
            while (ptr->data != sData)
            {
                ptr = ptr->next;
            }
            if (ptr == nullptr)
            {
                cout << "The node with data" << sData << "is not found" << endl;
                return;
            }
            if (ptr->next == nullptr)
            {
                cout << "The node with data " << sData << " is at the end of the list." << endl;
            }
            Node *temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            delete temp;
        }
    }

    void deleteBeforeANode(int sData)
    {
        cout << "hello";
        if (start == nullptr)
        {
            cout << "The list is empty::underflow condition" << endl;
            return;
        }
       else{
           Node *ptr = start;
           while (ptr->next->next->data != sData)
           {

               ptr = ptr->next;
           }

           Node *temp = ptr->next;
           ptr->next = temp->next;
           temp->next->prev = ptr;
           delete temp;
       }
    }

    void printList()
    {
        Node *ptr = start;
        if (start == nullptr)
        {
            cout << "Underflow" << endl;
            return;
        }
        else
        {
            while (ptr != nullptr)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << "\n";
        }
    }
};

int main()
{
    LinkedList l;
    l.insertAtBeginning(1);
    l.insertAtEnd(2);
    l.insertAtEnd(9);
    l.insertAfterANode(3, 2);
    l.insertBeforeANode(4, 2);
    l.printList();

    l.deleteFromBeginnig();
    l.deleteFromEnd();
    l.deleteBeforeANode(2);
    l.printList();
    return 0;
}