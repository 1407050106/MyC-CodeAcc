#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <unistd.h>
#include <cstring>
#include <queue>
#include <stack>
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

    Node(T v):val(v),in(0),out(0) {}   // 注意构造函�???
};

template<typename T>
struct edge{
    T val;
    shared_ptr<Node<T>> fromnode;
    shared_ptr<Node<T>> tonode;
    // 注意构造函�???
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

        vector<shared_ptr<edge<int>>> mintreep(shared_ptr<graph<int>> gph)
        {
            vector<shared_ptr<edge<int>>> res;
            unordered_set<shared_ptr<Node<int>>> record;
            priority_queue<shared_ptr<edge<int>>, vector<shared_ptr<edge<int>>>, greater<shared_ptr<edge<int>>>> probedges;

            // 所有点都找过了，OK！
            for (auto it : gph->nodes) //随便挑一个点开始
            {
                if (record.count(it.second)==0)
                {
                    record.insert(it.second);
                    for (shared_ptr<edge<int>> e : it.second->toedges)
                    {
                        probedges.push(e);
                    }

                    while (!probedges.empty())
                    {
                        shared_ptr<edge<int>> curedge = probedges.top();
                        probedges.pop();
                        if (record.count(curedge->tonode)==0)
                        {
                            record.insert(curedge->tonode);
                            res.push_back(curedge);
                            for (auto x:curedge->tonode->toedges)
                            {
                                probedges.push(x);
                            }
                        }
                    }
                }
            }
            return res;
        }
};

int main() {
    graphs<int> gps;
    //vector<vector<int>> test{{7,1,2},{6,1,3},{2,1,4},{1,4,3},{4,3,2},{8,2,5},{0,3,5},{9,5,4},{3,5,6},{1,6,8},{2,4,7},{1,7,6}};
    vector<vector<int>> test{{0,1,4},{1,1,2},{6,2,3},{5,4,3},{4,3,1}};
    shared_ptr<graph<int>> newgraph = gps.graphgenerator(test);
    vector<shared_ptr<edge<int>>> ans=gps.mintreep(newgraph);
    // YES!!!最小生成树建立完毕!
    for (auto a:ans)
    {
        cout<<a->val<<" ";
    }
}

