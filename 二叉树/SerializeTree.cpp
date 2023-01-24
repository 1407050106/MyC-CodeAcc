#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <string.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value) {};
    TreeNode(){};
};

class SerializeAndReconstructTree{
    public:
        // 先序方式序列化就是给你头节点，按先序顺序存储树
        TreeNode* CreateTree(TreeNode* node)
        {
            int input;
            cin>>input;
            if (input==0) {return nullptr;}
            else {
                node = new TreeNode(input);
                //root->val=input;
                node->left = CreateTree(node->left);
                node->right = CreateTree(node->right); 
            }
            return node;
        }

        void PrintTree(TreeNode* root)
        {
            if (!root) return;
            cout<<root->val<<" ";
            PrintTree(root->left);
            PrintTree(root->right);
        }

        // 先序方式的序列化
        queue<string> serialize(TreeNode* head)
        {
            queue<string> ans;
            pres(head, ans);
            return ans;
        }

        // 先序方式反序列化
        TreeNode* buidbypreorder(queue<string> tq)
        {
            if (tq.empty()) return nullptr;
            return preb(tq);
        }

        // 层序方式序列化比较简单, 但是按层反序列化比较难, 笔记有详细逻辑注释
        // 注意序列化的容器，其一定是一颗满二叉树

    private:  
        void pres(TreeNode* head, queue<string>& ans)
        {
            if (!head) 
            {ans.push("#");}    // 这里要用if-else结构，因为没有return结束
            else {                              
            ans.push(to_string(head->val));
            pres(head->left, ans);
            pres(head->right, ans);}
            printf("\n");
        }

        TreeNode* preb(queue<string>& tq)
        {
            string value = tq.front();
            tq.pop();
            if (value=="#") return nullptr;
            TreeNode* root = new TreeNode(atoi(value.c_str()));
            root->left=preb(tq);
            root->right=preb(tq);
            return root;
        }
};

class pprint{
    public:
        void operator()(int val){
            cout<<val<<" ";
        }
};

int main() {
    SerializeAndReconstructTree st;
    TreeNode *root, *res;
    res = st.CreateTree(root);
    // st.PrintTree(res);
    // 先序序列化得到二叉树的队列
    queue<string> tt = st.serialize(res);
    // while(!tt.empty())
    // {
    //     cout<<tt.front()<<" ";
    //     tt.pop();
    // }
    // printf("\n");
    TreeNode* ft = st.buidbypreorder(tt);
    st.PrintTree(ft);
}