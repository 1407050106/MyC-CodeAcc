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

// 题目：
// 给定一个有序数组arr，代表坐落在X轴上的点
// 给定一个正数K，代表绳子的长度
// 返回绳子最多压中几个点？
// 即使绳子边缘处盖住点也算盖住
vector<int> a{1,2,3,4,7,13,16,17};  // eg:长度为4的绳子最多能盖住几个点？
int aim=3;

class solution{
    public:
        // 用滑动窗口+两个指针，不回退，O（N）搞定！
        // 遇到数组就想：只要下标不越界，就有的玩
        int findnum(vector<int> v, int len)
        {
            int L=0, R=0, edge=v.size();
            int res=1;
            while (L<edge)  // 注意！！
            {
                int count=0;
                while (R<edge && v[R]-v[L]<=len)
                {
                    R++;
                    count++;
                }
                res=max(res, count);
                L++;
            }
            return res;
        }
};

int main()
{
    solution st;
    int ans=st.findnum(a, aim);
    cout<<"ans= "<<ans<<endl;
}