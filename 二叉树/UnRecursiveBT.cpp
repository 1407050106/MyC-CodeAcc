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
                    if(Node->right)       // 闁稿繐鐗嗚ぐ鎼佸触鎼粹€茬
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

        void posprint(TreeNode* Node)   // 閻熸洑绀佹稊蹇涘矗閸愬眰浠�
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
                    if(Node->left)       // 闁稿繐鐗嗘稊蹇涘触鎼粹€崇
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
                while(!temp.empty() || cur!=nullptr)  // 濞戞挶鍊撻柌婊堝级閳ュ弶锟姐垺绂嶉幒鏃€绁查柛鎺戝鐎规娊鏁嶇仦钘夋锭閻熸洑鐒﹂悥銈嗙▔瀹ュ嫯绀嬬紒宀€鍎ら崹銊╂嚀閸涙壆绠烽柡鍫濓拷搴∥濋柣鎰缁辨繄浜告潏鈺傚煕缂傦拷?闁告ê锟斤拷閻栵拷
                {
                    if (cur!=nullptr)
                    {
                        temp.push(cur);
                        cur=cur->left;
                    } else {
                        TreeNode* node = temp.top();    // 閺夆晜鐟╅崳椋庢啺娴ｈ鏆堥柟鏉块獜缁辩増绋夌€ｂ晝锟芥潙锟芥縿鍎�?娴ｈ棄绠柛娆愮墱濞堟垿寮�?闁哄秴鐗撻妴濠囨嚍閸屾粌浠柣銊ュ瑜板摜鈧稈鏅涢悺锟�
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
