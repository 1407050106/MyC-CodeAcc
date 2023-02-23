#include <iostream>
#include <vector>
using namespace std;

class robot{
    public:
        // 一共有N个数的范围，初始位置start，目的地aim，只能走N步
        int ways1(int N, int start, int aim, int K)
        {
            return process1(start, K, aim, N);
        }

        // 机器人当前来到的位置是cur，
        // 机器人还有rest步需要去走，
        // 最终的目标是aim，
        // 有哪些位置？1~N
        // 返回：机器人从cur出发，走过rest步之后，最终停在aim的方法数，是多少？
        int process1(int cur, int rest, int aim, int N)
        {
            if (rest==0)
            {
                return cur==aim?1:0;
            }
            // rest>0, 还有步数要走(注意分类)
            if (cur==1)
            {
                return process1(2, rest-1, aim, N);
            }
            if (cur==N)
            {
                return process1(N-1, rest-1, aim, N);
            }
            // 来到中间位置，既可以往左也可以往右，两种方法都可以，所以返回的方法数要加起来
            return process1(cur-1, rest-1, aim, N) + process1(cur+1, rest-1, aim, N);
        }

        /**********************************/
        // 改成动态规划
        int ways2(int N, int start, int aim, int K)
        {
            vector<vector<int>> dp(N+1, vector<int>(K+1));

            for (int i=0; i<=N; i++)
            {
                for (int j=0; j<=K; j++)
                {
                    dp[i][j]=-1;
                }
            }
            // dp就是缓存表, 填表方法严格按照递归的决策去写就行，不用自己想
            // dp[cur][rest] == -1 -> process1(cur, rest)之前没算过！
            // dp[cur][rest] != -1 -> process1(cur, rest)之前算过！返回值，dp[cur][rest]
            return process2(start, K, aim, N, dp);
        }
        // cur 范: 1 ~ N
	    // rest 范：0 ~ K
        int process2(int cur, int rest, int aim, int N, vector<vector<int>>& dp)
        {
            if (dp[cur][rest] != -1)
            {
                return dp[cur][rest];
            }
            // 之前没算过！
            int ans=0;
            // 这里注意dp表的填法，利用之前的递归尝试规则填表，不直接返回了
            // 这样所有的子过程分享同一张表，以后遇到直接拿值
            if (rest==0)
            {
                ans = cur==aim?1:0;
            } else if (cur==1)
            {
                ans = process2(2, rest-1, aim, N, dp);
            } else if (cur==N)
            {
                ans = process2(N-1, rest-1, aim, N, dp);
            } else {
                ans = process2(cur-1, rest-1, aim, N, dp) + process2(cur+1, rest-1, aim, N, dp);
            }
            
        }

        /************************/
        // 进一步优化!
        // public static int ways3(int N, int start, int aim, int K) {
        //     if (N < 2 || start < 1 || start > N || aim < 1 || aim > N || K < 1) {
        //         return -1;
        //     }
        //     // 当前来到的值是行，剩余步数是列, 每一个格子里的数代表的是来到这的方案种数!
        //     int[][] dp = new int[N + 1][K + 1];
        //     dp[aim][0] = 1;
        //     for (int rest = 1; rest <= K; rest++) {  // 每一列按行填满每一列按行填满...
        //         dp[1][rest] = dp[2][rest - 1];
        //         for (int cur = 2; cur < N; cur++) {
        //             dp[cur][rest] = dp[cur - 1][rest - 1] + dp[cur + 1][rest - 1];
        //         }
        //         dp[N][rest] = dp[N - 1][rest - 1];
        //     }
        //     return dp[start][K];   // good!
        // }
};

int main() {
    robot bt;
    cout<<bt.ways1(4,2,4,4)<<endl;
    cout<<bt.ways2(4,2,4,4)<<endl;
}