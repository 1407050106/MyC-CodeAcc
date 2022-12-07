#include <iostream>
#include <queue>
using namespace std;

class STACK{
    public:
        STACK()
        {
            mainz = new queue<int>;
            help = new queue<int>;
        }

        void push(int aim)
        {
            mainz->push(aim);
        } 

        int pop()
        {
            if (mainz->empty())
            {
                throw runtime_error("No value!");
            } else if (mainz->size()==1)
            {
                int v = mainz->front();
                mainz->pop();
                return v;
            } 
            while(mainz->size()>1)
            {
                help->push(mainz->front());
                mainz->pop();
            }
            int temp = mainz->front();
            mainz->pop();
            while(!help->empty())
            {
                mainz->push(help->front());
                help->pop();
            }
            return temp;
        }

        int top()
        {
            if (mainz->empty())
            {
                throw runtime_error("No value!");
            }
            return mainz->back();
        }

    private:
        queue<int>* mainz;
        queue<int>* help;
};

int main() {
    STACK ss;
    ss.push(1);
    ss.push(2);
    ss.push(3);
    cout<<ss.pop()<<endl;
    cout<<"TOP = "<<ss.top()<<endl;
}