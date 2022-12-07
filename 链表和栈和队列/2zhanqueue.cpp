#include <iostream>
#include <stack>
using namespace std;

class QUEUE{
    public:
        QUEUE()
        {
            mainz = new stack<int> ();
            pollz = new stack<int> ();
        }

        void push(int aim)
        {
            mainz->push(aim);
            bush();
        }

        int pop()
        {
            if (pollz->empty() && mainz->empty())         //必须两个都满足，才能确定是队列为空!!!
            {
                throw runtime_error("1-No values!");
            }
            bush();
            int temp = pollz->top();
            pollz->pop();
            return temp;
        }

        int top()
        {
            if (pollz->empty() && mainz->empty())
            {
                throw runtime_error("2-No values!");
            }
            bush();
            return pollz->top();
        }
        
    private:
        stack<int>* mainz;
        stack<int>* pollz;
        void bush()
        {
            if (pollz->empty())
            {
                while (!mainz->empty())
                {
                    pollz->push(mainz->top());
                    mainz->pop();                   
                }
            } else {
                cout<<"fail."<<endl;
            }
        }
};

int main() {
    QUEUE qs;
    qs.push(1);
    qs.push(2);
    qs.push(3);
    cout<<qs.pop()<<endl;
    qs.push(4);
    qs.push(5);
    cout<<qs.pop()<<endl;
    cout<<"TOP = "<<qs.top();
}