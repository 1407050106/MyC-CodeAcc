#include <iostream>
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
            if (!Node) return;
            cout<<Node->val<<" ";           
            inprint(Node->left);
            inprint(Node->right);          
        }

        void inprint(TreeNode* Node)
        {
            if (!Node) return;           
            inprint(Node->left);
            cout<<Node->val<<" ";
            inprint(Node->right);          
        } 

        void posprint(TreeNode* Node)
        {
            if (!Node) return;           
            inprint(Node->left);
            inprint(Node->right);
            cout<<Node->val<<" ";          
        }
};

int main()
{
    BTree bt;
    TreeNode *tree;
    bt.CreateTree(tree);
    cout<<tree->val<<endl;  // root
    cout<<tree->left->val<<endl;
    cout<<tree->right->val<<endl;

    bt.preprint(tree);
    printf("\n");
    bt.inprint(tree);
    printf("\n");
    bt.posprint(tree);
    printf("\n");
}