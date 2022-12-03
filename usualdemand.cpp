#include <iostream>
#include <typeinfo>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

string a;
char c[]={};
pair<string, int> b;
int d;

struct abc 
{
    int a;
    bool d;
    //int b;
    //char b;
    double c;
};

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

void QPrintTree(TreeNode* head)
{
    if (head)
    {
        cout<<head->val;
        QPrintTree(head->left);
        QPrintTree(head->right);
    }
}

void ZPrintTree(TreeNode* head)
{
    if (head)
    {
        ZPrintTree(head->left);
        cout<<head->val;
        ZPrintTree(head->right);
    }
}

void HPrintTree(TreeNode* head)
{
    if (head==nullptr)
    {
        return;
    }
    HPrintTree(head->left);
    HPrintTree(head->right);
    cout<<head->val;
}

TreeNode* CreateTreebycin(TreeNode* head)
{
    int a;
    cout<<"Please set a node:";
    cin>>a;
    if (a==0)
    {
        return nullptr;
    }
    head = new TreeNode;
    head->val=a;
    cout<<"You have set a node: "<<a<<endl;
    head->left = CreateTreebycin(head->left);
    head->right = CreateTreebycin(head->right);
    return head;
}


int main () 
{
    // // int i = 12;
    // // string j = to_string(i);
    // // cout << j << endl;
    // // cout << typeid(i).name();
    // cout<<"Please Input a string:"<<endl;
    // cin>>a; //getline
    // //cout<<a<<endl;
    // strcpy(c, a.c_str());
    // cout<<c<<endl;
    // cout<<c[0]<<endl;

    // b.first=a;
    // b.second=d;
    // cout<<b.first<<endl;

    //neicun duiqi
    //cout<<sizeof(abc);

    //shoudong shuru er cha shu
    TreeNode *top, *res;
    res=CreateTreebycin(top);
    QPrintTree(res);
    printf("\n");
    ZPrintTree(res);
    printf("\n");
    HPrintTree(res);
}
