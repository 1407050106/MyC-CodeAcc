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

int arry[4]={1,4,2,2};

int* changesomeone(int arr[])
{
    arr[2]=3;
    return arr;
}

int main() {
    int* b = changesomeone(arry);
    cout<<"b = "<<*(b+1)<<endl;
    int len = sizeof(arry)/sizeof(arry[0]);
    cout<<"len = "<<len<<endl;
    for (int k=0; k<len; k++)
    {
        cout<<arry[k]<<" ";
    }
}