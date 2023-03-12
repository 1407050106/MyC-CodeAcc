#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

//  已经掌握啦！
// 保存分别在左右子树上需要获取的信息
struct Info{
    bool isbalanced;  // 是否是平的
    int height;  // 以及它的高度
    Info() {};
    Info(bool i, int h):isbalanced(i),height(h) {};
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
        bool isAVL(TreeNode* head)
        {
            // 考虑用递归完成判断任务，那主函数如何调用递归函数呢？
           return process(head).isbalanced;
        }

        // 递归函数的输入、输出？要输出Info结构体的
        Info process(TreeNode* head)
        {
            if (head==nullptr) return Info(true, 0);
            Info leftinfo = process(head->left);
            Info rightinfo = process(head->right);
            // 每一层递归，都要计算当前头的高度和是否平衡
            int height = max(leftinfo.height, rightinfo.height)+1;
            bool balanced = true;
            if(!leftinfo.isbalanced) balanced=false;
            if(!rightinfo.isbalanced) balanced=false;
            if(abs(leftinfo.height-rightinfo.height)>1) balanced=false;
            return Info(balanced, height);
        }
};
int main() {
    ConstructTree bt;
    TreeNode* root;
    TreeNode* head;
    root = bt.CreateTree(head);

    bt.PrintTree(root);
    printf("\n");
    
    cout<<bt.isAVL(root)<<endl;
}