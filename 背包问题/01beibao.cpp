#include <iostream>
#include <vector>
using namespace std;

int voltage[5]={0,2,3,4,5};
int value[5]={0,3,4,5,6};
int bag[9]={0,1,2,3,4,5,6,7,8};     //max=8

//need wupin geshu and bag rongliang
vector<vector<int>> findmaxmoney(int num, int vol)
{
    vector<vector<int>> dp(num, vector<int>(vol));
    for (int i=0; i<num; i++)
    {
        dp[i][0]=0;
    }
    for (int i=0; i<vol; i++)
    {
        dp[0][i]=0;
    }

    for (int i=1; i<num; i++)
    {
        for (int j=1; j<vol; j++)    //j=bag
        {
            if (j<voltage[i])      
            {
                dp[i][j]=dp[i-1][j];
            } else {
                dp[i][j]=max(dp[i-1][j], value[i]+dp[i-1][j-voltage[i]]);   //important!  zhaodao qian n-1 de best
            }
        }
    }

    // for (int i=0; i<num; i++)
    // {
    //     for (int j=0; j<vol; j++)
    //     {
    //         cout<<dp[i][j];
    //     }
    //     printf("\n");
    // }

    cout<<"The best value for  composition of "<<num-1<<"things is"<<dp[num-1][vol-1]<<endl;

    return dp;

}

void findwhichselect(vector<vector<int>> dp, int num, int vol, vector<int>& v)
{
    if (vol==0 || num ==0)       //ruguo tiji biancheng 0, zhongzhi digui
    {
        return;
    }
    
   if (dp[num][vol]!=dp[num-1][vol])
   {
        v.push_back(num);
        vol=vol-voltage[num];
        num=num-1;
        findwhichselect(dp, num, vol, v);
   } else {
        num=num-1;
        findwhichselect(dp, num, vol, v);
   }
}

int main() {
    int num = sizeof(voltage)/sizeof(voltage[0]);   //shuzu changdu
    int vol = sizeof(bag)/sizeof(bag[0]);

    vector<vector<int>> dp = findmaxmoney(num, vol);
    vector<int> v;
    findwhichselect(dp, num-1, vol-1, v);
    for(int k=0; k<v.size(); k++)
    {
        cout<<v[k];
    }
}