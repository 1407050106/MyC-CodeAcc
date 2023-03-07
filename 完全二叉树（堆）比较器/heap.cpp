#include <iostream>
#include <queue>
using namespace std;

// this class is a big-root heap
class Heaps{
    public:
        Heaps(int nums):limit(nums)  // Pay attention!
        {
            arr = new int[limit];
            heapsize=0;
        }

        void push(int para)
        {
            if (heapsize==limit) throw runtime_error("The Heap is full!");
            arr[heapsize]=para;
            HeapInsert(arr, heapsize++);
        }

        int pop()
        {
            if (heapsize==0) throw runtime_error("The heap is null!");
            int ans = arr[0];
            swap(arr, 0, heapsize-1);
            Heapify(arr, 0, --heapsize);
            return ans;
        }

        void printheap() {
            if (heapsize==0) throw runtime_error("The heap is null!");
            for (int k=0; k<heapsize; k++) cout<<arr[k];
        }
    private:
        int limit;
        int *arr;
        int heapsize;

        // 这代表加数调整堆结构的过程1
        // 往堆中加数并调整堆结构
        // 新加进来的数，现在停在了index位置，请依次往上移动，
		// 移动到0位置，或者干不掉自己的父亲了，停！
        void HeapInsert(int arr[], int index)
        {
            while (arr[index]>arr[(index-1)/2]) 
            {
                swap(arr, index, (index-1)/2);
                index=(index-1)>>1;
            }
        }

        // 这代表删数后调整堆结构的过程2
        // 从index位置，往下看，不断地下沉
		// 停：较大的孩子都不再比index位置的数大；或者已经没孩子了
        void Heapify(int arr[], int index, int heapSize)
        {
            int left = (index<<1)+1;
            // 如果有左孩子，有没有右孩子，可能有可能没有！可如果没有左孩子，则右孩子也一定没有
            while (left<heapSize)
            {
                // 把较大孩子的下标，给largest
                int largest = left+1<heapSize && arr[left+1]>arr[left] ? left+1 : left;
                // 看子节点和父节点，哪个位置的数大
                largest = arr[largest] > arr[index] ? largest : index;
                if (largest == index) break;
                // index和较大孩子，要互换
                swap(arr, index, largest);
                // 代表父节点的index位置要继续下移
                index = largest;
                left = (index<<1)+1;
            }
        }

        void swap(int arr[], int p, int q)
        {
            // arr[p]=arr[p]^arr[q];
            // arr[q]=arr[p]^arr[q];
            // arr[p]=arr[p]^arr[q];
            int temp = arr[p];
            arr[p]=arr[q];
            arr[q]=temp;
        }       
};

// 模板泛型比较器
template <typename T>
class cmp
{
public:
    //重载 () 运算符
    bool operator()(T a, T b)
    {
        return a > b;   // zheli is jiangxu 
    }
};

int main() {
    // C++优先队列priority_queue默认为大顶堆
    // priority_queue<int> v;
    // v.push(5);
    // v.push(2);
    // v.push(1);
    // while (!v.empty()) 
    // {
    //     cout<<v.top()<<endl;;
    //     v.pop();
    // }

    // C++优先级队列修改成小根堆，自定义排序
    // priority_queue<int, vector<int>, greater<int>> w;
    // priority_queue<int, vector<int>, cmp<int>> w;
    // w.push(5);
    // w.push(2);
    // w.push(1);
    // while (!w.empty()) 
    // {
    //     cout<<w.top()<<endl;;
    //     w.pop();
    // }

    Heaps heaps(10);
    heaps.push(1);
    heaps.push(2);
    heaps.push(3);
    // heaps.push(4);
    // heaps.push(5);
    // heaps.push(6);
    heaps.printheap();
    printf("\n");
    heaps.pop();
    heaps.printheap();
}