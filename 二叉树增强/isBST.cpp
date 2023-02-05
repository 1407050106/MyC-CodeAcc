#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// 保存分别在左右子树上需要获取的信息
// 需要子树上的最小值、最大值以及本身是否是BST
struct Info{
    bool isBST;
    int tmax;
    int tmin;
    Info(bool insBST, int tm, int tn)
    {
        isBST=insBST; tmax=tm; tmin=tn;
    }
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value) {};
    TreeNode(){};
};

class ConstructTree{
    public:
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

        // 
        bool isBST(TreeNode* head)
        {
            if (head==nullptr) return true;  // 这一步别忘了
            return process(head)->isBST;
        }

        Info* process(TreeNode* head)
        {
            if (head==nullptr) return nullptr;
            Info* left = process(head->left);
            Info* right = process(head->right);

            int tmin = head->val;
            if (left!=nullptr) 
            {
                tmin=min(left->tmin, tmin);
            }
            if (right!=nullptr)
            {
                tmin=min(right->tmin, tmin);
            }

            int tmax = head->val;
            if (left!=nullptr) 
            {
                tmax=max(left->tmax, tmax);
            }
            if (right!=nullptr)
            {
                tmax=max(right->tmax, tmax);
            }
            // 先默认是BST，然后看怎么违反的就完事了
            // 意每一个可能性的判断条件都不要受到前面的干扰，要独立判断
            bool insBST = true;
            if(left!=nullptr && !left->isBST) insBST=false;
            if(right!=nullptr && !right->isBST) insBST=false;
            if(left!=nullptr && left->tmax>=head->val) insBST=false;
            if(right!=nullptr && right->tmin<=head->val) insBST=false;

            return new Info(insBST, tmax, tmin);
        }
};
int main() {
    ConstructTree bt;
    TreeNode* root;
    TreeNode* head;
    root = bt.CreateTree(head);

    bt.PrintTree(root);
    printf("\n");
    
    cout<<bt.isBST(root)<<endl;
}