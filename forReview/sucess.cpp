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

struct abc{  // 48 
    int a;
    char c;
    char d;
    long b;
    string s;
};

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


       void rpreorder(Node* root)
       {
            
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
}  