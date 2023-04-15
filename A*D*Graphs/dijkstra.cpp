#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <unistd.h>
#include <cstring>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
// 模板方法+智能指针建图
template<typename T> struct Node;
template<typename T> struct edge;
template<typename T> struct graph;

template<typename T>
struct Node{
    T val;
    int in;
    int out;
    vector<shared_ptr<Node<T>>> nexts;
    vector<shared_ptr<edge<T>>> toedges;

    Node(T v):val(v),in(0),out(0) {}   // 注意构造函�????
};

template<typename T>
struct edge{
    T val;
    shared_ptr<Node<T>> fromnode;
    shared_ptr<Node<T>> tonode;
    // 注意构造函�????
    edge(T v, shared_ptr<Node<T>> from, shared_ptr<Node<T>> to):val(v),fromnode(from),tonode(to) {}
};

template<typename T>
struct graph{
    unordered_map<T, shared_ptr<Node<T>>> nodes;
    unordered_set<shared_ptr<edge<T>>> edges;
};


// 智能指针的比较器还需要仔细思考怎么使用?
// bool compare1(const shared_ptr<edge<int>>& p, const shared_ptr<edge<int>>& q)
// {
//     return p->val<q->val;
// }


template<class T>
class graphs{
    public:
        int size;
        explicit graphs():size(0) {}
        shared_ptr<graph<T>> graphgenerator(vector<vector<T>> ev)
        {
            auto wgraph = make_shared<graph<T>>();  // 注意这里要（）初始化变量
            for (vector<T> eg : ev)
            {
                T value = eg[0];
                if (wgraph->nodes.count(eg[1])==0)
                {
                    wgraph->nodes.insert({eg[1], make_shared<Node<T>>(eg[1])}); 
                }
                if (wgraph->nodes.count(eg[2])==0)
                {
                    wgraph->nodes[eg[2]] = make_shared<Node<T>>(eg[2]);
                }

                auto fromnode = wgraph->nodes[eg[1]];
                auto tonode = wgraph->nodes[eg[2]];
                shared_ptr<edge<T>> wedge = make_shared<edge<T>>(value,fromnode,tonode);

                fromnode->out++;
                fromnode->nexts.push_back(tonode);
                fromnode->toedges.push_back(wedge);
                tonode->in++;
                wgraph->edges.insert(wedge);
            }
            size = wgraph->nodes.size();
            return wgraph;
        }

        unordered_map<shared_ptr<Node<int>>, int> dirikstra(shared_ptr<Node<int>> head)
        {
            unordered_map<shared_ptr<Node<int>>, int> distancemap;
            distancemap.insert({head, 0});
            unordered_set<shared_ptr<Node<int>>> records;

            // 每次封锁完一个点后，从剩下的点中找到距离值最小的点并返回
            shared_ptr<Node<int>> minnode = getmindistanceandunselectednode(distancemap, records);
            while (minnode!=nullptr)
            {
                int dis = distancemap[minnode];
                for (auto it : minnode->toedges)
                {
                    shared_ptr<Node<int>> curnode = it->tonode;
                    if (distancemap.count(curnode)==0)
                    {
                        distancemap.insert({curnode, dis+it->val});
                    } else {
                        distancemap.insert({curnode, min(dis+it->val, distancemap[curnode])});
                    }
                }
                records.insert(minnode);  // 此处锁点！
                minnode = getmindistanceandunselectednode(distancemap, records);
            }
            return distancemap;
        }

        shared_ptr<Node<int>> getmindistanceandunselectednode(unordered_map<shared_ptr<Node<int>>, int>& distancemap, unordered_set<shared_ptr<Node<int>>>& record)
        {
            shared_ptr<Node<int>> minnode = nullptr;
            int mindistances = INT_MAX;

            for (pair<shared_ptr<Node<int>>, int> onenode : distancemap)
            {
                shared_ptr<Node<int>> curnode = onenode.first;
                int curdistance = onenode.second;
                if (record.count(curnode)==0 && curdistance<mindistances)
                {
                    minnode = curnode;
                    mindistances = curdistance;
                }
            }
            return minnode;
        }
};

int main() {
    graphs<int> gps;
    //vector<vector<int>> test{{7,1,2},{6,1,3},{2,1,4},{1,4,3},{4,3,2},{8,2,5},{0,3,5},{9,5,4},{3,5,6},{1,6,8},{2,4,7},{1,7,6}};
    vector<vector<int>> test{{0,1,4},{1,1,2},{6,2,3},{5,4,3},{4,3,1}};
    shared_ptr<graph<int>> newgraph = gps.graphgenerator(test);

    unordered_map<shared_ptr<Node<int>>, int> mp = gps.dirikstra(newgraph->nodes[1]);
    for (auto it = mp.begin(); it!=mp.end(); it++)
    {
        cout<<it->first->val<<" "<<it->second<<endl;
    }
}