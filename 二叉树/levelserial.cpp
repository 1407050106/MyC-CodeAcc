#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include <numeric>
#include <algorithm>
#include <memory>
#include <cmath>
#include <ctime>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int value):val(value) {}
};

class mytrie{
    public:
       void createtree(Node* &root)
       {
            int a;
            cin>>a;
            if (a==0) return;
            root = new Node(a);
            createtree(root->left);
            createtree(root->right);
       }

       void inprint(Node* node)
       {
            if(!node) return;
            else {
                inprint(node->left);
                cout<<node->val<<" ";
                inprint(node->right);
            }
       }

       int printdepth(Node* node)
       {
            if (!node) return 0;
            else {
                int m = printdepth(node->left)+1;
                int n = printdepth(node->right)+1;
                return m>n?m:n;
            }
       }

        //  改写自树的BFS
       queue<string> cengorder(Node* root)
       {
            queue<string> ans;
            if (!root) 
            {
                return ans;
            }
            queue<Node*> tree;
            tree.push(root);
            while (!tree.empty())
            {
                // 上来就把当前层的全部for一遍！
                for (int i=0; i<tree.size(); i++)
                {
                    Node* cur = tree.front();
                    if (cur)
                    {
                        ans.push(to_string(cur->val));
                        tree.pop();
                        if(cur->left)
                        {
                            tree.push(cur->left);
                        } else {
                            tree.push(nullptr);
                        }
                        if(cur->right)
                        {
                            tree.push(cur->right);
                        } else {
                            tree.push(nullptr);
                        }
                    } else {
                        ans.push("#");
                        tree.pop();
                    }    
                }              
            }
            return ans;
       }
        // king left s method!
       queue<string> cengorder2(Node* root)
       {
            queue<string> ans;
            if (!root)
            {
                return ans;
            } else {
                queue<Node*> tree;
                ans.push(to_string(root->val));
                tree.push(root);
                while (!tree.empty())
                {
                    Node* cur = tree.front();
                    tree.pop();
                    if(cur->left)
                    {
                        ans.push(to_string(cur->left->val));
                        tree.push(cur->left);
                    } else {
                        ans.push("#");
                    }
                    if(cur->right)
                    {
                        ans.push(to_string(cur->right->val));
                        tree.push(cur->right);
                    } else {
                        ans.push("#");
                    }
                }
            }
            return ans;
       }
        // 反序列化 hard!
       Node* rcengorder(queue<string> q)
       {
            if (q.size()==0)
            {
                return nullptr;
            }
            // q不为空，说明至少有一个头节点 ，先把头节点建出来！
            Node* root = new Node(atoi(q.front().c_str()));
            q.pop();
            queue<Node*> qq;  // 用于存放 待建立的节点
            qq.push(root);
            while (!qq.empty())
            {
                // 相当于1个1个来
                Node* cur = qq.front();
                qq.pop();
                cur->left = generatenode(q.front());
                q.pop();
                cur->right = generatenode(q.front());
                q.pop();

                if (cur->left)
                {
                    qq.push(cur->left);
                }
                if (cur->right)
                {
                    qq.push(cur->right);
                }
            }
            return root;
       }

       // good help function!
        Node* generatenode(string s)
        {
            if (s=="#") return nullptr;
            else {
                return new Node(atoi(s.c_str()));
            }
        }
    private:

}; 

int main() {
    //cout<<sizeof(abc)<<endl;

    mytrie mt;
    Node* root;
    mt.createtree(root);
    mt.inprint(root);
    printf("\n");
    cout<<mt.printdepth(root);
    printf("\n");

    queue<string> res=mt.cengorder(root);
    // while (!res.empty())
    // {
    //     cout<<res.front()<<" ";
    //     res.pop();
    // }
    printf("\n");
    queue<string> res2=mt.cengorder2(root);
    while (!res2.empty())
    {
        cout<<res2.front()<<" ";
        res2.pop();
    }
    printf("\n");

    Node* w=mt.rcengorder(res);
    mt.inprint(w);
    printf("\n");
}  