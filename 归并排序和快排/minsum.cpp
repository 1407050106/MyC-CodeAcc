#include <iostream>
using namespace std;

int getsum(int *,int);
int process(int *,int, int);
int merge(int *,int, int, int);

int getsum(int arr[], int len)
{
    if (arr==nullptr || len<2){
        return 0;
    }
    return process(arr, 0, len-1);
}

int process(int arr[], int L, int R)
{
    if (L==R) return 0;
    int M = L+((R-L)>>1);    //位移运算要加括号！
    return process(arr,L,M) + process(arr,M+1,R) + merge(arr,L,M,R);
}

int merge(int arr[], int L, int M, int R)
{
    int help[R-L+1]={0};
    //int *help = new int[R-L+1];
    int p1=L, p2=M+1, i=0;
    int res=0;
    while (p1<=M&&p2<=R)
    {
        res+=arr[p1]<arr[p2]?arr[p1]*(R-p2+1):0;
        help[i++]=arr[p1]<arr[p2]?arr[p1++]:arr[p2++];
    }
    while (p1<=M) help[i++]=arr[p1++];
    while (p2<=R) help[i++]=arr[p2++];
    for (int k=0; k<R-L+1; k++)
    {
        arr[L+k]=help[k];
    }
    return res;
}

int main() {
    int arr[]={2,1,5,4,3,2,1,1,26,33,54,45};
    //int arr[]={5,6,1,2};
    int num = sizeof(arr)/sizeof(arr[0]);
    int res=getsum(arr, num);
    cout<<res<<endl;
    return 0;
}