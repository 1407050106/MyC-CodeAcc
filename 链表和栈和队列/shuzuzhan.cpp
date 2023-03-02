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

class zhan{
    public:
        zhan(int climit)
        {
            arr = new int(climit);
            size=0;
            limit = climit;
            index=0;
        }

        void push(int a)
        {
            if (size==limit) 
            {
                cout<<"Full!"<<endl;
                return;
            }
            size++;
            //cout<<"size="<<size<<endl;
            arr[index++]=a;
        }

        int pop()
        {
            if (size==0)
            {
                __throw_runtime_error("No value!");
            }  
            int b = arr[--index];
            size--;
            return b;
        }

        int top()
        {
            if (size==0)
            {
                __throw_runtime_error("No value!");
            }
            int s = index-1;
            return arr[s];
        }

        bool isEmpty()
        {
            return size==0;
        }

        ~zhan()
        {
            delete[] arr;
        }
    private:
        int* arr;
        int size;
        int limit;
        int index;
};

int main() {
    zhan zn(3);
    cout<<zn.isEmpty()<<endl;
    zn.push(1);
    zn.push(2);
    zn.push(3);
    cout<<zn.pop()<<endl;
    cout<<zn.pop()<<endl;
    cout<<zn.top()<<endl;
    cout<<zn.pop()<<endl;
    cout<<zn.pop()<<endl;
}