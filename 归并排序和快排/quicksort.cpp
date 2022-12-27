#include <iostream>
using namespace std;

void quicksort(int arr[], int L, int R)
{
    if (arr == nullptr) return;
    if (L>=R) return;            //>= is important!
    int l = L, r = R;
    int ext = arr[l];
    while(l<r)
    {
        while (l<r && arr[r]>=ext)
        {
            r--;
        }
        if (l<r) 
        {
            arr[l]=arr[r]; 
        }
        while (l<r && arr[l]<=ext)
        {
            l++;
        }
        if (l<r)
        {
            arr[r]=arr[l];
        }
        if (l==r)
        {
            arr[l]=ext;
        }
    }
    quicksort(arr, L, l-1);
    quicksort(arr, l+1, R);
}

int main() {
    int arr[]={3,4,5,2,6,1,6};
    int num = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, num-1);
    for (int i=0; i<num; i++)
    {
        cout << arr[i];
    }
}