#include <iostream>
using namespace std;

int getpair(int arr[], int len);
int process(int arr[], int L, int R);
int merge(int arr[], int L, int M, int R);

int getpair(int arr[], int len)
{
    if (arr==nullptr || len < 2)
    {
        return 0;
    }
    process(arr, 0, len-1);
}

int process(int arr[], int L, int R)
{
    if (L==R) return 0;
    int M = L+((R-L)>>1);
    return process(arr,L,M)+process(arr,M+1,R)+merge(arr, L, M ,R);
}

int merge(int arr[], int L, int M, int R)
{
    // [L....M] [M+1....R]
    int ans = 0;
    // 目前囊括进来的数，是从[M+1, windowR)
    int windowR = M + 1;
    for (int j = L; j <= M; j++) {
        //每一轮i，都看windowR能往右滑多少？windowR使用了不回退的技巧。
        while (windowR <= R && (long) arr[j] > (long) arr[windowR] * 2) {
            windowR++;
        }
        ans += windowR - M - 1;
    }

    int *help = new int[R-L+1];
    int p1=0, p2=M+1, i=0;
    while (p1<=M&&p2<=R)
    {
        help[i++]=arr[p1]<arr[p2]?arr[p1++]:arr[p2++];
    }
    while (p1<=M) help[i++]=arr[p1++];
    while (p2<=R) help[i++]=arr[p2++];
    for (int k=0; k<R-L+1; k++)
    {
        arr[L+k]=help[k];
    }
    return ans;
}

int main() {
    int arr[] = {3,1,0,4,3,1};
    int len = sizeof(arr)/sizeof(arr[0]);

    int res=getpair(arr, len);
    cout<<res<<endl;
}