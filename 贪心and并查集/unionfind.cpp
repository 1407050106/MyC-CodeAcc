#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

// 弃用
template<class T>
struct Node {
    T value;
    Node () {}
    Node(T v)
    {
        value=v;
    }

    bool operator <(const Node& n)
    {
        // if (value<n.value) return true;
        // if (value==n.value) return true;
        // return false;
        return value<n.value;
    }
};

template<class T>
class unionsets{
    public:
        unionsets () {};
        unionsets (vector<T> values)
        {
            for (T value : values)
            {
                nodes[value]=value;
                // cout<<nodes[value].value<<endl;   // OK!
                sizemap[value]=1;
            }
        };

        // 给你一个节点，请你往上到不能再往上，把代表返回
        T findFather(T cur)
        {
            stack<T> path;  // path记录了经过的节点
            while (cur!=nodes[cur])
            {
                path.push(cur);
                cur=nodes[cur];
            }
            // 弹出时，把之前沿途遇到的节点的父依次更新！
			// 方便以后再查，一步到位，这其实是一步优化~
            while (!path.empty())
            {
                T temp = path.top();
                path.pop();
                nodes[temp]=cur;    // 更新其父
            }  
            return cur;
        }
        // 根据代表节点是否一样判断其是否属于同一集合
        bool issame(T a, T b)
        {
            return findFather(a)==findFather(b); 
        }
        // 合并操作
        void tounion(T a, T b)
        {
            T ahead = findFather(a);
            T bhead = findFather(b);
            if (ahead!=bhead)
            {
                int aSetSize = sizemap[a];
                int bSetSize = sizemap[b];
                T big = aSetSize>=bSetSize? ahead:bhead;
                T small = big==ahead? bhead:ahead;
                nodes[small]=big;
                sizemap[big]=aSetSize+bSetSize;
                sizemap.erase(small);
            }
        }

        void watchonly()
        {
            cout<<nodes["a"]<<endl;
            cout<<sizemap["a"]<<endl;
        }

        // 弃用
        static bool compare1(const Node<T> &a, const Node<T> &b)
        {
            return a.value<b.value;
        }
        bool operator () (const Node<T> &a, const Node<T> &b)
        {
            return a.value<b.value;
        }
    private:
        // 主要可以依靠两个数据结构！
        // 用一张表起到指针的作用，就告诉你，谁的父亲是谁
        unordered_map<T, T> nodes;
        // 存储代表节点的大小,即代表节点所代表的集合大小
        unordered_map<T, int> sizemap;   
};

int main() {
    vector<int> a1={1,2,3};
    vector<string> a2={"a","ab", "abc", "c", "d"};
    unionsets<string> a(a2);
    //a.watchonly();
    cout<<a.issame(a2[0], a2[3])<<endl;
    a.tounion(a2[0], a2[3]);
    cout<<a.issame(a2[0], a2[3])<<endl;

    cout<<a.issame(a2[1], a2[3])<<endl;

}