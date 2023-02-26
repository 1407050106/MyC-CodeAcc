#include <iostream>
using namespace std;

template<typename T>
T checkalpha(T a)
{
    cout<<a<<endl;
    return a;
}

template<class T>
class Array {
    public:
        T CreateArray(T const& b) const;

        T CreateShuzu(int num, T member) const;

    private:
        T b;
};

template<class T>
T Array<T>::CreateArray(T const& b) const 
{
    cout<<b<<endl;
    return b;
}

template<class T>
T Array<T>::CreateShuzu(int num, T member) const
{
    
}

struct Node {
    int val;
    Node* next;
    Node* before;
};

class Shuzu {
    public:
        Node* CreateDoubleLian(int num)
        {
            Node* head = new Node;
            // 用一个指针指向head，然后以后利用它连接链表
            Node* pre = head;
            for (int i=0; i<num; i++)
            {
                Node* node = new Node;
                node->val = i+1;
                pre->next = node;
                node->before = pre;      //fanxiangzhizhen
                pre = node;
                node->next=NULL;
            }
            return head;
        }

        bool PrintDoubleLian(Node* T)
        {
            if (!T)
            {
                return false;
            }
            while(T->next)
            {
                cout<<T->val;
                T=T->next;
            }
            return true;
        }

        bool RPrintDoubleLian(Node* T)
        {
            if (!T)
            {
                return false;
            }
            while(T->next)
            {
                T=T->next;
            }
            while(T->before)
            {
                cout<<T->val<<endl;
                T=T->before;
            }
            return true;
        }

        
    private:

};

int a;
string c;
char d;

int main() {
    //scanf("%d", &a);
    //cout<<a<<endl;

    // // for mobanlei
    // Array<string> array2;
    // while (1)
    // {
    //     //scanf("%c", &d);   //not used to string
    //     cin>>c;

    //     array2.CreateArray(c);
    // }

    //for mobanhanshu
    // while(1)
    // {
    //     cin>>d;
    //     checkalpha(d);
    // }

    Shuzu shuzu;
    Node* front = shuzu.CreateDoubleLian(10);
    shuzu.RPrintDoubleLian(front);

    return 0;
}



