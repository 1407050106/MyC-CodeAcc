#include <iostream>
using namespace std;

//本文使用数组实现队列和栈, 可参考class03-code04
class Queue{
    public:
        Queue(int limit)
        {
            arr=new int[limit];
            this->limit=limit;
            begin=0;
            end=0;
            size=0;
        }

        void ask(int aim)
        {
            cout<<arr[aim]<<endl;
        }

        void push(int num)
        {
            if(size==limit)
            {
                cout<<"Enough!"<<endl;
            }
            size++;
            arr[begin]=num;
            begin=NextIndex(begin);
        }

        int pop()
        {
            if(size==0)
            {
                cout<<"Nothing!"<<endl;
            }
            size--;
            int ans = arr[end];
            end=NextIndex(end);
            return ans;
        }

        bool isEmpty()
        {
            return size==0;
        }

        int NextIndex(int index)
        {
            return index<limit-1?index+1:0;
        }

    private:   
        int* arr;     
        int begin;
        int end;
        int size;
        int limit;
};

int main() {
    // int *arr = new int[4];
    // delete [] arr;
    Queue wyl(3);
    wyl.push(1);
    wyl.push(10);
    wyl.push(100);
    wyl.pop();
    wyl.push(1000);
    wyl.ask(0);
    wyl.ask(1);
    wyl.ask(2);
}