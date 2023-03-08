#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

class Line{
    public:
        Line(int L, int R)  
        {
            start = L;
            end = R;
        }
        int start, end;
};

class minheap{
    public:
        minheap()
        {
            //mq = new priority_queue<int, vector<int>, greater<int>> ();
        }

        int method1 (vector<vector<int>> v)
        {
            int mins=0, maxs=0;
            int num=v.size();
            for (int i=0; i<num; i++)
            {
                mins = min(v[i][0], mins);
                maxs = max(maxs, v[i][1]);
            }
            int cover=0;
            for (double k=mins+0.5; k<maxs; k+=1)
            {
                int cur=0;
                for (int i=0; i<num; i++)
                {
                    if (v[i][0]<k && v[i][1]>k) cur++;
                }
                cover = max(cur, cover);
            }
            return cover;
        }

        int method2(vector<vector<int>> v)
        {
            int num=v.size();
            vector<Line> lines;
            for (int i=0; i<num; i++)
            {
                Line line(v[i][0], v[i][1]);
                lines.push_back(line);
            }
            sort(lines.begin(), lines.end(), comparestart);
            // 准备一个小根堆用于存放每条线段的右边界
            priority_queue<int, vector<int>, greater<int>> mq;
            int cover=0;
            for (int k=0; k<num; k++)
            {
                while(!mq.empty()&&mq.top()<=lines[k].start)
                {
                    mq.pop();
                }
                mq.push(lines[k].end);
                cover=max(cover, (int)mq.size());
            }
            return cover;
        }

        static bool comparestart(Line line1, Line line2)
        {
            return line1.start<line2.start;
        }

        vector<vector<int>> generator(int N, int L, int R)
        {
            int size = rand()%N+1;
            vector<vector<int>> ans(size, vector<int>(2));
            for (int i=0; i<size; i++)
            {
                vector<int> res;
                int mins = L+rand()%(R-L+1);
                int maxs = L+rand()%(R-L+1);
                if (mins==maxs) maxs+=1;
                res.push_back(min(mins, maxs));
                res.push_back(max(maxs, mins));
                ans.push_back(res);
            }
            return ans;
        }
};

int main() {
    minheap hh;
    cout<<"Testing begin!"<<endl;
    int N=10, L=1, R=20;
    int testtimes = 100000;
    for (int i=0; i<testtimes; i++)
    {
        vector<vector<int>> bj = hh.generator(N, L ,R);
        int num = bj.size();
        for (int i = 0; i < num; i++)
        {
            for (int j=0; j<2; j++)
            {
                cout<<bj[i][j]<<"";
            }
            printf("\n");
        }
        // vector<vector<int>> bj2;
        // bj2.push_back({1,3});
        // bj2.push_back({2,4});
        int ans1 = hh.method1(bj);
        int ans2 = hh.method2(bj);
        if (ans1!=ans2)
        {
            cout<<"Something wrong!"<<"ans1="<<ans1<<"ans2="<<ans2<<endl;
            return -1;
        }
    }
    cout<<"Testing end!"<<endl;
    return 0;
}