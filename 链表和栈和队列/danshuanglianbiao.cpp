#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    // Node(int value)
    // {
    //     val = value;
    // }
};

Node* CreateChain(int num)
{
    Node* head = new Node;
    Node* pre = head;
    for (int i=1; i<=num; i++)
    {
        Node* cur = new Node;
        cur->val=i;
        cur->next=nullptr;
        pre->next=cur;
        pre=cur;
    }
    return head->next;
}

//shuangxiang lianbiao
Node* CreateSChain(int num)   
{
    Node* head = new Node;
    Node *pre=head;

    for (int i=1; i<=num; i++)
    {
        Node* cur = new Node;
        cur->val = i;
        cur->next=nullptr;
        cur->prev=pre;
        pre->next=cur;   
        pre=cur;
    }

    return head->next;
}

void PrintChain(Node* head)
{
    if (head==nullptr)
    {
        cout<<"No Chain!"<<endl;
        return;
    }

    do{
        cout<<head->val<<endl;
        head = head->next;
    } while (head!=nullptr);           //zhezhong shuchu zuiwen
}

void RPrintChain(Node* head)
{
    if (head==nullptr)
    {
        cout<<"No Chain!"<<endl;
        return;
    }

    while(head->next!=nullptr)
    {
        head=head->next;
    }

    while(head->prev!=nullptr)
    {
        cout<<head->val;
        head=head->prev;
    }
}

//fanzhuan lianbiao
Node* ChainReverse(Node* head)
{
    Node* pre = nullptr;
    Node* next = nullptr;
    while (head!=nullptr)
    {
        next=head->next;
        head->next=pre;
        pre=head;
        head = next;
    }
    return pre;
}

Node* DoubleChainReverse(Node* head)
{
    Node* next = nullptr;
    Node* pre = nullptr;
    
    while(head!=nullptr)
    {
        next=head->next;
        head->next=pre;
        head->prev=next;
        pre = head;
        head = next;
    }
    return pre;
}

Node* Deleteone(Node* head, int target)    //2ge while
{
    while(head!=nullptr)
    {
        if (head->val!=target)
            break;
        head=head->next;
    }
    Node* pre = head;     //shuang zhizhen sixiang, touzhizhen is this, bu huibian
    Node* cur = head;
    while(cur!=nullptr)
    {
        if (cur->val==target)
        {
            pre->next=cur->next;    //pre genggai next zhixiang de jiedian
        } else {
            pre=cur;
        }
        cur=cur->next;   //cur zhishi qu bianli
    }
    return head;
}

int main() {
    int number = 3;
    // Node* head = CreateSChain(number);  
    // Node* headkong = new Node;
    // PrintChain(head); 
    // printf("\n");
    // RPrintChain(head);

    //fanzhuan lianbiao      should be : 1234554321
    // Node* head = CreateChain(number);
    // PrintChain(head);
    // Node* rhead = ChainReverse(head);
    // PrintChain(rhead);

    //fanzhuan doublelianbiao     should be : 1234554321
    // Node* head = CreateSChain(number);  
    // PrintChain(head);
    // Node* rhead = DoubleChainReverse(head);
    // PrintChain(rhead);

    //delete one number
    Node* head = CreateChain(number);
    Node* head2 = Deleteone(head, 1);
    PrintChain(head2);
}
