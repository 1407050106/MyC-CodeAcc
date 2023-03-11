#include <iostream>
#include <queue>
using namespace std;

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

        // 借助二叉树的层序遍历(这是左神的BFS方法，用自己的BFS也可以!)
        bool isCBT(TreeNode* head)
        {
            if (head==nullptr) return true;
            queue<TreeNode*> sequence;
            sequence.push(head);
            bool firstnotdoublesign = false; // 标志是否遇到过左右两个孩子不双全的节点
            while (!sequence.empty())
            {
                TreeNode* node = sequence.front();
                sequence.pop();
                TreeNode* l = node->left;
                TreeNode* r = node->right;
                // // 如果遇到了第一个不双全的节点，又发现当前节点不是叶节点 或者 有右无左.  只要遇到一次即可直接返回false!
                if ((firstnotdoublesign && (l!=nullptr || r!=nullptr)) || (l==nullptr && r!=nullptr)) return false;
                if(l!=nullptr) sequence.push(l);
                if(r!=nullptr) sequence.push(r);
                // 每遍历一步，就检查开关是否开启
			    // 相当于每一轮都看是否遇到了孩子不双全的节点，开启一次就够
                if(l==nullptr || r ==nullptr) firstnotdoublesign=true;  
            }
            return true;  // 所有节点判断完没有异常，返回true
        }
};
int main() {
    ConstructTree bt;
    TreeNode* root;
    TreeNode* head;
    root = bt.CreateTree(head);

    bt.PrintTree(root);
    printf("\n");
    cout<<bt.isCBT(root)<<endl;
}