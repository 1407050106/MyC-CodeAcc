#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <functional>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <unistd.h>
using namespace std;

struct Node{
    int pass;
    int end;
    unordered_map<int, shared_ptr<Node>> nexts;
    Node():pass(0),end(0) {}
};

class pretree{
    public:
        pretree()
        {
            root = make_shared<Node>();
        }
        
        void insert(string word)
        {
            if (word=="") return;
            shared_ptr<Node> node=root;
            node->pass++;
            int path=0;
            for (char c:word)
            {
                path=(int)c;
                if (node->nexts.count(path)==0)
                {
                    node->nexts.insert({path, make_shared<Node>()});
                }
                node = (node->nexts)[path];
                node->pass++;
            }
            node->end++;
        }

        int search(string word)
        {
            if (word=="") return 0;
            shared_ptr<Node> node = root;
            int path=0;
            for (char c:word)
            {
                path=(int)c;
                if (node->nexts.count(path)==0)
                {
                    return 0;
                }
                node=(node->nexts)[path];
            }
            return node->end;
        }

        int searchpre(string word)
        {
            if (word=="") return 0;
            shared_ptr<Node> node = root;
            int path=0;
            for (char c:word)
            {
                path=(int)c;
                if (node->nexts.count(path)==0)
                {
                    return 0;
                }
                node=(node->nexts)[path];
            }
            return node->pass;
        }

        void delet(string word)
        {
            if (search(word)>0)
            {
                shared_ptr<Node> node = root;
                node->pass--;
                int path=0;
                for (char c:word)
                {
                    path=(int)c;
                    auto it=node->nexts.find(path);
                    if (--(it->second->pass)==0)
                    {
                        node->nexts.erase(it);
                        return;
                    }
                    node=(node->nexts)[path];
                }
                node->end--;
            }
        }

    private:
        shared_ptr<Node> root;
};

void wyl(int val)
{
    cout<<val<<" ";
}

int main() {
    pretree pt;
    pt.insert("abc");
    pt.insert("abcd");
    pt.insert("abc");
    pt.insert("abcde");

    cout<<pt.search("abcd")<<endl;
    cout<<pt.searchpre("ab")<<endl;

    pt.delet("abc");
    cout<<pt.search("abc")<<endl;
    pt.delet("abc");
    cout<<pt.search("abc")<<endl;
    pt.delet("abc");
    cout<<pt.search("abc")<<endl;

    // valgrind --tool=memcheck --leak-check=full ./plusfunc.out
    // int* a = new int;
    // *a=6;

    // while(1)
    // {
    //     sleep(10);
    // }
}