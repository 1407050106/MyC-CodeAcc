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

class myheap{
    public:
        myheap(int maxs):limit(maxs)
        {
            arr.resize(limit);
            heapsize=0;
        }

        void push(int value)
        {
            if (heapsize==limit) __throw_runtime_error("Full!");
            arr[heapsize]=value;
            heapinsert(arr, heapsize++);
        }

        int pop()
        {
            if (heapsize==0) __throw_runtime_error("Nothing!");
            int ans = arr[0];
            swap(arr, 0, --heapsize);
            heapify(arr, 0);
            return ans;
        }

        void printheap() {
            if (heapsize==0) throw runtime_error("The heap is null!");
            for (int k=0; k<heapsize; k++) cout<<arr[k]<<" ";
            printf("\n");
        }

    // private:
        vector<int> arr;
        int limit;
        int heapsize;
        
        void heapinsert(vector<int>& v, int index)
        {
            // while (v[index]>v[((index-1)>>1)<0?0:((index-1)>>1)])
            // {
            //     swap(v, index, (index-1)>>1);
            //     index = ((index-1)>>1)<0?0:((index-1)>>1);
            // }
            while (v[index]>v[(index-1)/2])
            {
                swap(v, index, (index-1)/2);
                index = (index-1)/2;
            }
        }

        void heapify(vector<int>& v, int index)
        {
            int left = (index<<1)+1;
            while (left<heapsize)
            {
                int largest = left+1<heapsize && arr[left+1]>arr[left]?left+1:left;
                int large = arr[largest]>arr[index]?largest:index;
                if (large==index) break;
                swap(v, index, largest);
                index = largest;
                left = (index<<1)+1;
            }
        }

        void swap(vector<int>& v, int a, int b)
        {
            int temp = v[a];
            v[a]=v[b];
            v[b]=temp;
        }
}; 

int main() {
    myheap mp(6);
    mp.push(1);
    mp.push(2);
    mp.push(3);
    // mp.push(4);
    // mp.push(5);
    // mp.push(6);
    mp.printheap();

    priority_queue<int> compositeheap;
    compositeheap.push(1);
    compositeheap.push(2);
    compositeheap.push(3);
    // compositeheap.push(4);
    // compositeheap.push(5);
    // compositeheap.push(6);
    for (int i=0; i<3; i++)
    {
        cout<< compositeheap.top()<<" ";
        compositeheap.pop();
    }
}  