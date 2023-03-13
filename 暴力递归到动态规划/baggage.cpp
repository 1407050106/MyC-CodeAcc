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

class beibao{
    public:
        int getMaxValue(vector<int> w, vector<int> v, int bag)
        {
            if (w.size()==0 && w.size()!=v.size()) return 0;
            return process(w, v ,0, bag);
        }
        // 设计这个函数就是：w从index开始，在背包容量还剩rest的时候，能返回的最大价值
        int process(vector<int> w, vector<int> v, int index, int rest)
        {
            if (rest<0) return -1;
            if (index==w.size()) return 0;
            // possibility
            int p1 = process(w, v, index+1, rest);
            int p2=0;
            int next = process(w, v, index+1, rest-w[index]);
            if (next!=-1)  // 返回-1说明上游的货是无效的！会导致bag容量变成负数
            {
                p2=next+v[index];
            }
            return max(p1,p2);
        }

        // 这个动态规划是根据上一个尝试过的递归函数去改写的
        int dp(vector<int> w, vector<int> v, int bag)
        {
            if (w.size()==0 && w.size()!=v.size()) return 0;
            int N = w.size();
            vector<vector<int>> dp(N+1, vector<int>(bag+1));
            for (int index=N-1; index>=0; index--) // 跟递归时的顺序must相反!!!
            {
                for (int rest=0; rest<=bag; rest++)
                {
                    int p1=dp[index+1][rest];
                    int p2=0;
                    int next = rest-w[index]<0?-1:dp[index+1][rest-w[index]];
                    if(next!=-1)
                    {
                        p2=v[index]+next;
                    }
                    dp[index][rest]=max(p1, p2);
                }
            }
            return dp[0][bag];  // 返回的右上角
        }    
};

int main() {
    vector<int> w{2,3,4,5};
    vector<int> v{3,4,5,6};
    int bag = 8;

    beibao bb;
    cout<<bb.getMaxValue(w, v, bag)<<endl;

    cout<<bb.dp(w, v, bag)<<endl;
}