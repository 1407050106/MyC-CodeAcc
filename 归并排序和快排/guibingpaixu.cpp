#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <future>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

void MergeSort1(int arr[]);
void process(int arr[], int L, int R);
void merge(int arr[], int L, int mid, int R);

void MergeSort1(int arr[], int len)
{
    // cout<<"sizeof(arr)="<<sizeof(arr)<<endl;
    // cout<<"sizeof(arr[0])="<<sizeof(arr[0])<<endl;
    // int num = sizeof(arr)/sizeof(arr[0]);
    // cout<<"num="<<num<<endl;
    if (len<2) return;
    process(arr, 0, len-1);
}

void process(int arr[], int L, int R)
{
    if (L==R) return;
    int mid = L+((R-L)>>1);
    process(arr, L, mid);
    process(arr, mid+1, R);
    merge(arr, L, mid, R);
}

void merge(int arr[], int L, int mid, int R)
{
    int help[R-L+1]={};         //注意help的左右边界
    int p=L, q=mid+1;
    int i=0;
    while (p<=mid&&q<=R)
    {
        help[i++]=arr[p]<arr[q]?arr[p++]:arr[q++];
    }
    while (p<=mid)
    {
        help[i++]=arr[p++];
    }
    while (q<=R)
    {
        help[i++]=arr[q++];
    }
    for (int k=0; k<R-L+1; k++)
    {
        arr[L+k]=help[k];        //注意arr的左右边界
    }
}

// how to use merge? 
void MergeSort2(int arr[], int len)
{
    if (len<2) return;
    // 步长
    int stepsize=1, N=len;
    while(stepsize<N)    //主要是步长在变化，所以最外层循环以步长为准
    {
        // 当前左组的，第一个位置
        int L=0;         //everytime, from 0 start
        while(L<N)
        {
            int M = L+stepsize-1;
            if (M>=N) break;        //确保每个下标都不越界即可
            int R = min(M+stepsize, N-1);
            merge(arr, L, M, R);    //merge相当于自己写的一个工具,合并算法围绕该函数的参数去写就没那么复杂了
            L=R+1;
        }
        // 防止溢出
        if (stepsize > N/2) break;
        stepsize<<=1;
    }
}

class wyl {
    public:
        static int change(int arr[])
        {
            arr[0]=111;
            return 111;
        }
};
// string r = "change";
// class dy {
//     public:
//         template<class F, class... Args>
// 		auto commit(F&& f, Args&&... args) ->future<decltype(f(args...))>     //define template func to get any type input args and infer their returns
// 		{
// 			using RetType = decltype(f(args...)); 
// 			auto task = make_shared<packaged_task<RetType()>>(
// 				bind(forward<F>(f), forward<Args>(args)...)
// 				); 
//             task
// 			future<RetType> future = task->get_future();
//             {
//                 lock_guard<mutex> lock{ _lock };
//                 _tasks.emplace([task]() { (*task)(); });
//             }
//             cap = true;
//             _task_cv.notify_one();
//             cout<<"****************"<<endl;
// 			return future;
// 		}

//         inline dy()
//         {
//             Task thing; 
//             while(1)
//             {
//                 if (!_tasks.empty())
//                 {
//                     unique_lock<mutex> lock{ _lock };           
//                     _task_cv.wait(lock, [this]{return cap;});
//                     cout<<"cap="<<cap<<endl;
//                     thing = move(_tasks.front()); // strach a task from queue
//                     _tasks.pop();
//                     cout<<"8888888888888"<<endl;
//                     cap=false;
//                 }
//                 thing(); 
//             }  
//         }
//     private:
//         using Task = function<void()>;
//         queue<Task> _tasks;  
//         mutex _lock;             
//         condition_variable _task_cv;
//         bool cap = false;
// };

int main() {
    int test1[] = {4,1,2,3,11,9,0,1,24};
    int len = sizeof(test1)/sizeof(test1[0]);
    int test2[] = {4,1,2,3,11,9,0,1,24};
    // wyl qwe;
    // qwe.change(test);    //更改有效！

    // dy qwr;
    // future<int> res = qwr.commit(qwe.change, test);
    // cout<<res.get()<<endl;
    

    MergeSort1(test1, len);                
    for (int j=0; j<len; j++)
    {
        cout<<test1[j]<<" ";
    }
    printf("\n");
    MergeSort2(test2, len);                
    for (int j=0; j<len; j++)
    {
        cout<<test2[j]<<" ";
    }
}