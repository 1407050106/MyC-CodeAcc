#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int input):val(input){ next=nullptr; }
};

class test{
    public:
        // stack help
        bool isrev1(Node* head)
        {
            if (head==nullptr) throw runtime_error("No Link!");
            if (head->next==nullptr) return true;
            stack<int> temp;
            Node* node = head;
            while (node!=nullptr)
            {
                temp.push(node->val);
                node = node->next;
            }
            while(!temp.empty())
            {
                if (temp.top()!=head->val) return false;
                temp.pop();
                head=head->next;
            }
            return true;
        }

        // extra space O(1)
        bool isrev2(Node* head)
        {
            //PrintLink(head);

            if(head==nullptr || head->next==nullptr) return true;
            Node *n1=head, *n2=head;
            while(n2->next!=nullptr && n2->next->next!=nullptr) // find mid node!
            {
                n1=n1->next;  // n1 -> mid
                n2=n2->next->next;  
            } 
            // get n1 ÖÐµã
            Node *n3=n1->next, *n4=nullptr;
            n1->next=nullptr;
            while(n3!=nullptr)   //ni xu
            {
                n4=n3->next;
                n3->next=n1;
                n1=n3;
                n3=n4;
            }          
            // n1 is last node, but n2 buyiding!
            // n3 and n4 is nullptr
            n2 = n1; // use n2 save last node
            n4 = head;
            bool res = true;
            while (n4!=nullptr && n1!=nullptr)
            {
                //cout<<n4->val<<" "<<n1->val<<endl;
                if (n4->val!=n1->val) 
                {
                    //cout<<n4->val<<" "<<n1->val<<endl;
                    res = false;
                    break;
                }
                n4=n4->next; // left to mid
                n1=n1->next;  // right to mid
            }
            // do not forget recovery, so return finally
            n3=n2->next;
            n2->next=nullptr;
            while (n3!=nullptr)  // help think 1<-2<-3<-4  n4<-n3->n1
            {
                n4 = n3->next;
                n3->next=n2;
                n2 = n3;
                n3 = n4;
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
};



int main() {
    test tt;

    Node* node1 = new Node(1);
    node1->next = new Node(2);
    node1->next->next = new Node(2);
    node1->next->next->next = new Node(2);
    node1->next->next->next->next = new Node(1);
    cout<<tt.isrev1(node1)<<endl;

    Node* node2 = new Node(1);
    node2->next = new Node(1);
    node2->next->next = new Node(0);
    node2->next->next->next = new Node(1);
    node2->next->next->next->next = new Node(2);
    //tt.PrintLink(node2);
    cout<<tt.isrev2(node2)<<endl;
}