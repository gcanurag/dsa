#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int exp;
    Node *next;
    Node(int value, int index) : data(value), exp(index), next(nullptr) {}
};

class LinkedList
{
private:
    Node *start;

public:
    LinkedList() : start(nullptr) {}

    void insertion(int x, int index)
    {
        Node *newNode = new Node(x, index);
        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            Node *ptr = start;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    void additionOfPolynomials(LinkedList P, LinkedList Q)
    {
        Node *ptrP = P.start;
        Node *ptrQ = Q.start;
        // LinkedList R;

        while (ptrP->next!=nullptr|| ptrQ->next !=nullptr)
        {
            int p = ptrP->data;
            int q = ptrQ->data;
            cout << ptrP->exp << " " << ptrQ->exp << endl;
            if (ptrP->exp == ptrQ->exp)
            {
                int e = ptrP->exp;
                insertion(p + q, e);
                ptrP = ptrP->next;
                ptrQ = ptrQ->next;
                }
                else if (ptrP->exp > ptrQ->exp )
                {
                    int e = ptrP->exp;
                    insertion(p, e);
                    ptrP = ptrP->next;
                }
                else if (ptrP->exp < ptrQ->exp )
                {
                    int e = ptrQ->exp;
                    insertion(q, e);
                    ptrQ = ptrQ->next;
                }
                if (ptrP == nullptr) {
    while (ptrQ != nullptr) {
        insertion(ptrQ->data, ptrQ->exp);
        ptrQ = ptrQ->next;
    }
    break;
}

// Check if second list is exhausted
if (ptrQ == nullptr) {
    while (ptrP != nullptr) {
        insertion(ptrP->data, ptrP->exp);
        ptrP = ptrP->next;
    }
    break;
}
        }
        Node *ptr = (ptrP != nullptr) ? ptrP : ptrQ;
        while (ptr != nullptr)
        {
            insertion(ptr->data, ptr->exp);
            ptr = ptr->next;
        }
    }

    void printList()
    {
        const Node *ptr = start;
        // cout << ptr->data;
        while (ptr != nullptr)
        {
           if(ptr->next!=nullptr){
               cout << ptr->data << "x" << ptr->exp << " +"
                    << " ";
           }else
           {
              cout<< ptr->data << "x" << ptr->exp;
           }
            ptr = ptr->next;
        }
        cout << "\n";
    }
};

int main()
{
    LinkedList p, q, r;
    p.insertion(3, 14);
    p.insertion(2, 8);
    p.insertion(1, 0);
    p.printList();

    q.insertion(8, 14);
    q.insertion(-3, 10);
    q.insertion(10, 6);
    q.printList();

    r.additionOfPolynomials(p, q);
    r.printList();


    return 0;
}