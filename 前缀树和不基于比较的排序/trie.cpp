#include <iostream>
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

        // 相比其它方法，麻烦一些, 注意防止内存泄漏
        // void delet(string word)
        // {
        //     if (search(word)!=0)
        //     {
        //         Node1* node = root;
        //         node->pass--;   // 头节点处的p先--
        //         int path = 0;
        //         for (char a : word)    // 然后去找路
        //         {
        //             path = a-'a';
        //             if (--node->nexts[path]->pass==0)  // 这里这样想：当前这条路的p--后是否等于0
        //             {
        //                 node->nexts[path]=NULL;
        //                 return;
        //             }              
        //             node=node->nexts[path];
        //         }
        //         node->end--;
        //     }
        // }

        void delet(string word)
        {
            if (search(word)!=0)
            {
                Node1* node = root;
                node->pass--;   // 头节点处的p先--;
                int path = 0;
                for (char a : word)    // 然后去找路
                {
                    path = a-'a';
                    if (--node->nexts[path]->pass==0)  // 这里这样想：当前这条路的p--后是否等于0
                    {
                        //node->nexts[path]=nullptr;
                        // 如果要删除的话，只能在这一步利用两个指针依次释放剩下不要的节点内存
                        delete node->nexts[path];    // Pay attention!
                        // 然后node节点设空断链
                        node->nexts[path]=nullptr;   
                        return;
                    }              
                    node=node->nexts[path];
                }
                node->end--;
            }
        }

        // word这个单词之前加入过几次
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

        // 所有加入的字符串中，有几个是以pre这个字符串作为前缀的
        int prefixNumber(string pre)
        {
            if (pre=="") return 0;
            Node1* node = root;
            for (char a : pre)
            {
                int temp = a-'a';
                if (node->nexts[temp]==NULL) return 0;
                node = node->nexts[temp];
            }
            return node->pass;
        }
    private:
        Node1* root;
};

int main() {
    //int index = (int)'b';   // 获取字符的ASC码值
    Trie1 trie;
    trie.insert("abc");
    cout<<trie.search("abc")<<endl;
    cout<<trie.search("absk")<<endl;
    cout<<trie.prefixNumber("ab")<<endl;
    trie.insert("absk");
    cout<<trie.search("abc")<<endl;
    cout<<trie.search("absk")<<endl;
    cout<<trie.prefixNumber("ab")<<endl;
    trie.delet("absk");
    cout<<trie.search("abc")<<endl;
    cout<<trie.search("absk")<<endl;
    cout<<trie.prefixNumber("ab")<<endl;
    trie.delet("abc");
    cout<<trie.search("abc")<<endl;
    cout<<trie.search("absk")<<endl;
    cout<<trie.prefixNumber("ab")<<endl;
    return 0;
}
