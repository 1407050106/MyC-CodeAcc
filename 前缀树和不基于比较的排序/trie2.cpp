#include <iostream>
#include <climits>
#include <map>
#include <string.h> 
#include <vector>
using namespace std;

// for new trie and delete correctly
struct Node{
    int pass;
    int end;
    map<int, Node*>* nexts;
    Node(){            // 这里是要分配内存
        pass=0;
        end=0;
        nexts = new map<int, Node*>; 
    }
};

class Trie{
    private:
        Node* root; 

    public:
        Trie()
        {
            root=new Node();
        }
        ~Trie()
        {
            _Destroy(root);
        }

        void insert(string word)
        {
            if (word=="") return;
            Node* node = root;
            node->pass++;
            int path=0;
            for (char c:word)
            {
                path = (int)c;
                if (node->nexts->count(path)==0)
                {
                    //Node *nod=new Node();
                    node->nexts->insert({path, new Node()});
                }
                auto it = node->nexts->find(path);
                node = it->second;
                node->pass++;
            }
            node->end++;
        }

        // use map not difficult but easy
        void delet(string word)
        {
            if (search(word)!=0)
            {
                Node* node = root;
                node->pass--;
                int path = 0;
                for (char c:word)
                {   
                    path = (int)c;
                    // 注意这里的写法!!
                    auto it = node->nexts->find(path);
                    // 要用pass值做判断!!
                    if (--(it->second->pass)==0)
                    {
                        node->nexts->erase(it);
                        return;
                    }
                    node = it->second;
                }
                node->end--;
            }
        }

        int search(string word)
        {
            if (word=="") return 0;
            Node* node =root;
            int path = 0;
            for (char c:word)
            {
                path = (int)c;
                // 属于当前字符的路存在，才会有它的结尾节点记录
                if(node->nexts->count(path)==0)
                {
                    return 0;
                }
                auto it = node->nexts->find(path);
                node = it->second;
            }
            return node->end;
        }

        int searchpre(string word)
        {
            if (word=="") return 0;
            Node* node =root;
            int path = 0;
            for (char c:word)
            {
                path = (int)c;
                if(node->nexts->count(path)==0)
                {
                    return 0;
                }
                auto it = node->nexts->find(path);
                node = it->second;
            }
            return node->pass;
        }
};

int main() {
    // long a = LONG_MIN;
    // cout<<a<<endl;

    // for test
    Trie trie;
    trie.insert("abc");
    trie.insert("abc");
    trie.insert("abcd");
    trie.insert("abcdef");

    cout<<trie.search("abc")<<endl;

    trie.delet("abc");
    trie.delet("abc");
    trie.delet("abc");
    cout<<trie.search("abc")<<endl;

    cout<<trie.searchpre("abcdef")<<endl;
}