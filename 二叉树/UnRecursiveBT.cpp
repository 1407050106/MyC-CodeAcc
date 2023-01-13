#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value){}
};

class BTree{
    public:
        void CreateTree(TreeNode* &Node)
        {
            int input;
            cin>>input;
            if (input==0) return;
            Node = new TreeNode(input);
            CreateTree(Node->left);
            CreateTree(Node->right);
        }

        void preprint(TreeNode* Node)
        {
            if(Node)
            {
                stack<TreeNode*> temp;
                temp.push(Node);
                while(!temp.empty())
                {
                    Node = temp.top();
                    temp.pop();
                    cout<<Node->val<<" ";
                    if(Node->right)       // 先右后左
                    {
                        temp.push(Node->right);
                    }
                    if(Node->left)
                    {
                        temp.push(Node->left);
                    }
                }
                printf("\n");
            }
        }

        void posprint(TreeNode* Node)   // 要左右头
        {
            if (Node)
            {
                stack<TreeNode*> n1, n2;
                n1.push(Node);
                while(!n1.empty())
                {
                    Node = n1.top();
                    n1.pop();
                    n2.push(Node);
                    if(Node->left)       // 先左后右
                    {
                        n1.push(Node->left);
                    }
                    if(Node->right)
                    {
                        n1.push(Node->right);
                    }
                }

                while(!n2.empty())
                {
                    cout<<n2.top()->val<<" ";
                    n2.pop();
                }
                printf("\n");
            }
        }

        // hard
        void inprint(TreeNode* cur)
        {
            if (cur)
            {
                stack<TreeNode*> temp;
                while(!temp.empty() || cur!=nullptr)
                {
                    if (cur!=nullptr)
                    {
                        temp.push(cur);
                        cur=cur->left;
                    } else {
                        TreeNode* node = temp.top();    // 这里要注意：下一步要获取的是栈顶节点的右孩子
                        cout<<node->val<<" ";
                        temp.pop();
                        cur=node->right;
                    }
                }
                printf("\n");
            }
        }
};

int main() {
    BTree bt;
    TreeNode *tree;
    bt.CreateTree(tree);
    bt.preprint(tree);
    bt.inprint(tree);
    bt.posprint(tree);
}