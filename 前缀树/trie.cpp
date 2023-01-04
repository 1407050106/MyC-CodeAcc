#include <iostream>
#include <vector>
#include <vector>
using namespace std;

typedef struct Node1{
    int pass;
    int end;
    //vector<Node1> nexts;

    // char tmp = 'b'  (tmp - 'a')   
    Node1()
    {
        pass=0;    //节点只有p和e值，字符都在路上
        end=0;
        // 0    a
        // 1    b
        // 2    c
        // ..   ..
        // 25   z
        // nexts[i] == null   i方向的路不存在
        // nexts[i] != null   i方向的路存在
        
    }
}Node1;

// class Trie1{
//     public:
//         Trie1() 
//         {
//             root = Node1();
//         }

//         void insert(string word)
//         {
//             if (word=="") return;
//             Node1 node = root;   //用node从根节点去建树
//             node.pass++;
//             int path=0;
//             for(char a : word)
//             {
//                 path=a-'a';   //给你字符，去找路，就计算这个(tmp - 'a')
//                 if (&node.nexts[path]==nullptr)   //?
//                 {
//                     node.nexts[path] = Node1();
//                 }
//                 node=node.nexts[path];
//                 node.pass++;
//             }
//             node.end++;
//         }
//     private:
//         Node1 root;
// };

struct look{
    public:
        void operator() (Node1 val)
        {
        }
};

int main() {
    Node1 node1;
    // for (int k=0; k<26; k++)
    // {
    //     if ((bool)node1.nexts[k])
    //     {
    //         cout<<"Nothing!"<<endl;
    //     } else {
    //         cout<<"Alright!"<<endl;
    //     }
    // }
    return 0;
}