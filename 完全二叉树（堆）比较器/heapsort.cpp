#include <iostream>
#include <queue>
using namespace std;

void HeapSort(int arr[], int nums);
void heapInsert(int arr[], int index);
void heapify(int arr[], int index, int heapsize);
void swap (int arr[], int L, int R);

void HeapSort(int arr[], int nums)
{
    if(arr==nullptr||nums<2) return;
    //O(N*logN)
    // for (int k=0; k<nums; k++)
    // {
    //     heapInsert(arr, k);
    // }
    // O(N)
    for (int i = nums - 1; i >= 0; i--) 
    {
		heapify(arr, i, nums);
	}
    for (int j=0; j<nums; j++)
    {
        cout<<arr[j]<<" ";
    }
    printf("\n");
    swap(arr, 0, --nums);
    while (nums>0)
    {
        cout<<"nums="<<nums<<endl;
        heapify(arr, 0, nums);
        for (int j=0; j<8; j++)
        {
            cout<<arr[j]<<" ";
        }
        printf("\n");   
        swap(arr, 0, --nums);
    }    
}

void heapInsert(int arr[], int index)
{
    while (arr[(index-1)/2]<arr[index])
    {
        swap(arr, (index-1)/2, index);
        index = (index-1)/2;
    }
}

void heapify(int arr[], int index, int heapsize)
{
    int left = (index*2)+1;
    while (left < heapsize)
    {
        //int large = left+1<heapsize && arr[left]>arr[left+1] ? left:left+1;  // pay attention! this is not right!
        int large = left+1<heapsize && arr[left+1]>arr[left] ? left+1:left;
        if (arr[index]>=arr[large]) break;
        swap(arr, index, large);
        index = large;
        left = (index*2)+1;
    }
}

void swap (int arr[], int L, int R)
{
    // arr[L]=arr[L]^arr[R];
    // arr[R]=arr[L]^arr[R];
    // arr[L]=arr[L]^arr[R];
    int temp = arr[R];
    arr[R]=arr[L];
    arr[L]=temp;
}


int main() {
    int arr[]={1,3,4,2,3,1,24,66};
    int num = sizeof(arr)/sizeof(arr[0]);

    HeapSort(arr, num);
    printf("\n");
    for (int i=0; i<num; i++)
    {
        cout<<arr[i]<<" ";
    }    
}