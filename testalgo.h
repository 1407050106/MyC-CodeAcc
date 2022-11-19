#include <iostream>
//#include <cstdlib.h>
using namespace std;

struct Node 
{
    int val = 0;
    Node* next;
};

Node* create(int leng)
{
    Node* head = new Node;
    Node* pre = head;
    for (int i = 0; i < leng; i++)
    {
        Node* p = new Node;
        p->val = i+1;
        pre->next = p;
        pre = p;               //pre node becomes now node, move forward

        p->next=NULL;
        
    }
    return head;
}

void display(Node* head)
{
    Node* bac = head;

	do
	{
		cout << bac->val << endl;
		bac = bac->next;
	} while (bac->next);

	cout << "Over~\n" << endl;

}
