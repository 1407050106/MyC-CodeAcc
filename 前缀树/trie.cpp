#include <iostream>
#include <vector>
#include <vector>
#include <string.h>
using namespace std;

class Node1{
    public:
        int pass;
        int end;
        Node1 *nexts[26];    //这里要创建指针数组

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
            memset(nexts, NULL, sizeof(*nexts));
        }
};

class Trie1{
    public:
        Trie1() 
        {
            root = new Node1();
        }

        ~Trie1()
        {
            _Destroy(root);
        }

        void insert(string word)
        {
            if (word=="") return;
            Node1* node = root;   //用node从根节点去建树, 用指针创建数据结构基本都需要两个，一个用来从前到后
            node->pass++;
            int path=0;
            for(char a : word)
            {
                path=a-'a';   //给你字符，去找路，就计算这个(tmp - 'a')
                if (node->nexts[path]==NULL)   
                {
                    node->nexts[path] = new Node1();
                }
                node=node->nexts[path];
                node->pass++;
            }
            node->end++;
        }

        void delete(string word)
        {

        }

        int search(string word)
        {
            if (word=="") return 0;
            Node1* node = root;
            int index = 0;
            for (char a : word)
            {
                index = a-'a';
                if (node->nexts[index]==NULL)   //如果没路了 就说明没有该单词
                {
                    return 0;
                }
                node = node->nexts[index];
            }
            return node->end;
        }
    private:
        Node1* root;
};

int main() {
    Node1 node1;
    return 0;
}