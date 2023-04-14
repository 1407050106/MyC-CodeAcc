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

        vector<int> topologysort(shared_ptr<graph<int>> gph)
        {
            vector<int> res;
            unordered_map<shared_ptr<Node<int>>, int> record;
            queue<shared_ptr<Node<int>>> q;
            for (auto it:gph->nodes)
            {
                //record[it]=it->in;   // 一定�?�先记录
                record.insert({it.second, it.second->in});
                if (it.second->in==0) q.push(it.second);
            }
            while (!q.empty())
            {
                shared_ptr<Node<int>> cur = q.front();
                q.pop();
                res.push_back(cur->val);
                for (auto it:cur->nexts)
                {
                    record[it]--;
                    if (record[it]==0)
                    {
                        q.push(it);
                    }
                }
            }
            return res;
        }
};

int main() {
    graphs<int> gps;
    //vector<vector<int>> test{{7,1,2},{6,1,3},{2,1,4},{1,4,3},{4,3,2},{8,2,5},{0,3,5},{9,5,4},{3,5,6},{1,6,8},{2,4,7},{1,7,6}};
    vector<vector<int>> test{{0,1,4},{1,1,2},{6,2,3},{5,4,3}};  // �����޻�ͼ
    shared_ptr<graph<int>> newgraph = gps.graphgenerator(test);
    vector<int> ans=gps.topologysort(newgraph);
    for (int a:ans)
    {
        cout<<a<<" ";
    }
}

