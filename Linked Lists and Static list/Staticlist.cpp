#include <iostream>
#include <cmath>
using namespace std;

const int NUMNODES = 10;
class Node
{
public:
    int data;
    int next;
    Node() : data(0), next(-1) {}
    Node(int value) : data(value), next(-1) {}
};

class List
{
private:
    int avail;
    int list;
    Node node[NUMNODES];

public:
    List()
    {
        avail = 0;
        list = -1;
        for (int i = 0; i < NUMNODES; i++)
        {
            node[i].next = i + 1;
        }
        node[NUMNODES-1].next = -1;
    }

    int getNode(int x)
    {

        int index;
        if (avail == -1)
        {
            cout << "Overlow";
            exit(1);
        }
        else
        {
            index = avail;
            avail = node[avail].next;
            node[index].data = x;
            node[index].next = -1;
            return index;
        }
    }

    void freeNode(int index)
    {
        node[index].next = avail;
        avail = index;
        if (index == list)
        {
            list = -1;
        }
    }

    void insertAtBeginning(int x)
    {
        int index = getNode(x);
        node[index].next = list;
        list = index;
    }

    void insertAtEnd(int x)
    {
        int index = getNode(x);
        int i = list;
        while (node[i].next != -1)
        {
            i = node[i].next;
        }
        node[i].next = index;
    }

    void insertAfter(int x, int ref)
    {
        int index = getNode(x);
        int i = list;
        while (node[i].data != ref)
        {
            i = node[i].next;
        };
        node[index].next = node[i].next;
        node[i].next = index;
    }

    void deleteFromBegining()
    {
        int index = list;
        list = node[list].next;
        freeNode(index);
    }

    void deleteFromEnd()
    {
        int i, q;
        i = q = list;
        while (node[i].next != -1)
        {
            q = i;
            i = node[i].next;
        }
        node[q].next = -1;
        freeNode(i);
    }

    void deleteAfter(int refIndex) // here refIndex is the index of node after which the node is to be deleted;
    {
        int i, q;
        if (node[refIndex].next == -1)
        {
            cout << "Invalid deletion call";
            return;
        }
        i = refIndex;
        q = node[i].next;
        node[i].next = node[q].next;
        freeNode(q);
    }

    void deleteAfterSpecificData(int refData)
    {
        int i, q;
        i = list;
        while (node[i].data != refData)
        {
            i = node[i].next;
        }
        q = node[i].next;
        node[i].next = node[q].next;
        freeNode(q);
    }

    void printList()
    {
        int i = list;
        while (i != -1)
        {
            cout <<"("<< node[i].data << ","<<i<<"," << node[i].next <<")"<< " ";
            i = node[i].next;
        }
        cout << "\n";
    }
};

int main()
{
    List l;
    l.insertAtBeginning(1);
    l.insertAtBeginning(-1);
    l.insertAtBeginning(-2);
    l.insertAtEnd(2);
    l.printList();

    return 0;
}