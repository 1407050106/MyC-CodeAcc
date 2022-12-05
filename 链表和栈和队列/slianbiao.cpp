#include <iostream>
using namespace std;
//本文使用双向链表实现队列和栈
template<class T>
struct QueueNode{             //双端对列本质上还是利用了双向链表的结构体
    T val;
    QueueNode<T>* last;
    QueueNode<T>* next;

    QueueNode(T data)
    {
        val=data;
    }

    QueueNode()
    {}
};

//双端队列的实现
template<class T>
class WQueue{
    public:
        QueueNode<T>* AddFromFront(T val)
        {
            QueueNode<T>* cur = new QueueNode<T> (val);    //这种方式，直接创建对象很方便
            if (head==nullptr)
            {
                head=cur;
                tail=cur;
            } else {
                cur->next=head;     //这里head只代表了当前所指向的对象
                head->last=cur;
                head=cur;           //head和tail 要有完全当指针用的思想
            }
            return head;
        };

        QueueNode<T>* AddFromBack(T val)
        {
            QueueNode<T>* cur = new QueueNode<T> (val);    //这种方式，直接创建对象很方便
            if (head==nullptr)
            {
                head=cur;
                tail=cur;
            } else {
                cur->next=tail;     //这里head只代表了当前所指向的对象
                tail->last=cur;
                tail=cur;           //head和tail 要有完全当指针用的思想
            }
            return tail;
        };

        QueueNode<T>* PopFromFront()
        {
            if (head==nullptr)
            {
                return nullptr;
            }
            QueueNode<T>* cur = head;    //就是玩指针, 主要是利用指针操作指向的内存区域很方便
            if (head==tail)
            {
                head=nullptr;
                tail=nullptr;
                return nullptr;
            } else {
                head=head->next;
                cur->next=nullptr;
                head->last=nullptr;
                return head;
            }
        }

        QueueNode<T>* PopFromBack()
        {
            if (tail==nullptr)
            {
                return nullptr;
            }
            QueueNode<T>* cur = tail;    //就是玩指针
            if (head==tail)
            {
                head=nullptr;
                tail=nullptr;
                return nullptr;
            } else {
                tail=tail->next;
                cur->next=nullptr;
                tail->last=nullptr;
                return tail;
            }
        }

        bool isEmpty()
        {
            return head==nullptr;
        }

    private:
        QueueNode<T> *head;      //这俩指针，死死守住队列的首部和尾部
        QueueNode<T> *tail;
};

//可以继续用双端对列的模板类方法，去实现栈和队列, 可参考class03-code03

int main(){
    // QueueNode<int> qq=QueueNode<int> (10);
    // cout<<qq.val;
    // QueueNode<char> pp=QueueNode<char> ('a');
    // cout<<pp.val;

    WQueue<int> wyl;              //wyl就是一个int型的双端对列
    QueueNode<int> *test, *res;
    wyl.AddFromFront(1);
    wyl.AddFromFront(3);
    wyl.AddFromBack(4);
    wyl.AddFromBack(8);
    test=wyl.PopFromFront();      //就是针对wyl这个对象做的操作
    cout<<test->val;
    res=wyl.PopFromBack();
    cout<<res->val;
    cout<<wyl.isEmpty();
}