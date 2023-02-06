#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Info{
    int maxSubSize;
    int allSize;
    int max;
    int min;
    Info () {};
    Info(int m, int a, int ma, int mi) 
    {
        maxSubSize = m;
        allSize = a;
        max=ma;
        min=mi;
    };
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

        int maxsub(TreeNode* head)
        {
            if (head==nullptr) return 0;
            return process(head)->maxSubSize;
        }

        // 递归函数的输入、输出？要输出Info结构体的
        Info* process(TreeNode* head)
        {
            if(head==nullptr) return nullptr;
            Info* leftinfo = process(head->left);
            Info* rightinfo = process(head->right);
            // 先设定初始值
            int allSize=1;
            int cmax=head->val;
            int cmin=head->val;
            // 这一步判断就决定我们必须使用Info*，因为只要Info为空，那就说明没有子树
            // 这一步判断的意思是：如果左子树不为空
            if (leftinfo!=nullptr) 
            {
                cmax = max(leftinfo->max, cmax);
                cmin = min(leftinfo->min, cmin);
                allSize+=leftinfo->allSize;
            }
            if (rightinfo!=nullptr) 
            {
                cmax = max(rightinfo->max, cmax);
                cmin = min(rightinfo->min, cmin);
                allSize+=rightinfo->allSize;
            }
            // int maxSubSize;
            // 那就剩下一个参数待加工了，我们还是这样，每个可能性去遍历判断，
            // 更新我们每种可能性下的maxSubSize值，最后取所有可能性中的最大值
            // 从第一种可能性开始
            int p1=-1;
            if (leftinfo!=nullptr)
            {
                p1 = leftinfo->maxSubSize;
            }
            int p2=-1;
            if (rightinfo!=nullptr)
            {
                p2 = rightinfo->maxSubSize;
            }
            int p3 = -1;
            // 里有代码coding的精心组织
            bool leftisBST = leftinfo==nullptr?true:(leftinfo->allSize==leftinfo->maxSubSize);
            bool rightisBST = rightinfo==nullptr?true:(rightinfo->allSize==rightinfo->maxSubSize);
            if (leftisBST && rightisBST)
            {
                // 这里注意：判断还是要避免之前的任何干扰，从头开始严格判断，将最全面的可能性展示出来
                // 比如这里，如果左树不为空才能继续获取Info中的max值进行判断
                bool leftislegal = leftinfo==nullptr?true:(leftinfo->max<head->val);
                bool rightislegal = rightinfo==nullptr?true:(rightinfo->min>head->val);
                if (leftislegal && rightislegal)
                {
                    // 这里还是要判断一下：左右子树是否存在？存在才能取值
                    int leftsize = leftinfo==nullptr?0:leftinfo->allSize;
                    int rightsize = rightinfo==nullptr?0:rightinfo->allSize;
                    p3 = leftsize + rightsize +1;
                }
            }
            int maxSubSize = max(max(p1,p2), p3);
            return new Info(maxSubSize, allSize, cmax, cmin);
        }
};
int main() {
    ConstructTree bt;
    TreeNode* root;
    TreeNode* head;
    root = bt.CreateTree(head);

    bt.PrintTree(root);
    printf("\n");

    cout<<bt.maxsub(root)<<endl;
}