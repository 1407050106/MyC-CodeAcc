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

template <class T> struct Node;
template <class T> struct Edge;
template <class T> struct Graph;

template <class T>
struct Node{
    T val;
    int in;
    int to;
    vector<Node<T>> tonodes;
    vector<Edge<T>> toedges;

    Node(T inv):val(inv),in(0),to(0) {} 
};

template <class T>
struct Edge{
    T value;
    Node<T> fromnode;
    Node<T> tonode;
    
    Edge(T inv, Node<T> f, Node<T> t):value(inv),fromnode(f),tonode(t) {}
};

template <class T>
struct Grap{
    unordered_map<T, Node<T>> nodes;
    unordered_set<Edge<T>> edges;
};

template <class T>
class graphs{
    private:
        shared_ptr< Grap<T> > mygraph;
        int size;
    public:
        explicit graphs():size(0) {}
        shared_ptr< Grap<T> > make_graph(vector<vector<T>> edgesum)
        {   
            if (!edgesum.empty())
            {
                mygraph = make_shared<Grap<T>>();
                for (vector<T> eg:edgesum)
                {
                    T aval = eg[0];
                    if (mygraph->nodes.count(eg[1])==0)
                    {
                        mygraph->nodes.emplace(eg[1], Node<T>(eg[1]));
                    }
                    if (mygraph->nodes.count(eg[2]==0))
                    {
                        mygraph->nodes.emplace(eg[2], Node<T>(eg[2]));
                    }

                    Node<T> fromnode = mygraph->nodes[eg[1]];
                    Node<T> tonode = mygraph->nodes[eg[2]];
                    Edge<T> curedge = Edge<T>(aval, fromnode, tonode);

                    fromnode.to++;
                    fromnode.toedges.emplace_back(curedge);
                    fromnode.tonodes.emplace_back(tonode);
                    tonode.in++;
                    mygraph->edges.emplace(curedge);
                }

                size = mygraph->nodes.size();
                return mygraph;

            } else {
                return nullptr;
            }
        }
     
};


int main()
{
    graphs<int> wgp;
    vector<vector<int>> testgraph={{0,1,3},{1,3,6},{2,1,2},{1,2,6},{4,1,4},{8,4,6}};
    // shared_ptr<Graph<int>> aim = wgp.make_graph(testgraph);
}