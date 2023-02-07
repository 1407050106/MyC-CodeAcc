#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value) {};
    TreeNode(){};
};

// 保存分别在左右子树上需要获取的信息
struct Info{
    TreeNode* root;
    int maxsubsize;
    int max;
    int min;
    Info() {};
    Info(TreeNode* node, int mb, int ma, int mi)
    {
        root=node;
        maxsubsize=mb;
        max=ma;
        min=mi;
    }
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
        TreeNode* tellsubhead(TreeNode* head)
        {
            if (head==nullptr) return nullptr;
            return process(head)->root;
        }

        Info* process(TreeNode* head)
        {
            if (head==nullptr) return nullptr;
            Info* leftinfo = process(head->left);
            Info* rightinfo = process(head->right);

            int tmax=head->val;
            int tmin=head->val;
            if(leftinfo!=nullptr)
            {
                tmax = max(leftinfo->max, tmax);
                tmin = min(leftinfo->min, tmin);
            }
            if(rightinfo!=nullptr)
            {
                tmax = max(rightinfo->max, tmax);
                tmin = min(rightinfo->min, tmin);
            }

            TreeNode* root = nullptr;
            int maxsubsize=0;
            int p1=-1;
            if(leftinfo!=nullptr) p1=leftinfo->maxsubsize;
            int p2=-1;
            if(rightinfo!=nullptr) p2=rightinfo->maxsubsize;
            int p3=-1;
            bool leftisBST = leftinfo==nullptr?true:(leftinfo->root==head->left);
            bool rightisBST = rightinfo==nullptr?true:(rightinfo->root==head->right);
            if(leftisBST && rightisBST)
            {
                bool leftless = leftinfo==nullptr?true:(leftinfo->max<head->val);
                bool rightlarger = rightinfo==nullptr?true:(rightinfo->min>head->val);
                if(leftless && rightlarger)
                {
                    int leftsize = leftinfo==nullptr?0:leftinfo->maxsubsize;
                    int rightsize = rightinfo==nullptr?0:rightinfo->maxsubsize;
                    p3 = leftsize+rightsize+1;
                } 
            }
            maxsubsize=max(max(p1,p2), p3);
            if (maxsubsize==p1)
            {
                root = leftinfo->root;
            } else if(maxsubsize==p2)
            {
                root = rightinfo->root;
            } else {
                root = head;
            }
            return new Info(root,maxsubsize,tmax,tmin);
        }
};
int main() {
    ConstructTree bt;
    TreeNode* root;
    TreeNode* head;
    root = bt.CreateTree(head);

    bt.PrintTree(root);
    printf("\n");
    
    cout<<bt.tellsubhead(root)->val<<endl;
}