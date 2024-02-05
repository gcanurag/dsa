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

class Queue
{
private:
    int avail, f, r;
    Node node[NUMNODES];

public:
    Queue()
    {
        avail = 0;
        f = r = -1;
        for (int i = 0; i < NUMNODES; i++)
        {
            node[i].next = i + 1;
        }
        node[NUMNODES - 1].next = -1;
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
        if (index == f)
        {
            f = -1;
            r = -1;
        }
    }

    void enqueue(int x)
    {
        int index = getNode(x);
        if (r == NUMNODES - 1)
        {
            cout << "The queue is full";
            return;
        }
        else if (f == -1 && r == -1)
        {
            f = r = 0;
            node[r].next = -1;
        }
        else
        {
            node[r].next = index;
            r = index;
            node[index].next = -1;
        }
    }

    void dequeue()
    {
        if (f == -1 && r == -1)
        {
            cout << "Underflow";
            return;
        }
        else if (f == r)
        {
            cout << "Only one element is present" << endl;
            f = -1;
            r = -1;
        }
        else
        {
            int index = f;
            f = node[f].next;
            freeNode(index);
        }
    }

    void printList()
    {
        int i = f;
        while (i != -1)
        {
            cout << "(" << node[i].data << "," << i << "," << node[i].next << ")"
                 << " ";
            i = node[i].next;
        }
        cout << "\n";
    }
};

int main()
{
    Queue q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.printList();

    q.dequeue();
    q.printList();

    return 0;
}