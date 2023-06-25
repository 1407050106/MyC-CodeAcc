#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class myheap{
    public:
        explicit myheap(int lm):limit(lm) 
        {
            heapsize=0;
            dq.resize(lm);
        }
        ~myheap() noexcept {}

        void push(int a)
        {
            if (heapsize==limit) __throw_runtime_error("满啦！");
            dq[heapsize]=a;
            heapinsert(heapsize++);
        }

        int pop()
        {
            if (heapsize==0) __throw_runtime_error("空的！");
            int res=dq[0];
            swap(dq[0], dq[--heapsize]);
            heapify(0, heapsize);
            return res;
        }

        int top()
        {
            if (heapsize==0) __throw_runtime_error("空的！");
            return dq[0];
        }

        void printheap()
        {
            if (heapsize==0) __throw_runtime_error("空的！");
            for (int i=0; i<heapsize; i++)
            {
                cout<<dq[i]<<" ";
            }
        }

    private:
        void heapinsert(int index)
        {
            while (dq[index]>dq[(index-1)/2]) // 注意这里：会涉及到负数的除法就用/
            {
                swap(dq[index], dq[(index-1)/2]);
                index=(index-1)>>1;
            }
        }

        void heapify(int index, int heapsize)
        {
            int left = 2*index+1;
            while (left<heapsize)
            {
                int largest = left+1<heapsize && dq[left+1]>dq[left]?left+1:left;
                largest = dq[index]>=dq[largest]?index:largest;
                if (largest==index) break;
                swap(dq[index], dq[largest]);
                index=largest;
                left=2*index+1;
            }          
        }

        vector<int> dq;
        int heapsize;
        int limit;
};

int main()
{
    myheap mh(10);
    mh.push(1);
    mh.push(2);
    mh.push(5);
    mh.push(10);

    cout<<mh.top()<<endl;
    mh.printheap();
    printf("\n");
    cout<<mh.pop()<<endl;
    cout<<mh.top()<<endl;
    mh.printheap();
}