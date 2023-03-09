#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include <numeric>
#include <algorithm>
#include <memory>
#include <cmath>
#include <ctime>
using namespace std;

struct abc{  // 48 
    int a;
    char c;
    char d;
    long b;
    string s;
};

struct Node{
    int val;
    Node* next;
    Node(int input):val(input){ next=nullptr; }
};

class mytrie{
    public:
        
    private:
       
}; 

void PrintLink(Node* head);
bool isrvlink(Node* head);

bool isrvlink(Node* head)
{   
    if (head==nullptr || head->next==nullptr) return true;
    Node *slow=head, *fast=head;
    while (fast->next!=nullptr && fast->next->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *cur = slow->next, *next=nullptr;
    slow->next=nullptr;
    while(cur!=nullptr)
    {
        next=cur->next;
        cur->next=slow;
        slow=cur;
        cur=next;
    }
    // slow is end
    bool res=true;
    cur=slow; // record end
    fast=head;
    while (fast!=nullptr&&slow!=nullptr)
    {
        if (fast->val!=slow->val) 
        {
            res = false;
            break;
        }
        fast=fast->next;
        slow=slow->next;
    }
    fast=nullptr;
    while (cur!=nullptr)
    {
        next=cur->next;
        cur->next=fast;
        fast=cur;
        cur=next;
    }
    return res;
}

void PrintLink(Node* head)
{
    if (head==nullptr) return;
    Node* node=head;
    while (node!=nullptr)
    {
        cout<<node->val<<" ";
        node=node->next;
    }
    printf("\n");
}

int main() {
    //cout<<sizeof(abc)<<endl;
    Node* node1 = new Node(1);
    node1->next = new Node(2);
    node1->next->next = new Node(3);
    node1->next->next->next = new Node(2);
    node1->next->next->next->next = new Node(1);
    PrintLink(node1);
    cout<<isrvlink(node1)<<endl;
    PrintLink(node1);
}  