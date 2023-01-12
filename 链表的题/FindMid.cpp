#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int v):val(v){}
};

class LinkedList{
    public:
        // 快慢指针法主要是定好指针起始位置
        int fmidorupmid(Node* head)   // 容器法位置：return arr.get((arr.size() - 1) / 2);
        {
            if (head==nullptr || head->next==nullptr || head->next->next==nullptr)
            {
                return head->val;
            }
            // 链表必须有3个点或以上
            Node* slow = head->next;
            Node* fast = head->next->next;
            while(fast->next!=nullptr && fast->next->next!=nullptr)
            {
                slow = slow->next;
                fast=fast->next->next;
            }
            return slow->val;
        }

        int fmidordownmid(Node* head)   // 容器法位置：return arr.get(arr.size() / 2);
        {
            if (head==nullptr || head->next==nullptr)
            {
                return head->val;
            }
            Node* slow = head->next;
            Node* fast = head->next;     // compare to findupmid, only this changed!
            while(fast->next!=nullptr && fast->next->next!=nullptr)
            {
                slow = slow->next;
                fast=fast->next->next;
            }
            return slow->val;
        }

        // 从 找中或上中点 推理而来
        int fmidorupmidpre(Node* head)   // 容器法位置：return arr.get((arr.size() - 3) / 2);
        {
            if (head==nullptr || head->next==nullptr || head->next->next==nullptr)
            {
                //return head->val;
                return -1;
            }
            Node* slow = head;
            Node* fast = head->next->next;
            while(fast->next!=nullptr && fast->next->next!=nullptr)
            {
                slow = slow->next;
                fast=fast->next->next;
            }
            return slow->val;
        }

        int fmidordownmidpre(Node* head)   // 容器法位置：return arr.get((arr.size() - 2) / 2);
        {
            if (head==nullptr || head->next==nullptr)
            {
                return -1;
            }
            if (head->next->next==nullptr)
            {
                return head->val;
            }
            Node* slow = head;
            Node* fast = head->next;
            while (fast->next!=nullptr && fast->next->next!=nullptr)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow->val;
        }
};

int main() {
    Node* node = new Node(0);
    node->next = new Node(1);
    node->next->next = new Node(2);
    node->next->next->next = new Node(3);

    LinkedList list;
    cout<<list.fmidorupmid(node)<<endl;
    cout<<list.fmidordownmid(node)<<endl;
    cout<<list.fmidorupmidpre(node)<<endl;
    cout<<list.fmidordownmidpre(node)<<endl;
}