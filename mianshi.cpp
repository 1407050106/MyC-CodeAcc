#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a;

void jishu(int temp, int v1, int v2, int& count){
    if (temp-v1-v2 < 0)
    {
        return;
    }
    if (temp-v1-v2 == 0)
    {
        count++;
        return;
    }

    if (temp/v1>0 && temp%v1==0){
        count++;
    }
    if (temp/v2>0 && temp%v2==0){
        count++;
    }

    int temp1 = temp-v1-v2;
    int temp2 = temp-v1;
    int temp3 = temp-v2;
    jishu(temp1, v1, v2, count);
    jishu(temp2, v1, v2, count);
    jishu(temp3, v1, v2, count);
}

int main(){
    
    // test reverse string but word not
    // getline(cin, a);

    // int num = a.length();
    
    // int pos=a.find(" ");

    // for (int i=pos+1; i<num; i++)
    // {
    //     cout<<a[i];
    // }

    // cout<<" ";

    // for (int j = 0; j<pos; j++)
    // {
    //     cout<<a[j];
    // }


    
}