#include <iostream>
#include <stdlib.h>
using namespace std;

typedef pair<int, int> wyl;

void swap(int arr[], int L, int R);
int partition(int arr[], int L, int R);
wyl netherlandsFlag(int arr[], int L, int R);
void quicksort1(int arr[]);
void process1(int arr[], int L, int R);
void quicksort2(int arr[]);
void process2(int arr[], int L, int R);
void quicksort3(int arr[]);
void process3(int arr[], int L, int R);

void swap(int arr[], int L, int R)
{
    // arr[L]=arr[L]^arr[R];
    // arr[R]=arr[L]^arr[R];
    // arr[L]=arr[L]^arr[R];
    int temp = arr[R];
    arr[R]=arr[L];
    arr[L]=temp;
}

// NetherlanFlag 1.0
// arr[L..R]上，以arr[R]位置的数做划分值
// <= X > X
int partition(int arr[], int L, int R)
{
    if (L>R) return -1;
    if (L==R) return L;
    int less = L-1;
    int index = L;
    while (index<R)
    {
        if (arr[index]<=arr[R])
        {
            less++;
            //swap(arr, index, less);
            int temp = 0;
            temp=arr[less];
            arr[less]=arr[index];
            arr[index]=temp;
            index++;
        }
    }
    index++;
    swap(arr, index, R);    // pay attention!
    return index;
}

// NetherlanFlag 2.0
// arr[L...R] 玩荷兰国旗问题的划分，以arr[R]做划分值
// <arr[R] ==arr[R] >arr[R]
wyl netherlandsFlag(int arr[], int L, int R)
{
    if (L>R) 
    {
        pair<int, int> ans(-1, -1);
        return ans;
    }
    if (L==R)
    {
        pair<int, int> ans(L, R);
        return ans;
    }
    int less = L - 1; // < 区 右边界
	int more = R; // > 区 左边界
	int index = L;
    while(index<more)  // 当前位置，不能和 >区的左边界撞上
    {
        if (arr[index]==arr[R])
        {
            index++;
        } else if (arr[index]<arr[R]) {
            swap(arr, index++, ++less);  //no need to see the left, so skip
        } else {
            // 这里的index不用++！！！
            swap(arr, index, --more);
        }
    }
    // 注意交换的下标始用！
    swap(arr, more, R);
    // int res[]={less+1, more};
    // cout<<"space is = "<<res[0]<<res[1]<<endl;
    // int* b;
    // b=res; 
    //for (int i=0; i<2; i++)          //All right!
    //{
    //	cout<<*(b+i)<<endl;
    //}
    // 返回相等的那个区间边界，荷兰国旗会告诉你等于区域是哪个范围
    pair<int, int> ans(less+1, more);
    return ans;
}

// quicksort 1.0
void quicksort1(int arr[])
{
    int num = sizeof(arr)/sizeof(arr[0]);
    if ( arr==nullptr || num<2 ) return;
    process1(arr, 0, num-1);
}
void process1(int arr[], int L, int R)
{
    if (L>=R) return;
    int M = partition(arr, L, R);
    // 这里要注意，这一步M的前后位置就已经在数组里固定好了
    // 而且，随着递归，数组也变得有序了
    process1(arr, L, M-1);
    process1(arr, M+1, R);
}

// quicksort 2.0
void quicksort2(int arr[])
{
    int num = sizeof(arr)/sizeof(arr[0]);
    if ( arr==nullptr || num<2 ) return;
    process2(arr, 0, num-1);  
}
void process2(int arr[], int L, int R)
{
    if (L>=R) return;
    pair<int, int> wer = netherlandsFlag(arr, L, R);
    cout<<wer.first<<wer.second<<endl;
    process2(arr, L, wer.first-1);
    process2(arr, wer.second+1, R);
}

// quicksort 3.0
void quicksort3(int arr[])
{
    int num = sizeof(arr)/sizeof(arr[0]);
    if ( arr==nullptr || num<2 ) return;
    process3(arr, 0, num-1);  
}
void process3(int arr[], int L, int R)
{
    if (L>=R) return;
    swap(arr, R, L+rand()%(R-L+1));
    pair<int, int> wer = netherlandsFlag(arr, L, R);
    process3(arr, L, wer.first-1);
    process3(arr, wer.second+1, R);
}

// for test
void GenerateRandomArray(int arr[])
{
    // use vector in after days!
}

int main() {
    // for verify netherlandflag 2.0
    // int arr[]={4,1,2,3};
    // pair <int, int> res;
    // res=netherlandsFlag(arr, 1, 3);
    // cout<<res.first<<res.second<<endl;
    int test[10]={0};
    for (int i=0; i<10; i++)
    {
        test[i]=rand()%10+1;
    }
    for (int i=0; i<10; i++)
    {
        cout<<test[i]<<" ";
    }
    printf("\n");

    int nums = sizeof(test)/sizeof(test[0]);
    quicksort2(test);
    for (int i=0; i<10; i++)
    {
        cout<<test[i]<<" ";
    }
}
