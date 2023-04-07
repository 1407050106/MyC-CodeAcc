#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

// ��ȫ�����Լ�д�ķ�������!
struct Edge{
    int weight;
    Node* from;
    Node* to;
    Edge(int w, Node* f, Node* t):weight(w), from(f), to(t) {}
};

struct Node {
    int value;
    int in;
    int out;
    vector<Node*> nexts;
    vector<Edge*> edges;
    Node(){}
    Node(int val) {value=val; in=0; out=0;}  // zhuyi how to set!
};

struct graph{
    unordered_map<int, Node*> nodes;
    unordered_set<Edge*> edges;
};

class GraphGenerator {
    private:
    public:
        graph* createGraph(vector<vector<int>> matrix)
        {
            // 创建一个东西首先就是要有一块地址～
            graph* grap = new graph(); 
            // 拿到每一条边，matrix[i]的信�?? 
            for (int i=0; i<matrix.size(); i++)
            {
                int weight = matrix[i][0];
                int from = matrix[i][1];
                int to = matrix[i][2];

                if (grap->nodes.count(from)==0)
                {
                    grap->nodes[from] = new Node(from);
                }
                if (grap->nodes.count(to)==0)
                {
                    grap->nodes[to] = new Node(to);
                }

                // set edge first!
                Node* fromnode = grap->nodes[from];
                Node* tonode = grap->nodes[to];
                Edge* newedge = new Edge(weight, fromnode, tonode);

                // then set others~
                fromnode->out+=1;
                fromnode->nexts.push_back(tonode);
                fromnode->edges.push_back(newedge);
                tonode->in+=1;
                grap->edges.insert({newedge});
            }
            return grap;
        }
};

class readgraph{
    public:
        // 注意防止循环图结构
        void graphBFS(graph* graph)
        {
            if (!graph) return;
            queue<Node*> curlevel;
            unordered_set<Node*> set;
            curlevel.push(graph->nodes.begin()->second);
            set.insert({graph->nodes.begin()->second});
            while(!curlevel.empty())
            {
                for (int i=0; i<curlevel.size(); i++)
                {
                    Node* cur = curlevel.front();
                    curlevel.pop();
                    cout<<cur->value<<endl;
                    for (int j=0; j<cur->nexts.size(); j++)
                    {
                        // !!!!!!!!!! No circle~
                        if (set.count(cur->nexts[j])==0)
                        {
                            curlevel.push(cur->nexts[j]);
                            set.insert({cur->nexts[j]});
                        }
                    }
                }
            }
        }

        void grapfDFS(graph* graph)
        {
            // for yourself later
            // 看了左神的非递归写法你就会有递归的思路
        }
};

int main() 
{
    
}