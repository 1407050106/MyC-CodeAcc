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

    Node(T v):val(v),in(0),out(0) {}   // 注意构造函�??
};

template<typename T>
struct edge{
    T val;
    shared_ptr<Node<T>> fromnode;
    shared_ptr<Node<T>> tonode;
    // 注意构造函�??
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

        void bfsgraph(shared_ptr<graph<T>> gph) 
        {
            auto it = gph->nodes[1];   // 这里设置的从1开始，也可以从�?处开始，但是遍历结果会不一样哦
            shared_ptr<Node<T>> head = it;
            queue<shared_ptr<Node<T>>> q;
            unordered_set<shared_ptr<Node<T>>> record;
            q.push(head);
            record.insert(head);
            while (!q.empty())
            {
                int len = q.size();
                for (int i=0; i<len; i++)
                {
                    shared_ptr<Node<T>> cur = q.front();
                    cout<<cur->val<<" ";
                    q.pop();
                    for (auto it : cur->nexts)
                    {
                        if (record.count(it)==0)
                        {
                            q.push(it);record.insert(it);
                        }
                    }
                } 
                printf("\n");
            }
        }

        void dfsgraph(shared_ptr<graph<int>> gph)  // 这�?�dfs，相当于找出全部�?径！
        {
            shared_ptr<Node<int>> head = gph->nodes[1];  // 也是指定�?1位置为起�?
            vector<string> res;unordered_set<shared_ptr<Node<int>>> record;
            process(record, head, "", res);
            for (auto s : res) cout<<s<<" ";
            printf("\n");
        }

        void process(unordered_set<shared_ptr<Node<int>>>& record, shared_ptr<Node<int>> node, string path, vector<string>& res)
        {
            path+=to_string(node->val);
            record.insert(node);
            int limit = node->nexts.size(), count=0;  // 我太�?明了：DFS里必须限制，某个节点真的无�?�可走时才能return！！�?
            for (auto it : node->nexts)
            {
                if (record.count(it)!=0)  // �?一种情况：无路�?走时再return
                {
                    if (++count==limit)
                    {
                        res.push_back(path);
                        return;
                    }   
                } else if (it->nexts.empty())  // �?二�?�情况：下一层没有出�?时，直接return
                {
                    path+=to_string(it->val);
                    res.push_back(path);
                    return;
                } else {    // �?三�?�情况：有路就继�?往下走�?
                    process(record, it, path, res);
                }
            }
        }

        void dfs2(shared_ptr<graph<int>> gph)  // easy!这�?�自己压栈的写法，可以找出全部节点，没有重�?�！
        {
            shared_ptr<Node<int>> head = gph->nodes[1];
            stack<shared_ptr<Node<int>>> help;
            unordered_set<shared_ptr<Node<int>>> record;
            help.push(head); record.insert(head);
            cout<<head->val<<" ";
            while(!help.empty())
            {
                shared_ptr<Node<int>> cur = help.top();
                help.pop();
                for (auto node:cur->nexts)
                {
                    if (record.count(node)==0)
                    {
                        help.push(cur);
                        help.push(node);
                        record.insert(node);
                        cout<<node->val<<" ";
                        break;
                    }
                }
            }
        }
};

int main() {
    graphs<int> gps;
    // ��ɫ�ʼǱ��ϵĸ��Ӳ���ͼ
    vector<vector<int>> test{{7,1,2},{6,1,3},{2,1,4},{1,4,3},{4,3,2},{8,2,5},{0,3,5},{9,5,4},{3,5,6},{1,6,8},{2,4,7},{1,7,6}};
    shared_ptr<graph<int>> newgraph = gps.graphgenerator(test);

    // cout<<newgraph->nodes[5]->out<<endl;
    cout<<"graphs size = "<<gps.size<<endl;
    cout<<"*************BFS*****************"<<endl;
    gps.bfsgraph(newgraph);
    cout<<"*************DFS1*****************"<<endl;
    gps.dfsgraph(newgraph);
    cout<<"*************DFS2(z)**************"<<endl;
    gps.dfs2(newgraph);
}

