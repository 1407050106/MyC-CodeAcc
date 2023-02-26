#include <iostream>
#include <stdlib.h>
using namespace std;

void Print32(int num)
{
    for (int i=31; i>=0; i--)      //must 1>=0 not i==0
    {
        //cout<<"wyl"<<endl;
        cout<<((num & (1<<i))==0?0:1);    //must==0?    cout<<((num & (1<<i))==0?0:1)
    }
}

int main()
{
    // int num=32;
    // //cout<<"wyl"<<endl;
    // Print32(num);

    //xiang fan shu
    // int a=44;
    // Print32(a);
    // cout<<endl;
    // Print32(~a);
    // cout<<endl;
    // cout<<~a+1<<endl;     
}